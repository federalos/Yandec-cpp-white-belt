#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

class Person {
    public:
        Person (const string& First_Name, const string& Last_Name, const int& Bday){
            FirstNames[Bday] = First_Name;
            LastNames[Bday] = Last_Name;
            BirthDay = Bday;
        }
        void ChangeFirstName(int year, const string& first_name) {
            // добавить факт изменения имени на first_name в год year
            if (year >= BirthDay){
                FirstNames[year] = first_name;
            }
        }
        void ChangeLastName(int year, const string& last_name) {
            // добавить факт изменения фамилии на last_name в год year
            if (year >= BirthDay){
                LastNames[year] = last_name;
            }
        }
        string GetFullName(int year) const {
            // получить имя и фамилию по состоянию на конец года year
            vector<string> First_names = Left_first_names(year);
            vector<string> Last_names = Left_last_names(year);
            if (year < BirthDay){
                return "No person";
            }else{
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

        }
        string GetFullNameWithHistory(int year) const {
            // получить все имена и фамилии по состоянию на конец года year
            vector<string> First_names = Left_first_names(year);
            vector<string> Last_names = Left_last_names(year);
            if (year < BirthDay){
                return "No person";
            }else{
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
        }
        
    private:
        // приватные поля

        map<int, string> FirstNames;
        map<int, string> LastNames;
        int BirthDay;

        vector<string> Left_first_names(const int& year) const {
            vector<string> First_names; 
            map<int, string>::const_reverse_iterator iter;
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

        vector<string> Left_last_names(const int& year) const {
            vector<string> Last_names; 
            map<int, string>::const_reverse_iterator iter;
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
        
        string vector_to_string(const vector<string>& vec_str) const{
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
    Person person("Polina", "Sergeeva", 1960);
    for (int year : {1959, 1960}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }
    person.ChangeFirstName(1965, "Appolinaria");
    person.ChangeLastName(1967, "Ivanova");
    for (int year : {1965, 1967}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }
    return 0;
}

