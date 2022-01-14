//https://leetcode.com/problems/valid-parentheses/

bool check(char a, char b) {
    if (a == '(' and b == ')') {
        return true;
    } else if (a == '{' and b == '}') {
        return true;
    } else if (a == '[' and b == ']') {
        return true;
    }
    return false;
}

bool isValid(string s) {
    stack<char> st;
    for (auto x: s) {
        if (x == '(' || x == '[' || x == '{') {
            st.push(x);
        } else {
            if (!st.empty() && check(st.top(), x)) {
                st.pop();
            } else {
                return false;
            }
        }
    }
    if (!st.empty()) {
        return false;
    }
    return true;

}
