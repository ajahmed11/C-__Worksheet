#include <iostream>
using namespace std;

class MaxFinder

{

public:

    int findMax(int a, int b)
    {

        return (a > b) ? a : b;
    }

    float findMax(float a, float b)

    {

        return (a > b) ? a : b;
    }

    int findMax(int a, int b, int c)

    {
        if (a >= b && a >= c)
            return a;

        else if (b >= a && b >= c)
            return b;

        else
            return c;
    }

    float findMax(int a, float b)
    {

        return (a > b) ? a : b;
    }
};

int main() {
    MaxFinder m1;
    int int1, int2, int3;

    float float1, float2;

    cout << "--------------------------------------------" << endl;
    cout << "----- Maximum nunber between two integers -----" << endl;

    cout << "Enter any two integers: ";
    cin >> int1 >> int2;

    cout << "Max: " << m1.findMax(int1, int2) << endl;

    cout << "--------------------------------------------" << endl;
    cout << "----- Maximum number between two floats -----" << endl;

    cout << "Enter any two float value: ";
    cin >> float1 >> float2;

    cout << "Max: " << m1.findMax(float1, float2) << endl;

    cout << "--------------------------------------------" << endl;
    cout << "----- Maximum Number among three integers -----" << endl;

    cout << "Enter any three integers: ";
    cin >> int1 >> int2 >> int3;

    cout << "Maximum Number: " << m1.findMax(int1, int2, int3) << endl;

    cout << "--------------------------------------------" << endl;

    cout << "----- Maximum between integer and float -----" << endl;

    cout << "Enter any integer and a float: ";

    cin >> int1 >> float1;

    cout << "Maximum Number: " << m1.findMax(int1, float1) << endl;

    cout << "--------------------------------------------" << endl;



    return 0;
}
