//https://cses.fi/problemset/task/1083
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
ll arthSum(ll n)
{
      ll sum = n * (n + 1);
      sum /= 2;
      return sum;
}
 
int main()
{
      send help ll n, y = 0, z;
      cin >> n;
      ll x = arthSum(n);
      n--;
      while (n--)
      {
            cin >> z;
            y += z;
      }
      cout << x - y;
}
