#include <iostream>

using namespace std;

int main(){
    // Инициализация вводных чисел
    int a, b;
    cin >> a >> b;
    while (a > 0 && b > 0){
        if(a > b){
            a = a % b;
        } else {
            b = b % a;
        }
    }
    cout << a + b;
    return 0;
}