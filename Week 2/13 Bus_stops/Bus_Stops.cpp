#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

void Print_Buses(const map<string, vector<string>>& Buses){
    if (Buses.size() == 0){
        cout << "No buses" << endl;;
    } else {
        for (auto bus : Buses){
            cout << "Bus " << bus.first << ": ";
            for (const string& stop : bus.second){
                cout << stop << " ";
            }
            cout << endl;
        }
    }
}

void Add_new_bus(map<string, vector<string>>& Buses, vector<string>& queue){
    string name_bus;
    int amount_of_stops, itter_stops = 0;
    cin >> name_bus >> amount_of_stops;
    queue.push_back(name_bus);
    string stop;

    while (itter_stops < amount_of_stops){
        cin >> stop;
        Buses[name_bus].push_back(stop);
        itter_stops++;
    }

}

vector<string> Print_buses_for_stop(map<string, vector<string>>& Buses_database, const vector<string>& queue, const string& Name_stop, const string& current_bus){
    vector<string> output;

    for (auto bus : queue){
        for (auto stop : Buses_database[bus]){
            if ((Name_stop == stop)&&(bus != current_bus)){
                output.push_back(bus);
                break;
            }
        }
    }

    return output;
}

void Print_Stops_for_buses(map<string, vector<string>>& Buses_database, const vector<string>& queue){
    string Name_bus;
    cin >> Name_bus;

    vector<string> List_of_stops;

    vector<string> buses_at_stop;

    map<string, vector<string>> Buses_database_without_current_bus;

    if (Buses_database.count(Name_bus) == 0){
        cout << "No bus"<< endl;
    } else{
        List_of_stops = Buses_database[Name_bus];
        for (auto stop : List_of_stops){
            cout << "Stop " << stop << ": ";
            buses_at_stop = Print_buses_for_stop(Buses_database, queue, stop, Name_bus);
            if (buses_at_stop.size() == 0){
                cout << "no interchange" << endl;
            } else{
                for (auto bus: buses_at_stop){
                cout << bus << " ";
                }
                cout << endl;
            }
        }

    }

}

int main(){
    int Q,itter = 0;
    cin >> Q;

    string command;

    vector<string> queue_buses;
    map<string, vector<string>> Buses_database;

    string Name_stop;
    string current_bus = "";

    vector<string> output;

    while (itter < Q){
        cin >> command;
        if (command == "NEW_BUS"){
            Add_new_bus(Buses_database, queue_buses);
        } else if (command == "BUSES_FOR_STOP"){
            cin >> Name_stop;
            output = Print_buses_for_stop(Buses_database, queue_buses, Name_stop, current_bus);
            if (output.size() == 0){
                cout << "No stop" << endl;
            } else{
                for (auto bus : output){
                    cout << bus << " ";
                }
                cout << endl;
            }
        } else if (command == "STOPS_FOR_BUS"){
            Print_Stops_for_buses(Buses_database, queue_buses);
        } else if (command == "ALL_BUSES"){
            Print_Buses(Buses_database);
        } 
        itter++;
    }

    return 0;
}