#include <iostream>

#include <cstdlib>

#include <ctime>

using namespace std;

class guessingGame

{

private:

    int maxRange;
    int randomNumber;

public:

    void difficultylevel()

    {
        int choice;

        cout << "----------------------------" << endl;
        cout << "Select difficulty level:" << endl << endl;
        cout << "----------------------------" << endl;

        cout << "1. Easy Level (1-8)" << endl;

        cout << "2. Medium Level (1-30)" << endl;

        cout << "3. Hard Level (1-50)" << endl << endl;

        cout << "----------------------------" << endl;
        cout << "Enter which level you want to play (1-3): ";

        cin >> choice;

        cout << "----------------------------" << endl;

        switch (choice)

        {
            case 1:

                maxRange = 8;
                break;

            case 2:

                maxRange = 30;
                break;

            case 3:

                maxRange = 50;
                break;

            default:

                cout << "Invalid choice! Defaulting to Easy Level.\n";
                maxRange = 8;
        }
    }

    void generateRandomNumber()
    {

        srand(time(0));
        randomNumber = (rand() % maxRange) + 1;

    }

    void playGame()

    {
        int guess;

        cout << "----------------------------" << endl;

        cout << "Guess a number between 1 and " << maxRange << ": ";

        while (true)

        {
            cin >> guess;

            if (guess == randomNumber)

                {
                    cout << "Congratulations! You have guessed the correct number." << endl;
                    cout << "----------------------------" << endl;

                    break;
                }

            else if (guess < randomNumber)
                {
                    cout << "Oops!!! You entered a too low digit! Try again: ";
                }
            else
                {
                    cout << "Oops!!! You entered a too high digit! Try again: ";
                }
        }
    }
};

int main()
{
    guessingGame g1;

    g1.difficultylevel();
    g1.generateRandomNumber();
    g1.playGame();

    return 0;
}
