#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class SortedStrings {
public:
  void AddString(const string& s) {
    Vector_strings.push_back(s);
    // добавить строку s в набор
  }
  vector<string> GetSortedStrings() {
    sort(begin(Vector_strings), end(Vector_strings));
    return Vector_strings;
    // получить набор из всех добавленных строк в отсортированном порядке
  }
private:
  // приватные поля
  vector<string> Vector_strings;
};

void PrintSortedStrings(SortedStrings& strings) {
  for (const string& s : strings.GetSortedStrings()) {
    cout << s << " ";
  }
  cout << endl;
}

int main() {
  SortedStrings strings;
  
  strings.AddString("first");
  strings.AddString("third");
  strings.AddString("second");
  PrintSortedStrings(strings);
  
  strings.AddString("second");
  PrintSortedStrings(strings);
  
  return 0;
}