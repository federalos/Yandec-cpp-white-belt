#include <iostream>
#include <string>

using namespace std;

bool IsPalindrome(string str){
    int end_itter = str.size();
    char end_char;

    for (auto s : str){
        end_char = str[end_itter-1];
        if (s != end_char){
            return false;
        } else{
            end_itter--;
        }
    }
    return true;
}
/*
int main(){
    string input;
    cin >> input;
    cout << IsPalindrome(input);
    return 0;
}
*/