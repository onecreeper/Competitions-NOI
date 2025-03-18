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
            vector<int> counted(26,0);
            vector<int> toFind(26,0);
            vector<int> res;
            int n = s.size();
            int m = p.size();
            bool isTarget = true;

            for(auto i : p) toFind[int(i) - int('a')] = i;

            for (int i = 0; i < n;++i){
                isTarget = true;

                for(int j = i; j < n;++j){
                    if ((toFind[int(j) - int('a')] == 0) || (j - i > m) || isTarget == false) break;
                    ++counted[int(j) - int('a')];
                    if (toFind[int(j) - int('a')] == counted[int(j) - int('a')]){
                        for(int k = 0;k < 26;++k){
                            if(toFind[k] != counted[k]){
                                isTarget = false;
                                break;
                            }
                        } 
                    }
                }

                if (isTarget == true) res.push_back(i);
            }
            return res;
    }
};


class Solution2 {
    public:
        vector<int> findAnagrams(string s, string p) {
            vector<int> toFind(26,0);
            vector<int> res;
            int n = s.size() , m = p.size();
            for (auto i : p) ++toFind[int(i) - int('a')]; 
            for (int i = 0 ; i <= n - m; ++i){
                vector<int> counted(26,0);
                for (int j = i ; j < i + m ; ++j){
                    ++counted[int(s[j]) - int('a')];
                }
                if (counted == toFind) res.push_back(i);
            }
            return res;    
    }
};

int main() {
    Solution2 s;
    vector<int> res = s.findAnagrams("cbaebabacd","abc");
    for (auto i : res) cout << i;    
}



// int main() {
//     vector<type> nums = {9,9,9,9};
//     Solution1 s;
//     type a = s.method(nums);
//     cout << a << endl;
// }