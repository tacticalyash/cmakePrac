// cmakePractice.cpp : Defines the entry point for the application.
//

#include "cmakePractice.h"
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void BFS(TreeNode* root) {
    if (!root) return;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; ++i) {
            TreeNode* node = q.front();
            q.pop();
            cout << node->val << " ";
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        cout << endl; 
    }
}


void printTree(TreeNode* root, int level = 0) {
    if (root == nullptr) return;

    printTree(root->right, level + 1);
    if (level != 0) {
        for (int i = 0; i < level - 1; ++i)
            cout << "|\t";
        cout << "|-- ";
    }
    cout << root->val << endl;
    printTree(root->left, level + 1);
}

int main() {
   
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);


    cout << "Breadth-First Traversal of the Binary Tree:" << endl;
    BFS(root);

   
    cout << "\nBinary Tree Structure:" << endl;
    printTree(root);
    cout << "HELLO WORLD!";

    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
