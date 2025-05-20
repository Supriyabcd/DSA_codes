#include<bits/stdc++.h>
using namespace std;

//binary representation of number in decimal syatem
string convert2binary(int n){
    string result = "";
    while(n>0){
        if(n % 2 == 1)
        result += '1';
        else
        result += '0';
        n = n/2;
    }
    reverse(result.begin(), result.end());
    return result;
}

//decimal value of binary representation
int convert2decimal(string bin_str){
    int num = 0, p2 = 1;
    int len = bin_str.length();

    for(int i = len-1; i >= 0; i--){
        if(bin_str[i] == '1')
            num = num + p2;
        p2 = p2*2;    
    }
    return num;
}

//swap 2 nums using xor
void swap_nums(int a, int b){
    a = a^b;
    b = a^b;
    a = a^b;
    cout << "a = " << a << " b = " << b <<endl;
}

//check if ith bit is set or not
//brutr force - convert to binary and search in result
//better approach - & and << operator
void checkset_bit(int n, int i){
    
    if((n & (1<< i-1)) != 0) 
    cout << "bit is set" << endl;
    else 
    cout<< "bit is not set" << endl;
}

//set or clear ith bit
//brute force - same as above
//better - bit operators
void set_clear_bit(int n, int i){
    int set_bit = (n | (1 << i-1));
    int clear_bit = (n & (~(1 << i-1)));

    cout << set_bit << clear_bit;
}
//toggle ith bit
void toggle_bit(int n, int i){
    int toggled = (n ^ (1 << i-1));
    cout << toggled << endl;
}
//extract ith bit
int extract_bit(int n, int i){
    return ((n & (1 << (i-1)))>> (i-1));
    //same as (n >> (i-1))%2;
}

//unset rightmost set bit
int unset_last_set_bit(int n){
    return (n&(n-1));
}

//check if power of 2
bool isPowerOfTwo(int n) {
    if( n <= 0) return false;

    return (n & (n-1)) == 0;
}

//odd or even 
string oddEven(int n) {
    if(n & 1 == 1)
        return "odd";
    else return "even";
}

//count #set bits

//XOR of nos. in given range
//case 1 : range 1 to n 
//brute force = recursive
//better approach
int findXORtillN(int n){
    if(n%4 == 1) return 1;
    else if(n%4 == 2) return n+1;
    else if(n%4 == 3) return 0;
    else return n;
}

//case 2: range l to r
int FindXOR(int l, int r){
    return findXORtillN(l)^findXORtillN(r);
}

int main(){
    int n, a , b;
    cin >> n;
    string result = convert2binary(n);
    int num = convert2decimal(result);

    cout << result <<" "<< num << endl;
    cin >> a >> b;
    swap_nums(a,b);
    return 0;
}