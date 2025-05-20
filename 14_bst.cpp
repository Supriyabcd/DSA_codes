#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
using namespace std;

struct TreeNode{
    int data;
    TreeNode* right;
    TreeNode* left; 
    TreeNode(int x): data(x), left(nullptr), right(nullptr) {}
};

class BST{
    public:
        BST() : root(nullptr){}

        void insert(int value){
            root = insert(root, value);
        } 
        
        bool search(int value){
            return search(root, value);
        } 

        void deleteNode(int value){
            root = deleteNode(root,value);
        }

        TreeNode* FindNode(int value){
            return deleteNode(root, value);
        }

        TreeNode* inorderSuccessor(TreeNode* node);
        TreeNode*inorderPredecessor(TreeNode* node);
        vector<int> levelOrder();

    private:
        TreeNode* root;

        TreeNode* insert(TreeNode* node, int value){
            if (!node) return new TreeNode(value);
            if (value < node->data){
                node->left = insert(node->left, value);
            } else {
                node->right = insert(node->right, value);
            }
            return node;
        }

        bool search(TreeNode* node, int value){
            if (!node) return false;
            if(node->data == value) return true;
            if(value < node->data) return search(node->left, value);
            if(value > node->data) return search(node->right, value);            
        }
        
        TreeNode* minValueNode(TreeNode* node){
            TreeNode* current = node;
            while(current && current->left ){
                current = current->left;
            }
            return current;
        }

        TreeNode* maxValueNode(TreeNode* node){
            TreeNode* current = node;
            while(current && current->right){
                current = current->right;
            }
            return current;
        }

        TreeNode* deleteNode(TreeNode* root, int value);

        TreeNode* findNode(TreeNode* root, int value){
            if (!root) return nullptr;
            if (root->data == value) return root;
            if (value < root->data) {
                return findNode(root->left, value);
            }
            return findNode(root->right, value);
        }
};

TreeNode* BST::inorderSuccessor(TreeNode* node)
{ 
    //returns succ of root 
    if(node->right){
        return minValueNode(node->right);
    }
    // returns succ of nodes other than root
    TreeNode* succ = nullptr;
    TreeNode* ancestor = root;
    while(ancestor != node){
        if(node->data < ancestor->data){
            succ = ancestor;
            ancestor = ancestor->left;
        } else {
            ancestor = ancestor->right;
        }
    }
    return succ;
}

TreeNode* BST:: inorderPredecessor(TreeNode* node)
{
    // returns pred of root
    if(node->left){
        return maxValueNode(node->left);
    }

    //returns pred of nodes other than root
    TreeNode* pred = nullptr;
    TreeNode* ancestor = root;
    while(ancestor != node){
        if (node->data > ancestor->data){
            pred = ancestor;
            ancestor = ancestor->right;
        } else {
            ancestor = ancestor->left;
        }
    }
    return pred;
}

vector<int> BST:: levelOrder()
{
    vector<int> result;
    if (!root) return result;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()){
        TreeNode* node = q.front();
        q.pop();
        result.push_back(node->data);
        if(node->left)
            q.push(node->left);
        if(node->right)
            q.push(node->right);
    }
    return result;
}

TreeNode* BST::deleteNode(TreeNode* root, int value)
{
    if (!root) return root;
    if (value < root->data){
        root->left = deleteNode(root->left, value);
    } else if (value > root->data){
        root->right = deleteNode(root->right, value);
    } else {
        if (!root->left){
            TreeNode* temp = root->right;
            delete root;
            return temp;
        } else if (!root->right){
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }
        TreeNode* temp = minValueNode(root->right);
        root->data = temp ->data;
        root->right = deleteNode(root->right, temp-> data);
        }
        return root;
}

void printLevelOrder(const vector<int>& result)
{
    for(int val : result){
        cout << val <<" ";
    }
    cout << endl;
}

int main()
{
    BST tree;

    vector<int> insertSeq = {10, 5, 15, 3, 7, 12, 18, 1, 4, 6, 8, 11, 14, 17, 20};
    cout << "Insertion :" << endl;
    for (int val : insertSeq)
    {
        tree.insert(val);
        vector<int> LevelOrderResult = tree.levelOrder();
        printLevelOrder(LevelOrderResult);
    }

    cout << "Searching:" << endl;
    vector<int> searchSeq = {100, 5, 19};
    for (int val: searchSeq){
        cout << (tree.search(val) ? "Yes" : "No") << endl;
    }

    TreeNode* node = tree.FindNode(10);
    if(node){
        TreeNode* succ = tree.inorderSuccessor(node);
        TreeNode* pred = tree.inorderPredecessor(node);
        cout << "Inorder successor of " << node->data <<" : " <<(succ ? to_string(succ->data):"None") << endl;
        cout << "Inorder predecessor of " << node->data << " : " << (pred ? to_string(pred->data):"None") << endl;
    }

    cout << "Deletion" << endl;
    vector<int> deleteSeq = {10, 15, 5, 7, 12};
    for(int val:deleteSeq)
    {
        tree.deleteNode(val);
        vector<int> levelOrderResult = tree.levelOrder();
        printLevelOrder(levelOrderResult);
    }
    return 0;
}