#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


/*
Command 1 = ADD *int* *string*  - 
Command 2 = DUMP _
Command 3 = NEXT

*/

/* Gregorian calendar

No.	    Name	    Length in days
1	    January	    31
2	    February	28 (29 in leap years) // For this task, it's OK to consider that February always have 28 days in every year
3	    March	    31
4	    April	    30
5	    May	        31
6	    June	    30
7	    July	    31
8	    August	    31
9	    September	30
10	    October	    31
11	    November	30
12	    December	31
*/

void Add_func(vector<vector<string>>&v){
    int day;
    string task_name;
    cin >> day >> task_name;

    v[day - 1].push_back(task_name);
}

void Dump_func(const vector<vector<string>>&v){
    int day;
    cin >> day;

    //Amount of task for this day
    cout << v[day - 1].size() << " ";
    for (auto task : v[day - 1]){
        cout << task << " ";
    }
    cout << endl;
}

void Next_func(vector<vector<string>>&v, const vector<int> Calendar, int& Mounth_itter){
    Mounth_itter = Mounth_itter % 12;
    
    vector<vector<string>> new_v(Calendar[Mounth_itter]);

    int min_of_sizes = min(new_v.size(), v.size());
    int max_of_sizes = max(new_v.size(), v.size());

    for (int itter = 0; itter < min_of_sizes; itter++){
        new_v[itter].insert(end(new_v[itter]), begin(v[itter]), end(v[itter]));
    }

    if (v.size() > new_v.size()){
        int itter_extra_size = min_of_sizes;
        for (itter_extra_size; itter_extra_size < max_of_sizes; itter_extra_size++){
            new_v[new_v.size() - 1].insert(end(new_v[new_v.size() - 1]), begin(v[itter_extra_size]), end(v[itter_extra_size]));
        }
    } 
    
    v = new_v;
}

int main(){

    // Gregorian calendar days info
    vector<int> Calendar {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int Mounth_itter = 0;
    // Task list
    vector<vector<string>> Tasks_list(Calendar[Mounth_itter]);

    // amount of operation
    int Q;
    cin >> Q;

    // Command for each line
    string command;

    for (int itter = 0; itter < Q; itter++){
        cin >> command;
        if (command == "ADD"){
            Add_func(Tasks_list);
        }else if (command == "DUMP"){
            Dump_func(Tasks_list);
        }else if (command == "NEXT"){
            Mounth_itter++;
            Next_func(Tasks_list, Calendar, Mounth_itter);
        }
        

    }

    return 0;
}