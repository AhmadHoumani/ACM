//https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/practice-problems/algorithm/reunion-of-1s-1b5bd063/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lld;
typedef unsigned long long ull;
const lld pi = 3.14159265358979323846;
const ll MOD = 1000000007;
int _rank[100001];
int par[100001];
char ar[100010];

int find(int a) {
    if (par[a] == -1) {
        return a;
    } else {
        return find(par[a]);
    }
}

void merge(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b)return;
    if (_rank[a] > _rank[b]) {
        _rank[a] += _rank[b];
        par[b] = a;
    } else {
        _rank[b] += _rank[a];
        par[a] = b;

    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, k, t, mx = 0;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> ar[i];
        if (ar[i] == '1') {
            par[i] = -1;
            _rank[i] = 1;
            if (i > 1 && ar[i - 1] == '1') {
                merge(i, i - 1);
            }
            int p = find(i);
            mx = max(ll(_rank[p]), mx);
        }
    }
    while (k--) {
        cin >> t;
        if (t == 1) {
            cout << mx << "\n";
        } else {
            cin >> t;
            if (ar[t] == '1') {
                continue;
            } else {
                ar[t] = '1';
                par[t] = -1;
                _rank[t] = 1;
                if (t > 1 && ar[t - 1] == '1') merge(t, t - 1);

                if (t < n && ar[t + 1] == '1') merge(t, t + 1);

                int p = find(t);
                mx = max(ll(_rank[p]), mx);

            }

        }
    }

}



