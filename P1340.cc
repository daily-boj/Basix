#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

constexpr int DAYS[]      = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365}; // sum of days of months
constexpr int LEAP_DAYS[] = {0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366}; // +1 after Jan.
constexpr int YEAR = 525600; // minutes
constexpr int DAY = 1440; // minutes

constexpr bool is_leap(int year) {
    return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
}

constexpr int to_days(int year, int month) {
    if(is_leap(year)) return LEAP_DAYS[month-1];
    else return DAYS[month-1];
}

int numeric_month(const string& month) {
    if (month == "January") return 1;
    else if (month == "February") return 2;
    else if (month == "March") return 3;
    else if (month == "April") return 4;
    else if (month == "May") return 5;
    else if (month == "June") return 6;
    else if (month == "July") return 7;
    else if (month == "August") return 8;
    else if (month == "September") return 9;
    else if (month == "October") return 10;
    else if (month == "November") return 11;
    else if (month == "December") return 12;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string month;
    int day = 0;
    int year = 0;
    int hour = 0;
    int minute = 0;

    cin >> month >> day;
    cin.ignore(numeric_limits<streamsize>::max(), ',');
    cin >> year >> hour;
    cin.ignore(numeric_limits<streamsize>::max(), ':');
    cin >> minute;

    int sum = 0; // im minutes
    sum += to_days(year, numeric_month(month)) * DAY;
    sum += day * DAY;
    sum += hour * 60;
    sum += minute;

    double divisor = YEAR;
    if(is_leap(year)) divisor += DAY;

    cout << (sum*100) / divisor << endl;
}
