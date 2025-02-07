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

class Solution1 {   // 我不会
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int direction = 0;   //0右 1下 2左 3上
        int xLen = matrix[0].size(), yLen = matrix.size();  //x两次碰壁后开始每次 -1 , y一次后开始
        int x = 0, y = 0;
        int xC = 0, yC = 0;
        bool xS = 0, yS = false;
        int c = (xLen * yLen);
        for (int i = 1; i < c; i++){
            res.push_back(matrix[y][x]);

            if ((x == xLen - 1 && direction == 0) || (x == 0 && direction == 2)){
                direction = (direction + 1) % 4;
                xC ++;
                if (xC == 2) xS = true;
                if (xS == true) xLen--;
            }
            else if ((y == yLen - 1 && direction == 1) || (y == 0 && direction == 3)){
                direction = (direction + 1) % 4;
                yC ++;
                if (yC == 1) yS = true;
                if (yS == true) yLen--;
            }
            if (direction == 0) x++;
            else if (direction == 2) x--;
            else if (direction == 1) y++;
            else y--;

            cout << i-1 << ":" <<x << " " << y << " " << xLen << " " << yLen << " " << direction << endl;
        }
        res.push_back(matrix[y][x]);
        return res;


    }
};

class Solution2 {  //不会啊，开摆
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int direction = 0;   //0右 1下 2左 3上
        int xLen = matrix[0].size(), yLen = matrix.size();  //x两次碰壁后开始每次 -1 , y一次后开始
        int xCount = 0 , yCount = 0;
        int count = xLen * yLen;

        int x = 0, y = 0;
        int xC = 0, yC = 0;
        bool xS = false, yS = false;

        for (int i = 0; i < count; i++) {
            res.push_back(matrix[y][x]);

            if ((x == xLen - 1 && direction == 0) || (x == 0 && direction == 2)) {
                xC++;
                if (xC == 2) xS = true;
                if (xS == true) xLen--;
            } else if ((y == yLen - 1 && direction == 1) || (y == 0 && direction == 3)) {
                yC++;
                if (yC == 1) yS = true;
                if (yS == true) yLen--;
            }

            if (xCount == xLen || yCount == yLen) {
                direction = (direction + 1) % 4;
                xCount = 0;
                yCount = 0;
            }

            if (direction == 0) {
                x++;
                xCount++;
            } else if (direction == 1) {
                y++;
                yCount++;
            } else if (direction == 2) {
                x--;
                xCount++;
            } else {
                y--;
                yCount++;
            }
        }

        return res;
    }
};



int main() {
    vector<vector<int>> op = {{1,2,3},{4,5,6},{7,8,9}};

    Solution2 s;
    vector<int> a = s.spiralOrder(op);
    for (int i : a) cout << i << endl;
    cout << endl << (a.size() == 9) << endl;
}