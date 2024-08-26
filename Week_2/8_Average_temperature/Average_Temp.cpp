#include <iostream>
#include <vector>

using namespace std;

void init_vector(vector<int>& v, const int& N){
    int itter = 0;
    int number_to_vector;
    while (itter < N){
        cin >> number_to_vector;
        v.push_back(number_to_vector);
        itter++;
    }
}

int mean_of_vector (const vector<int>& v){
    int sum = 0;
    for (auto itter : v){
        sum += itter;
    }
    return sum/v.size();
}

vector<int> higher_aver_indexes (const vector<int>& v, const int& aver){
    vector<int> indexes;
    int ind = 0;
    for (auto itter : v){
        if (itter > aver){
            indexes.push_back(ind);
        }
        ind++;
    }
    return indexes;
}

void print_vector(const vector<int> v){
    cout << v.size() << endl;
    for (auto itter : v){
        cout << itter << " ";
    }
    cout << endl;
}

int main(){

    int N;
    cin >> N;

    vector<int> Temperature;
    init_vector(Temperature, N);

    int mean_temperature = mean_of_vector(Temperature);

    vector<int> Indexes_highier_average = higher_aver_indexes(Temperature, mean_temperature);

    print_vector(Indexes_highier_average);

    return 0;
}