#include "Date.hpp"
#include <iostream>

int main() {
    DateTime dt1(2024, 12, 13, 14, 30, 0);
    DateTime dt2(2023, 11, 12, 10, 15, 0);

    dt1.addDateTime(0, 1, 0, 2, 15, 30); // Example of adding date and time
    std::cout << "After addition: " << dt1.format("Today is YYYY-MM-DD and the time is HH:MM:SS") << std::endl;

    int difference = dt1.computeDifference(dt2);
    std::cout << "Difference in seconds: " << difference << std::endl;

    return 0;
}
