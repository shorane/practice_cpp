#include <iostream>
#include<strings.h>
#include<stack>
using namespace std;

int main()
{
    
    string S;
    cout<<"Please enter the expression"<<endl;
    cin>>S;
    stack<char> st;
    int len = S.length();

    for(int i=0;i<len;i++){
        if ((S[i]=='{')or (S[i]=='[') or (S[i]=='(') ){
             st.push(S[i]);
            //  cout<<"Pushed in "<<S[i]<<endl;
             }
        if ((S[i]=='}' and st.top()=='{')||(S[i]==']' and st.top()=='[')||(S[i]==')' and st.top()=='(')){
            // cout<<"Popping "<<st.top()<<endl;
            st.pop();
        }
    }
    if (st.empty()){
        cout<<"Balanced"<<endl;
    }
    else{cout<<"NO"<<endl;}


    return 0;
}
