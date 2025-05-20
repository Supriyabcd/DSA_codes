#include<iostream>
using namespace std;


//n = no. of rows

//Rectangular pattern 
void pattern1(int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
        cout << " * " ;
        }
        cout << endl;
    }
}

//Right-angled triangle pattern
void pattern2(int n){
    for(int i = 0; i < n; i++){
        for (int j = 0; j <= i; j++){
            cout << " * ";
        }
        cout << endl;
    }
}

//right angle no. pyramid
/*
1
12
123
1234
*/
void pattern3(int n){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            cout << j <<" ";
        }
        cout << endl;
    }
}

//no. pyramid
/*
1
22
333
4444
*/
void pattern4(int n){
    for(int i = 1; i <= n; i++){
        for(int j = 1 ;j <= i; j++){
            cout << i <<" ";
        }
        cout << endl;
    }
}

//inverted right pyramid
void pattern5(int n){
    for(int i = 0; i < n; i++){
        for (int j = 0 ; j < n - i; j++){
            cout << "* " ;
        }
        cout << endl;
    }
}

//inverted no. pyramid
void pattern6(int n){
    for(int i = 0; i < n; i++){
        for (int j = 1; j < n-i; j++){
            cout << j << " ";
        }
        cout << endl;
    }
}

//star pyramid
void pattern7(int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n-i-1 ; j++){
            cout << " " << endl;
        }
        for (int j = 0; j <  2*i + 1; j++){
            cout << "* " ;
        }
        for(int j = 0; j < n-i-1 ; j++){
            cout << " " << endl;
        }
        cout << endl;
    }
}

//inverted star pyramid
void pattern8(int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i ; j++){
            cout << " ";
        }
        for(int j = 0; j < 2*n - (2*i + 1); j++){
            cout << "*";
        }
        for(int j = 0; j < i ; j++){
            cout << " ";
        }
        cout << endl;
    }
}

//diamond 
void pattern9(int n){
    pattern7(n);
    pattern8(n);
}

//half diamond 
void pattern10(int n){
    pattern2(n);
    pattern5(n);
}

/*
1
01
101
0101
*/
void pattern11(int n){
    int start = 1;
    for(int i = 0; i < n; i++){
        if (i%2 == 0) start = 1;
        else start = 0;
        for(int j = 0; j <= i; j++){
            cout << start;
            start = 1 - start;
        }
        cout << endl;
    }
}

/*
1      1
12    21
123  321
12344321
*/
void pattern12(int n){
    for(int i = 1; i <= n; i++){
        for(int j = 1 ; j <= i ;j++){
            cout << j;
        }
        for(int j = 0; j < 2*(n-i); j++){
            cout << " ";
        }
        for(int j = 1 ; j <= i ;j++){
            cout << j;
        }
        cout << endl;
    }
}

/*
1
2 3 
4 5 6
7 8 9 10
*/
void pattern13(int n){
    int p = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= 1; j++){
            cout << p << " ";
            p++;
        }
        cout << endl;
    }
}

/*
A
AB
ABC
*/
void pattern14(int n){
    for(int i = 0; i < n; i++){
        for(char ch = 'A' ; ch <= 'A' + i; ch++){
            cout << ch << " ";
        }
        cout << endl;
    }
}

//inverted "Abc" pyramid
void pattern15(int n){
    for(int i = 0; i < n; i++){
        for(char j = 'A' ; j <= 'A' + n - i; j++){
            cout << j << " ";
        }
        cout << endl;
    }
}

/*
A
B B
C C C
*/
void pattern16(int n){
    int j; 
    char ch = 'A';
    for(int i = 1; i <= n; i++){
        for(ch , j = 1 ; j <= i ; j++){
            cout << ch << " ";
        }
        ch ++;
        cout << endl;
    }
}

/*
D
C D
B C D
A B C D
*/
void pattern18(int n){
   for(int i = 0; i < n; i++){
        for(char ch = 'A' + n - 1 - i; ch >= 'A' + n - 1; ch++){
            cout << ch << " ";
        }
        cout << endl;
    }
}

