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


class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        // 如果数组长度小于3，无法组成三角形，返回0
        if (nums.size() < 3) return 0;

        // 将数组按从大到小排序
        sort(nums.begin(), nums.end(), greater<int>());

        // 遍历数组，检查每个三元组是否满足三角形条件
        for (int i = 0; i < nums.size() - 2; i++) {
            // 检查三角形不等式：nums[i+1] + nums[i+2] > nums[i]
            if (nums[i+1] + nums[i+2] > nums[i]) {
                // 如果满足条件，返回周长
                return nums[i] + nums[i+1] + nums[i+2];
            }
        }

        // 如果没有找到满足条件的三元组，返回0
        return 0;
    }
};


int main() {
    vector<int> nums = {1,2,1,10};
    Solution s;
    int a = s.largestPerimeter(nums);
    cout << a << endl;
}