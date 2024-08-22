#include <iostream>
#include <vector>

using namespace std;

void Reverse(vector<int>& v){
    vector<int> inv_v;
    for (int itter=v.size()-1; itter >= 0; itter--){
        inv_v.push_back(v[itter]);
    }
    v.clear();
    v = inv_v;

}

int main(){
    vector<int> numbers = {1, 5, 3, 4, 2};
    Reverse(numbers);
    return 0;
}