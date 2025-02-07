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

class Solution1 {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<int> row(matrix[0].size(),0) , col(matrix.size());
        for (int y = 0;y < matrix.size() ; y++){
            for (int x = 0; x < matrix[0].size(); x++){
                if (matrix[y][x] == 0) {
                    col[y] = 1;
                    row[x] = 1;
                }
            }
        }
        for (int i = 0; i < col.size() ; i++){
            if (col[i] == 1){
                for (int j = 0; j < row.size();j++){
                    matrix[i][j] = 0;
                }
            }
        }
        for (int i = 0; i < row.size() ; i++){
            if (row[i] == 1){
                for (int j = 0; j < col.size();j++){
                    matrix[j][i] = 0;
                }
            }
        }
        // return matrix;
    }
};


class Solution2 {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool firstRowZero = false;
        bool firstColZero = false;

        // 检查第一行是否有零
        for (int i = 0; i < matrix[0].size(); i++) {
            if (matrix[0][i] == 0) {
                firstRowZero = true;
                break;
            }
        }

        // 检查第一列是否有零
        for (int i = 0; i < matrix.size(); i++) {
            if (matrix[i][0] == 0) {
                firstColZero = true;
                break;
            }
        }

        // 使用第一行和第一列作为标记
        for (int y = 1; y < matrix.size(); y++) {
            for (int x = 1; x < matrix[0].size(); x++) {
                if (matrix[y][x] == 0) {
                    matrix[0][x] = 0;
                    matrix[y][0] = 0;
                }
            }
        }

        // 置零行
        for (int y = 1; y < matrix.size(); y++) {
            if (matrix[y][0] == 0) {
                for (int x = 1; x < matrix[0].size(); x++) {
                    matrix[y][x] = 0;
                }
            }
        }

        // 置零列
        for (int x = 1; x < matrix[0].size(); x++) {
            if (matrix[0][x] == 0) {
                for (int y = 1; y < matrix.size(); y++) {
                    matrix[y][x] = 0;
                }
            }
        }

        // 如果第一行需要置零
        if (firstRowZero) {
            for (int i = 0; i < matrix[0].size(); i++) {
                matrix[0][i] = 0;
            }
        }

        // 如果第一列需要置零
        if (firstColZero) {
            for (int i = 0; i < matrix.size(); i++) {
                matrix[i][0] = 0;
            }
        }
    }
};



// int main() {
//     // Solution s;
//     // type res = s.method();
//     // cout << res << endl;
// }

int main() {
    vector<vector<int>> op = {{1,0,3},{4,5,6},{7,8,9}};

    Solution2 s;
    s.setZeroes(op);
    for (int i = 0; i < op.size() ; i++){
        for (int j = 0; j < op[0].size();j++){
            cout << op[i][j];
        }
        cout << endl;
    }

}