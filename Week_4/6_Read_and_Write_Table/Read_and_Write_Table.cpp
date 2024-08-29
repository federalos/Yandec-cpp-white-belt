#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

int main(){
    ifstream input ("input.txt");

    int row, col;
    int value; 
    if (input){
        input >> row >> col;
        // debug stuff
        //cout << "row = " << row << " | col = " << col << endl;
        cout << setfill(' ');

        //cout << setfill(' ');
        for (int iter_row = 0; iter_row < row; iter_row++){
            for (int iter_col = 0; iter_col < col; iter_col++){
                input >> value;
                input.ignore(1);
                cout << setw(10) << value;
                // Debug stuff
                //cout << "(" << iter_row << ", " << iter_col<< ")";
                if (iter_col != col-1){
                    cout << ' ';
                    // Debug stuff
                    //cout << "s";
                }
            }
            if (iter_row != row-1){
                cout << endl;
                // Debug stuff
                //cout << 'n' << endl;
            }
        }
    }
	return 0;
}