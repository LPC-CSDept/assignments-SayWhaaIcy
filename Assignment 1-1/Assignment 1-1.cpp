#include <iostream>
#include <fstream>
using namespace std;

struct Student {
  int id;
  char sname[20];
  double score[2];
  double sum;
  double avg;
};

void findStudent(Student[]);

int main()
{
    ifstream ifs;
    ofstream ofs;

    Student s[10];
    ifs.open("students.txt");
    ofs.open("student.bin");

// To read students.txt file
    for (int i=0; i<10; i++)
    {
        ifs >> s[i].id;
        ifs >> s[i].sname;
        ifs >> s[i].score[0];
        ifs >> s[i].score[1];
        s[i].sum = s[i].score[0] + s[i].score[1];
        s[i].avg = s[i].sum/2;
    }

// Writing values from "Student structure into binary file "students.bin"
    for (int i=0; i<10; i++)
    {
        ofs.write( (char *)&s, sizeof(s));
    }

    findStudent(s);

    cout << "To request another student's information please restart program. Goodbye." << endl;
}

// Finding indivdual Student ID
    void findStudent(Student s[]){
        int input;
        bool found = 0;
        do
        {
            cout << "Enter the 5 digit Student ID: " << endl;
            cin >> input;
            cout << endl;
            
            for (int i=0; i<10; i++)
            {
                if (input == s[i].id)
                {
                    cout << "Requested Student Information: \n";
                    cout << "Student ID: " << s[i].id << "\n";
                    cout << "Student Name: " << s[i].sname << "\n";
                    cout << "Score 1: " << s[i].score[0] << "\n";
                    cout << "Score 2: " << s[i].score[1] << "\n";
                    cout << "Sum    : " << s[i].sum << "\n";
                    cout << "Average: " << s[i].avg << endl << endl;
                    found = 1;
                }
            }

            if (found !=1)
                cout << "You entered an invalid ID \n";
            
        } while (found !=1);
    }