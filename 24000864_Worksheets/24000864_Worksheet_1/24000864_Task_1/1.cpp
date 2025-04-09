#include <iostream>
#include <limits>

using namespace std;

class TemperatureConverter

{

private:

    double temperature;

public:

    void getdata()

    {
        cout << "--------------------------------" << endl;
        cout << "Enter temperature value: ";


        while (!(cin >> temperature))

            {
                cout << "Invalid input. Please enter a numeric temperature value: ";
                cin.clear();

                cin.ignore(numeric_limits<streamsize>::max(), '\n');

            }

            cout << "--------------------------------" << endl;
    }

    double converttoFahrenheit()

        {

            return (temperature * 9.0 / 5.0) + 32;

        }


    double converttoCelsius()

        {

            return (temperature - 32) * 5.0 / 9.0;

        }

    void convertTemperature()

        {

            char choice;

            cout << "--------------------------------" << endl;

            cout << "Convert to (C)elsius or (F)ahrenheit? Enter C or F: ";
            cin >> choice;

        if (choice == 'f')

            {

                cout << "Converted Temperature: " << converttoFahrenheit() << " F" << endl;
            }

        else if (choice == 'c' || choice == 'C')
            {

                cout << "Converted Temperature: " << converttoCelsius() << " C" << endl;

            }
        else
            {

                cout << "Invalid choice. Please enter 'C' or 'F'." << endl;
            }

            cout << "--------------------------------" << endl;
    }
};

int main()
    {
        TemperatureConverter C1;

    C1.getdata();
    C1.convertTemperature();

    return 0;
}
