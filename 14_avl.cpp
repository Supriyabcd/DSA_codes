#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class AVLTree{
    public:
        AVLTree() : root(nullptr) {}

        void insertKey(int key){
                root = insert(root, key);
        }

        void deleteKey(int key){
                root = deleteNode(root, key);
        }

        void inOrder(){
                inOrderTraversal(root);
        }

        void levelOrder(){
                levelOrderTraversal(root);
        }

        void displayInfo(){
                displayNodeInfo(root);
        }


    private:
        struct Node{
                int data;
                Node* right;
                Node* left;
                int height;
                Node(int k) : data(k), left(nullptr), right(nullptr), height(1) {}
        };

        Node* root;

        int height(Node* node){
                return node ? node->height : 0;
        }

        int balanceFactor(Node* node){
                return node ? height(node->left) - height(node->right) : 0;
        }

        void updateheight(Node* node){
                if (node){
                        node->height = 1 + max(height(node->left), height(node->right));
                }
        }

        Node* rightRotate(Node* y){
                Node* x = y->left;
                y->left = x->right;
                x->right = y;
                updateheight(y);
                updateheight(x);
                return x;
        }

        Node* leftRotate(Node* x){
                Node* y = x->right;
                x->right = y->left;
                y->left = x;
                updateheight(x);
                updateheight(y);
                return y;
        }

        Node* balance(Node* node){
                updateheight(node);
                int balance = balanceFactor(node);

                if(balance > 1){
                        if(balanceFactor(node->left) < 0){
                                node->left = leftRotate(node->left);
                        }
                        return rightRotate(node);
                }

                if(balance < -1){
                        if(balanceFactor(node->right) > 0){
                                node->right = rightRotate(node->right);
                        }
                        return leftRotate(node);
                }
                return node;
        }

        Node* insert(Node* node, int key){
                if (!node){
                        return new Node(key);
                }

                if (key < node->data){
                        node->left = insert(node->left, key);
                } else if (key > node->data) {
                        node->right = insert(node->right, key);
                } else { 
                        return node;
                }
                return balance(node);
        }

        Node* minValueNode (Node*node){
                Node* current = node;
                while(current->left){
                        current = current->left;
                }
                return current;
        }

        Node* deleteNode(Node* root, int key)
        {
                if(!root){
                        return root;
                }

                if(key < root->data){
                        root->left = deleteNode(root->right, key);
                } else if (key > root->data) {
                        root->right = deleteNode(root->right, key);
                } else {
                        if (!root->left || !root->right){
                                root = root->left ? root->left : root->right;
                        } else {
                        Node* temp = minValueNode(root->right);
                        root->data = temp->data;
                        root->right = deleteNode(root->right, temp->data);
                }
                
                if(!root){
                        return root;
                }
            }
            return balance(root);
        }

        void inOrderTraversal(Node* root){
                if (root){
                        inOrderTraversal(root->left);
                        cout << root->data << " ";
                        inOrderTraversal(root->right);
                }
        }

        void displayNodeInfo(Node* root){
                if (root){
                        displayNodeInfo(root->left);
                        cout << "Node: Key =" << root->data << ", Height = " << root->height << ", Balance Factor = " << balanceFactor(root) << endl;
                        displayNodeInfo(root->right);
                }
        }

        void levelOrderTraversal(Node* root){
                if (!root) {
                        return;
                }

                queue<Node*> q;
                q.push(root);
                while(!q.empty()){
                        Node* node = q.front();
                        q.pop();
                        cout << node->data << " ";
                        if(node->left){
                                q.push(node->left);
                        }
                        if (node->right){
                                q.push(node->right);
                        }
                }
        }
};

int main(){

    AVLTree tree;
    int choice, data;

    do{
        cout << "\nAVL Tree Operations:  " << endl;
        cout << "1. Insertion " << endl;
        cout << "2. Deletion " << endl;
        cout << "3. Display node information " << endl;
        cout << "4. Inorder traversal " << endl;
        cout << "5. Level Order Traversal" << endl;
        cout << "0. Exit " << endl;
        cout << "Enter your choice: " ;
        cin >> choice;      

        switch(choice){
            case 1: cout << "Enter the integer to be inserted: ";
                    cin >> data;
                    tree.insertKey(data);
                    break;
            case 2: cout << "Enter the integer to be deleted:";
                    cin >> data;
                    tree.deleteKey(data);
                    break;
            case 3: tree.displayInfo();
                    break;
            case 4: tree.inOrder();
                    break;
            case 5: tree.levelOrder();
                    break;
            case 0: cout << "Exiting..." << endl;
                    exit(0);
            default : cout << "Invalid choice. Please try again \n";
        }
        
    } while(choice != 0);

    return 0;
}