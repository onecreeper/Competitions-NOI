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

class Solution1 { //排序
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};

class Solution2 {  //计数(哈希表)
public:
    bool isAnagram(string s, string t) {
        // 如果两个字符串长度不同，直接返回 false
        if (s.length() != t.length()) {
            return false;
        }

        int charcounts[26] = {0};

        // 统计字符串 s 中每个字符的出现次数
        for (char ch : s) {
            charcounts[ch - 'a']++;
        }

        // 减去字符串 t 中每个字符的出现次数
        for (char ch : t) {
            charcounts[ch - 'a']--;
        }

        // 检查是否所有字符的计数都为 0
        for (int count : charcounts) {
            if (count != 0) {
                return false;
            }
        }

        return true;
    }
};


int main() {
    Solution1 s;
    bool res = s.isAnagram("aa","bb");
    cout << res << endl;
}
