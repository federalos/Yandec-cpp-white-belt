#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

void about_func(map<string, string>& map){
    string country_name;
    cin >> country_name;
    if (map[country_name].size() == 0){
        cout << "Country " << country_name << " doesn't exist" << endl;
        map.erase(country_name);
    } else{
        cout << "Country " << country_name << " has capital " << map[country_name] << endl;  
    }

}

void Dump_func(const map<string, string>& map){
    if (map.empty()){
        cout << "There are no countries in the world" << endl;
    } else{
        for (const auto& item : map){
            cout << item.first << "/" << item.second << " ";
        }
        cout << endl;
    }
}

void change_capital_func (map<string, string>& map){
    string country, capital;
    cin >> country >> capital;
    if (map[country].size() == 0){
        map[country] = capital;
        cout << "Introduce new country " << country << " with capital " << map[country] << endl;
    }else{
        if (map[country] == capital){
            cout << "Country " << country << " hasn't changed its capital" << endl;
        } else{
            cout << "Country " << country << " has changed its capital from " << map[country];
            map[country] = capital;
            cout << " to " << map[country] << endl;
        }
    }
}

void rename_func(map<string, string>& map){
    string old_country_name, new_country_name;
    cin >> old_country_name >> new_country_name;

    if ((old_country_name == new_country_name)||(map.count(old_country_name) == 0)||(map.count(new_country_name) == 1)){
        cout << "Incorrect rename, skip" << endl;
    } else{
        cout << "Country " << old_country_name <<  " with capital " <<  map[old_country_name];
        map[new_country_name] = map[old_country_name];
        map.erase(old_country_name);
        cout << " has been renamed to " << new_country_name << endl;
    }
}


int main(){
    // Amount of command
    int Q;
    cin >> Q;
    // Name of command
    string command;
    // Map Contry->City
    map<string, string> Country_Capitals;

    int itter = 0;
    while (itter < Q){
        
        cin >> command;
        //cout << itter + 1 << " "; // Number of output line for debug purpose
        if (command == "CHANGE_CAPITAL"){
            change_capital_func(Country_Capitals);
        }else if (command == "RENAME"){
            rename_func(Country_Capitals);
        }else if (command == "ABOUT"){
            about_func(Country_Capitals);
        }else if (command == "DUMP"){
            Dump_func(Country_Capitals);
        }
        itter++;
    }

    return 0;
}