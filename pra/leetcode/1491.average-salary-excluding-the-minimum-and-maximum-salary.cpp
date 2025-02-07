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
    double average(std::vector<int>& salary) {
        std::sort(salary.begin(), salary.end());
        int sum = std::accumulate(salary.begin() + 1, salary.end() - 1, 0);
        return static_cast<double>(sum) / (salary.size() - 2);
    }
};


int main() {
    vector<int> nums = {4000,3000,1000,2000};
    Solution s;
    double a = s.average(nums);
    cout << a << endl;
}