#!/bin/bash

# Colors for output
GREEN='\033[0;32m'
RED='\033[0;31m'
YELLOW='\033[0;33m'
NC='\033[0m' # No Color

# Make sure the game is compiled
echo -e "${YELLOW}Compiling the game...${NC}"
make re

if [ $? -ne 0 ]; then
    echo -e "${RED}Compilation failed!${NC}"
    exit 1
fi

echo -e "${GREEN}Compilation successful!${NC}\n"

# Function to run a test
run_test() {
    local test_name=$1
    local map_file=$2
    local expected_result=$3
    
    echo -e "${YELLOW}Running test: ${test_name}${NC}"
    ./so_long $map_file
    
    local exit_code=$?
    if [ $exit_code -eq $expected_result ]; then
        echo -e "${GREEN}Test passed!${NC}"
    else
        echo -e "${RED}Test failed! Expected exit code $expected_result, got $exit_code${NC}"
    fi
    echo ""
}

# Test with valid maps (exit code 0 means success)
echo -e "${YELLOW}=== Testing Valid Maps ===${NC}"
run_test "Simple valid map" "maps/valid_simple.ber" 0
run_test "Large valid map" "maps/valid_large.ber" 0

# Test with invalid file extensions (exit code non-zero means error)
echo -e "${YELLOW}=== Testing Invalid File Extensions ===${NC}"
run_test "Wrong extension" "maps/invalid.txt" 1
run_test "No extension" "maps/invalid" 1

# Test with invalid map structures
echo -e "${YELLOW}=== Testing Invalid Map Structures ===${NC}"
run_test "Non-rectangular map" "maps/invalid_not_rectangular.ber" 1
run_test "Map not closed by walls" "maps/invalid_not_closed.ber" 1

# Test with invalid map contents
echo -e "${YELLOW}=== Testing Invalid Map Contents ===${NC}"
run_test "No player" "maps/invalid_no_player.ber" 1
run_test "Multiple players" "maps/invalid_multiple_players.ber" 1
run_test "No collectibles" "maps/invalid_no_collectibles.ber" 1
run_test "No exit" "maps/invalid_no_exit.ber" 1
run_test "Invalid characters" "maps/invalid_invalid_chars.ber" 1

# Test with path validation issues
echo -e "${YELLOW}=== Testing Path Validation ===${NC}"
run_test "No path to exit" "maps/invalid_no_path_to_exit.ber" 1
run_test "No path to collectible" "maps/invalid_no_path_to_collectible.ber" 1

# Test with non-existent file
echo -e "${YELLOW}=== Testing File Errors ===${NC}"
run_test "Non-existent file" "maps/does_not_exist.ber" 1

# Memory leak test with Valgrind
if command -v valgrind &> /dev/null; then
    echo -e "${YELLOW}=== Testing Memory Leaks ===${NC}"
    valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./so_long maps/valid_simple.ber
else
    echo -e "${YELLOW}Valgrind not found. Skipping memory leak tests.${NC}"
fi

echo -e "${GREEN}All tests completed!${NC}"