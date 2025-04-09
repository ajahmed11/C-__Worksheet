#include <iostream>

#include <stdexcept>

using namespace std;

class Time

{
    int hour, minute;

    void validate()

    {
        if (hour < 0 || hour >= 24 || minute < 0 || minute >= 60)

        {

            throw invalid_argument("INVALID iNPUT!!! Eter between 0 and 23, minutes between 0 and 59.");

        }
    }

public:

    Time(int h = 0, int m = 0)

    {
        hour = h;

        minute = m;

        validate();
    }


    void display()

        {

            cout << "   " << hour << " hour(s) " << minute << " minute(s)" << endl;
        }

    Time operator+(Time& t)

        {
            Time temp;

            temp.hour = hour + t.hour;

            temp.minute = minute + t.minute;

        if (temp.minute >= 60)

            {
                temp.hour += temp.minute / 60;

                temp.minute = temp.minute % 60;
            }

        if (temp.hour >= 24)

            {

                temp.hour = temp.hour % 24;
            }

        temp.validate();
        return temp;

    }

    bool operator>(Time& t)

    {
        if (hour > t.hour)

            {

                return true;
            }

        else if (hour == t.hour && minute > t.minute)

        {

            return true;
        }

        return false;
    }
};

int main()

{
    try

        {
            int h1, m1, h2, m2;

            cout << "-----------------------------------------------" << endl;

            cout << "Enter Time 1:" << endl;

            cout << "   Hours: ";

            cin >> h1;

            cout << "   Minutes: ";
            cin >> m1;

        cout << "-----------------------------------------------" << endl;


        cout << "Enter Time 2:" << endl;
        cout << "   Hours: ";
        cin >> h2;

        cout << "   Minutes: ";
        cin >> m2;
        cout << "-----------------------------------------------" << endl;

        Time t1(h1, m1);
        Time t2(h2, m2);

        cout << "\nTime 1: ";
        t1.display();

        cout << "\n-----------------------------------------------" << endl;
        cout << "\nTime 2: ";
        t2.display();

        Time sum = t1 + t2;

        cout << "\n-----------------------------------------------" << endl;
        cout << "\nSum of Time 1 and Time 2: ";
        sum.display();

        cout << "\n-----------------------------------------------" << endl;
        if (t1 > t2)

            {

                cout << "Time 1 is greater than Time 2" << endl;

            }

         else

            {

                cout << "Time 2 is greater than or equal to Time 1" << endl;

            }

        cout << "-----------------------------------------------" << endl;
    }
    catch (const invalid_argument& e)

    {

        cout << "Error: " << e.what() << endl;

    }

    return 0;
}
