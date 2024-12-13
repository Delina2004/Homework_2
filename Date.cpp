#include "Date.hpp"
#include <cmath>
#include <sstream>
#include <iomanip>

Time::Time(int h, int m, int s) : hour(h), minute(m), second(s) {}

void Time::addTime(int h, int m, int s) {
    second += s;
    minute += second / 60;
    second %= 60;

    minute += m;
    hour += minute / 60;
    minute %= 60;

    hour += h;
    hour %= 24;
}

void Time::subtractTime(int h, int m, int s) {
    second -= s;
    if (second < 0) {
        second += 60;
        minute--;
    }

    minute -= m;
    if (minute < 0) {
        minute += 60;
        hour--;
    }

    hour -= h;
    if (hour < 0) {
        hour += 24;
    }
}

Date::Date(int y, int m, int d) : year(y), month(m), day(d) {}

bool Date::isLeapYear(int y) {
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

int Date::daysInMonth(int y, int m) {
    static const int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (m == 2 && isLeapYear(y)) return 29;
    return days[m - 1];
}

void Date::addDate(int y, int m, int d) {
    year += y;
    month += m;
    if (month > 12) {
        year += month / 12;
        month = month % 12;
    }

    day += d;
    while (day > daysInMonth(year, month)) {
        day -= daysInMonth(year, month);
        month++;
        if (month > 12) {
            month = 1;
            year++;
        }
    }
}

void Date::subtractDate(int y, int m, int d) {
    year -= y;
    month -= m;
    if (month < 1) {
        year -= (1 - month) / 12 + 1;
        month = 12 + month % 12;
    }

    day -= d;
    while (day < 1) {
        month--;
        if (month < 1) {
            month = 12;
            year--;
        }
        day += daysInMonth(year, month);
    }
}

DateTime::DateTime(int y, int m, int d, int h, int min, int s) : date(y, m, d), time(h, min, s) {}

void DateTime::addDateTime(int y, int m, int d, int h, int min, int s) {
    time.addTime(h, min, s);
    date.addDate(y, m, d);
}

void DateTime::subtractDateTime(int y, int m, int d, int h, int min, int s) {
    time.subtractTime(h, min, s);
    date.subtractDate(y, m, d);
}

int DateTime::computeDifference(const DateTime& other) {
    int days1 = date.year * 365 + date.day;
    for (int i = 1; i < date.month; ++i) days1 += date.daysInMonth(date.year, i);
    int days2 = other.date.year * 365 + other.date.day;
    for (int i = 1; i < other.date.month; ++i) days2 += other.date.daysInMonth(other.date.year, i);

    int totalSeconds1 = days1 * 24 * 3600 + time.hour * 3600 + time.minute * 60 + time.second;
    int totalSeconds2 = days2 * 24 * 3600 + other.time.hour * 3600 + other.time.minute * 60 + other.time.second;

    return std::abs(totalSeconds1 - totalSeconds2);
}

std::string DateTime::format(const std::string& formatString) {
    std::ostringstream formatted;
    for (size_t i = 0; i < formatString.length(); ++i) {
        if (formatString[i] == 'Y' && formatString.substr(i, 4) == "YYYY") {
            formatted << date.year;
            i += 3;
        }
        else if (formatString[i] == 'M' && formatString.substr(i, 2) == "MM") {
            formatted << std::setw(2) << std::setfill('0') << date.month;
            i += 1;
        }
        else if (formatString[i] == 'D' && formatString.substr(i, 2) == "DD") {
            formatted << std::setw(2) << std::setfill('0') << date.day;
            i += 1;
        }
        else if (formatString[i] == 'H' && formatString.substr(i, 2) == "HH") {
            formatted << std::setw(2) << std::setfill('0') << time.hour;
            i += 1;
        }
        else if (formatString[i] == 'M' && formatString.substr(i, 2) == "MM") {
            formatted << std::setw(2) << std::setfill('0') << time.minute;
            i += 1;
        }
        else if (formatString[i] == 'S' && formatString.substr(i, 2) == "SS") {
            formatted << std::setw(2) << std::setfill('0') << time.second;
            i += 1;
        }
        else {
            formatted << formatString[i];
        }
    }
    return formatted.str();
}
