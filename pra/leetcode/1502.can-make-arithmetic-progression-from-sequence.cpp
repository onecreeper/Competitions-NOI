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
    bool canMakeArithmeticProgression(vector<int>& arr) {
        int s = arr.size();
        sort(arr.begin(),arr.end());
        if (s == 2) return true;
        if (s <= 1) return false;
        int d = arr[1] - arr[0];
        for (int i = 2;i < s; i++){
            if (arr[i] - arr[i - 1] != d) return false;
        }
        return true;
    }
};


int main() {
    vector<int> nums = {9,9,9,9};
    Solution1 s;
    bool a = s.canMakeArithmeticProgression(nums);
    cout << a << endl;
}

