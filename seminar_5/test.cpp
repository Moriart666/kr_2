#include "lib.hpp"
#include <gtest/gtest.h>

// Test TreeNode constructor
TEST(TreeNodeTest, Constructor) {
    TreeNode node(10);
    EXPECT_EQ(node.value, 10);
    EXPECT_EQ(node.left, nullptr);
    EXPECT_EQ(node.right, nullptr);
}

// Test BinaryTree buildFromArray and levelOrderTraversal
TEST(BinaryTreeTest, BuildFromArray) {
    BinaryTree bt;
    std::vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    bt.buildFromArray(arr);

    testing::internal::CaptureStdout();
    bt.levelOrderTraversal();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Обход дерева в ширину: 1 2 3 4 5 6 7 \n");
}

// Test BinaryTree isSymmetric
TEST(BinaryTreeTest, IsSymmetric) {
    BinaryTree bt1;
    std::vector<int> symmetricArr = {1, 2, 2, 3, 4, 4, 3};
    bt1.buildFromArray(symmetricArr);
    EXPECT_TRUE(bt1.isSymmetric());

    BinaryTree bt2;
    std::vector<int> asymmetricArr = {1, 2, 2, 3, 4, 5, 3};
    bt2.buildFromArray(asymmetricArr);
    EXPECT_FALSE(bt2.isSymmetric());
}

// Test BinaryTree minDepth
TEST(BinaryTreeTest, MinDepth) {
    BinaryTree bt1;
    std::vector<int> arr1 = {1, 2, 3, 4, 5};
    bt1.buildFromArray(arr1);
    EXPECT_EQ(bt1.minDepth(), 3);

    BinaryTree bt2;
    std::vector<int> arr2 = {1};
    bt2.buildFromArray(arr2);
    EXPECT_EQ(bt2.minDepth(), 1);

    BinaryTree bt3;
    std::vector<int> arr3 = {};
    bt3.buildFromArray(arr3);
    EXPECT_EQ(bt3.minDepth(), 0);
}

// Test BinarySearchTree buildFromArray, getMin, getMax, productMinMax
TEST(BinarySearchTreeTest, MinMaxProduct) {
    BinarySearchTree bst;
    std::vector<int> arr = {15, 10, 20, 8, 12, 17, 25, 6, 11, 16, 27};
    bst.buildFromArray(arr);

    EXPECT_EQ(bst.getMin(), 6);
    EXPECT_EQ(bst.getMax(), 27);
    EXPECT_EQ(bst.productMinMax(), 162);
}

// Test BinarySearchTree levelOrderTraversal and inOrder
TEST(BinarySearchTreeTest, Traversals) {
    BinarySearchTree bst;
    std::vector<int> arr = {15, 10, 20, 8, 12, 17, 25, 6, 11, 16, 27};
    bst.buildFromArray(arr);

    testing::internal::CaptureStdout();
    bst.levelOrderTraversal();
    std::string output1 = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output1, "Обход дерева в ширину: 15 10 20 8 12 17 25 6 11 16 27 \n");

    testing::internal::CaptureStdout();
    bst.inOrder();
    std::string output2 = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output2, "In-Order Traversal: 6 8 10 11 12 15 16 17 20 25 27 \n");
}

// Test areIdentical function
TEST(IdenticalTest, AreIdentical) {
    BinarySearchTree bst1;
    std::vector<int> arr1 = {15, 10, 20, 8, 12, 17, 25, 6, 11, 16, 27};
    bst1.buildFromArray(arr1);

    BinarySearchTree bst2;
    std::vector<int> arr2 = {15, 10, 20, 8, 12, 17, 25, 6, 11, 16, 27};
    bst2.buildFromArray(arr2);

    BinarySearchTree bst3;
    std::vector<int> arr3 = {15, 10, 20, 8, 12, 17, 25, 6, 11, 16, 28};
    bst3.buildFromArray(arr3);

    BinarySearchTree emptyBST1;
    BinarySearchTree emptyBST2;

    EXPECT_TRUE(areIdentical(bst1.getRoot(), bst2.getRoot()));
    EXPECT_FALSE(areIdentical(bst1.getRoot(), bst3.getRoot()));
    EXPECT_TRUE(areIdentical(emptyBST1.getRoot(), emptyBST2.getRoot()));
}

// Test BinarySearchTree productMinMax on empty tree
TEST(BinarySearchTreeTest, ProductMinMaxEmpty) {
    BinarySearchTree bst;
    EXPECT_THROW(bst.productMinMax(), std::runtime_error);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}