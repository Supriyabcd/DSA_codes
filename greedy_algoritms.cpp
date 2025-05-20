#include<bits/stdc++.h>
using namespace std;

/*lemonade change:
each glass 5Rs.
customers in queue give 5, 10 and 20 - given array 
return ture if possible to give change to it*/
bool lemonadeChange(vector<int>& bills){
    int fives = 0, tens = 0;
    for(int i = 0; i < bills.size(); i++){
        if(bills[i] == 5){
            fives++;
        } else if(bills[i] == 10){
            if(fives != 0) {
                tens++;
                fives--;
            } else {return false;}
        } else {
            if (fives != 0 && tens != 0){
                fives -= 2;
                tens--;
            } else if(fives >= 3) {
                fives -= 3; 
            } else {
                return false;
            }
        }
    }
    return true;
}

/* assign cookies

*/
int main(){
    return 0;
}