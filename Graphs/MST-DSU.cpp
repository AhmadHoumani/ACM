//https://www.hackerearth.com/practice/algorithms/graphs/minimum-spanning-tree/practice-problems/algorithm/minimum-spanning-tree-5/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lld;
typedef unsigned long long ull;
const lld pi = 3.14159265358979323846;
const ll MOD = 1000000007;
int par[100001];
struct edge {
    int a;
    int b;
    int c;
};
edge ar[100001];

bool comp(edge a, edge b) {
    if (a.c < b.c) {
        return true;
    }
    return false;
}

int find(int a) {
    if (par[a] == -1) {
        return a;
    }
    return par[a] = find(par[a]);
}

void merge(int a, int b) {
    par[a] = b;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, m, a, b, w, sum = 0;
    cin >> n >> m;
    memset(par, -1, sizeof par);
    for (int i = 0; i < m; ++i) {
        cin >> ar[i].a >> ar[i].b >> ar[i].c;
    }
    sort(ar, ar + m, comp);
    for (int i = 0; i < m; ++i) {
        a = find(ar[i].a);
        b = find(ar[i].b);
        if (a != b) {
            sum += ar[i].c;
            merge(a, b);
        }
    }
    cout << sum;
}


