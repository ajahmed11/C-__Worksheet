#include <iostream>

#include <fstream>

#include <string>

using namespace std;

class Vehicle

{
protected:

    string registrationNumber;

    string color;

public:

    Vehicle(string regNum, string clr) : registrationNumber(regNum), color(clr) {}


    virtual void writeToFile()

    {
        ofstream file("vehicle_details.txt", ios::app);

        if (file.is_open())
        {
            file << "----------------------------" << endl;
            file << "Vehicle Registration Number: " << registrationNumber << endl;
            file << "Vehicle Color: " << color << endl;
            file << "----------------------------" << endl;
            file.close();
        }
        else
        {
            cout << "---!!! ERROR!!!--- can't be able to open file!" << endl;
        }
    }

    virtual ~Vehicle() {}
};

class Car : public Vehicle
{
private:

    int numberOfSeats;

public:

    Car(string regNum, string clr, int seats) : Vehicle(regNum, clr), numberOfSeats(seats) {}

    void writeToFile() override

    {
        ofstream file("vehicle_details.txt", ios::app);


        if (file.is_open())

        {
            file << "----------------------------" << endl;

            file << "Car Details:\n";

            file << "Registration Number: " << registrationNumber << endl;

            file << "Color: " << color << endl;

            file << "Number of Seats: " << numberOfSeats << endl;

            file << "----------------------------" << endl;

            file.close();
        }

        else

        {

            cout << "---!!! ERROR!!!--- can't be able to open file!" << endl;

        }
    }
};

class Bike : public Vehicle
{

private:

    float engineCapacity;

public:

    Bike(string regNum, string clr, float engineCap) : Vehicle(regNum, clr), engineCapacity(engineCap) {}


    void writeToFile() override

    {

        ofstream file("vehicle_details.txt", ios::app);

        if (file.is_open())

        {

            file << "----------------------------" << endl;

            file << "Bike Details:\n";

            file << "Registration Number: " << registrationNumber << endl;

            file << "Color: " << color << endl;

            file << "Engine Capacity: " << engineCapacity << " cc" << endl;

            file << "----------------------------" << endl;

            file.close();

        }

        else

            {

                cout << "---!!! ERROR!!!--- can't be able to open file!" << endl;
            }
    }
};

void addVehicleDetails()

{
    int choice;

    cout << "-------------------------------------------------\n";
    cout << "   ------ !!! Enter Vehicles Details !!! ------"<<endl;
    cout << "-------------------------------------------------\n"<<endl<<endl;

    string regNum, color;

    cout << "Choose Vehicle Type:\n"<<endl;

    cout << "1. Car:   "<<endl;

    cout << "2. Bike:  "<<endl;

    cout << "Enter your choice: ";

    cin >> choice;
    cin.ignore();

    cout << "Enter Registration Number: ";
    getline(cin, regNum);

    cout << "Enter Color of vehicle: ";
    getline(cin, color);

    if (choice == 1)

    {
        int seats;

        cout << "Enter Number of Seats of Vehicle: ";

        cin >> seats;

        Car newCar(regNum, color, seats);

        newCar.writeToFile();

    }
    else if (choice == 2)
    {
        float engineCapacity;

        cout << "Enter Engine Capacity (in cc): ";

        cin >> engineCapacity;

        Bike newBike(regNum, color, engineCapacity);

        newBike.writeToFile();
    }

    else

    {

        cout << "incorrect  choice! Please enter 1 or 2." << endl;

    }

    cout << "Vehicle details have been saved to the file." << endl;
}

void showVehicleDetails()
{
    ifstream file("vehicle_details.txt");

    if (file.is_open())

    {

        string line;

        cout << "-------------------------------------------------" << endl;

        cout << "\n======Vehicle Details =====\n" << endl;

        cout << "-------------------------------------------------" << endl;

        while (getline(file, line))

        {

            cout << line << endl;

        }

        file.close();

    }

    else

    {

        cout << "No vehicle records found!" << endl;

    }
}

int main()

{
    int choice;

    while (true)

    {
        cout << "-------------------------------------------------" << endl;

        cout << "\n===== Vehicle Management System =====\n" << endl;

        cout << "-------------------------------------------------" << endl;

        cout << "1. Add Vehicle Details\n";

        cout << "2. Show Vehicle Details\n";

        cout << "3. Exit\n";

        cout << "Enter your choice: ";

        cin >> choice;

        cin.ignore();

        switch (choice)

        {

        case 1:

            addVehicleDetails();
            break;

        case 2:

            showVehicleDetails();
            break;

        case 3:

            cout << "Exiting program. Thank you!\n";
            return 0;

        default:

            cout << "Invalid choice ! Please make number choice again.\n";
        }
    }
}