/* alpha-hill
   a
  aba
 abcba
abcdcba
*/
void pattern17(int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - i - 1; j++){
            cout << " ";
        }
        char ch = 'A';
          int breakpoint = (2*i+1)/2;
          for(int j=1;j<=2*i+1;j++){
              
              cout<<ch;
              if(j <= breakpoint) ch++;
              else ch--;
            }
        for(int j = 0; j < n - i - 1; j++){
            cout << " ";
        }
        cout << endl;
    }
}

//symmetric  diamond void in rectangle
void pattern19(int n){
    int inS = 0;
    for(int i = 0; i < n; i++){
        for(int j = 1; j < n-i; j++){
            cout << "*";
        }
        for (int j = 0; j < inS; j++){
            cout << " ";
        }
        for(int j = 0; j < n-i; j++){
            cout << "*";
        }
        inS += 2;
        cout << endl;
    }
    inS = 2*n-2;
    for (int i = 1; i <= n ; i++)
    {
        for(int j = 1; j <= i; j++){
            cout << "*";
        }
        for (int j = 0; j < inS; j++){
            cout << " ";
        }
        for(int j = 1; j <= i; j++){
            cout << "*";
        }
        inS -= 2;
        cout << endl;    
    }
}

//symmetric butterfiy pattern
void pattern20(int n){
    int inS = 2*n-2;
    for (int i = 1; i <= n ; i++)
    {
        for(int j = 1; j <= i; j++){
            cout << "*";
        }
        for (int j = 0; j < inS; j++){
            cout << " ";
        }
        for(int j = 1; j <= i; j++){
            cout << "*";
        }
        inS -= 2;
        cout << endl;    
    }
    inS = 0;
    for(int i = 0; i < n; i++){
        for(int j = 1; j < n-i; j++){
            cout << "*";
        }
        for (int j = 0; j < inS; j++){
            cout << " ";
        }
        for(int j = 0; j < n-i; j++){
            cout << "*";
        }
        inS += 2;
        cout << endl;
    }
}

//hollow rectangle
void pattern21(int n){
    if (n <= 0) {
        cout << "Invalid input!" << endl;
        return;
    }
    for(int j = 0; j < n; j++){
        cout << "*";
    }
    cout << endl;
    for(int i = 1; i < n-1; i++){
        cout << "*";
        for(int j = 1; j < n-1; j++){
            cout << " ";
        }
        if (n > 1)
            cout << "*";
        cout << endl;
    }
    if (n > 1){
    for(int j = 0; j < n; j++){
        cout << "*";
    }
    cout << endl;
    }
}

void pattern22(int n){
    int right, left, top, bottom;
    for(int i = 0; i < 2*n - 1; i++){
        for(int j = 0; j < 2*n - 1 ; j++){
            left = j; 
            right = 2*n - 2 - j;
            top = i;
            bottom = 2*n - 2 - i;
            cout << n-min(min(left, right), min(top,bottom)) <<" ";
        }
        cout << endl;
    }
}

int main(){
    int n, choice;

    cout << "\nMenu:" << endl;
    cout << "1. Rectangle" <<endl;
    cout << "2. Right angled triangle" << endl;
    cout << "3. Right-angled number pyramid " << endl;
    cout << "4. Right-angled number pyramid - II" << endl;
    cout << "5. Inverted Right angled triangle" << endl;
    cout << "6. Inverted Right-angled number pyramid" << endl;
    cout << "7. Pyramid" << endl;
    cout << "8. Inverted pyramid" << endl;
    cout << "9. Diamond" <<endl;
    cout << "10. Half diamond\n";
    cout << "11. Binary right-angled triangle" <<endl;
    cout << "12. Number crown\n";
    cout << "13. ";
    cout << " Enter the no. of rows:" ;
    cin >> n;
    
    return 0;
}