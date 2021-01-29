// #include <bits/stdc++.h>
#include <iostream>
using namespace std;

string compressString(string s);

int main(){

    // given string
    
    // string a = "aaabcc";    //expected ans: a3b1c2
    string a = "aaabccd";   // expected ans: a3b1c2d1

    // call compress function
    cout << "Result: " << compressString(a) << endl;

    return 0;
}


string compressString(string s){
    string answer = "";
    int localCount = 1;

    for (int i = 0; i < s.length() ; ++i){

        if (i == s.length()-1) { 
            answer += s[i] + to_string(1);
            break;
        }
        
        while (s[i] == s[i+1]){
            ++localCount;
            ++i;
            if (i == s.length()) break;
        }
        
        answer += s[i] + to_string(localCount);
        localCount = 1;
    }
    return answer;
}