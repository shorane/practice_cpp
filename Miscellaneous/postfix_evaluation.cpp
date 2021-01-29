// C++ program to evaluate value of a postfix expression 
#include <iostream> 
#include <string> 
#include <stack>
using namespace std; 

// The main function that returns value of a given postfix expression 
string evaluatePostfix(string exp) 
{ 
	// Create a stack of capacity equal to expression size 
	stack<double> s;

	// Scan all characters one by one 
	for (int i = 0; exp[i]; ++i) 
	{ 
		// If the scanned character is an operand (number here), 
		// push it to the stack. 
		if (exp[i] == ' ' or exp[i] == '(' or exp[i] == ')') continue; 
        
        if (isdigit(exp[i])) 
            s.push(exp[i] - '0');
			// push(stack, exp[i] - '0'); 

		// If the scanned character is an operator, pop two 
		// elements from stack apply the operator 
		else
		{ 
			int val1 = s.top(); s.pop(); 
			int val2 = s.top(); s.pop(); 
			switch (exp[i]) 
			{ 
			case '+': s.push(val2 + val1); break; 
			case '-': s.push(val2 - val1); break; 
			case '*': s.push(val2 * val1); break; 
			case '/': s.push(val2 / val1); break; 
			} 
		} 
	} 
	return to_string(s.top()); 
} 

// Driver program to test above functions 
int main() 
{ 
	string exp = "1 1 + 1 + 1 +"; 
	cout << evaluatePostfix(exp); 
	return 0; 
} 
