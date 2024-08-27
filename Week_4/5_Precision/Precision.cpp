#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int main(){
	string path_read = "input.txt";
    ifstream input (path_read);
    double value;
    cout << fixed << setprecision(3);
    while (input >> value){
        cout << value << endl;
    }
	return 0;
}