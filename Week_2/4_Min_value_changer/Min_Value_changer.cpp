#include <iostream>

using namespace std;

// Если first > second, записать в second значение first
void UpdateIfGreater(const int& first, int& second ){
    if (first > second){
        second = first;
    }
}

int main() {
    int first = 4;
    int second = 2;
    UpdateIfGreater(first, second);
    return 0;
}