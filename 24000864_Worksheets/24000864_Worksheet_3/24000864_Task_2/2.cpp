#include <iostream>

#include <fstream>

#include <vector>

#include <string>

#include <sstream>

#include <iomanip>

using namespace std;

const string subjects[] = {"PYTHON", "C/C++", "JAVA", "FORENSICS", "Ethical"};


class Person

{

public:

    int roll_no;
    string student_name;

    void inputBasicInfo()

    {
        cout << "Enter Roll Number: ";
        cin >> roll_no;

        cin.ignore();

        cout << "Enter the Student Name: ";
        getline(cin, student_name);
    }
};


class Student : public Person

{

public:

    vector<int> marks;

    void getdata()

    {
        cout << "----------------------------------------------" << endl;
        cout << "  ------- !!! ADD Student Details!!! -------" << endl;
        cout << "----------------------------------------------" << endl;

        inputBasicInfo();

        marks.clear();
        cout << "Enter student marks for subjects:\n";
        for (int i = 0; i < 5; i++)

            {
                int student_mark;

                cout << subjects[i] << ": ";

                cin >> student_mark;

            if (student_mark < 0 || student_mark > 100)

                {
                    cout << " ---invalid!!! mark input---. --marks Must be between 0 and 100.--\n";

                    i--;

                continue;
            }

            marks.push_back(student_mark);
        }
    }

    float average() const

    {
        float total = 0;

        for (int mark : marks)

            total += mark;

        return total / marks.size();
    }

    char grade() const

    {
        float avg = average();

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

    void display() const

    {
        cout << left << setw(20) << roll_no << setw(25) << student_name;

        for (int student_mark : marks)

            cout << setw(10) << student_mark;

        cout << setw(10) << fixed << setprecision(2) << average();

        cout << setw(6) << grade();
        cout << endl;
    }

    string toString() const

    {
        stringstream ss;

        ss << roll_no << "|" << student_name << "|";

        for (size_t i = 0; i < marks.size(); ++i)

            {
                ss << marks[i];

                if (i < marks.size() - 1) ss << ",";
        }

        return ss.str();
    }

    bool fromString(const string& line)

    {
        stringstream ss(line);

        string roll_noStr, student_nameStr, student_markStr;

        if (!getline(ss, roll_noStr, '|') || !getline(ss, student_nameStr, '|') || !getline(ss, student_markStr))

            return false;

        try
            {

                roll_no = stoi(roll_noStr);
            }

        catch (...)

            {
                return false;
            }

            student_name = student_nameStr;
            marks.clear();

            stringstream ms(student_markStr);
            string m;

        while (getline(ms, m, ',')) {

            try

                {
                    marks.push_back(stoi(m));
                }

            catch (...)

                {

                    return false;

                }
        }

        return marks.size() == 5;
    }
};

void displayAll()

{
    ifstream file("students.txt");

    if (!file)
        {
            cout << "No records found.\n";
            return;
        }

    cout << left << setw(20) << "Roll Number" << setw(25) << "Student Name";

    for (int i = 0; i < 5; ++i)

        cout << setw(10) << subjects[i];

    cout << setw(10) << "Average" << setw(6) << "Grade";

    cout << "\n" << string(115, '-') << endl;

    string line;
    Student s;

    while (getline(file, line))

        {
            if (s.fromString(line))
                {

                    s.display();
                }
            else

                {

                    cout << "Invalid line: " << line << endl;

                }
    }
    file.close();
}

void addStudent()

{
    Student s;
    s.getdata();

    ofstream file("students.txt", ios::app);

    if (!file)

        {
            cout << "Error writing to file.\n";
            return;
        }
    file << s.toString() << endl;
    file.close();

    cout << "---------------------------------------------------" << endl << endl;
    cout << "----- !!! CoNgRaTuLaTiOnS ReCoRd AdDeD !!! -----" << endl;
    cout << "Student information has been added successfully.\n";
    cout << "------------------------------------------------------" << endl << endl;
}

void updateStudent()

{
    ifstream file("students.txt");

    if (!file)
        {
            cout << "No records found.\n";
            return;
        }

    vector<Student> all;
    string line;
    Student s;
    while (getline(file, line))
        {
            if (s.fromString(line))

            {

                all.push_back(s);
            }
    }
    file.close();

    int roll;


    cout << "-------------------------------------------------" << endl;
    cout << "               !!! STUDENT ReCoRd !!!       " << endl;
    cout << "    ------ !!! UPDATE STUDENT DATA!!! ------" << endl;
    cout << "-------------------------------------------------" << endl;
    cout << "Enter Roll Number to update student data: ";
    cin >> roll;

    bool found = false;

    for (auto& stu : all)

        {
            if (stu.roll_no == roll)

            {
                cout << "Enter new marks for student " << stu.student_name << ":\n";
                stu.marks.clear();
            for (int i = 0; i < 5; ++i)
                {
                    int mark;

                    cout << subjects[i] << ": ";
                    cin >> mark;

                    stu.marks.push_back(mark);
                }

            found = true;
            break;
        }
    }

    if (!found)

        {
            cout << "Student not found.\n";
            return;
        }

    ofstream out("students.txt");

    for (const auto& stu : all)
        {
            out << stu.toString() << endl;
        }

    out.close();

    cout << "----------------------------------------" << endl << endl;
    cout << "------Congratulations------" << endl << endl;
    cout << "-----Record updated.-----\n";
    cout << "----------------------------------------" << endl << endl;
}

int main()
{
    int choice;

    cout << "-------------------------------------------------------------" << endl;
    cout << "     ------ !!! WELCOME TO Management System !!! -----" << endl;
    cout << "-------------------------------------------------------------" << endl << endl;

    while (true)

        {
            cout << "1. View Students\n";
            cout << "2. Add Student\n";
            cout << "3. Update Student\n";
            cout << "4. Exit\n";
            cout << "----------------------------------------" << endl ;
            cout << "Choice: ";

            cin >> choice;
            cin.ignore();

        switch (choice)

        {
            case 1:

                displayAll();
                break;

            case 2:

                addStudent();
                break;

            case 3:

                updateStudent();
                break;

            case 4:

                cout << "____ --- !!! Thank you For visiting !!!---___!\n";
                return 0;

            default:

                cout << "please !!! Enter correct choice.\n";
        }
    }
}
