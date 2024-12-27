#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <stdexcept>

// Восстановление бинарного дерева из массива
// Проверка на симметричность бинарного дерева
// Поиск минимальной глубины
// Произведение минимального и максимального значения
// Сравнение двух деревьев

struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val);
};

class BinaryTree {
private:
    TreeNode* root;

    void deleteTree(TreeNode* node);
    void inOrderTraversal(TreeNode* node) const;
    bool isMirror(TreeNode* t1, TreeNode* t2) const;

public:
    BinaryTree();
    ~BinaryTree();

    void buildFromArray(const std::vector<int>& arr);
    void levelOrderTraversal() const;
    void inOrder() const;
    bool isSymmetric() const;
    int minDepth() const;
    TreeNode* getRoot() const;
};

class BinarySearchTree {
private:
    TreeNode* root;

    void deleteTree(TreeNode* node);
    TreeNode* insert(TreeNode* node, int value);
    void inOrderTraversal(TreeNode* node) const;
    int findMin(TreeNode* node) const;
    int findMax(TreeNode* node) const;

public:
    BinarySearchTree();
    ~BinarySearchTree();

    void buildFromArray(const std::vector<int>& arr);
    void inOrder() const;
    int getMin() const;
    int getMax() const;
    long long productMinMax() const;
    void levelOrderTraversal() const;
    TreeNode* getRoot() const;
};

bool areIdentical(TreeNode* root1, TreeNode* root2);
