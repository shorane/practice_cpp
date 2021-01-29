// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include<memory>
using namespace std;

// currency system
int coins[] = {1,5,10,25};

int getChange(int total, shared_ptr<vector<int> > record);
int startGetChange(int total);

int main(){

    // what is x
    int x;
    cout << "Enter x amount: "; cin >> x; cout << endl;

    // get min_change for x
    cout << startGetChange(x) << endl;
    
    return 0;
}

int startGetChange(int total){
    // Dynamic Programming. Since the next function uses recursion, 
    // we can store intermediate values in a vector or list
    shared_ptr<vector<int> > smallest_change_record(new vector<int>(total+1, -1));
    (*smallest_change_record)[0] = 0;
    return getChange(total, smallest_change_record);
}

int getChange(int total, shared_ptr<vector<int> > record){
    if (total == 0) return 0;

    int min_change_num = total;
    int change_num;

    // check for all coins in the currency system
    for(auto& coin : coins){
        if (total >= coin){

            // Only run the recursion on the intermediate value if it has not been 
            // run before
            if ( (*record)[total-coin] == -1 ){
            change_num = 1 + getChange(total - coin, record);
            (*record)[total-coin] = change_num - 1; 
            }
            else{
                change_num = (*record)[total-coin] + 1;
            }
        }
        // keep the minimum number of change coins updated in the for
        min_change_num = (min_change_num < change_num)?min_change_num:change_num;
    }
    return min_change_num;
}