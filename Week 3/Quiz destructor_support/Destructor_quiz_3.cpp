#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Weather {
public:
  Weather(const string& new_state, int new_temperature) {
    state = new_state;
    temperature = new_temperature;
    cout << 'c';
  }
  ~Weather() {
    cout << 'd';
  }
private:
  string state;
  int temperature;
};

void f(int x) {
  cout << 'a';
  if (x % 2 == 1) {
    Weather weather("rain", 5);
    cout << 'b';
  }
  Weather weather2("fog", 4);
  cout << 'e';
}

int main() {
  f(11);
  return 0;
}

