// Title - Validating Goods Train
// Author - AKSHITH SIMHA KATRAGADA
// Date - March 6 2022
// Space Complexity - O(1), Time Complexity - O(n) where n is the length of the input string.

#include <bits/stdc++.h>
using namespace std;

void legalGoodsTrainCheck(string input)
{
    int value_E = 0;
    int value_T = 0;
    int value_G = 0;
    transform(input.begin(), input.end(), input.begin(), ::toupper);

    for(int i=0; i<input.size(); i++) {

        if(input[i] == 'E') {
            if(i > 1 || value_G != 0 || value_T != 0){
                cout << "Reject" << endl;
                return;
            }
            else {
                value_E++;
            }
        }

        else if(input[i] == 'T') {
            if(value_E == 0) {
                cout << "Reject" << endl;
                return;
            }
            else {
                value_T++;
            }
        }

        else if(input[i] == 'G') {
            if(value_E == 0 || value_T == 0) {
                cout << "Reject" << endl;
                return;
            }
            else {
                if(value_G == 1) {
                    cout << "Reject" << endl;
                    return;
                }

                value_G++;
            }
        }

        else {
            cout << "Reject" << endl;
            return;
        }
    }

    if(value_E == 0 || value_T == 0 || value_G == 0) {
        cout << "Reject" << endl;
    }
    else {
        cout << "Accept" << endl;
    }
}

int main()
{
    cout << "Please enter the string to check - " << endl;
    string input;
    cin >> input;

    legalGoodsTrainCheck(input);
}