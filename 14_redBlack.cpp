#include<bits/stdc++.h>
using namespace std;

enum Color {Red, Black};

struct Node{
    int key;
    Color color;
    Node *left, *right, *parent; 

    Node(int key) : key(key), color(Red), left(nullptr), right(nullptr), parent(nullptr) {} 
};

class RedBlackTree{
    private: 
        Node *root, *nil;

        void left_rotate(Node *x){
            Node *y = x->right;
            x->right = y->left;
            if(y->left != nil)
                y->left->parent = x;

            y->parent = x->parent;
            if(x->parent == nil)
                root = y;
            else if (x == x->parent->left)
                x->parent->left = y;
            else
                x->parent->right = y;

            y->left = x;
            x->parent = y;
        }

        void right_rotate(Node *x)
        {
            Node* y = x->left;
            x->left = y->right;
            if(y->right != nil)
                y->right->parent = x;

            y->parent = x->parent;
            if(x->parent == nil)
                root = y;
            else if(x == x->parent->right)
                x->parent->right = y;
            else 
                x->parent->left = y;

            y->right = x;
            x->parent = y;
        }
        void fix_insert(Node* node);

        public:
            RedBlackTree(){
                nil = new Node(0);
                nil->color = Black;
                root = nil;
            }

            void insert(int key)
            {
                Node *new_node = new Node(key);
                Node* parent = nil;
                Node* current = root;

                while (current != nil){
                    parent = current;
                    if()
                }

            }
};

void RedBlackTree::fix_insert(Node* node)
{
    while(node->parent->color == Red)
    {
        if(node->parent == node->parent->parent->left){
            Node* uncle = node->parent->parent->right;
            if()
        }
    }   
}
int main()
{

    return 0;
}