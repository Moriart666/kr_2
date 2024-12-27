#include "lib.hpp"
#include <gtest/gtest.h>

// Тесты для countBinarySequences
TEST(CountBinarySequencesTest, BasicTests) {
    EXPECT_EQ(countBinarySequences(0), 0);
    EXPECT_EQ(countBinarySequences(1), 2);
    EXPECT_EQ(countBinarySequences(2), 3);
    EXPECT_EQ(countBinarySequences(3), 5);
    EXPECT_EQ(countBinarySequences(4), 8);
}

// Тесты для longestIncreasingSubsequence
TEST(LongestIncreasingSubsequenceTest, BasicTests) {
    std::vector<int> nums1 = {3, 2, 8, 9, 5, 10};
    EXPECT_EQ(longestIncreasingSubsequence(nums1), 4);
    std::vector<int> nums2 = {1, 2, 7, 9, 0, 10};
    EXPECT_EQ(longestIncreasingSubsequence(nums2), 4);
    std::vector<int> nums3 = {8, 8, 8, 8};
    EXPECT_EQ(longestIncreasingSubsequence(nums3), 1);
    std::vector<int> nums4 = {};
    EXPECT_EQ(longestIncreasingSubsequence(nums4), 0);
}

// Тесты для longestIncreasingSubsequenceOptimized
TEST(LongestIncreasingSubsequenceOptimizedTest, BasicTests) {
    std::vector<int> nums1 = {3, 2, 8, 9, 5, 10};
    EXPECT_EQ(longestIncreasingSubsequenceOptimized(nums1), 4);
    std::vector<int> nums2 = {1, 2, 7, 9, 0, 10};
    EXPECT_EQ(longestIncreasingSubsequenceOptimized(nums2), 4);
    std::vector<int> nums3 = {8, 8, 8, 8};
    EXPECT_EQ(longestIncreasingSubsequenceOptimized(nums3), 1);
    std::vector<int> nums4 = {};
    EXPECT_EQ(longestIncreasingSubsequenceOptimized(nums4), 0);
}

// Тесты для maxPathSum
TEST(MaxPathSumTest, BasicTests) {
    TreeNode* root1 = new TreeNode(10);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(10);
    root1->left->left = new TreeNode(20);
    root1->left->right = new TreeNode(1);
    root1->right->right = new TreeNode(-25);
    root1->right->right->left = new TreeNode(3);
    root1->right->right->right = new TreeNode(4);
    EXPECT_EQ(maxPathSum(root1), 42);
    // Освобождение памяти
    delete root1->right->right->left;
    delete root1->right->right->right;
    delete root1->right->right;
    delete root1->right;
    delete root1->left->left;
    delete root1->left->right;
    delete root1->left;
    delete root1;
}

// Тесты для maxProfit
TEST(MaxProfitTest, BasicTests) {
    std::vector<int> prices1 = {3, 2, 8, 9, 5, 10};
    EXPECT_EQ(maxProfit(prices1), 8);
    std::vector<int> prices2 = {7, 1, 5, 3, 6, 4};
    EXPECT_EQ(maxProfit(prices2), 5);
    std::vector<int> prices3 = {7, 6, 4, 3, 1};
    EXPECT_EQ(maxProfit(prices3), 0);
    std::vector<int> prices4 = {};
    EXPECT_EQ(maxProfit(prices4), 0);
}

// Тесты для longestPalindromicSubstring
TEST(LongestPalindromicSubstringTest, BasicTests) {
    EXPECT_EQ(longestPalindromicSubstring("babad"), "bab"); // Или "aba"
    EXPECT_EQ(longestPalindromicSubstring("cbbd"), "bb");
    EXPECT_EQ(longestPalindromicSubstring("a"), "a");
    EXPECT_EQ(longestPalindromicSubstring("ac"), "a"); // Или "c"
    EXPECT_EQ(longestPalindromicSubstring(""), "");
}

// Тесты для coinChange
TEST(CoinChangeTest, BasicTests) {
    std::vector<int> coins1 = {1, 2, 5};
    EXPECT_EQ(coinChange(coins1, 11), 3);
    std::vector<int> coins2 = {2};
    EXPECT_EQ(coinChange(coins2, 3), -1);
    std::vector<int> coins3 = {1};
    EXPECT_EQ(coinChange(coins3, 0), 0);
    std::vector<int> coins4 = {1};
    EXPECT_EQ(coinChange(coins4, 1), 1);
    std::vector<int> coins5 = {1, 3, 4, 5};
    EXPECT_EQ(coinChange(coins5, 7), 2); // 3 + 4
}

// Главная функция для запуска тестов
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}