#include "lib.hpp"
#include <gtest/gtest.h>

// Tests for isHeap
TEST(IsHeapTest, EmptyArray) {
    std::vector<int> arr;
    EXPECT_TRUE(isHeap(arr));
}

TEST(IsHeapTest, SingleElement) {
    std::vector<int> arr = {10};
    EXPECT_TRUE(isHeap(arr));
}

TEST(IsHeapTest, MinHeap) {
    std::vector<int> arr = {1, 3, 5, 7, 9, 11};
    EXPECT_TRUE(isHeap(arr));
}

TEST(IsHeapTest, MaxHeap) {
    std::vector<int> arr = {10, 9, 8, 7, 6, 5};
    EXPECT_TRUE(isHeap(arr));
}

TEST(IsHeapTest, NotHeap) {
    std::vector<int> arr = {10, 5, 8, 3, 15};
    EXPECT_FALSE(isHeap(arr));
}

// Tests for mergeKSortedArrays
TEST(MergeKSortedArraysTest, EmptyArrays) {
    std::vector<std::vector<int>> arrays;
    std::vector<int> expected;
    EXPECT_EQ(mergeKSortedArrays(arrays), expected);
}

TEST(MergeKSortedArraysTest, SingleArray) {
    std::vector<std::vector<int>> arrays = {{1, 2, 3}};
    std::vector<int> expected = {1, 2, 3};
    EXPECT_EQ(mergeKSortedArrays(arrays), expected);
}

TEST(MergeKSortedArraysTest, MultipleArrays) {
    std::vector<std::vector<int>> arrays = {
        {1, 4, 7},
        {2, 5, 8},
        {3, 6, 9}
    };
    std::vector<int> expected = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    EXPECT_EQ(mergeKSortedArrays(arrays), expected);
}

TEST(MergeKSortedArraysTest, ArraysWithDifferentSizes) {
    std::vector<std::vector<int>> arrays = {
        {1, 5, 9},
        {2, 3, 7, 10},
        {4, 6, 8}
    };
    std::vector<int> expected = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    EXPECT_EQ(mergeKSortedArrays(arrays), expected);
}

// Helper function to create a TreeNode
TreeNode* createNode(int value) {
    TreeNode* node = new TreeNode{value, nullptr, nullptr, 0};
    return node;
}

// Tests for setBalanceFactors
TEST(SetBalanceFactorsTest, EmptyTree) {
    TreeNode* root = nullptr;
    setBalanceFactors(root);
    EXPECT_EQ(root, nullptr);
}

TEST(SetBalanceFactorsTest, SingleNode) {
    TreeNode* root = createNode(10);
    setBalanceFactors(root);
    EXPECT_EQ(root->balanceFactor, 0);
    delete root;
}

TEST(SetBalanceFactorsTest, BalancedTree) {
    TreeNode* root = createNode(10);
    root->left = createNode(5);
    root->right = createNode(15);
    setBalanceFactors(root);
    EXPECT_EQ(root->balanceFactor, 0);
    EXPECT_EQ(root->left->balanceFactor, 0);
    EXPECT_EQ(root->right->balanceFactor, 0);
    delete root->left;
    delete root->right;
    delete root;
}

TEST(SetBalanceFactorsTest, UnbalancedTree) {
    TreeNode* root = createNode(10);
    root->left = createNode(5);
    root->left->left = createNode(2);
    setBalanceFactors(root);
    EXPECT_EQ(root->balanceFactor, 2);
    EXPECT_EQ(root->left->balanceFactor, 1);
    EXPECT_EQ(root->left->left->balanceFactor, 0);
    delete root->left->left;
    delete root->left;
    delete root;
}

// Tests for invertTree
TEST(InvertTreeTest, EmptyTree) {
    TreeNode* root = nullptr;
    invertTree(root);
    EXPECT_EQ(root, nullptr);
}

TEST(InvertTreeTest, SingleNode) {
    TreeNode* root = createNode(10);
    invertTree(root);
    EXPECT_EQ(root->left, nullptr);
    EXPECT_EQ(root->right, nullptr);
    delete root;
}

TEST(InvertTreeTest, InvertBalancedTree) {
    TreeNode* root = createNode(10);
    root->left = createNode(5);
    root->right = createNode(15);
    invertTree(root);
    EXPECT_EQ(root->left->value, 15);
    EXPECT_EQ(root->right->value, 5);
    delete root->left;
    delete root->right;
    delete root;
}

TEST(InvertTreeTest, InvertUnbalancedTree) {
    TreeNode* root = createNode(10);
    root->left = createNode(5);
    root->left->left = createNode(2);
    invertTree(root);
    EXPECT_EQ(root->left->value, 5);
    EXPECT_EQ(root->right, nullptr);
    EXPECT_EQ(root->left->left, nullptr);
    EXPECT_EQ(root->left->right->value, 2);
    delete root->left->right;
    delete root->left;
    delete root;
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}