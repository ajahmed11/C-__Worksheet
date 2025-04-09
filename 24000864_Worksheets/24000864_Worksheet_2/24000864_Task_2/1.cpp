#include <iostream>

using namespace std;

class Circle
{
private:
    float radius;

public:

    Circle(float r)
    {
        radius = r;
    }

    friend void compareTwoCircles(Circle c1, Circle c2);
};

void compareTwoCircles(Circle c1, Circle c2)
{
    float area1 = 3.14159 * c1.radius * c1.radius;
    float area2 = 3.14159 * c2.radius * c2.radius;

    cout << "----------------------------------------------" << endl;
    cout << "Area of Circle 1: " << area1 << endl;
    cout << "Area of Circle 2: " << area2 << endl;
    cout << "----------------------------------------------" << endl;

    if (area1 > area2)
        {

            cout << "Circle 1 has the larger area." << endl;
        }

    else if (area2 > area1)

        {

            cout << "Circle 2 has the larger area." << endl;
        }
    else
        {

            cout << "Both circles have the same area." << endl;
        }

        cout << "----------------------------------------------" << endl;
}

int main()
{

    float radius1, radius2;

    cout << "----------------------------------------------" << endl;
    cout << "Enter the radius for Circle 1: ";

    cin >> radius1;
    Circle circle1(radius1);

    cout << "Enter the radius for Circle 2: ";
    cin >> radius2;

    Circle circle2(radius2);

    cout << "----------------------------------------------" << endl;

    compareTwoCircles(circle1, circle2);

    return 0;
}
