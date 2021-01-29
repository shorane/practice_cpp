// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <sstream>
#include <memory>
#include <unordered_map>
#include <map>
using namespace std;

/*
Objective: Return the kth most frequent string/strings from a given sentence

Process: 
1. make unord_map with <string, int> where int is the frequency
2. copy flipped pairs to an ordered map
3. ordered map must be <int,vector<string>> to store multiple words with same freq
4. return the word/words from this above ordered map

*/ 

// ptr to string can also be returned for efficiency, the focus has been on the 
// implementation in this code
vector<string> kth_mf( shared_ptr< vector<string> > words, int k);

int main(){

    // make a test case
    string sentence = "aa ab aa ac aa ac ac ac ac ab ad ae ae af af at at ag ag"; // aa:3 , ab: 2, ac:5, ad:1, ae: 2
    //get k
    int k; cout << "Enter k: "; cin >> k; cout << endl;

    // Process single string of sentence to make a list of words
    // The below process can also be used if the ss is passed directly to 
    // the function and used to make the dict

    stringstream s(sentence);   // make ss from sentence string
    string word;
    shared_ptr< vector<string> > words(new vector<string>);

    while (s >> word){ 
        (*words).push_back(word);   // add words to vector
    }
    
    // call the kth function and print the result
    // the function might return more than one words if they have the same freq
    auto res = kth_mf(words, k);        

    cout << "The kth most frequent word(s): " << endl;
    for (auto& word: res){
        cout << word << " ";
    }
    cout << endl << endl;

    return 0;
}

vector<string> kth_mf( shared_ptr< vector<string> > words, int k){
    
    // create ordered hashmap of type <word,freq>
    unordered_map<string,int> dict; 
    multimap<int, vector<string> > mmp;
    vector<string> ans;
    // Create unordered map to get key value pairs of each word and its freq
    for (auto& word: *words){
        ++dict[word];
    }

    // If k is larger than num of unique words, return error message
    if (k > dict.size()) {
        string error_msg = "K larger than number if words";
        ans.push_back(error_msg);
        return ans;
    }

    // Transfer info to multimap / map.
    // flip the key value pairs. This allows sorting based on freq (value).
    // sorting is in increasing order to rend is used below
    // words with same freq are stored in the same freq "key"
    // the kth most freq vector will be returned, this can contain 1 or more words
    // this could also be done using a map 
    // multimap allows adding same key for different values and this could be used in other implementations
    // here, both map and multimap work fine

    for( auto& item: dict){
        // if this same freq is present in multimap
        // add to that vector
        auto ptr = mmp.find(item.second);
        if ( ptr != mmp.end()){ 
            ptr->second.push_back(item.first);
        }

        // else create new vector, create pair and add to map
        else {
            vector<string> vec;
            vec.push_back(item.first);
            mmp.insert(make_pair(item.second, vec));}
    }

    // print for debugging
    cout << "The sorted map/multimap: " << endl;
    for (auto& item: mmp){
        cout << "Freq: " << item.first << ": ";
        for (auto& ws: item.second){
            cout << ws << " ";
        }
        cout << endl;
    }cout << endl;
    
    // iterate through multimap/map and return the kth most frequent string
    auto it = ++mmp.rend();
    int count = 1;
    while (count !=k) {++it; ++count;}

    return it->second;
}