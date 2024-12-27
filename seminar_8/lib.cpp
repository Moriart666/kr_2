#include "lib.hpp"
#include <algorithm>
#include <vector>
#include <string>
#include <climits>

TreeNode::TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

long long countBinarySequences(int N) {
    if (N == 0) return 0;
    if (N == 1) return 2;
    std::vector<std::vector<long long>> dp(N + 1, std::vector<long long>(2, 0));
    dp[1][0] = 1;
    dp[1][1] = 1;
    for (int i = 2; i <= N; ++i) {
        dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
        dp[i][1] = dp[i - 1][0];
    }
    return dp[N][0] + dp[N][1];
}

int longestIncreasingSubsequence(const std::vector<int>& nums) {
    if (nums.empty()) return 0;
    std::vector<int> dp(nums.size(), 1);
    for (size_t i = 1; i < nums.size(); ++i) {
        for (size_t j = 0; j < i; ++j) {
            if (nums[i] > nums[j]) {
                dp[i] = std::max(dp[i], dp[j] + 1);
            }
        }
    }
    return *std::max_element(dp.begin(), dp.end());
}

int longestIncreasingSubsequenceOptimized(const std::vector<int>& nums) {
    std::vector<int> tails;
    for (int num : nums) {
        auto it = std::lower_bound(tails.begin(), tails.end(), num);
        if (it == tails.end()) {
            tails.push_back(num);
        } else {
            *it = num;
        }
    }
    return tails.size();
}

int maxPathSumHelper(TreeNode* root, int& globalMax) {
    if (root == nullptr) return 0;
    int leftMax = std::max(0, maxPathSumHelper(root->left, globalMax));
    int rightMax = std::max(0, maxPathSumHelper(root->right, globalMax));
    globalMax = std::max(globalMax, leftMax + rightMax + root->val);
    return std::max(leftMax, rightMax) + root->val;
}

int maxPathSum(TreeNode* root) {
    int globalMax = INT_MIN;
    maxPathSumHelper(root, globalMax);
    return globalMax;
}

int maxProfit(const std::vector<int>& prices) {
    if (prices.empty()) return 0;
    int minPrice = prices[0];
    int maxProf = 0;
    for (size_t i = 1; i < prices.size(); ++i) {
        if (prices[i] < minPrice) {
            minPrice = prices[i];
        } else {
            maxProf = std::max(maxProf, prices[i] - minPrice);
        }
    }
    return maxProf;
}

std::string longestPalindromicSubstring(const std::string& s) {
    if (s.empty()) return "";
    int start = 0, maxLen = 1;
    for (size_t i = 0; i < s.size(); ++i) {
        int left = i, right = i;
        while (left >=0 && right < s.size() && s[left] == s[right]) {
            if ((right - left + 1) > maxLen) {
                start = left;
                maxLen = right - left + 1;
            }
            if (left == 0) break;
            left--;
            right++;
        }
        left = i;
        right = i + 1;
        while (left >=0 && right < s.size() && s[left] == s[right]) {
            if ((right - left + 1) > maxLen) {
                start = left;
                maxLen = right - left + 1;
            }
            if (left == 0) break;
            left--;
            right++;
        }
    }
    return s.substr(start, maxLen);
}

int coinChange(const std::vector<int>& coins, int amount) {
    std::vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;
    for (int i = 1; i <= amount; ++i) {
        for (const int& coin : coins) {
            if (coin <= i) {
                dp[i] = std::min(dp[i], dp[i - coin] + 1);
            }
        }
    }
    return dp[amount] > amount ? -1 : dp[amount];
}