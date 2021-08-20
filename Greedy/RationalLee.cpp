//https://codeforces.com/contest/1369/problem/C
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lld;
typedef unsigned long long ull;
const lld pi = 3.14159265358979323846;
const ll MOD = 1000000007;


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll tt,n,k;
    cin>>tt;
    while(tt--){
	cin>>n>>k;
	int a[n];
	int b[k];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<k;i++){
		cin>>b[i];
	}
	sort(a,a+n),sort(b,b+k);
	//take care of 1s;
	ll i=0,j=n-1,p=0,res=0;
	while(i<k &&b[i]==1 ){
		res+=2*a[j];
		j--,i++;

	}
	for(int q=k-1;q>=i;q--){
		res+=a[j]+a[p];
		b[q]-=2;
		j--,p++;
		while(b[q]>0){
			//res+=a[p];	
			b[q]--,p++;
		}
	}
	cout<<res<<"\n";
	}
  }
