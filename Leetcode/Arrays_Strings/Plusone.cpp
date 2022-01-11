class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
    int n = digits.size(), f = -1;
    if (digits[n - 1] != 9) {
        digits[n - 1]++;
        return digits;
    }
    for (int i = n - 1; i >= 0; --i) {
        if (digits[i] != 9) {
            digits[i]++;
            f = i;
            break;
        }
    }
    if (f != -1) {
        for (int i = f+1; i < n; ++i) {
            digits[i] = 0;
        }
        return digits;
    }
    fill(digits.begin(), digits.end(), 0);
    digits[0] = 1;
    digits.push_back(0);
    return digits;
}
};
