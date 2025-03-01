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

class Solution1 {
public:
    int calPoints(vector<string>& operations) {
        vector<int> score;
        int res = 0;
        int j = 0;
        for (int i = 0;i < operations.size();i++){
            if (operations[i] == "+") score.push_back(score[j - 1]+score[j - 2]);
            else if (operations[i] == "D") score.push_back(score[j - 1] * 2);
            else if (operations[i] == "C") {
                score.pop_back();
                j --;
                continue;
            }
            else score.push_back(stoi(operations[i]));
            j ++;
        }
        for (int i : score) res += i;
        // for (int i : score) cout << i << endl;
        return res;
    }
};


int main() {
    vector<string> nums = {"5","2","C","D","+"};
    Solution1 s;
    int a = s.calPoints(nums);
    cout << a << endl;
}
