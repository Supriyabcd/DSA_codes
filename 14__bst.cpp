#include<bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.*/
 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
public:
    //recursive preorder traversal
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;

        if(root == NULL){
            return result;
        }

        result.push_back(root->val);
        vector<int> left = preorderTraversal(root->left);
        result.insert(result.end(), left.begin(), left.end());
        vector<int> right = preorderTraversal(root->right);
        result.insert(result.end(), right.begin(), right.end());
        return result;
    }

    //recursive postorder traversal
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;

        if(root == NULL){
            return result;
        }

        vector<int> left = postorderTraversal(root->left);
        result.insert(result.end(), left.begin(), left.end());
        vector<int> right = postorderTraversal(root->right);
        result.insert(result.end(), right.begin(), right.end());
        
        result.push_back(root->val);
        return result;
    }

    //recursive inorder traversal
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        if(root == NULL){
            return result;
        }
        vector<int> left =  inorderTraversal(root->left);
        result.insert(result.end(), left.begin(), left.end());
        result.push_back(root->val);
        vector<int> right = inorderTraversal(root->right);
        result.insert(result.end(), right.begin(), right.end());
        return result;
    }

    //iterative Morris inorder traversal
    vector<int> getInorder(TreeNode* root) {
        
        vector<int> inorder_result;
        TreeNode* cur = root;
        
        while (cur != NULL) {
            //if left child is null
            if (cur->left == NULL) {
                inorder_result.push_back(cur->val);
                cur = cur->right;
            } else {
            // If the left child is not NULL,
            // find the predecessor (rightmost node
            // in the left subtree)
                TreeNode* prev = cur->left;
                while (prev->right && prev->right != cur) {
                    prev = prev->right;
                }
                
                // If the predecessor's right child
                // is NULL, establish a temporary link
                // and move to the left child
                if (prev->right == NULL) {
                    prev->right = cur;
                    cur = cur->left;
                } else {
                    // If the predecessor's right child
                    // is already linked, remove the link,
                    // add current node to inorder vector,
                    // and move to the right child
                    prev->right = NULL;
                    inorder_result.push_back(cur->val);
                    cur = cur->right;
                }
            }
        }
        
        return inorder_result;
    }

    //iterative Morris preorder traversal
    vector<int> getPreorder(TreeNode* root) {
        vector<int> preorder_result;
        TreeNode* cur = root;

        while (cur != NULL) {
            //if no left child
            if (cur->left == NULL) {
                // Add the value of the
                // current node to the preorder vector
                preorder_result.push_back(cur->val);
                
                // Move to the right child
                cur = cur->right;
            } else {
                // If the current node has a left child
                // Create a pointer to traverse to the
                // rightmost node in the left subtree
                TreeNode* prev = cur->left;
                
                // Traverse to the rightmost node in the
                // left subtree or until we find a node 
                // whose right child is not yet processed
                while (prev->right && prev->right != cur) {
                    prev = prev->right;
                }
                
                // If the right child of the
                // rightmost node is NULL
                if (prev->right == NULL) {
                    // Set the right child of the
                    // rightmost node to the current node
                    prev->right = cur;
                    
                    // Move to the left child
                    cur = cur->left;
                } else {
                    // If the right child of the
                    // rightmost node is not NULL
                    // Reset the right child to NULL
                    prev->right = NULL;
                    
                    // Add the value of the
                    // current node to the preorder vector
                    preorder_result.push_back(cur->val);
                    
                    // Move to the right child
                    cur = cur->right;
                }
            }
        }
        return preorder_result;
    }

    //level order
    vector<int> levelOrder(TreeNode* root){
        vector<int> result;
        if (!root) return result;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            result.push_back(node->val);
            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
        }
        return result;
    }

    //height - maximum depth of tree
    // int height(TreeNode* root){
    //     int level = 0;

    //     if(!root) return level;

    //     queue<TreeNode*> q;
    //     q.push(root);

    //     while(!q.empty()){
            
    //         TreeNode* temp = q.front();
    //         q.pop();
    //         if(temp->left)
    //             q.push(temp->left);
    //         if(temp->right)
    //             q.push(temp->right);
    //     }
    //     return level;
    // }
    int maxDepth(TreeNode* root){
        if(!root) return 0;

        int rh = maxDepth(root->right);
        int lh = maxDepth(root->left);

        return 1 + max(lh, rh);
    }

    int diameterOfBT(TreeNode* root){
        
    }
};