#include "lib.hpp"
#include <gtest/gtest.h>
#include <vector>
#include <stdexcept>

TEST(PrefixSumTest, GetSumValidIndices) {
    std::vector<int> arr = {1, 2, 3, 4, 5};
    PrefixSum ps(arr);
    EXPECT_EQ(ps.getSum(0, 2), 6);
    EXPECT_EQ(ps.getSum(1, 3), 9);
    EXPECT_EQ(ps.getSum(0, 4), 15);
}

TEST(PrefixSumTest, GetSumInvalidIndices) {
    std::vector<int> arr = {1, 2, 3};
    PrefixSum ps(arr);
    EXPECT_THROW(ps.getSum(-1, 2), std::out_of_range);
    EXPECT_THROW(ps.getSum(1, 3), std::out_of_range);
    EXPECT_THROW(ps.getSum(2, 1), std::out_of_range);
}

TEST(NextPowerOfTwoTest, VariousInputs) {
    EXPECT_EQ(nextPowerOfTwo(1), 1);
    EXPECT_EQ(nextPowerOfTwo(2), 2);
    EXPECT_EQ(nextPowerOfTwo(3), 4);
    EXPECT_EQ(nextPowerOfTwo(5), 8);
    EXPECT_EQ(nextPowerOfTwo(16), 16);
    EXPECT_EQ(nextPowerOfTwo(17), 32);
    EXPECT_EQ(nextPowerOfTwo(0), 1);
    EXPECT_EQ(nextPowerOfTwo(-5), 1);
}

TEST(ExtendToPowerOfTwoTest, VariousSizes) {
    std::vector<int> arr1 = {1, 2, 3};
    std::vector<int> expected1 = {1, 2, 3, 0};
    EXPECT_EQ(extendToPowerOfTwo(arr1), expected1);
    
    std::vector<int> arr2 = {4, 5, 6, 7};
    std::vector<int> expected2 = {4, 5, 6, 7};
    EXPECT_EQ(extendToPowerOfTwo(arr2), expected2);
    
    std::vector<int> arr3 = {};
    std::vector<int> expected3 = {0};
    EXPECT_EQ(extendToPowerOfTwo(arr3), expected3);
}

TEST(FindRotationIndexTest, WithRotationIndex) {
    std::vector<int> arr = {9, 4, 8, 7, 1, 11, 2, 6, 1};
    EXPECT_EQ(findRotationIndex(arr), 3);
}

TEST(FindRotationIndexTest, WithoutRotationIndex) {
    std::vector<int> arr = {1, 2, 3, 4, 5};
    EXPECT_EQ(findRotationIndex(arr), -1);
}

TEST(MaxSubarraySumKTest, ValidK) {
    std::vector<int> arr = {1, 4, 2, 10, 23, 3, 1, 0, 20};
    EXPECT_EQ(maxSubarraySumK(arr, 4), 36);
    
    std::vector<int> arr2 = {2, 3, 4, 1, 5};
    EXPECT_EQ(maxSubarraySumK(arr2, 2), 7);
}

TEST(MaxSubarraySumKTest, InvalidK) {
    std::vector<int> arr = {1, 2, 3};
    EXPECT_THROW(maxSubarraySumK(arr, 4), std::invalid_argument);
    EXPECT_THROW(maxSubarraySumK(arr, 0), std::invalid_argument);
    EXPECT_THROW(maxSubarraySumK(arr, -1), std::invalid_argument);
}

TEST(MaxEqualSumSubarrayTest, MatchingSubarrays) {
    std::vector<int> arr1 = {1, 2, 3, 4, 5, 6};
    std::vector<int> arr2 = {1, 2, 3, 4, 5, 6};
    EXPECT_EQ(maxEqualSumSubarray(arr1, arr2), 6);
    
    std::vector<int> arr3 = {0, 0, 0, 0};
    std::vector<int> arr4 = {0, 0, 0, 0};
    EXPECT_EQ(maxEqualSumSubarray(arr3, arr4), 4);
    
    std::vector<int> arr5 = {1, 2, 3, 0, 3};
    std::vector<int> arr6 = {1, 2, 1, 0, 4};
    EXPECT_EQ(maxEqualSumSubarray(arr5, arr6), 3);
}

TEST(MaxEqualSumSubarrayTest, NoMatchingSubarrays) {
    std::vector<int> arr1 = {1, 2, 3};
    std::vector<int> arr2 = {4, 5, 6};
    EXPECT_EQ(maxEqualSumSubarray(arr1, arr2), 0);
}

TEST(MaxEqualSumSubarrayTest, DifferentLengths) {
    std::vector<int> arr1 = {1, 2, 3};
    std::vector<int> arr2 = {1, 2};
    EXPECT_THROW(maxEqualSumSubarray(arr1, arr2), std::invalid_argument);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}