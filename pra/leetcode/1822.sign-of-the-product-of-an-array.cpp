// 万能头文件
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


class Solution1 {
public:
    int arraySign(vector<int>& nums) {  //相乘如果数据过大会溢出
        int res = nums[0];
        for (int i = 1; i < nums.size();i++){
            res *= nums[i];
        }
        if (res > 0) return 1;
        if (res == 0) return 0;
        return -1;
    }
};

class Solution2 {
public:
    int arraySign(vector<int>& nums) {  
        int res = 1;
        for (int i : nums){
            if (i == 0) return 0;
            if (i < 0) res *= -1;
        }
        return res;
    }
};


int main() {
    vector<int> nums = {-1,5,3,1,65,1,5,-6};
    Solution2 s;
    int res = s.arraySign(nums);
    cout << res << endl;
}