# So_Long Test Script Documentation

This document explains the automated testing script `test_so_long.sh` for the So_Long project.

## Overview

The test script provides comprehensive validation of the So_Long game implementation, ensuring that:
- The game compiles successfully
- Valid maps are processed correctly
- Invalid maps are properly rejected with appropriate error handling
- Memory management is sound (no leaks)

## Running the Tests

To run the full test suite:

```bash
./test_so_long.sh
```

The script will automatically:
1. Compile the game with `make re`
2. Run a series of tests with different map files
3. Report the success/failure of each test

## Test Categories

### Valid Maps
Tests that the game properly loads and runs with valid map configurations:
- **Simple valid map**: A basic valid map that meets all requirements
- **Large valid map**: A more complex, larger valid map

### Invalid File Extensions
Tests rejection of files with incorrect formats:
- **Wrong extension**: Files not ending with `.ber`
- **No extension**: Files with no extension

### Invalid Map Structures
Tests proper rejection of structurally flawed maps:
- **Non-rectangular map**: Maps that aren't perfectly rectangular
- **Map not closed by walls**: Maps missing wall boundaries

### Invalid Map Contents
Tests proper rejection of maps with invalid content:
- **No player**: Maps missing the player character 'P'
- **Multiple players**: Maps with more than one player character
- **No collectibles**: Maps missing collectibles 'C'
- **No exit**: Maps missing the exit 'E'
- **Invalid characters**: Maps containing characters other than '0', '1', 'P', 'C', and 'E'

### Path Validation
Tests proper validation of path accessibility:
- **No path to exit**: Maps where the player cannot reach the exit
- **No path to collectible**: Maps where the player cannot reach all collectibles

### File Errors
Tests proper handling of file-related errors:
- **Non-existent file**: Attempting to load a file that does not exist

### Memory Leak Testing
If Valgrind is installed on the system, tests for memory leaks:
- Runs the game with Valgrind to detect any memory leaks or errors

## Advanced Test Features

### Test Timing
The script measures the execution time for each test:
- Displays the time taken in milliseconds for each map test
- Helps identify performance issues with specific map types

### Test Logging
Test results are saved to a log file (`test_results.log`):
- Records a timestamp for the test session
- Captures all test outputs for future reference
- Useful for tracking regression issues over time

### Random Map Generation
The script includes functionality to generate random test maps:
- Creates maps with customizable dimensions
- Useful for stress testing with diverse map layouts
- Generated maps are saved with the prefix `generated_` in the maps directory

### Cleanup Function
The script includes an automatic cleanup routine:
- Removes any dynamically generated map files
- Deletes the test log file when testing is complete
- Activated automatically when the script exits (via trap)

## Exit Codes

The test script expects:
- Exit code 0 for successful operations (valid maps)
- Non-zero exit code for error conditions (invalid maps)

## Test Map Files

The script relies on the following map files in the `maps/` directory:
- `valid_simple.ber`: A simple valid map
- `valid_large.ber`: A larger valid map
- `invalid_not_rectangular.ber`: A non-rectangular map
- `invalid_not_closed.ber`: A map not fully enclosed by walls
- `invalid_no_player.ber`: A map without a player
- `invalid_multiple_players.ber`: A map with multiple players
- `invalid_no_collectibles.ber`: A map without collectibles
- `invalid_no_exit.ber`: A map without an exit
- `invalid_invalid_chars.ber`: A map with invalid characters
- `invalid_no_path_to_exit.ber`: A map where the exit is unreachable
- `invalid_no_path_to_collectible.ber`: A map where some collectibles are unreachable

## Output

The script uses color-coded output:
- 🟢 Green: Success messages and passed tests
- 🔴 Red: Error messages and failed tests
- 🟡 Yellow: Section headers and informational messages

## Extending the Tests

To add new tests:
1. Create appropriate map files in the `maps/` directory
2. Add new test cases to the script using the `run_test` function:
```bash
run_test "Test name" "path/to/map.ber" expected_exit_code
```

To generate and test with random maps:
```bash
# Generate a random map with specified dimensions
generate_random_map "maps/generated_test.ber" width height

# Run test with the generated map
run_test "Random map test" "maps/generated_test.ber" expected_exit_code
```

## Troubleshooting

If a test fails, the script provides:
- The expected and actual exit codes
- The path to the map file that caused the failure
- Detailed error messages to help diagnose the issue