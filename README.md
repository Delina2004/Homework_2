# Date and Time Arithmetic Project

## Overview
This project implements a system for managing and performing arithmetic operations on date and time. The system consists of three classes:

1. `Time`: Handles operations related to hours, minutes, and seconds.
2. `Date`: Handles operations related to year, month, and day.
3. `DateTime`: Combines the functionality of `Date` and `Time` to manage complete date-time arithmetic.

## Features

### Time Class
- Add and subtract hours, minutes, and seconds.
- Automatically handles overflow and underflow, such as carrying extra seconds to minutes or minutes to hours.

### Date Class
- Add and subtract years, months, and days.
- Automatically handles leap years and month boundaries.
- Correctly adjusts for varying days in different months.

### DateTime Class
- Combines `Date` and `Time` to support full date-time arithmetic.
- Compute the difference between two `DateTime` objects in seconds.
- Format the date and time based on a customizable format string (e.g., `YYYY-MM-DD`, `HH:MM:SS`).

## File Structure
The project is divided into the following files:

1. **Header File (`Date.hpp`)**
   - Contains class declarations and function prototypes.

2. **Implementation File (`Date.cpp`)**
   - Contains the method implementations for `Date`, `Time`, and `DateTime`.

3. **Main File (`main.cpp`)**
   - Contains the main function to demonstrate the features of the system.

4. **README File**
   - Provides an overview and instructions for the project.

## Usage Instructions

### Compilation
To compile the project, use the following command:
```bash
g++ main.cpp Date.cpp -o DateTimeApp
```

### Execution
Run the compiled program:
```bash
./DateTimeApp
```

### Example Operations
- Add 1 month and 2 hours to a `DateTime` object.
- Format the current `DateTime` as: "Today is YYYY-MM-DD and the time is HH:MM:SS."
- Compute the difference in seconds between two `DateTime` objects.

## Dependencies
- Standard C++ Libraries: `<iostream>`, `<string>`, `<iomanip>`, `<cmath>`

## Sample Output
Example of running the program:
```
After addition: Today is 2025-01-13 and the time is 16:45:30
Difference in seconds: 31556790
```

## Notes
- The program handles edge cases like leap years and varying days in months.
- The `DateTime::format` method allows flexible formatting with both placeholders and static text.

## Author
This project was implemented by [Your Name].

