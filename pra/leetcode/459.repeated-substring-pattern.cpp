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

class Solution1 { //对半砍就行   错误!
public:
    bool repeatedSubstringPattern(string s) {
        int i = 1 , prefix_len = 0 , ss = s.size();

        if ((ss%2)!=0) return false;
        int base = ss/2;
        string left = s.substr(0,base),right = s.substr(base);
        if (left == right) return true;

        return false;
    }
};

class Solution2 { //这不就是kmp的next数组？？ ESAY!
public:
    bool repeatedSubstringPattern(string s) {
        int i = 1, prefix_len = 0, ss = s.size();

        vector<int> next(ss, 0);
        if (ss <= 1) return false;
        while (i < ss) {
            if (s[i] == s[prefix_len]) {
                prefix_len++;
                next[i] = prefix_len;
                i++;
            } else {
                if (prefix_len == 0) {
                    next[i] = 0;
                    i++;
                } else {
                    prefix_len = next[prefix_len - 1];
                }
            }
        }
        int last_next = next.back();
        if (last_next > 0 && ss % (ss - last_next) == 0) {
            return true;
        }
        return false;
    }
};




int main() {
    Solution2 s;
    bool res = s.repeatedSubstringPattern("asassas");
    cout << res << endl;
}
