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

// 给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。
// 返回 滑动窗口中的最大值 。
// 示例 1：
// 输入：nums = [1,3,-1,-3,5,3,6,7], k = 3
// 输出：[3,3,5,5,6,7]
// 解释：
// 滑动窗口的位置                最大值
// ---------------               -----
// [1  3  -1] -3  5  3  6  7       3
//  1 [3  -1  -3] 5  3  6  7       3
//  1  3 [-1  -3  5] 3  6  7       5
//  1  3  -1 [-3  5  3] 6  7       5
//  1  3  -1  -3 [5  3  6] 7       6
//  1  3  -1  -3  5 [3  6  7]      7
// 示例 2：
// 输入：nums = [1], k = 1
// 输出：[1]



class Solution1 { //没有脑子法
    public:
        vector<int> maxSlidingWindow(vector<int>& nums, int k) {
            vector<int> res;
            int s = nums.size();
            for (int i = 0; i < s - k + 1; ++i){
                int max = nums[i];
                for (int j = i;j < i + k;++j){
                    if (nums[j] > max){
                        max = nums[j];
                    }
                }
                res.push_back(max);
            }
            return res;
        }
    };

class Solution2 { //自己想出的队列
    public:
        vector<int> maxSlidingWindow(vector<int>& nums, int k){
            vector<int> result;
            deque<int> dq;  // 存储索引，队列中的索引对应的元素单调递减
            for (int i = 0; i < nums.size(); ++i) {
                // 移除队列中超出窗口的索引
                while (!dq.empty() && dq.front() <= i - k) {
                    dq.pop_front();
                }
                // 维护单调递减性：从队尾移除所有比当前元素小的索引
                while (!dq.empty() && nums[dq.back()] < nums[i]) {
                    dq.pop_back();
                }
                // 将当前索引加入队列
                dq.push_back(i);
                // 记录最大值
                if (i >= k - 1) {
                    result.push_back(nums[dq.front()]);
                }
            }
            return result;
        }
    };

    
    

int main(){
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    Solution1 s;
    vector<int> res = s.maxSlidingWindow(nums,k);
    for (auto i : res) cout << i;
}