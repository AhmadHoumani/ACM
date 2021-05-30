//DFS
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lld;
typedef unsigned long long ull;
const lld pi = 3.14159265358979323846;
const ll mod = 1000000007;
const ll template_array_size = 1e6 + 332001;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
#define send                                  \
      {                                       \
            ios_base::sync_with_stdio(false); \
      }
#define help               \
      {                    \
            cin.tie(NULL); \
      }
int main()
{
      //freopen("equal.in", "r", stdin);
      send help int n, m;
      while (true)
      {
            cin >> n;
            if (n == 0)
            {
                  break;
            }
            else
            {

                  ll x = n;
                  bool happy = true;
                  if (n % 2 != 0)
                        happy = false;
                  vector<vector<int>> tie(500000 + 10);
                  while (n--)
                  {
                        int a, b;
                        cin >> a >> b;
                        tie[a].push_back(b);
                        tie[b].push_back(a);
                  }

                  for (int i = 1; i <= (int)tie.size(); i++)
                  {
                        // if (tie[i].size() != 0)
                        // {
                        //       cout << tie[i].size();
                        // }
                        if (tie[i].size() % 2 == 1)
                        {
                              happy = false;
                              break;
                        }
                  }
                  if (happy)
                  {
                        cout << "YES" << endl;
                  }
                  else
                  {
                        cout << "NO" << endl;
                  }
            }
      }
}
//Implementation

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lld;
typedef unsigned long long ull;
const lld pi = 3.14159265358979323846;
const ll mod = 1000000007;
const ll template_array_size = 1e6 + 332001;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
#define send                                  \
      {                                       \
            ios_base::sync_with_stdio(false); \
      }
#define help               \
      {                    \
            cin.tie(NULL); \
      }
int main()
{
      //freopen("equal.in", "r", stdin);
      send help ll n;
      while (true)
      {
            cin >> n;
            if (n == 0)
            {
                  break;
            }
            else
            {
                  ll a, b, x = 1, y = 1;
                  bool happy = true;
                  if (n % 2 != 0)
                        happy = false;
                  vector<vector<int>> tie(500000 + 10);
                  while (n--)
                  {

                        cin >> a >> b;
                        x *= a;
                        y *= b;
                  }
                  // cout << x << " " << y;
                  if (x != y)
                  {
                        happy = false;
                  }
                  if (happy)
                  {
                        cout << "YES" << endl;
                  }
                  else
                  {
                        cout << "NO" << endl;
                  }
            }
      }
}
