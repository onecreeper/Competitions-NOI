// 万能头文件
#include <bits/stdc++.h>
// #include <iostream>
// #include <vector>

using namespace std;


class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        vector<int> me(accounts.size(),0);
        for (int i = 0 ; i < accounts.size(); i++){
            for (int j : accounts[i]) me[i] += j;
        }
        auto max_it = std::max_element(me.begin(), me.end());
        return *max_it; 
    }
};


int main() {
    vector<vector<int>> op = {{1,5},{7,3},{3,5}};

    Solution s;
    int a = s.maximumWealth(op);
    cout << a << endl;
}