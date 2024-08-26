#include <iostream>
#include <vector>

using namespace std;

vector<int> Reversed(const vector<int>& v){
    vector<int> inv_v;
    for (int itter=v.size()-1; itter >= 0; itter--){
        inv_v.push_back(v[itter]);
    }
    return inv_v;
}

int main(){
    vector<int> numbers = {1, 5, 3, 4, 2};
    vector<int> inv = Reversed(numbers);
    return 0;
}