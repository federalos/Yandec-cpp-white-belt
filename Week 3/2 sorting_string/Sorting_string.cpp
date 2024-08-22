#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int N, itter_N = 0;
    cin >> N;

    vector<string> Strings;
    string String;

    while (itter_N < N){
        cin >> String;
        Strings.push_back(String);
        itter_N++;
    }
    sort(begin(Strings),end(Strings),[](const string& x, const string& y){
            string x2, y2;
            for (char i : x){
                x2 += tolower(i);
            }
            for (char j : y){
                y2 += tolower(j);
            }
            return (x2 < y2);});

    for (const auto& i : Strings){
        cout << i << " ";
    }
    cout << endl;

    return 0;
}