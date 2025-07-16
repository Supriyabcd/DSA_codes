#include<bits/stdc++.h>
using namespace std;

//Counting digits

//Brute force - O(log(10)n)
int countDigits(int n){
    int cnt = 0;
    while(n > 0){
        cnt = cnt + 1;
        n = n / 10;
    }
    return cnt;
}

//optimal - O(1)
int count_digits(int n){
    int cnt = (int)(std::log10(n)+1);
    return cnt;
}

//reverse a no. 
int reverseNum(int n){
    int r, revNum = 0;
    while (n > 0){
        r = n % 10;
        revNum = revNum*10 + r;
        n = n/10;
    }
    return revNum;
}

//palindrome check
bool palindromeCheck(int x){
    // Handle negative numbers and multiples of 10 (which are not palindromes)
    if (x < 0 || (x % 10 == 0 && x != 0))
        return false;

    int revNum = 0;
    int originalNum = x;

    while (x > revNum) {
        int digit = x % 10;
        revNum = revNum * 10 + digit;
        x /= 10;
    }
    /*
    Reversing Half: No risk of overflow, number of digits being reversed is halved - so within 
    Even-Length Numbers:after reversing half, the reversed part (revNum) should be equal to the remaining part (x).
    Odd-Length Numbers:middle digit doesn't affect the palindrome property, so after reversing half, 
    the remaining part (x) should equal the reversed part without its last digit (revNum / 10).
        */
        return x == revNum || x == revNum / 10;
    }

//palindrome check for a string
bool isPalindrome(string s) {

        int left = 0, right = s.length()-1;
        while(left<right)
        {
            if(!isalnum(s[left])) 
                left++;
            else if(!isalnum(s[right])) 
                right--;
            else if(tolower(s[left])!=tolower(s[right])) 
                return false;
            else {
                left++; 
                right--;
            }
        }
        return true;

}
//armstrong no. = is a number that is equal to the sum of its own digits 
//each raised to the power of the number of digits.
bool armstrong (int n){
    int num = n;
    int cnt_digits = count_digits(n);
    int sum = 0;
    while (n > 0){
        int d = n % 10;
        sum = sum + (int)(std::pow((double)d, (double)cnt_digits));
        n = n/10;
    }

    return (num == sum);
}

//prime or not
//Brute force
bool checkPrime(int n){
    int cnt = 0;
    for (int  i = 0; i <= n; i++){
        if (n%i == 0){
            cnt++;
        }
    }

    if (cnt == 2) 
        return true;
    else 
        return false;
}

//Optimal solution
bool Prime_(int n){
   if (n <= 1) return false;
    for (int i = 2; i <= sqrt(n); i++){
        if (n % i == 0){
            return false;
        }
    }
    return true;
}

//HCF - O(min(n1, n2))
//Brute force
int HCF(int n1, int n2){
    int hcf = 1;
    for (int i = 1; i <= min(n1, n2); i++){
        if(n1%i == 0 && n2%i == 0 ){
            hcf = i;
        }
    }
    return hcf;
}

//better approach
int findHCF(int n1, int n2){
    for (int i = min(n1, n2); i > 0; i--){
        if(n1%i == 0 && n2%i == 0 && i){
            return i;
        }
    }
    return 1;
}

//optimal - euclidean algorithm
int find_hcf(int n1, int n2){
    while (n1 > 0 && n2 > 0){
        if(n1 > n2){
            n1 = n1 % n2;
        }
        else{
            n2 = n2 % n1;
        }
    }
        return (n1 == 0) ? n2 : n1;
// remember lcm = (n1*n2)/hcf
}

//factors of a no.
//Brute force 
vector<int> divisors(int n){
    vector <int> d;
    for (int  i = 1; i <= n; i++){
        if (n%i == 0){
            d.push_back(i);
        }
    }
    return d;
}

//optimal
vector<int> divisors_(int n){
    vector <int> d;
    for (int  i = 1; i <= std::sqrt(n); i++){
        if (n%i == 0){
            d.push_back(i);

            if(n/i != i){
                d.push_back(n/i);
            }
        }
    }
    sort(d.begin(), d.end());
    return d;
}


int main(){
    int n, n1, n2, choice;
    string s; 
    vector <int> result;

    while (true){
    cout << "\nMenu : " << endl;
    cout << "1. Count the digits " << endl;
    cout << "2. Find all the divisors "<< endl;
    cout << "3. Find HCF of 2 numbers" << endl;
    cout << "4. Check whether prime or not " << endl;
    cout << "5. Check whether armstrong or not " << endl;
    cout << "6. Check whether palindrome or not" << endl;
    cout << "7. Check if string is palidrome or not" << endl;
    cout << "0. Exit" << endl; 
    cout << "Enter your choice : " ;
    cin >> choice;

    switch(choice) {
        case 0: return 0; 
        case 1: cout << "Enter the number: " ;
                cin >> n;
                cout << "No. of digits in " << n << " = " << count_digits(n);
                break;
        case 2: cout << "Enter the number: " ; 
                cin >> n;
                cout << "The divisors of " << n << " = " ; 
                result = divisors_(n);
                for (auto it = result.begin(); it != result.end(); it++){
                    cout << *(it) << " ";
                }
                break;
        case 3: cout << "Enter the numbers : ";
                cin >> n1 >> n2;
                cout << "HCF of " << n1 << " and  " << n2 << " = " << find_hcf(n1, n2);
                break;
        case 4: cout << "Enter the number : " ;
                cin >> n;
                if (Prime_(n))
                    cout << n << " is Prime";
                else
                    cout << n << " is not prime";
                break;
        case 5: cout << "Enter the number : ";
                cin >> n;
                if (armstrong(n))
                    cout << n << " is armstrong number";
                else
                    cout << n << " is not armstrong number";
                break;
        case 6: cout << "Enter the number : ";
                cin >> n;
                if (palindromeCheck(n))
                    cout << n << " is a palindrome" ;
                else
                    cout << n << " is not a palindrome" ;
                break;
        case 7: cout << "Enter the string";
                cin >> s;
                if(isPalindrome(s))
                    cout << s << " is a Palindrome";
                else
                    cout << s << " is not a palindrome ";
        default: cout << "Invalid choice" << endl;
                break;

    }
    }
    return 0;
}