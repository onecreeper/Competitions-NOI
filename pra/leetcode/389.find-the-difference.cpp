#include <iostream>
#include <string>

using namespace std;

class Solution1 {  //计数
public:
    char findTheDifference(string s, string t) {
        int charcounts[26] = {0};
        int charcountt[26] = {0};
        for(int i = 0; i < s.length(); i++) {
            int ch = s[i];
            charcounts[ch - 'a'] += 1;
        }
        for(int i = 0; i < t.length(); i++) {
            int ch = t[i];
            charcountt[ch - 'a'] += 1;
        }
        for(int i = 0; i < 26; i++) {
            if ((charcountt[i] - charcounts[i]) != 0) {
                return i + 'a';
            }
        }
        return '\0'; // 如果没有找到不同字符，返回空字符
    }
};

class Solution2 {  //求和
public:
    char findTheDifference(string s, string t) {
        int sums = 0;
        int sumt = 0;
        for (char i : s){
            sums += i;
        }
        for (char i : t){
            sumt += i;
        }
        char res = (sums > sumt) ? sums - sumt : sumt - sums;
        return res;
    }
};

class Solution3 {  //位运算 将两个字符串加起来，找出现奇数次的字符即可，异或的力量！
    class Solution {
    public:
        char findTheDifference(string s, string t) {
            int ret = 0;
            for (char ch: s) {
                ret ^= ch;
            }
            for (char ch: t) {
                ret ^= ch;
            }
            return ret;
        }
    };
};



int main() {
    Solution2 s;
    char res = s.findTheDifference("asdasd", "asdasdb");
    cout << res << endl;
}
