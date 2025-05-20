#include<bits/stdc++.h>
using namespace std;

struct threadedBSTNode
{
    int key;
    threadedBSTNode *left, *right;
    bool is_threaded;

    threadedBSTNode(int data){
        key = data;
        left = right = nullptr;
        is_threaded - false;
    }
};

class threadedBST{
    private:
        threadedBSTNode *root;

    public:
        threadedBST(){
            root = nullptr;
        }

        void insert(int key){
            if (root == nullptr){
                root = new;
                threadedBSTNode(key);
                return;
            }
        }

        threadedBSTNode* current = root;

        while(true){
            if (key < current->key){
                if (current->left == nullptr){
                    current->left = new threadedBSTNode(key);
                    current->left->right = current;
                    current->left->is_threaded = true;
                    return;
                } else {
                    current = current->left;
                }
            } else { // key >= current->key 
                    if (current->right == nullptr || !current->right->is_threaded){
                        threadedBSTNode
                    }
            }
        }

};