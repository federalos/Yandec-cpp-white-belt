#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <string>

using namespace std;

int main (){
    int Q, itter_command = 0;
    cin >> Q;

    int N, itter_stops;

    set<string> stops;
    
    string stop;

    map <set<string>, int> Stops_Bus;

    int itter_buses = 1;

    while (itter_command < Q){
        itter_stops = 0;
        stops.clear();
        cin >> N;

        while (itter_stops < N){
            cin >> stop;
            stops.insert(stop);
            itter_stops++;
        }

        if (Stops_Bus.count(stops) == 0){
            Stops_Bus[stops] = itter_buses;
            itter_buses++;
            cout << "New bus " << Stops_Bus[stops] << endl;
        } else {
            cout << "Already exists for " << Stops_Bus[stops] << endl;
        }

        itter_command++;
    }
    return 0;
}