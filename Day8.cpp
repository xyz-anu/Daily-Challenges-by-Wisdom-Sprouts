#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;
string reverseWords(const string& s) {
    istringstream iss(s);
    vector<string> words;
    string word;
    while (iss >> word)
        words.push_back(word);
    reverse(words.begin(), words.end());
    string result;
     for (int i = 0; i < words.size(); ++i) {
        if (i > 0) result += " ";
        result += words[i];
    }
    return result;
}
int main() {
    cout << reverseWords("the sky is blue") << endl;           
    cout << reverseWords("  hello   world  ") << endl;         
    cout << reverseWords("coding") << endl;                    
    cout << reverseWords("123 456! good-morning,") << endl;   
    cout << reverseWords(" ") << endl; 
    cout << reverseWords("word") << endl; 
}
