// 万能头文件
#include <bits/stdc++.h>


using namespace std;


class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        // 规定 A为先手， A 用 1 表示， B 用 2 表示 未落子表示为 0
        // 只需要判断最后一个落子的!!!!!!!!!

        vector<vector<int>> board(3, vector<int>(3, 0));


        // 根据操作来表示棋盘
        bool isAPlaced = false; //A是否落子
        for (vector<int> i : moves) {
            if (isAPlaced == false) board[i[0]][i[1]] = 1;
            else board[i[0]][i[1]] = 2;
            isAPlaced = !isAPlaced;
        }
        // for (vector<int> j : board) for (int k : j) cout << k;

        //判断

        //横向
        for (vector<int> i : board) {
            if (i[0] == 1 && i[1] == 1 && i[2] == 1) return "A";
            if (i[0] == 2 && i[1] == 2 && i[2] == 2) return "B";
        }
        //纵向
        for (int i = 0 ; i < 3 ; i++) {
            if (board[0][i] == 1 && board[1][i] == 1 && board[2][i] == 1) return "A";
            if (board[0][i] == 2 && board[1][i] == 2 && board[2][i] == 2) return "B";
        }

        //右上 左上
        if (board[0][2] == 1 && board[1][1] == 1 && board[2][0] == 1) return "A";
        if (board[0][2] == 2 && board[1][1] == 2 && board[2][0] == 2) return "B";

        if (board[0][0] == 1 && board[1][1] == 1 && board[2][2] == 1) return "A";
        if (board[0][0] == 2 && board[1][1] == 2 && board[2][2] == 2) return "B";
        
        if (moves.size() == 9) return "Draw" ;
        return "Pending";
        
    }
};


// int main() {
//     // Solution s;
//     // type res = s.method();
//     // cout << res << endl;
// }



int main() {
    vector<vector<int>> op = {{2,0},{1,1},{0,2},{2,1},{1,2},{1,0},{0,0},{0,1}};

    Solution s;
    string a = s.tictactoe(op);
    cout << a << endl;
}