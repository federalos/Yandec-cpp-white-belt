#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

class Person {
    public:
        void ChangeFirstName(int year, const string& first_name) {
            // добавить факт изменения имени на first_name в год year
            FirstNames[year] = first_name;
        }
        void ChangeLastName(int year, const string& last_name) {
            // добавить факт изменения фамилии на last_name в год year
            LastNames[year] = last_name;
        }
        string GetFullName(int year) {
            // получить имя и фамилию по состоянию на конец года year
            vector<string> First_names = Left_first_names(year);
            vector<string> Last_names = Left_last_names(year);

            if ((First_names.size() == 0)&&(Last_names.size() == 0)){
                return "Incognito";
            } else if ((First_names.size() > 0)&&(Last_names.size() == 0)){
                return  First_names[0] + " with unknown last name";
            } else if ((First_names.size() == 0)&&(Last_names.size() > 0)){
                return  Last_names[0] + " with unknown first name";
            } else{
                return First_names[0] + " " + Last_names[0];
            }

        }
        string GetFullNameWithHistory(int year) {
            // получить все имена и фамилии по состоянию на конец года year
            vector<string> First_names = Left_first_names(year);
            vector<string> Last_names = Left_last_names(year);

            if ((First_names.size() == 0)&&(Last_names.size() == 0)){
                return "Incognito";
            } else if ((First_names.size() >= 1)&&(Last_names.size() == 0)){
                string First_names_list = vector_to_string(First_names);
                return  First_names_list + " with unknown last name";
            } else if ((First_names.size() == 0)&&(Last_names.size() >= 1)){
                string Last_names_list = vector_to_string(Last_names);
                return  Last_names_list + " with unknown first name";
            } else{
                string First_names_list = vector_to_string(First_names);
                string Last_names_list = vector_to_string(Last_names);
                return First_names_list + " " + Last_names_list;
            }
        }
        
    private:
        // приватные поля

        map<int, string> FirstNames;
        map<int, string> LastNames;

        vector<string> Left_first_names(const int& year){
            vector<string> First_names; 
            map<int, string>::reverse_iterator iter;
            for (iter = FirstNames.rbegin(); iter != FirstNames.rend(); iter++){
                int key = iter->first;
                string value = iter->second;
                if (key <= year){
                    if (First_names.empty()){
                        First_names.push_back(value);
                    } else if (value != First_names.back()){
                        First_names.push_back(value);
                    }
                }
            }
            return First_names;
        }

        vector<string> Left_last_names(const int& year){
            vector<string> Last_names; 
            map<int, string>::reverse_iterator iter;
            for (iter = LastNames.rbegin(); iter != LastNames.rend(); iter++){
                int key = iter->first;
                string value = iter->second;
                if (key <= year){
                    if (Last_names.empty()){
                        Last_names.push_back(value);
                    } else if (value != Last_names.back()){
                        Last_names.push_back(value);
                    }
                }
            }
            return Last_names;
        }           
        
        string vector_to_string(const vector<string> vec_str){
            string str_out = "";
            if (vec_str.size() == 1){
                return vec_str[0];
            } else{
                str_out += vec_str[0] + " (";
                for (int iter = 1; iter < vec_str.size(); iter++){
                    str_out += vec_str[iter] + ", ";
                }
                str_out.erase(str_out.end()-2, str_out.end());
                str_out+= ")";
                return str_out;
            }
        }

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

// Test 4
/*
    person.ChangeFirstName(1900, "Eugene");
    person.ChangeLastName(1900, "Sokolov");
    person.ChangeLastName(1910, "Sokolov");
    person.ChangeFirstName(1920, "Evgeny");
    person.ChangeLastName(1930, "Sokolov");
    cout << person.GetFullNameWithHistory(1940) << endl;
*/

// Test 5
/*
    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");
    for (int year : {1900, 1965, 1990}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }
    
    person.ChangeFirstName(1970, "Appolinaria");
    for (int year : {1969, 1970}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }
    
    person.ChangeLastName(1968, "Volkova");
    for (int year : {1969, 1970}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }
    
    person.ChangeFirstName(1990, "Polina");
    person.ChangeLastName(1990, "Volkova-Sergeeva");
    cout << person.GetFullNameWithHistory(1990) << endl;
    
    person.ChangeFirstName(1966, "Pauline");
    cout << person.GetFullNameWithHistory(1966) << endl;
    
    person.ChangeLastName(1960, "Sergeeva");
    for (int year : {1960, 1967}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }
    
    person.ChangeLastName(1961, "Ivanova");
    cout << person.GetFullNameWithHistory(1967) << endl;
*/

// Test 6
/*
    person.ChangeFirstName(1965, "Polina");
    person.ChangeFirstName(1965, "Appolinaria");

    person.ChangeLastName(1965, "Sergeeva");
    person.ChangeLastName(1965, "Volkova");
    person.ChangeLastName(1965, "Volkova-Sergeeva");

    for (int year : {1964, 1965, 1966}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }
*/


    return 0;
}

