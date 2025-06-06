#include<iostream>
#include<string>
#include<unordered_map>
#include<stack>
#include<algorithm>
using namespace std;

//Palindrome check
//optimized solution
string result(string s)
{
    int left = 0;
    int right = s.length()-1;
    
    string temp="";
    string ans="";
    
    //Iterate the string and keep on adding to form a word
    //If empty space is encountered then add the current word to the result
    while (left <= right) {
        char ch= s[left];
        if (ch != ' ') {
            temp += ch;
        } else if (ch == ' ') {
            if (ans!="") ans = temp + " " + ans;
            else ans = temp;
            temp = "";
        }
        left++;
    }
    
    //If not empty string then add to the result(Last word is added)
    if (temp!="") {
        if (ans!="") ans = temp + " " + ans;
        else ans = temp;
    }
    
    return ans;    
}

//anagram = possible premutation ofa given string
//solution one - sort and compare - T = O(nlogn)
bool CheckAnagram(string str1, string str2)
{
  if (str1.length() != str2.length())
    return false;
 
  sort(str1.begin(), str1.end());
  sort(str2.begin(), str2.end());
  
  return str1 == str2;
}

//better soln = hashmap/freqarr
bool AnagramCheck(string str1, string str2)
{
  // Create a hashmap to store character frequencies
    unordered_map<char, int> charCount;
    //
    
    // Count frequency of each character in string s1
    for(char ch: str1) 
        charCount[ch] += 1;
  
    // Count frequency of each character in string s2
    for(char ch: str2) 
        charCount[ch] -= 1;
  
    // Check if all frequencies are zero
    for (auto& pair : charCount) {
        if (pair.second != 0) {
            return false;
        }
    }
    
    // If all conditions satisfied, they are anagrams
    return true;
}

int main()
{
    string s="TUF is great for interview preparation";
    cout<<"Before reversing words: "<<endl;
    cout<<s<<endl;
    s+=" ";
    stack<string> st;
    int i;
    string str="";
    for(i=0;i<s.length();i++)
    {
        if(s[i]==' ')
        {
            st.push(str);
            str="";
        }
        else str+=s[i];
    }
    string ans="";
    while(st.size()!=1)
    {
        ans+=st.top()+" ";
        st.pop();
    }
    ans+=st.top();// The last word should'nt have a space after it
    cout<<"After reversing words: "<<endl;
    cout<<ans;
    return 0;
}

