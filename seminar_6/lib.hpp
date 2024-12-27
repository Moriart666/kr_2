#pragma once
#include <vector>
#include <queue>
#include <algorithm>

//  Деревья поиска 2
struct Element{
    int value;
    int array;
    int index;
    bool operator<(const Element& other) const;
};

bool isHeap(const std::vector<int>& arr);
std::vector<int> mergeKSortedArrays(const std::vector<std::vector<int>>& arrays);

struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;
    int balanceFactor;
};

int calculateHeight(TreeNode* node);
void setBalanceFactors(TreeNode* root);
void invertTree(TreeNode* root);
