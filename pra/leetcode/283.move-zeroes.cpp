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
    void moveZeroes(vector<int>& nums) {
        int n_size = nums.size();
        vector<int> zero_index;
        for (int i = 0; i<n_size; i++){
            if (nums[i] != 0) zero_index.push_back(i);
        } 
        // for (int j : zero_index) cout << j << endl;
        int zero_index_size = zero_index.size();
        for (int k = 0;k < n_size; k++){
            if (k + 1 > zero_index_size){
                nums[k] = 0;
            }
            else{
                nums[k] = nums[zero_index[k]];
            }

        }


    }
};

class Solution2 {  //双指针
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size(), left = 0, right = 0;
        while (right < n) {
            if (nums[right]) {
                swap(nums[left], nums[right]);
                left++;
            }
            right++;
        }
    }
};



int main() {
    vector<int> nums = {1,5,3,0,1,65,0,0,0,1,0,5,6};
    Solution2 s;
    s.moveZeroes(nums);
    for (int i : nums) cout << i << endl;
}
