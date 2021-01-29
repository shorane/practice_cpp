// #include <bits/stdc++.h>
#include <iostream>
using namespace std;



int main(){
    const int limit = 20;
    for(int i = 1; i <= 20; ++i){

        if (i % 3 == 0 and i % 5 !=0){ cout << "Fizz";}
        else if (i % 3 != 0 and i % 5 ==0){ cout << "Buzz";}
        else if (i % 3 == 0 and i % 5 ==0){ cout << "FizzBuzz";}
        else{ cout << i;}
        cout << endl;
        
    }
    
    return 0;
}