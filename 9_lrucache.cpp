#include<iostream>
#include<queue>
#include<stack>
#include<unordered_map>

using namespace std;

//using arrays
//Time : insertion/put = O(n) , search/get = O(n)
//Space : O(n) 
class LRUCache1{
    public:
        class Node{
            public:
            int key;
            int value;
            int timestamp;

            Node(int k, int val, int time){
                key = k;
                value = val;
                timestamp = time;
            }
        };

        vector<Node*> arr;
        int cap, time;

        LRUCache1(int capacity){
            cap = capacity;
            arr.resize(cap);
            time = 0;
        }

        int get(int key){
            time++;
            for(int i = 0; i < arr.size(); i++){
                if(arr[i]->key == key){
                    arr[i]->timestamp = time;
                    return arr[i]->value;
                }
            }
            return -1;
        }

        int put(int key, int val){
            time++;
            
            return -1;
        }
};

//using singly linked
//time : put = O(n), get = O(n)
//space : O(n)
class LRUCache2{

};

//optimal: using doubly linked list
//time: put = O(1), get = O(1)
//space: O(n)
class LRUCache{
    public:
    class Node{
        public:
            int key;
            int val;
            Node* prev;
            Node* next;
            Node(int _key, int _val) : key(_key), val(_val), prev(nullptr), next(nullptr) {}
    };

    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    unordered_map <int, Node*> mpp;
    int cap;

    
    LRUCache(int capacity) {
        cap = capacity;
        head -> next = tail;
        tail -> prev = head;
    }

    void addNodeAfterHead(Node* node){
        Node* curAfterHead = head->next;
        head->next = node;
        node->next = curAfterHead;
        node->prev = head;
        curAfterHead->prev = node;
    }

    void DeleteNode(Node* node){
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }
    
    int get(int key) {
        if (mpp.find(key) != mpp.end()) {
            Node * resnode = mpp[key];
            int res = resnode->val;
            DeleteNode(resnode);
            addNodeAfterHead(resnode);
            return res;
            }
        return -1;
    }
    
    void put(int key, int value) {
        if (mpp.find(key) != mpp.end()) {
            // Key exists, update its value and move it to the front
            Node* existingNode = mpp[key];
            existingNode->val = value;
            DeleteNode(existingNode);
            addNodeAfterHead(existingNode);
        } else {
            // Key does not exist, add it to the cache
            if (mpp.size() == cap) {
                // Cache is full, remove the least recently used node
                Node* lruNode = tail->prev;
                mpp.erase(lruNode->key);
                DeleteNode(lruNode);
            }
            // Create a new node and add it to the front
            Node* newNode = new Node(key, value);
            addNodeAfterHead(newNode);
            mpp[key] = newNode;
        }
    }
};

int main(){
    LRUCache lrucache(3);

    return 0;
} 