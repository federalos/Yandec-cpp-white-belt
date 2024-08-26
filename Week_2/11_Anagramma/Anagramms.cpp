#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

map<char, int> counter_chars (const string& str){
    
    map<char, int> result;
    for (int itter = 0; itter<str.size(); itter++){
        result[str[itter]]++;
    }
    return result;
}

bool compar_maps (const map<char, int>& map_1, map<char, int> map_2){

    bool result = true;
    char key;
    int item_second;
    if (map_1.size() == map_2.size()){
        for (auto item : map_1){
            key = item.first;
            item_second = map_2[key];
            if (item.second != item_second) {
                result = false;
            }
        }
    }else{
        result = false;
    }
    
    return result;
}

int main(){
    int N, itter = 0;
    cin >> N;

    string word_first, word_second;

    map<char, int> Chars_counter_first, Chars_counter_second;
    

    while (itter < N){
        cin >> word_first >> word_second;
        Chars_counter_first = counter_chars(word_first);
        Chars_counter_second = counter_chars(word_second);
        if (compar_maps(Chars_counter_first, Chars_counter_second)){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
        itter++;
        
        
    }
    return 0;
}