#include <iostream>

using namespace std;

class BouncyNumberChecker

{

public:

    bool isBouncy(int number)

    {
        bool increasing = false, decreasing = false;

        int lastDigit = number % 10;

        number /= 10;

        while (number > 0)

            {
                int currentDigit = number % 10;

                if (currentDigit < lastDigit)

                    increasing = true;

                if (currentDigit > lastDigit)

                    decreasing = true;

            lastDigit = currentDigit;
            number /= 10;

                if (increasing && decreasing)

                    return true;
            }

        return false;
    }

    void checkNumber()
        {
            int number;

            cout << "------------------------------" << endl;
            cout << "Enter a positive integer: ";
            cin >> number;
            cout << "------------------------------" << endl;

        if (number < 100)
            {
                cout << "Entered Number = " << number << endl;

                cout << "It is NOT a bouncy number (It starts from 3-digit numbers)." << endl;
            }

        else if (isBouncy(number))
            {

                cout << number << " is a bouncy number!" << endl;
            }

        else

            {

                cout << number << " is NOT a bouncy number." << endl;
            }

        cout << "------------------------------" << endl;
    }
};

int main()
{
    BouncyNumberChecker c1;

    c1.checkNumber();

    return 0;
}
