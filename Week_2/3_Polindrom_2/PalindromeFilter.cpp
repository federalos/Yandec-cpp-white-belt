#include <iostream>
#include <string>
#include <vector>

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

vector<string> PalindromeFilter(vector<string> strings, int minLength){
    vector<string> Filtred_Palindroms;
    for(auto s : strings){
        if (s.size() >= minLength){
            if (IsPalindrome(s)){
                Filtred_Palindroms.push_back(s);
            }
        }
    }
    return Filtred_Palindroms;
}



int main(){
    vector<string> input_str = {"weew", "bro", "code"};
    int minLength = 4; 
    vector<string> Output_str = PalindromeFilter(input_str, minLength);
    for(auto s: Output_str){
        cout << s << " ";
    }
    
    return 0;
}