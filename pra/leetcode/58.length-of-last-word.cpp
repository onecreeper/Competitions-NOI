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

class Solution {
public:
    int lengthOfLastWord(string s) {
        int ss = s.size();
        int count = 0;
        for (int j = ss - 1 ; j >= 0 ;j--){
            if (s[j] == ' ') s.erase(j, 1);
            else break;
        }
        ss = s.size();
        for (int i = ss - 1 ; i >= 0 ;i--){
            if (s[i] == ' ') break;
            count ++;
        }
        return count;
    }
};



int main() {
    Solution s;
    int res = s.lengthOfLastWord("asdasd sd   ");
    cout << res << endl;
}
