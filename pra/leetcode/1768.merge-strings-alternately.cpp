#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int l1 = word1.length();
        int l2 = word2.length();
        string res;
        int minLength = min(l1, l2);

        // 交替合并两个字符串
        for (int i = 0; i < minLength; i++) {
            res += word1[i];
            res += word2[i];
        }

        // 添加剩余的部分
        if (l1 > l2) {
            res += word1.substr(minLength);
        } else {
            res += word2.substr(minLength);
        }

        return res;
    }
};

int main() {
    Solution s;
    string result = s.mergeAlternately("abc", "pqrasd");
    cout << result << endl; // 输出: apbqcr
    return 0;
}
