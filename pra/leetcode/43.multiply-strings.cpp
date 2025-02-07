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

class Solution { //数大就废掉了
public:
    string multiply(string num1, string num2) {
        int num1_i = 0 ,num2_i = 0;
        for (int i = num1.size() - 1; i >= 0;i--)
        {
            num1_i += (static_cast<int>(num1[i]) - 48) * static_cast<int>(pow(10,num1.size() - 1 - i));
        }
        for (int i = num2.size() - 1; i >= 0;i--)
        {
            num2_i += (static_cast<int>(num2[i]) - 48) * static_cast<int>(pow(10,num2.size() - 1 - i));
        }
        return to_string(num1_i * num2_i);
    }
};



int main() {
    Solution s;
    string res = s.multiply("165","1");
    cout << res << endl;
}

