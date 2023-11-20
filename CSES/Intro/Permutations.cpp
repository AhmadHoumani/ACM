//https://cses.fi/problemset/task/1070
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
      send help
          ll n;
      cin >> n;
      if (n == 1)
      {
            puts("1");
      }
      else if (n < 4)
      {
            puts("NO SOLUTION");
      }
      else if (n == 4)
      {
            puts("3 1 4 2");
      }
      else
      {
            int a[n];
 
            for (int i = 0, j = n, k = 1; i < n ; i += 2, j--,k++)
            {
                  a[i] = k;
                  a[i + 1] = j;
            }
            swap(a[0],a[n-1]);
            for (auto x : a)
            {
                  cout << x << " ";
            }
      }
}
