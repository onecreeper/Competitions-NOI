// 万能头文件
#include <bits/stdc++.h>


using namespace std;

class Solution {
public:
    bool isRobotBounded(string instructions) {
        //想成向量，假设第一次与北方夹角为A，只要夹角不为0，他就一定进入循环 -> x轴有移动
        //回到原点
        int x = 0,y = 0;
        int direction = 0;
        vector<char> directionList = {'N','E','S','W'};
        for (char i : instructions) {
            if (i == 'L') {
                direction = (direction + 3) % 4;  // 左转
            } else if (i == 'R') {
                direction = (direction + 1) % 4;  // 右转
            }
            else{
                if (direction == 0) y++;
                else if (direction == 1) x++;
                else if (direction == 2) y--;
                else if (direction == 3) x--;
            }
        }
        if ((x == 0 && y == 0) || direction != 0 ) return true;
        return false;
    }
};



int main() {
    Solution s;
    bool res = s.isRobotBounded("GL");
    cout << res << endl;
}



// int main() {
//     vector<type> nums = {9,9,9,9};
//     Solution1 s;
//     type a = s.method(nums);
//     cout << a << endl;
// }