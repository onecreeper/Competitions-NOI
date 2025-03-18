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
        vector<int> findAnagrams(string s, string p) {
            vector<int> counted(26, 0);
            vector<int> toFind(26, 0);
            vector<int> res;
            int n = s.size();
            int m = p.size();
            
            if (n < m) return res;
    
            for (auto i : p) toFind[int(i) - int('a')]++;
            for (int i = 0; i < m; ++i) {
                counted[int(s[i]) - int('a')]++;
            }
            if (counted == toFind) res.push_back(0);
            for (int i = m; i < n; ++i) {
                counted[int(s[i]) - int('a')]++;
                counted[int(s[i - m]) - int('a')]--;
                if (counted == toFind) {
                    res.push_back(i - m + 1);
                }
            }
            
            return res;
        }
    };


int main() {
    Solution s;
    vector<int> res = s.findAnagrams("cbaebabacd","abc");
    for (auto i : res) cout << i;    
}



// int main() {
//     vector<type> nums = {9,9,9,9};
//     Solution1 s;
//     type a = s.method(nums);
//     cout << a << endl;
// }