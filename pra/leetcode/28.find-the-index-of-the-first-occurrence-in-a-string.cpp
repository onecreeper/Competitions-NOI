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

class Solution1
{ // 自带功能你不用？？？？
public:
    int strStr(string haystack, string needle)
    {
        size_t pos = haystack.find(needle);
        if (pos != string::npos)
        {
            return int(pos);
        }
        else
        {
            return -1;
        }
    }
};

class Solution2
{ // 暴力匹配
public:
    int strStr(string haystack, string needle)
    {
        int sh = haystack.size(), sn = needle.size();
        for (int i = 0; i + sn <= sh; i++)
        {
            bool flag = true;
            for (int j = 0; j < sn; j++)
            {
                if (haystack[j + i] != needle[j])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                return i;
            }
        }
        return -1;
    }
};

class Solution3
{ // KMP算法
public:
    int strStr(string haystack, string needle)
    {
        int hs = haystack.size(), ns = needle.size();
        if (ns == 0) return 0;
        if (ns > hs) return -1;
        // next 数组计算   abab 0012
        vector<int> next(ns, 0);
        int prefix_len = 0, i = 1;
        while (i < ns)
        {
            if (needle[prefix_len] == needle[i])
            {
                prefix_len++;
                next[i] = prefix_len;
                i++;
            }
            else
            {
                if (prefix_len == 0)
                {
                    next[i] = 0;
                    i++;
                }
                else
                {
                    prefix_len = next[prefix_len - 1];
                }
            }
        }

        // kmp搜索
        i = 0; // 重置 i 的值
        int j = 0;
        while (i < hs)
        {
            if (haystack[i] == needle[j])
            {
                j++;
                i++;
            }
            else if (j > 0)
            {
                j = next[j - 1];
            }
            else
            {
                i++;
            }
            if (j == ns) return i - j;
        }
        return -1;
    }
};

int main()
{
    Solution3 s;
    int res = s.strStr("aaaaaaaab", "aab");
    cout << res << endl;
}
