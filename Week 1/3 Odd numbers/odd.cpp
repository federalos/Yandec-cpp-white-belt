#include <iostream>

using namespace std;
/*
A - Левая граница
B - Правая граница

Задача вывести все чётные числа в диапазоне [A,B] через пробел

Выполняются следующие условия по умолчанию:
-) A <= B
-) A >= 1
-) B <= 30000
*/
int main() {
    int A, B;
    cin >> A >> B;

    for(int itter = A; itter <= B; itter++){
        if (itter % 2 == 0){
            cout << itter << " ";
        }
    }
    return 0;
}