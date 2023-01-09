#ifndef CPP_ALGORITHMS_TREENODE_H
#define CPP_ALGORITHMS_TREENODE_H


#include <__nullptr>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


#endif //CPP_ALGORITHMS_TREENODE_H
