//https://leetcode.com/problems/is-subsequence/
class Solution {
public:
    bool isSubsequence(string s, string t) {
    int l = 0;
    for (auto c: t) {
        if (s[l] == c) {
            l++;
        }
    }
    if (l >= s.size()) {
        return true;
    }
    return false;
}


};
