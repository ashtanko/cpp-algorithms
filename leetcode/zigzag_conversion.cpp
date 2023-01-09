#include <iostream>
#include <vector>

class ZigzagConversion {
public:
    static std::string solve(std::string s, int numRows) {
        if (numRows <= 1) return s;
        std::vector<std::string> vec(numRows, "");
        for (int i = 0, row = 0, step = 1; i < s.size(); i++) {
            vec[row] += s[i];
            if (row == 0) step = 1;
            if (row == numRows - 1) step = -1;
            row += step;
        }
        std::string ret;
        for (auto d: vec) ret += d;
        return ret;
    }
};


int main() {
    std::string actual = ZigzagConversion::solve("PAYPALISHIRING", 3);
    std::string expected = "PAHNAPLSIIGYIR";
    assert(actual == expected);
    return 0;
}
