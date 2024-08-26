#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>

using namespace std;

void add_func(map<string, set<string>>& synonyms){
    string word_1, word_2;
    cin >> word_1 >> word_2;
    synonyms[word_1].insert(word_2);
    synonyms[word_2].insert(word_1);
}

void count_func(map<string, set<string>>& synonyms){
    string word;
    cin >> word;
    int output = 0;

    if (synonyms.count(word) != 0){
        output = synonyms[word].size();
    }
    cout << output << endl;
}

void check_func(map<string, set<string>>& synonyms){
    string word_1, word_2, output = "NO";
    cin >> word_1 >> word_2;

    if (synonyms.count(word_1) != 0){
        if (synonyms[word_1].count(word_2) != 0){
            output = "YES";
        }
    } else if (synonyms.count(word_2) != 0){
        if (synonyms[word_2].count(word_1) != 0){
            output = "YES";
        }
    }
    cout << output << endl;
}

int main(){
    int Q, itter_command = 0;
    cin >> Q;

    string command;

    map<string, set<string>> synonyms;

    while (itter_command < Q){
        cin >> command;
        if (command == "ADD"){
            add_func(synonyms);
        } else if (command == "COUNT"){
            count_func(synonyms);
        } else if (command == "CHECK") {
            check_func(synonyms);
        }
        itter_command++;
    }
    return 0;
}