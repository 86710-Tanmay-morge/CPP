#include <iostream>
using namespace std;

class Time
{
private:
    int hour;
    int minute;
    int second;

public:
    Time() : hour(0), minute(0), second(0) {}
    Time(int h, int m, int s) : hour(h), minute(m), second(s) {}
    int getHour()
    {
        return hour;
    }
    int getMinute()
    {
        return minute;
    }
    int getSecond()
    {
        return second;
    }
    void setHour(int h)
    {
        if (h >= 0 && h < 24)
        {
            hour = h;
        }
        else
        {
            cout << "Invalid hour!" << endl;
        }
    }
    void setMinute(int m)
    {
        if (m >= 0 && m < 60)
        {
            minute = m;
        }
        else
        {
            cout << "Invalid minute!" << endl;
        }
    }
    void setSecond(int s)
    {
        if (s >= 0 && s < 60)
        {
            second = s;
        }
        else
        {
            cout << "Invalid second!" << endl;
        }
    }
    void printTime() const
    {
        cout << (hour < 10 ? "0" : "") << hour << ":"
             << (minute < 10 ? "0" : "") << minute << ":"
             << (second < 10 ? "0" : "") << second << endl;
    }
};

int main()
{
    int h, m, s;
    Time *timeArray = new Time[5];
    for (int i = 0; i < 5; ++i)
    {
        cout << "Enter hour, minute, and second for Time object " << i + 1 << ": ";
        cin >> h >> m >> s;
        timeArray[i] = Time(h, m, s);
    }
    cout << "\nDisplaying Time objects:\n";
    for (int i = 0; i < 5; ++i)
    {
        cout << "Time object " << i + 1 << ": ";
        timeArray[i].printTime();
    }
    delete[] timeArray;

    return 0;
}
