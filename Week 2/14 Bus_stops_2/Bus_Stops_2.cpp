#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int main(){
    int Q, itter_command = 0;
    cin >> Q;

    int N, itter_stops;

    map<vector<string>, int> Stops_bus_DB;
    vector<string> Stops;
    string stop;

    int itter_bus_number = 1;

    while (itter_command < Q){
        itter_stops = 0;
        cin >> N;
        while (itter_stops < N){
            cin >> stop;
            Stops.push_back(stop);
            itter_stops++;
        }
        if (Stops_bus_DB.count(Stops) == 0){
            Stops_bus_DB[Stops] = itter_bus_number;
            cout << "New bus " << Stops_bus_DB[Stops] << endl;
            itter_bus_number++;
        } else{
            cout << "Already exists for " << Stops_bus_DB[Stops] << endl;
        }
        Stops.clear();
        itter_command++;
        
    }
    return 0;
}