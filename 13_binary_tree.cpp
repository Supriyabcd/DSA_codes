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
        
    }
};