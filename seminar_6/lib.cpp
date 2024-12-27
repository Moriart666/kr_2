#include "lib.hpp"

bool Element::operator<(const Element& other) const{
    return value > other.value;
}

bool isHeap(const std::vector<int>& arr){
    int n = arr.size();
    bool isMinHeap = true;
    bool isMaxHeap = true;
    for(int i = 0; i <= (n - 2) / 2; ++i){
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if(left < n){
            if(arr[i] > arr[left]) isMinHeap = false;
            if(arr[i] < arr[left]) isMaxHeap = false;
        }
        if(right < n){
            if(arr[i] > arr[right]) isMinHeap = false;
            if(arr[i] < arr[right]) isMaxHeap = false;
        }
        if(!isMinHeap && !isMaxHeap) return false;
    }
    return isMinHeap || isMaxHeap;
}

std::vector<int> mergeKSortedArrays(const std::vector<std::vector<int>>& arrays){
    std::priority_queue<Element> pq;
    for(int i = 0; i < arrays.size(); ++i){
        if(!arrays[i].empty()){
            pq.push(Element{arrays[i][0], i, 0});
        }
    }
    std::vector<int> result;
    while(!pq.empty()){
        Element current = pq.top();
        pq.pop();
        result.push_back(current.value);
        if(current.index + 1 < arrays[current.array].size()){
            pq.push(Element{arrays[current.array][current.index + 1], current.array, current.index + 1});
        }
    }
    return result;
}

int calculateHeight(TreeNode* node){
    if(!node) return 0;
    int leftHeight = calculateHeight(node->left);
    int rightHeight = calculateHeight(node->right);
    node->balanceFactor = leftHeight - rightHeight;
    return 1 + std::max(leftHeight, rightHeight);
}

void setBalanceFactors(TreeNode* root){
    calculateHeight(root);
}

void invertTree(TreeNode* root){
    if(!root) return;
    TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;
    invertTree(root->left);
    invertTree(root->right);
}