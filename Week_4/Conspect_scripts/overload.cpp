#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iomanip>

using namespace std;

struct Duration {
    int hour;
    int min;

    Duration (int h = 0, int m = 0){
        int total = h*60 + m;
        hour = total / 60;
        min = total % 60;
    }
};

Duration operator+(const Duration& lhs, const Duration& rhs){
    return Duration(lhs.hour + rhs.hour, lhs.min + rhs.min);
}

bool operator<(const Duration& lhs, const Duration& rhs){
    if (lhs.hour == rhs.hour){
        return lhs.min < rhs.min;
    }
    return lhs.hour < rhs.hour;
}
/*
Duration ReadDuration(istream& stream){
    int h = 0;
    int m = 0;

    stream >> h;
    stream.ignore(1);
    stream >> m;

    return Duration {h, m};
}
*/

istream& operator>>(istream& stream, Duration& duration){
    stream >> duration.hour;
    stream.ignore(1);
    stream >> duration.min;
    return stream;
}

/*
void PrintDuration(ostream& stream, const Duration& duration){
    stream << setfill('0');
    stream << setw(2) << duration.hour << ':' 
           << setw(2) << duration.min;
}
*/

ostream& operator<<(ostream& stream, const Duration& duration){
    stream << setfill('0');
    stream << setw(2) << duration.hour << ':' 
           << setw(2) << duration.min;
    return stream;
}

void PrintVector(const vector<Duration>& durs){
    for (const auto& d:durs){
        cout << d << ' ';
    }
    cout << endl;
}

int main (){
    stringstream dur_ss("02:50");
    Duration dur1;
    dur_ss >> dur1;
    Duration dur2 = {0, 35};
    Duration dur3 = dur1 + dur2;
    vector<Duration> v{dur3, dur1, dur2};
    PrintVector(v);
    sort(begin(v), end(v));
    PrintVector(v);
    return 0;
}