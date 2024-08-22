#include <iostream>
#include <string>

using namespace std;

int main(){
    string str;
    int index_F;
    int counter_F = 0;
    int itter_index = -1;
    int one_f = -1;
    int zero_f = -2;
    
    cin >> str;
    
    for (auto itter_char : str){
        itter_index++;
        if (itter_char == 'f'){
            counter_F++;
            if (counter_F == 2){
                  index_F = itter_index;
                  cout << index_F;
                  break;
            }
        }
    }

    if (counter_F == 1){
        cout << one_f;
    }else if (counter_F == 0)
    {
        cout << zero_f;
    }

    return 0;
}