#pragma once
#include <vector>
#include <stdexcept>

class PrefixSum {
private:
    std::vector<long long> prefix;
public:
    PrefixSum(const std::vector<int>& arr);
    long long getSum(int l, int r) const;
};

int nextPowerOfTwo(int n);
std::vector<int> extendToPowerOfTwo(const std::vector<int>& arr);
int findRotationIndex(const std::vector<int>& arr);
long long maxSubarraySumK(const std::vector<int>& arr, int k);
int maxEqualSumSubarray(const std::vector<int>& arr1, const std::vector<int>& arr2);
