//https://leetcode.com/problems/longest-palindrome/submissions/
class Solution {
public:
    
int longestPalindrome(string s) {
    map<char, int> mp;
    int ans = 0;

    int n = s.size();
    for (auto c: s) {
        mp[c]++;
        if (mp[c] % 2 == 0) {
            mp[c] = 0;
            ans += 2;
        }
    }
    if (ans < n) {
        ans++;
    }
    return ans;
}
};
