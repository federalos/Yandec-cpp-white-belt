#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
	string path_read = "input.txt";
    ifstream input (path_read);
    string path_write = "output.txt";
    ofstream output(path_write);
	string line;
	if (input){
		while (getline(input, line)){
			output << line << endl;
		}
	}
	return 0;
}