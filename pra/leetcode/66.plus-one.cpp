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
    vector<int> plusOne(vector<int>& digits) {
        int digits_size = digits.size();
        digits[digits_size - 1] += 1;
        for (int i = digits_size - 1; i >= 0 ; i--){
            if (digits[i] == 10){
                digits[i] = 0;
                
                if (i == 0){
                    digits.insert(digits.begin(), 1);
                }
                else{
                    digits[i - 1] += 1;
                }
            } 
        }
        return digits;
    }
};

// class Solution2 {  //变成数字就行了哈哈哈 error懒得改
// public:
//     vector<int> plusOne(vector<int>& digits) {
//         for (int i = digits.size() - 1; i >= 0; --i) {
//             if (digits[i] < 9) {
//                 digits[i]++;
//                 return digits;
//             }
//             digits[i] = 0;
//         }
//         digits.insert(digits.begin(), 1);
//         return digits;
//     }
// };


int main() {
    vector<int> nums = {9,9,9,8};
    Solution1 s;
    s.plusOne(nums);
    for (int i : nums) cout << i << endl;
}
