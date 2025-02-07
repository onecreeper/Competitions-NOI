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
    bool judgeCircle(string moves) {
        int Vertical = 0, Horizontal = 0;
        for (char i : moves){
            switch (i){
                case 'U':
                    Vertical++;
                    break;
                case 'D':
                    Vertical--;
                    break;
                case 'R':
                    Horizontal++;
                    break;
                case 'L':
                    Horizontal--;
                    break;
                default:
                    return false;
            }
        }
        if (Vertical == 0 && Horizontal == 0) return true;
        return false;
    }
};




int main() {
    string nums = {"U"};
    Solution s;
    bool a = s.judgeCircle(nums);
    cout << a << endl;
}