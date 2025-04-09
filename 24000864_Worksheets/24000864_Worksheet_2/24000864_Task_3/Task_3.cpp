#include <iostream>

#include <fstream>

#include <vector>

#include <string>

#include <stdexcept>

using namespace std;

class BookManager

{

public:

    void addBooks()

    {

        ofstream out("books.dat", ios::binary | ios::app);

        if (!out)

            {

            cout << "Error opening books.dat for writing." << endl;
            return;
        }

        for (int i = 0; i < 10; ++i)

            {
                string title;

                cout << "Enter  Title for book:  " << i + 1 << ": ";

                cin.ignore();

                getline(cin, title);

                out.write(title.c_str(), title.size() + 1);
            }

        out.close();

        cout << "------------------------------------------------------" << endl;

        cout << "\n congrats!!! Books Details are saved successfully!" << endl;

        cout << "------------------------------------------------------" << endl;
    }

    void searchBook()

    {

        string searchTitle;

        cout << "Enter book title you want to search: ";

        cin.ignore();

        getline(cin, searchTitle);

        ifstream in("books.dat", ios::binary);
        if (!in)

            {

                cout << "Error opening books.dat for reading." << endl;

                return;
        }

        string title;

        bool found = false;

        while (getline(in, title, '\0'))
            {
                if (title == searchTitle)

                {

                    found = true;
                    break;
            }
        }

        in.close();

        cout << (found ? "\n Book you searched is found !" : "\n Book You searched doesn't  found.") << endl;

        cout << "---------------------------------------------" << endl;
    }

    void showAllBooks()

        {
            ifstream in("books.dat", ios::binary);

            if (!in)
                {
                    cout << "Error opening books.dat for reading." << endl;

                    return;
                }

            cout << "---------------------------------------------";

            cout << "\n ----Book EXISTS in Library:----  \n";

            cout << "---------------------------------------------" << endl;

            string title;

            int count = 0;

        while (getline(in, title, '\0'))

            {

                cout << ++count << ". " << title << endl;
            }

            if (count == 0)

                cout << "No Matching books found." << endl;

            in.close();
            cout << "--------------------------------" << endl;
    }
};

class StudentManager

{

public:
    struct Student

        {
            int roll;

            string name;

            float marks;
    };

private:

    vector<Student> students;

public:

    void loadStudents()

    {
        students.clear();

        ifstream in("students.txt");

        Student s;

        while (in >> s.roll >> ws && getline(in, s.name) && in >> s.marks)

            {

                students.push_back(s);
            }

        in.close();
    }

    void addStudent()

    {
        Student s;

        cout << "Enter Student roll number: ";

        cin >> s.roll;
        cin.ignore();

        cout << "Enter student name: ";
        getline(cin, s.name);

        cout << "Enter Student marks (0-100): ";
        cin >> s.marks;

        if (s.marks < 0 || s.marks > 100)

            {

                throw out_of_range(" Marks must be between 0 and 100.");

            }

        students.push_back(s);

        saveStudents();

        cout << "\n wow!! Student record saved successfully!" << endl;
        cout << "--------------------------------" << endl;
    }

    void saveStudents()

        {
            ofstream out("students.txt", ios::app);

            for (const auto& s : students)
                {
                    out << s.roll << endl

                    << s.name << endl

                    << s.marks << endl;
                }

            out.close();
        }

    void displayStudents()

    {
        if (students.empty())

            {

                cout << "!!! student Student Details found !!!." << endl;

            }
        else
            {



            cout << "\n  !!! Student Records  !!! :\n";

            cout << "-------------------------------"<<endl ;


            for (const auto& s : students)

                {
                    cout << "Roll No: " << s.roll

                        << ", Name: " << s.name

                        << ", Marks: " << s.marks << endl;
                }
            }

        cout << "--------------------------------" << endl;
    }
};

int main()

{
    BookManager bookManager;

    StudentManager studentManager;

    int choice;
    do

        {
            cout << "\n===== !! LIBRARY MENU !! ===========" << endl;

            cout << "1. Add Book Titles" << endl;

            cout << "2. Search for a Book" << endl;

            cout << "3. Add New Student" << endl;

            cout << "4. Show Students Details " << endl;

            cout << "5. Show Existing Books" << endl;

            cout << "0. Exit Program " << endl;

            cout << "Enter your choice: ";

            cin >> choice;

            cout << "--------------------------------" << endl;

        switch (choice)

        {
            case 1:

                bookManager.addBooks();
                break;

            case 2:

                bookManager.searchBook();
                break;

            case 3:

                try

                    {

                        studentManager.loadStudents();
                        studentManager.addStudent();

                    }

                catch (const exception& e)

                    {
                        cout << "\n Exception occurred: " << e.what() << endl;

                        cout << "--------------------------------" << endl;
                    }

                    break;

            case 4:

                studentManager.loadStudents();
                studentManager.displayStudents();
                break;

            case 5:

                bookManager.showAllBooks();
                break;

            case 0:

                cout << "-----------------------------------";
                cout << "\n !! ThAnK YoU __ Visit Again !!"<<endl;
                cout << "-----------------------------------" << endl;
                break;

            default:

                cout << "❗ Invalid choice. Please try again." << endl;
                cout << "--------------------------------" << endl;
        }

    }

    while (choice != 0);


    return 0;
}
