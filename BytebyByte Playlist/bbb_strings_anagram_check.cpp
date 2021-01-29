// #include <bits/stdc++.h>
#include <iostream>
#include <memory>
using namespace std;

// Objective: Given two strings, check if they are anagrams
// assumption: lowercase == uppercase, all characters will be within the 256 ASCII chars
// use tolower() function for above assumption
// assumption: ignoring whitespace and other non-alphabet characters

//approach 1: 
    /* iterate through first string. make a dictionary with values as counts of each character
        iterate through second string and reduce count for each match
        finally, check for counts (>0) in the dictionary.

    Time: O(m+n+m) ~ O(m) where m is the larger length if that case exists.
*/

// approach 2: 
    /* if length of strings is unequal, return false.
        iterate through string length. add tolower() of s1 and subtract tolower() of s2 to a char/string dict
        check for nonzero values over the length of the dictionary

    Time:  O(2*n)
*/

// approach 3: 
    /* if length of strings is unequal, return false.
        iterate through string length. add ints of tolower() of s1 and subtract tolower() of s2 to an int sum variable
        if sum is zero, return true else false

    Time:  O(n)
*/

// using approach 3
bool isAnagram(const string& s1, const string& s2);

int main(){

    // get the two strings
    string a, b;
    // cout << "Enter first string: "; getline(cin, a); cout << endl;
    // cout << "Enter second string: "; getline(cin,b); cout << endl;
    // cout << " String a: " << a <<endl;
    // cout << " String b: " << b <<endl;

    a = "i am lord voldemort";
    b = "tom marvolo riddle";

    
    // call checker function on strings
    cout << "Result: " << isAnagram(a,b) << endl;

    return 0;
}

// getline(cin, stringInput) captures whitespaces as well. So use this for sentence strings
// cin >> stringInput captures only the first word. Skips everythings following a whitespace, including the whitespace

bool isAnagram(const string& s1, const string& s2){

    int sum = 0, i = 0;

    while (i < s1.length() or i < s2.length()) {

        if (i < s1.length() and isalpha(s1[i]))
        { // only access string till its valid length and only consider alphabets
            sum += tolower(s1[i]) - '0';
        }

        if (i < s2.length() and isalpha(s2[i]))
        { // only access string till its valid length and only consider alphabets
            sum -= tolower(s2[i]) - '0';
        }

        ++i;
    }
    return sum == 0;
}