//https://www.hackerearth.com/practice/algorithms/graphs/strongly-connected-components/practice-problems/algorithm/a-walk-to-remember-qualifier2/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lld;
typedef unsigned long long ull;
const lld pi = 3.14159265358979323846;
const ll MOD = 1000000007;
vector<int> gp[1000001];
bool vis[1000001];
int val[1000001];
bool onStack[1000001];
int low[1000001];
int in[1000001];
stack<int> st;
int timer = 1, SCC = 0;

void dfs(int node) {
    vis[node] = 1;
    low[node] = in[node] = timer++;
    onStack[node] = 1;
    st.push(node);
    for (int child:gp[node]) {
        if (vis[child] && onStack[child]) {
            low[node] = min(low[node], in[child]);
        } else {
            if (!vis[child]) {
                dfs(child);
                if (onStack[child]) {
                    low[node] = min(low[node], low[child]);
                }
            }
        }
    }
    if (in[node] == low[node]) {
        SCC++;
        //cout << "SCC #" << SCC << endl;
        int top;
        int count = 0;
        while (1) {
            top = st.top();
            st.pop(), onStack[top] = 0;
            if (top != node) {
                count = 1;
            }
            if (count) {
                val[top] = 1;
            }
            if (top == node)break;
        }
    }
    //cout << endl;
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
    }
    for (int i = 1; i <= n; ++i) {
        if (!vis[i])
            dfs(i);
    }
    for (int i = 1; i <= n; ++i) {
        cout << val[i] << " ";
    }
}


