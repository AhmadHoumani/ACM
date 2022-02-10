#include<bits/stdc++.h>

using namespace std;
using namespace std::chrono;
using namespace std;
typedef long long ll;
typedef long double lld;
typedef unsigned long long ull;
const ll MOD = 1000000007;
#define print(v) for(auto x:v) cout<<x<<""
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)


vector<int> gp[205];
bool vis[205];

void dfs(int node) {
    vis[node] = 1;
    for (int child: gp[node]) {
        if (!vis[child]) {
            dfs(child);
        }
    }
}

int main() {
    io;
    vector<int> values(10000);
    auto f = []() -> int { return rand() % 10000; };
    generate(values.begin(), values.end(), f);
    auto start = high_resolution_clock::now();

    int n, m, a, k;
    bool did = false;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {

        cin >> k;

        for (int j = 0; j < k; ++j) {
            cin >> a;
            gp[i].push_back(a + 101), gp[a + 101].push_back(i);
            did = true;
        }

    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (!vis[i]) {
            ans++;
            dfs(i);
        }
    }
    if (did) {
        cout << ans - 1;
    } else {
        cout << ans;
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "\nTime taken by function: "
         << duration.count() << " microseconds" << endl;
}
