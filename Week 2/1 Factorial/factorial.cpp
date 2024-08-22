#include <iostream>

using namespace std;

int Factorial(int x){
    int result = 1;
    if (x > 0){
        for (int itter = 1; itter <= x; itter++){
            result *= itter;
        }
    }

    return result;
    
}
/* Test of output
int main() {
    int input, output;
    cin >> input;

    output = Factorial(input);

    cout << output;

    return 0;
}
*/