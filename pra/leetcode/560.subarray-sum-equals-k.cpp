// 万能头文件
// #include <bits/stdc++.h>  //导致无提示
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <deque>
#include <list>
#include <numeric>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <bitset>
#include <functional>
#include <utility>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <iterator>
#include <tuple>
#include <limits>
#include <ctime>
#include <random>
#include <chrono>


using namespace std;

// 给你一个整数数组 nums 和一个整数 k ，请你统计并返回 该数组中和为 k 的子数组的个数 。

// 子数组是数组中元素的连续非空序列。

// 例 1：

// 输入：nums = [1,1,1], k = 2
// 输出：2
// 示例 2：

// 输入：nums = [1,2,3], k = 3
// 输出：2
 

class Solution1 {
    public:
        int subarraySum(vector<int>& nums, int k) {
            // 解法：前缀和 + 哈希表
            // 前缀合 : pre[i] = pre[i - 1] + nums[i] 即从第一个数字到当前数字的合
            int n = nums.size();
            vector<int> pre(n);
            int res = 0;
            // 计算前缀和
            pre[0] = nums[0];
            for (int i = 1; i < n; ++i){
                pre[i] = pre[i - 1] + nums[i];
            }
            // 需求 假设 i, j 是子串的开始和结束位置的索引，那么需要让 pre[j] - pre[i - 1] == k
            // 此时可以参考两数之和，创建哈希表
            // 哈希表记录前缀和出现的次数，键为前缀和，值为出现次数
            unordered_map<int, int> hashtable;
            hashtable[0] = 1; // 初始化前缀和0的出现次数为1，用于处理子数组从头开始的情况

            int count = 0;
            for (int i = 0; i < n; ++i) {
                int current_sum = pre[i];
                int target = current_sum - k; // 需要查找的前缀和
                
                // 如果存在前缀和等于target，则累加其出现次数
                count += hashtable[target];
                
                // 将当前前缀和加入哈希表，并更新出现次数
                hashtable[current_sum]++;
            }
            
            return count;
        }
    };

class Solution2 { //这是官解，优势：无需pre数组，pre 与 哈希表同步处理
    public:
        int subarraySum(vector<int>& nums, int k) {
            unordered_map<int, int> mp;
            mp[0] = 1;
            int count = 0, pre = 0;
            for (auto& x:nums) {
                pre += x;
                if (mp.find(pre - k) != mp.end()) {
                    count += mp[pre - k];
                }
                mp[pre]++;
            }
            return count;
        }
    };



int main() {
    Solution1 s1;
    vector<int> nums = {3,4,7,2,-3,1,5,2};
    int k = 7;
    int res = s1.subarraySum(nums,k);
    cout << res << endl;
}



// int main() {
//     vector<type> nums = {9,9,9,9};
//     Solution1 s;
//     type a = s.method(nums);
//     cout << a << endl;
// }