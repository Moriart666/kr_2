#include "lib.hpp"
#include <unordered_map>

PrefixSum::PrefixSum(const std::vector<int>& arr) {
    int n = arr.size();
    prefix.resize(n + 1, 0);
    for(int i = 0; i < n; ++i) {
        prefix[i + 1] = prefix[i] + arr[i];
    }
}

long long PrefixSum::getSum(int l, int r) const {
    if(l < 0 || r >= static_cast<int>(prefix.size()) - 1 || l > r) {
        throw std::out_of_range("Invalid indices");
    }
    return prefix[r + 1] - prefix[l];
}

int nextPowerOfTwo(int n) {
    if(n <= 0) return 1;
    if((n & (n - 1)) == 0) return n;
    int power = 1;
    while(power < n) {
        power <<= 1;
    }
    return power;
}

std::vector<int> extendToPowerOfTwo(const std::vector<int>& arr) {
    int originalSize = arr.size();
    int newSize = nextPowerOfTwo(originalSize);
    std::vector<int> extendedArr(newSize, 0);
    for(int i = 0; i < originalSize; ++i) {
        extendedArr[i] = arr[i];
    }
    return extendedArr;
}

int findRotationIndex(const std::vector<int>& arr) {
    long long total_sum = 0;
    for(auto num : arr) {
        total_sum += num;
    }
    long long left_sum = 0;
    for(int i = 0; i < static_cast<int>(arr.size()); ++i) {
        long long right_sum = total_sum - left_sum - arr[i];
        if(left_sum == right_sum) {
            return i;
        }
        left_sum += arr[i];
    }
    return -1;
}

long long maxSubarraySumK(const std::vector<int>& arr, int k) {
    int n = arr.size();
    if(k > n || k <= 0) {
        throw std::invalid_argument("Invalid k");
    }
    long long current_sum = 0;
    for(int i = 0; i < k; ++i) {
        current_sum += arr[i];
    }
    long long max_sum = current_sum;
    for(int i = k; i < n; ++i) {
        current_sum += arr[i] - arr[i - k];
        if(current_sum > max_sum) {
            max_sum = current_sum;
        }
    }
    return max_sum;
}

int maxEqualSumSubarray(const std::vector<int>& arr1, const std::vector<int>& arr2) {
    if(arr1.size() != arr2.size()) {
        throw std::invalid_argument("Arrays must be of same length");
    }
    int n = arr1.size();
    std::vector<int> diff(n, 0);
    for(int i = 0; i < n; ++i) {
        diff[i] = arr1[i] - arr2[i];
    }
    std::unordered_map<long long, int> sum_map;
    long long cumulative_sum = 0;
    int max_len = 0;
    for(int i = 0; i < n; ++i) {
        cumulative_sum += diff[i];
        if(cumulative_sum == 0) {
            max_len = i + 1;
        }
        if(sum_map.find(cumulative_sum) != sum_map.end()) {
            int prev_index = sum_map[cumulative_sum];
            if((i - prev_index) > max_len) {
                max_len = i - prev_index;
            }
        } else {
            sum_map[cumulative_sum] = i;
        }
    }
    return max_len;
}