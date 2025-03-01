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
    int countOdds(int low, int high) {
        return (high+1)/2 - low/2;
    }
};



// int main() {
//     // Solution s;
//     // type res = s.method();
//     // cout << res << endl;
// }



int main() {
    // vector<type> nums = {9,9,9,9};
    Solution s;
    int a = s.countOdds(3,10);
    cout << a << endl;
}