//https://cses.fi/problemset/task/1068
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
      send help ll n;
      cin >> n;
      cout << n << " ";
      while (n != 1)
      {
            (n % 2 != 0)
                ? (n *= 3, n++)
                : n /= 2;
 
            cout << n << " ";
      }
}
