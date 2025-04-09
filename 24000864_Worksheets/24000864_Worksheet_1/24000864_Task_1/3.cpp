#include <iostream>

#include <algorithm>

using namespace std;

class ArraySorted
{
private:

    int arr[100];

    int size;

public:
    void getdata()

    {
        cout << "--------------------------" << endl;

        cout << "Please enter the number of elements in the array: "<<endl;

        cout << "--------------------------" << endl;

        cin >> size;

        if (size <= 0 || size > 100)

            {

                cout << "Invalid size of array. Please enter a number between 1 and 100.\n";
                return;
            }

            cout << "Enter " << size << " integers: ";

        for (int i = 0; i < size; i++)

            {

                cin >> arr[i];

            }

        cout << "--------------------------" << endl;

    }

    void displayArray()

    {
        for (int i = 0; i < size; i++)

            {

                cout << arr[i] << " ";

            }

        cout << endl;

    }

    void sortedArray()
    {

        cout << "--------------------------" << endl;

        cout << "Original array: ";
        displayArray();

        sort(arr, arr + size);

        cout << "Sorted array in ascending order: ";
        displayArray();

        cout << "--------------------------" << endl;

    }
};

int main()
{
    ArraySorted A1;

    A1.getdata();
    A1.sortedArray();

    return 0;
}
