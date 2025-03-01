#include <bits/stdc++.h>
using namespace std;

class Solution1 {  //基于map
public:
    int romanToInt(string s) {
        //任务1 正确拆分罗马数字
        //特殊情况: IV IX XL XC CD CM

        map<string, int> roman_to_arabic = {
            {"IV", 4},
            {"IX", 9},
            {"XL", 40},
            {"XC", 90},
            {"CD", 400},
            {"CM", 900}
        };
        map<char, int> single_roman_to_arabic = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        int ss = s.size();
        int res = 0;
        for (int i = 0; i < ss; i++){
            if (i < ss - 1){
                string str = {s[i], s[i + 1]};
                auto it = roman_to_arabic.find(str);
                if (it != roman_to_arabic.end()) {
                        res += it->second;
                        i++; // 跳过下一个字符
                        continue;
                    }
            }
            auto it = single_roman_to_arabic.find(s[i]);
            res += it -> second;

        }
        return res;
    }
};


/*
方法2：

    若存在小的数字在大的数字的左边的情况
    ，根据规则需要减去小的数字。对于这种情况，
    我们也可以将每个字符视作一个单独的值，若一
    个数字右侧的数字比它大，则将该数字的符号取反。
*/


int main() {
    Solution1 s;
    int res = s.romanToInt("IVVV");
    cout << res << endl;
}
