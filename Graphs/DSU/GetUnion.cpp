//https://codeforces.com/edu/course/2/lesson/7/1/practice/contest/289390/problem/A
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double lld;
typedef unsigned long long ull;
const lld pi = 3.14159265358979323846;
const ll MOD = 1000000007;
vector<int> gp[1000001];
int par[1000001];
int lvl[1000001];

int find(int a) {
    if (par[a] == a) {
        return a;
    }
    return par[a] = find(par[a]);
}

void merge(int a, int b) {
    a = find(a), b = find(b);
    if (a == b) {
        return;
    }
    if (lvl[a] > lvl[b]) {
        par[b] = a;
        lvl[a] += lvl[b];
    } else {
        par[a] = b;
        lvl[b] += lvl[a];
    }
}

signed main() {

    int n, m, a, b;
    string query;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        par[i] = i;
        lvl[i] = 1;
    }
    while (m--) {
        cin >> query;
        cin >> a >> b;
        if (query == "union") {
            merge(find(a), find(b));


        } else {
            if (find(par[a]) == find(par[b])) {
                cout << "YES" << "\n";
            } else {
                cout << "NO" << "\n";
            }
        }
    }

}









