#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int N, itter_N = 0;
    cin >> N;

    vector<int> numbers;
    int number;

    while (itter_N < N){
        cin >> number;
        numbers.push_back(number);
        itter_N++;
    }
    sort(begin(numbers),end(numbers),[](int x, int y){return (abs(x) < abs(y));});

    for (const auto& i : numbers){
        cout << i << " ";
    }
    cout << endl;

    return 0;
}