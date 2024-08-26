#include <iostream>
#include <vector>
#include <string>

using namespace std;

// True -> Worry
// False -> Quite

void Worry_Func(vector<bool>& v, const int& index){
    v[index] = true;
}

void Quiet_Func(vector<bool>& v, const int& index){
    v[index] = false;
}

void Come_Func(vector<bool>& v, const int& amount){
    if (amount > 0){
        for (int itter = 0; itter < amount; itter++){
            v.push_back(false);
        }
    }else{
        v.resize(v.size() + amount);
    }
}

int Amount_Worry(const vector<bool> v){
    int Amount_of_worries = 0;

    for (auto itter : v){
        if (itter == true){
            Amount_of_worries++;
        }
    }
    return Amount_of_worries;
}

int main(){

    int Q;
    cin >> Q;

    string operation_name;

    vector<bool> Queue;

    for (int itter = 0; itter < Q; itter++){
        cin >> operation_name;
        if (operation_name == "WORRY"){
            /* WORRY i: пометить i-го человека с начала очереди как беспокоящегося*/
            int index;
            cin >> index;
            Worry_Func(Queue, index);

        }else if (operation_name == "QUIET"){
            /* QUIET: пометить i-го человека как успокоившегося */
            int index;
            cin >> index;
            Quiet_Func(Queue, index);

        }else if (operation_name == "COME"){
            /* COME k: добавить k спокойных человек в конец очереди */
            /* COME -k: убрать k человек из конца очереди */
            int amount;
            cin >> amount;
            Come_Func(Queue, amount);

        }else if (operation_name == "WORRY_COUNT"){
            /* WORRY_COUNT: узнать количество беспокоящихся людей в очереди */
            int Amount_Worryies;
            Amount_Worryies = Amount_Worry(Queue);
            cout << Amount_Worryies<< endl;
        }else{
            break;
        }
    }
    return 0;
}