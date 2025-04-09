#include <iostream>

using namespace std;

class TicketBookingSystem

{

private:

    char seating[5][5];

public:

    TicketBookingSystem()

    {

        for (int i = 0; i < 5; i++)

            {
                for (int j = 0; j < 5; j++)

                    {
                        seating[i][j] = 'O';
                    }
        }
    }

    void displaySeating()
    {
        cout << "-----------------------------" << endl;
        cout << "\nCurrent Seating Arrangement:\n";

        for (int i = 0; i < 5; i++)
            {
                for (int j = 0; j < 5; j++)

                    {
                        cout << seating[i][j] << " ";

                    }

            cout << endl;
        }

        cout << "-----------------------------" << endl;
    }

    void bookSeat()

    {
        int row, col;

        cout << "Enter the row (1-5) to book your seat: ";
        cin >> row;

        cout << "Enter the column (1-5) to book your seat: ";
        cin >> col;

        if (row < 1 || row > 5 || col < 1 || col > 5)

            {
                cout << "Invalid row or column number! Please enter values between 1 and 5.\n";
                return;
            }

        row--;
        col--;

        if (seating[row][col] == 'X')

            {
                cout << "Error: The seat is already booked!\n";
            }

        else

            {
                seating[row][col] = 'X';
                cout << "Seat booked successfully!\n";
            }
    }
};

int main()

{
    TicketBookingSystem cinema;

    while (true)
        {
            cinema.displaySeating();
            cinema.bookSeat();

        char choice;

        cout << "Do you want to book another seat? (Y/N): ";
        cin >> choice;

        if (choice == 'n')

            {
                cout << "Thank you for using the Cinema Booking System!\n";
                break;
        }
    }

    return 0;
}
