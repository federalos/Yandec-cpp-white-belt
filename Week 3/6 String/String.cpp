#include <iostream>
#include <string>

using namespace std;

class ReversibleString{
    public:
        ReversibleString(){str = "";}
        ReversibleString(const string& input_string){str = input_string;}
        void Reverse(){
            string old_str = str;
            for (int iter = old_str.size(); iter >= 0; iter--){
                str[old_str.size() - 1 - iter] = old_str[iter];
            }
        }
        string ToString() const{return str;}
    
    private:
        string str;

};

int main() {
  ReversibleString s("live");
  s.Reverse();
  cout << s.ToString() << endl;
  
  s.Reverse();
  const ReversibleString& s_ref = s;
  string tmp = s_ref.ToString();
  cout << tmp << endl;
  
  ReversibleString empty;
  cout << '"' << empty.ToString() << '"' << endl;
  
  return 0;
}