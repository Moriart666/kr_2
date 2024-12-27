#pragma once
#include <vector>
#include <string>
#include <climits>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x);
};

long long countBinarySequences(int N);
int longestIncreasingSubsequence(const std::vector<int>& nums);
int longestIncreasingSubsequenceOptimized(const std::vector<int>& nums);
int maxPathSum(TreeNode* root);
int maxProfit(const std::vector<int>& prices);
std::string longestPalindromicSubstring(const std::string& s);
int coinChange(const std::vector<int>& coins, int amount);
