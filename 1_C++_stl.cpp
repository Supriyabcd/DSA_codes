#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<list>
#include<map>
#include<unordered_set>
using namespace std;

void explainPair()
{
    pair<int, int> p = {1, 3};
    cout << p.first << " " << p.second;
    pair < int, pair <int, int>> p1 = {1, {3,4}};
    cout << p.first << " " << p1.second.second << " " << p1.second.first;
    pair<int, int> arr[] = {{1, 2}, {2, 5}, {5, 1}};
    cout << arr[1].second;
}

void Vector(){

    vector<int> v;
    v.push_back(1);
    v.push_back(3);
    v.push_back(5);
    v.emplace_back(2);

    vector<pair<int, int>> vec;

    vec.push_back({1,2});
    vec.emplace_back(1,2);

    vector<int> v1(5, 100); // vector with five instances of 100

    vector<int> v1(5);
    vector<int> v2(5, 20);
    vector<int> v3(v2);

    vector<int>::iterator it = v.begin();
    it++;
    cout << *(it) << " ";

    it = it + 2;
    cout << *(it) << " ";

    vector<int>::iterator it = v.end();
    //vector<int>::iterator it1 = v.rend(); - points to ele just after 1st ele
    //vector<int>::iterator it2 = v.rbegin(); - points to last ele
    
    cout << v[0] << " " << v.at(0);
    cout << v.back() << " ";

    for (vector<int>::iterator it = v.begin(); it != v.end(); it++){
        cout << *(it) << " ";
    }

    for (auto it = v.begin(); it != v.end(); it++){
        cout << *(it) << " ";
    }

    for (auto it : v) {
        cout << it << " ";
    }

    v.erase(v.begin() + 2, v.begin() + 4);
    vector<int> u(2,100);
    u.insert(u.begin(), 300);
    u.insert(u.begin()+1, 2, 10);

    vector<int> c(2, 100);
    u.insert(u.begin(), c.begin(), c.end());
    //v1 - {10,20}
    //v2 = {30, 40}
    v1.swap(v2); //v1 = {30,40} v2 = {10,20}
}

    void List(){
        list<int> ls;

        ls.push_back(2);
        ls.emplace_back(4);

        ls.push_front(5);
        ls.emplace_front(); 
    }

    // Deque(){same functions as list, vectors }

    void Stack(){
        //push, top, pop, emplace, empty, swap
        //LIFO
    }

    void Queue(){
        //FIFO
        //push, emplace, back, front, pop
    }

    void PriorityQueue(){
        priority_queue<int> pq;//largest character at top
        //non-linear 
        //push, pop,emplace , top

        //minimum priority queue
        priority_queue<int, vector<int>, greater<int>> pq1;
        //push, pop-O(log n), emplace, top
    }

    void SET(){
        set<int> s;
        //insert, emplace
        auto it = s.find(3);
        s.erase(3);
        int count = s.count(1);

        auto it2 = s.find(4);
        s.erase(it, it2);
        //size, empty, swap
        //lower_bound, upper_bound 
        //all operations
        //all operations in O(log n)
    }

    void MultiSet(){
        multiset<int> m;
        //insert, erase(address) or erase(start ad., end ad.) , count, find
    }

    void uset(){
        unordered_set<int> st;
        // similar to set only diff. randomized order of storing elements
        //all functions of set work except lower and upper bound one
    }

    void Map(){//O(log n)
        map<int, int> p; //key-value pairs, unique keys
        p[1] = 2; // key = 1, value = 2 
        p.emplace(3,1); // {key, value}
        p.insert({2,4});
        
        for (auto it : p){
            cout << it.first << " " << it.second << endl;
        }

        auto it = p.find(3);
        auto it = p.lower_bound(2);
        auto it = p.upper_bound(3);
        //erase, swap, size, empty        
    }
// multimap = same as map + can store duplicate keys
// unorderd map = same as map but not in sorted order, O(1) but wcs = O(n) 


/*Algorithms:
sort (start_it, end_it) - sorts in increasing order
sort (start_it, end_it, greater<int> ) - sorts in decreasing order
*/
void algos(){
pair <int, int> a1[] = {{1,2}, {2,1}, {4,1}};
//sort this array such that second are in ascending order,
//if second are same, then arrange such that their first are descending 
sort(a1, a1+3, comp);
//comp - comparator func is given below

int num1 = 7;
int count = __builtin_popcount(num1);
//7)2 = 111, so count = 3
long long num = 165786578687;
int count = __builtin_popcountll(num);

//permutations
string s = "321";
sort(s.begin(), s.end());
do {
    cout << s << endl;
}while(next_permutation(s.begin(), s.end()));

int a[3] = {2, 3, 4};
int maxi = *max_element(a, a+3);

}

bool comp(pair<int, int> p1, pair <int, int> p2){
    if (p1.second < p2.second) return true;
    if (p1.second > p2.second) return false;

    if(p1.first > p2.first) return true;
    return false;
}

int main(){
    return 0;
}