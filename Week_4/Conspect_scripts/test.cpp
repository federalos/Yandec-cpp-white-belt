#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

int main(){
	vector<string> names = {"a", "b", "c"};
	vector<double> values = {5, 0.01, 0.000005};
	cout << setfill('.');
	cout << left;
	for (const auto& n: names){
		cout << setw(10) << n << ' ';
	}
	cout << endl;
	cout << fixed << setprecision(2);
	
	for (const auto& v: values){
		cout << setw(10) << v << ' ';
	}

}