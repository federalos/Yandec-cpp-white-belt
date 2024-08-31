#include <string>
#include <sstream>
#include <exception>
#include <iostream>

using namespace std;

void EnsureEqual(const string& left, const string& right){
    if (left != right){
        stringstream str_err;
        str_err << left << " != " << right;
        throw runtime_error(str_err.str());
    }
}

int main() {
  try {
    EnsureEqual("C++ White", "C++ White");
    EnsureEqual("C++ White", "C++ Yellow");
  } catch (runtime_error& e) {
    cout << e.what() << endl;
  }
  return 0;
}