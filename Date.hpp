#ifndef DATE_HPP
#define DATE_HPP

#include <string>

class Time {
public:
    int hour, minute, second;

    Time(int h = 0, int m = 0, int s = 0);
    void addTime(int h, int m, int s);
    void subtractTime(int h, int m, int s);
};

class Date {
public:
    int year, month, day;

    Date(int y = 2000, int m = 1, int d = 1);
    bool isLeapYear(int y);
    int daysInMonth(int y, int m);
    void addDate(int y, int m, int d);
    void subtractDate(int y, int m, int d);
};

class DateTime {
public:
    Date date;
    Time time;

    DateTime(int y = 2000, int m = 1, int d = 1, int h = 0, int min = 0, int s = 0);
    void addDateTime(int y, int m, int d, int h, int min, int s);
    void subtractDateTime(int y, int m, int d, int h, int min, int s);
    int computeDifference(const DateTime& other);
    std::string format(const std::string& formatString);
};

#endif // DATE_HPP
