#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
	string path_to_file = "input.txt";
    ifstream input (path_to_file);
	string line;
	if (input){
		while (getline(input, line)){
			cout << line << endl;
		}
	}
	return 0;
}