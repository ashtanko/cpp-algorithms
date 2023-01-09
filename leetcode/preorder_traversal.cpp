#include "tree.h"
#include <vector>
#include <stack>
#include <iostream>

class IterativeSolution {
public:
    static std::vector<int> preorderTraversal(TreeNode *root) {
        std::vector<int> nodes;
        std::stack<TreeNode *> todo;
        while (root || !todo.empty()) {
            if (root) {
                nodes.push_back(root->val);
                if (root->right) {
                    todo.push(root->right);
                }
                root = root->left;
            } else {
                root = todo.top();
                todo.pop();
            }
        }
        return nodes;
    }
};

class RecursiveSolution {
public:
    static std::vector<int> preorderTraversal(TreeNode *root) {
        std::vector<int> nodes;
        preorder(root, nodes);
        return nodes;
    }

private:
    static void preorder(TreeNode *root, std::vector<int> &nodes) {
        if (!root) {
            return;
        }
        nodes.push_back(root->val);
        preorder(root->left, nodes);
        preorder(root->right, nodes);
    }
};

class MorrisSolution {
public:
    static std::vector<int> preorderTraversal(TreeNode *root) {
        std::vector<int> nodes;
        while (root) {
            if (root->left) {
                TreeNode *pre = root->left;
                while (pre->right && pre->right != root) {
                    pre = pre->right;
                }
                if (!pre->right) {
                    pre->right = root;
                    nodes.push_back(root->val);
                    root = root->left;
                } else {
                    pre->right = NULL;
                    root = root->right;
                }
            } else {
                nodes.push_back(root->val);
                root = root->right;
            }
        }
        return nodes;
    }
};

void printResult(std::vector<int> result) {
    for (int i: result) {
        std::cout << i << "\n";
    }
}

int main() {
    auto *node = new TreeNode(1);
    node->right = new TreeNode(2);
    node->right->left = new TreeNode(3);
    std::vector<int> iterativeResult = IterativeSolution::preorderTraversal(node);
    std::vector<int> recursiveResult = RecursiveSolution::preorderTraversal(node);
    std::vector<int> morrisResult = MorrisSolution::preorderTraversal(node);
    printResult(iterativeResult);
    std::cout << std::endl;
    printResult(recursiveResult);
    std::cout << std::endl;
    printResult(morrisResult);
    return 0;
}
