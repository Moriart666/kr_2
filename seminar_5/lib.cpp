#include "lib.hpp"

TreeNode::TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}

BinaryTree::BinaryTree() : root(nullptr) {}

BinaryTree::~BinaryTree() {
    deleteTree(root);
}

void BinaryTree::deleteTree(TreeNode* node) {
    if (!node) return;
    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}

void BinaryTree::inOrderTraversal(TreeNode* node) const {
    if (!node) return;
    inOrderTraversal(node->left);
    std::cout << node->value << " ";
    inOrderTraversal(node->right);
}

bool BinaryTree::isMirror(TreeNode* t1, TreeNode* t2) const {
    if (!t1 && !t2) return true;
    if (!t1 || !t2) return false;
    return (t1->value == t2->value) &&
           isMirror(t1->left, t2->right) &&
           isMirror(t1->right, t2->left);
}

void BinaryTree::buildFromArray(const std::vector<int>& arr) {
    if (arr.empty()) {
        root = nullptr;
        return;
    }

    root = new TreeNode(arr[0]);
    std::queue<TreeNode*> q;
    q.push(root);

    int i = 1;
    while (i < arr.size()) {
        TreeNode* current = q.front();
        q.pop();

        if (i < arr.size()) {
            current->left = new TreeNode(arr[i]);
            q.push(current->left);
            i++;
        }

        if (i < arr.size()) {
            current->right = new TreeNode(arr[i]);
            q.push(current->right);
            i++;
        }
    }
}

void BinaryTree::levelOrderTraversal() const {
    if (!root) {
        std::cout << "Дерево пусто." << std::endl;
        return;
    }

    std::queue<TreeNode*> q;
    q.push(root);
    std::cout << "Обход дерева в ширину: ";
    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();
        std::cout << current->value << " ";
        if (current->left) q.push(current->left);
        if (current->right) q.push(current->right);
    }
    std::cout << std::endl;
}

void BinaryTree::inOrder() const {
    std::cout << "In-Order Traversal: ";
    inOrderTraversal(root);
    std::cout << std::endl;
}

bool BinaryTree::isSymmetric() const {
    return isMirror(root, root);
}

int BinaryTree::minDepth() const {
    if (!root) return 0;
    std::queue<std::pair<TreeNode*, int>> q;
    q.push({root, 1});
    while (!q.empty()) {
        TreeNode* current = q.front().first;
        int depth = q.front().second;
        q.pop();
        if (!current->left && !current->right) {
            return depth;
        }
        if (current->left) q.push({current->left, depth + 1});
        if (current->right) q.push({current->right, depth + 1});
    }
    return 0;
}

TreeNode* BinaryTree::getRoot() const {
    return root;
}

BinarySearchTree::BinarySearchTree() : root(nullptr) {}

BinarySearchTree::~BinarySearchTree() {
    deleteTree(root);
}

void BinarySearchTree::deleteTree(TreeNode* node) {
    if (!node) return;
    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}

TreeNode* BinarySearchTree::insert(TreeNode* node, int value) {
    if (!node) {
        return new TreeNode(value);
    }
    if (value < node->value) {
        node->left = insert(node->left, value);
    }
    else {
        node->right = insert(node->right, value);
    }
    return node;
}

void BinarySearchTree::inOrderTraversal(TreeNode* node) const {
    if (!node) return;
    inOrderTraversal(node->left);
    std::cout << node->value << " ";
    inOrderTraversal(node->right);
}

int BinarySearchTree::findMin(TreeNode* node) const {
    if (!node) throw std::runtime_error("Дерево пусто.");
    while (node->left) {
        node = node->left;
    }
    return node->value;
}

int BinarySearchTree::findMax(TreeNode* node) const {
    if (!node) throw std::runtime_error("Дерево пусто.");
    while (node->right) {
        node = node->right;
    }
    return node->value;
}

void BinarySearchTree::buildFromArray(const std::vector<int>& arr) {
    for (const int& val : arr) {
        root = insert(root, val);
    }
}

void BinarySearchTree::inOrder() const {
    std::cout << "In-Order Traversal: ";
    inOrderTraversal(root);
    std::cout << std::endl;
}

int BinarySearchTree::getMin() const {
    return findMin(root);
}

int BinarySearchTree::getMax() const {
    return findMax(root);
}

long long BinarySearchTree::productMinMax() const {
    if (!root) throw std::runtime_error("Дерево пусто.");
    int minVal = getMin();
    int maxVal = getMax();
    return static_cast<long long>(minVal) * maxVal;
}

void BinarySearchTree::levelOrderTraversal() const {
    if (!root) {
        std::cout << "Дерево пусто." << std::endl;
        return;
    }

    std::queue<TreeNode*> q;
    q.push(root);
    std::cout << "Обход дерева в ширину: ";
    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();
        std::cout << current->value << " ";
        if (current->left) q.push(current->left);
        if (current->right) q.push(current->right);
    }
    std::cout << std::endl;
}

TreeNode* BinarySearchTree::getRoot() const {
    return root;
}

bool areIdentical(TreeNode* root1, TreeNode* root2) {
    if (!root1 && !root2)
        return true;
    if (!root1 || !root2)
        return false;
    if (root1->value != root2->value)
        return false;
    return areIdentical(root1->left, root2->left) && areIdentical(root1->right, root2->right);
}