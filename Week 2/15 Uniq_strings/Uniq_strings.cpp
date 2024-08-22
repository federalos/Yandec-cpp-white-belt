#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

int main(){
    int N, itter_string = 0;
    cin >> N;

    string str;
    vector<string> strings;

    while (itter_string < N){
        cin >> str;
        strings.push_back(str);
        itter_string++;
    }

    set<string> set_of_strings(begin(strings), end(strings));

    cout << set_of_strings.size();
    return 0;
}