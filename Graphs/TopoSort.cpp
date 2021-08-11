//https://www.spoj.com/problems/TOPOSORT/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lld;
typedef unsigned long long ull;
const lld pi = 3.14159265358979323846;
const ll MOD = 1000000007;
vector<int> gp[1000001];
int in[1000001];
vector<int> res;

bool khanA(int n) {
    priority_queue<int, vector<int>, greater<int>> qp;
    for (int i = 1; i <= n; ++i) {
        if (in[i] == 0) {
            qp.push(i);
        }
    }
    while (!qp.empty()) {
        int top = qp.top();
        qp.pop();
        res.push_back(top);
        for (int child:gp[top]) {
            in[child]--;
            if (in[child] == 0) {
                qp.push(child);
            }
        }
    }
    return res.size() == n;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, a, b;
    cin >> n >> m;
    while (m--) {
        cin >> a >> b;
        gp[a].push_back(b);
        in[b]++;
    }
    if (!khanA(n)) {
        cout << "Sandro fails.";
    } else {
        for (int child:res) {
            cout << child << " ";
        }
    }
}


