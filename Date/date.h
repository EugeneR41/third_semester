#include <string>
#include <sstream>

class Date {
private:
    int Year, Month, Day;

public:
    Date(int year, int month, int day) {
        Year = year;
        Month = month;
        Day = day;
    }
    bool IsLeap() const {
        return (((Year) % 4) == 0 &&
                (((Year) % 100) != 0 || ((Year) % 400) == 0));
    }
    std::string ToString() const {
        std::string day = std::to_string(Day);
        std::string month = std::to_string(Month);
        std::string year = std::to_string(Year);

        for (unsigned int i = 0; i < 2 - day.length(); i++) {
            day.insert(0, "0");
        }
        for (unsigned int i = 0; i < 2 - month.length(); i++) {
            month.insert(0, "0");
        }
        while (year.length() != 4) {
            year.insert(0, "0");
        }
        std::stringstream date;
        date << day << "." << month << "." << year;
        return date.str();
    }
    Date DaysLater(int days) const {
        int year = Year;
        int day = Day;
        int month = Month;
        int mon[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int mon1[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        while (days != 0) {
            day++;
            if (IsLeap()) {
                if (day > mon1[month - 1]) {
                    day = 1;
                    month++;
                }
            } else if (day > mon[month - 1]) {
                day = 1;
                month++;
            }
            if (month > 12) {
                month = 1;
                year++;
            }
            days--;
        }
        Date date(year, month, day);
        return date;
    }
    int DaysLeft(const Date & date) const {
        int year = Year;
        int day = Day;
        int month = Month;
        int mon[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int mon1[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int answer = 0;
        while ((year != date.Year) || (month != date.Month) ||
               (day != date.Day)) {
            day++;
            answer++;
            if (IsLeap()) {
                if (day > mon1[month - 1]) {
                    day = 1;
                    month++;
                }
            } else if (day > mon[month - 1]) {
                day = 1;
                month++;
            }
            if (month > 12) {
                month = 1;
                year++;
            }
        }
        return answer;
    }
};
