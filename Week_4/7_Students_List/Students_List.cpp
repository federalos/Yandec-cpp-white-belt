#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Student
{
    string Name;
    string Surname;
    int Birth_Day;
    int Birth_Month;
    int Birth_Year;
};


int main(){
    int Amount_Commands = 0;
    cin >> Amount_Commands;

    Student student;
    vector<Student> Students;

    string name, surname;
    int day, month, year;

    // Listing of students;
    for (int iter_command = 0; iter_command < Amount_Commands; iter_command++){
        cin >> name >> surname >> day >> month >> year;
        student = {name, surname, day, month, year};
        Students.push_back(student);
    }

    cin >> Amount_Commands;
    string command;
    int number;
    for (int iter_command = 0; iter_command < Amount_Commands; iter_command++){
        cin >> command >> number;
        if ((command == "name") && (number > 0) && (number <= Students.size())){
            cout << Students[number - 1].Name << " " 
                << Students[number - 1].Surname << endl;
        }else if ((command == "date") && (number > 0) && (number <= Students.size())){
            cout << Students[number - 1].Birth_Day << "." 
                << Students[number - 1].Birth_Month << "." 
                << Students[number - 1].Birth_Year << endl;
        }else{
            cout << "bad request" << endl;
        }
    }

    return 0;
}