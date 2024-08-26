#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    vector<int> Bin;
    int Dec;
    cin >> Dec;

    int sup_dec = Dec;
    while(sup_dec != 1){
        Bin.push_back(sup_dec % 2);
        sup_dec = sup_dec / 2;
    }

    Bin.push_back(sup_dec % 2);

    reverse(Bin.begin(), Bin.end());

    for(auto itter : Bin){
        cout << itter;
    }
    return 0;
}