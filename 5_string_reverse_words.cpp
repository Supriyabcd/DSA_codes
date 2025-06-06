#include<iostream>
#include<string>
#include<sstream>
#include<algorithm>
#include<stack>
#include<vector>

using namespace std;

string reverseWords(string s){
    vector<string> words;
    string word;
    stringstream ss(s);
    
    while(ss >> word){
        words.push_back(word);
    }

    reverse(words.begin(), words.end());
    
    string result = "";
    for(int  i = 0; i < words.size(); i++){
        result += words[i];
        if (i != words.size() - 1) result += " ";
    }
    return result;
}

int main(){
    string str;

    getline(cin, str);

    string result = reverseWords(str);
    cout << result << endl;
    return 0;
}