// #include <bits/stdc++.h>
#include <iostream>
using namespace std;


// Objective: To get the number of 1s in the binary representation of any number x
// note: bitwise and is also supposed to work but is failing here :( ?
int getNumOnes(int x);

int main(){

    // what is x
    int x;
    cout << "Enter number x: "; cin >> x; cout << endl;

    // get number of ones
    cout << getNumOnes(x) << endl;
    
    return 0;
}


int getNumOnes(int x){

    int sum = 0;

    while (x > 0){

        sum += x % 2;  // x%2 will be 0 if least sig digit is 0 and 1 otherwise
        // sum += x ^ 1;  // bitwise and with 1 gives 1 if least sig digit is 1 and 0 otherwise
        x >>= 1; // performing right shift on x. The least significant bit is removed.
    }

    return sum;
}


/* right shift
    x >> y   This removes y least significant digits from the binary notation of x
             the integer form of x gets divided by 2^y and the output is the int value of the result

    left shift
    x << y   Adds y 0s to binary of x
             multiplies x by 2^y
*/
