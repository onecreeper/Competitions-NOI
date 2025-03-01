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
    bool isMonotonic(vector<int>& nums) {
        int nums_size = nums.size();
        if (nums_size <= 2 && nums_size > 0) return true;
        if (nums_size <= 0) return false;
        //获取特征1
        int spec = 0; //1为增，0为减
        for (int i = 1;i < nums_size; i++){
            if (nums[i] != nums[i - 1]){
                spec = nums[i] > nums[i - 1];
                break;
            }
        }
        //通过特征进行一次判断
        for (int j = 1;j < nums_size; j++){
            if ((nums[j] != nums[j - 1])&&(spec != (nums[j] > nums[j - 1]))) return false;
        }
        return true;
    }
};


int main() {
    vector<int> nums = {1,2,3,2};
    Solution1 s;
    bool res = s.isMonotonic(nums);
    cout << res << endl;
}