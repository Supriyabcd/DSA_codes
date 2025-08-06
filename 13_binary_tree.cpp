#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* right;
    TreeNode* left; 
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if(!root) return {};

        vector<int> result;

        result.push_back(root->val);
        vector<int> left = preorderTraversal(root->left);
        result.insert(result.end(), left.begin(), left.end());
        vector<int> right = preorderTraversal(root->right); 
        result.insert(result.end(), right.begin(), right.end());
        return result;
    }

    vector<int> inorderTraversal(TreeNode* root){
        if(!root) return {};

        vector<int> result;
        vector<int> left = inorderTraversal(root->left);
        result.insert(result.end(), left.begin(), left.end());
        result.push_back(root->val);
        vector<int> right = inorderTraversal(root->right);
        result.insert(result.end(), right.begin(), right.end());        
        return result;
    }

    vector<int> postorderTraversal(TreeNode* root){
        if(!root) return {};

        vector<int> result;

        vector<int> left = postorderTraversal(root->left);
        result.insert(result.end(), left.begin(), left.end());
        vector<int> right = postorderTraversal(root->right);
        result.insert(result.end(), right.begin(), right.end());
        result.push_back(root->val);
        return result;
    }

    vector<vector<int>> levelorderTraversal(TreeNode* root){
        if(!root) return {};

        vector<vector<int>> result;
        queue<TreeNode*> q;

        vector<int> temp;
        q.push(root);

        while(!q.empty()){
            temp.resize(0);
            int size = q.size();
            for(int i = 0; i < size; i++){
                TreeNode* node = q.front();
                q.pop();
                temp.push_back(node->val);
                if(node->right) q.push(node->right);
                if(node->left) q.push(node->left);
            }
            result.push_back(temp);
        }
        return result;
    }

    //iterative preorder
    //iterative postorder
    //postorder using stacks - 1 or 2
    //pre, in, post, level order all at once

    int heightoftree(TreeNode* root){
        if(!root) return 0;

        int rh = heightoftree(root->right);
        int lh = heightoftree(root->left);

        return 1 + max(lh, rh);
    }
    //diameter of binary tree
    //check if tree is height-balanced or not 
    
    //invert/flip binary tree
    TreeNode* flipBT(TreeNode* head){

    }

    //check if two binary trees are identical or not


    //least common ancestor - LCA of two given nodes n1, n2
    //brute force - storing the path from root to the nodes and comapring the node nearest to the node matching in both paths
    //TC = O(n) , SC = O(n)
    //optimal - 
    /*traverse the tree starting from the root. If any of the given keys (n1 and n2) matches with the root, 
    then the root is LCA (assuming that both keys are present). If the root doesn't match with any of the keys, 
    we recur for the left and right subtree. The node which has one key present in its left subtree and the other key present in the right subtree is the LCA, 
    else if, both keys lie in the left subtree, then the left subtree has LCA, else the LCA lies in the right subtree.
    */ 
    //TC = O(n), SC = O(h)
    TreeNode* lca(TreeNode* root, int n1, int n2){
    if (!root)
        return nullptr;

    if (root->val == n1 || root->val == n2)
        return root;

    TreeNode* leftLca = lca(root->left, n1, n2);
    TreeNode* rightLca = lca(root->right, n1, n2);

    if (leftLca && rightLca)
        return root;

    return leftLca ? leftLca : rightLca;

    }

    
};