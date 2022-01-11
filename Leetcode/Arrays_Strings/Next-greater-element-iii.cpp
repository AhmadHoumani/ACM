//https://leetcode.com/problems/next-greater-element-iii

int nextGreaterElement(int n) {
    string s = to_string(n);
    int len = s.length(), f = -2;
    for (int i = len - 1; i > 0; --i) {
        if (s[i] > s[i - 1]) {
            f = i-1;
            break;
        }
    }
    if (f == -2) {
        return -1;
    }
    for (int i = len - 1; i >= f; i--) {
        if (s[i] > s[f]) {
            swap(s[i], s[f]);
            break;
        }
    }
    reverse(s.begin()+f+1,s.end());
    long res = stol(s);

    return (res > INT_MAX) ? -1 : res;
}
};
