#include<bits/stdc++.h>
using namespace std;

class LRUCache {
public:
    class Node {
    public:
        int key;
        int val;
        Node* prev;
        Node* next;
        Node(int _key, int _val) {
            key = _key;
            val = _val;
        }
    };

    Node* head = new Node(-1, -1); // Dummy head
    Node* tail = new Node(-1, -1); // Dummy tail

    unordered_map<int, Node*> mpp; // Key to Node map
    int cap; // Capacity of the cache

    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void addNodeAfterHead(Node* node) {
        Node* curAfterHead = head->next;
        head->next = node;
        node->next = curAfterHead;
        node->prev = head;
        curAfterHead->prev = node;
    }

    void deleteNode(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    int get(int key) {
        if (mpp.find(key) != mpp.end()) {
            Node* resnode = mpp[key];
            int res = resnode->val;
            deleteNode(resnode);
            addNodeAfterHead(resnode); // Move to front
            return res;
        }
        return -1; // Cache miss
    }

    void put(int key, int value) {
        if (mpp.find(key) != mpp.end()) {
            // Key exists, update its value and move it to the front
            Node* existingNode = mpp[key];
            existingNode->val = value;
            deleteNode(existingNode);
            addNodeAfterHead(existingNode);
        } else {
            // Key does not exist, add it to the cache
            if (mpp.size() == cap) {
                // Cache is full, remove the least recently used node
                Node* lruNode = tail->prev;
                mpp.erase(lruNode->key);
                deleteNode(lruNode);
            }
            // Create a new node and add it to the front
            Node* newNode = new Node(key, value);
            addNodeAfterHead(newNode);
            mpp[key] = newNode;
        }
    }
};

int main(){
    //required code
    return 0;
}