#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

class Person {
    public:
        void ChangeFirstName(int year, const string& first_name) {
            // добавить факт изменения имени на first_name в год year
            FirstNames[year] = first_name;
            Years_changes_firstname.push_back(year);
            sort(begin(Years_changes_firstname), end(Years_changes_firstname));
        }
        void ChangeLastName(int year, const string& last_name) {
            // добавить факт изменения фамилии на last_name в год year
            LastNames[year] = last_name;
            Years_changes_lastname.push_back(year);
            sort(begin(Years_changes_lastname), end(Years_changes_lastname));
        }
        string GetFullName(int year) {
            // получить имя и фамилию по состоянию на конец года year
            int first_name_nearest = nearest_left_year(year, Years_changes_firstname);
            int last_name_nearest = nearest_left_year(year, Years_changes_lastname);

            if ((first_name_nearest == -1) && (last_name_nearest == -1)){
                return "Incognito";
            } else if ((first_name_nearest == -1) && (last_name_nearest != -1)){
                return LastNames[last_name_nearest] +" with unknown first name";
            } else if ((first_name_nearest != -1) && (last_name_nearest == -1)){
                return FirstNames[first_name_nearest] + " with unknown last name";
            } else{
                return FirstNames[first_name_nearest] + " " + LastNames[last_name_nearest];
            }
        }
    private:
        // приватные поля
        int nearest_left_year(const int& year, const vector<int>& years){
            for (int itter = years.size()-1; itter>=0; itter--){
                if (years[itter] <= year){
                    return years[itter];
                } 
            }
            return -1;
        }

        map<int, string> FirstNames;
        vector<int> Years_changes_firstname;

        map<int, string> LastNames;
        vector<int> Years_changes_lastname;

};

int main() {
    Person person;
    
    // Test 1
/*
person.ChangeFirstName(65, "P");
    person.ChangeLastName(67, "S");
    person.ChangeFirstName(70, "A");
    cout << person.GetFullName(66) << endl;
    person.ChangeLastName(70, "N");
    cout << person.GetFullName(70) << endl;
*/    
    
    // Test 2
/*
    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");
    for (int year : {1900, 1965, 1990}) {
        cout << person.GetFullName(year) << endl;
    }
    
    person.ChangeFirstName(1970, "Appolinaria");
    for (int year : {1969, 1970}) {
        cout << person.GetFullName(year) << endl;
    }
    
    person.ChangeLastName(1968, "Volkova");
    for (int year : {1969, 1970}) {
        cout << person.GetFullName(year) << endl;
    }
*/
   
   // Test 3
/*
    cout << person.GetFullName(2000) << endl;
    person.ChangeLastName(1968, "1968_2nd");
    person.ChangeLastName(1967, "1967_2nd");
    person.ChangeLastName(1965, "1965_2nd");
    person.ChangeLastName(1966, "1966_2nd");

    for (int year : {1900, 1920, 1950, 1965, 1966, 1967, 1968}) {
        cout << person.GetFullName(year) << endl;
    }

    person.ChangeFirstName(1920, "1920_1st");
    person.ChangeFirstName(1900, "1900_1st");
    person.ChangeFirstName(1965, "1965_1st");
    person.ChangeFirstName(1950, "1950_1st");

    for (int year : {1900, 1920, 1950, 1965, 1966, 1967, 1968}) {
        cout << person.GetFullName(year) << endl;
    }
*/    
    return 0;
}

