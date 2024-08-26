#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>

using namespace std;

set<string> BuildMapValuesSet(const map<int, string>& m) {
    set<string> s;
    for (auto item : m){
        s.insert(item.second);
    }
    return s;
}

int main(){
    map<int, string> m ={{1, "odd"}, {2, "even"}, {3, "odd"}, {4, "even"}, {5, "odd"}};
    set<string> values = BuildMapValuesSet(m);
    for (const string& value : values) {
        cout << value << endl;
    }
    return 0;
}