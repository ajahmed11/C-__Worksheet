#include <iostream>
#include <string>
using namespace std;

class Student

{

private:

    string name;

    string subjects[3] = {"Python", "Networking", "Cybersecurity"};

    int marks[3];

public:

    void getDetails()

        {

            cout << "------------------------------------------" << endl;

            cout << "Enter the student's name: ";

        getline(cin, name);

        for (int i = 0; i < 3; i++)

            {

                cout << "Enter marks for " << subjects[i] << " (0-100): ";

                cin >> marks[i];

            while (marks[i] < 0 || marks[i] > 100)

                {

                    cout << "Invalid input! Marks must be between 0 and 100. Please enter again: ";

                    cin >> marks[i];

                }
        }
        cout << "------------------------------------------" << endl;
    }

    int totalMarks()

    {

        int total = 0;

        for (int i = 0; i < 3; i++)

            {

                total += marks[i];

            }

        return total;
    }


    double averageMarks()

    {

        return static_cast<double>(totalMarks()) / 3.0;
    }

    char calculateGrade()

    {

        double avg = averageMarks();

        if (avg >= 90)
            return 'A';

        else if (avg >= 80)
            return 'B';

        else if (avg >= 70)
            return 'C';

        else if (avg >= 60)
            return 'D';

        else
            return 'F';
    }


    void displayDetails()

    {

        cout << "\n------------------------------------------" << endl;

        cout << "Student Name: " << name << endl;

        for (int i = 0; i < 3; i++)
            {

                cout << subjects[i] << " Marks: " << marks[i] << endl;

            }

        cout << "Total Marks: " << totalMarks() << endl;

        cout << "Average Marks: " << averageMarks() << endl;

        cout << "Grade: " << calculateGrade() << endl;

        cout << "------------------------------------------" << endl;
    }
};

int main()

{
    Student s1;

    s1.getDetails();

    s1.displayDetails();

    return 0;
}
