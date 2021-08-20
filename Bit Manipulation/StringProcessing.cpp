//https://www.codechef.com/problems/JAIN
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
    int tt,n;
    string str;
    cin>>tt;
    while(tt--){
		ll F[32]={0};
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>str;
			int mask=0;
			for(char ch : str)
			{
				if(ch == 'a') mask = mask | (1 << 0);
				if(ch == 'e') mask = mask | (1 << 1);
				if(ch == 'i') mask = mask | (1 << 2);
				if(ch == 'o') mask = mask | (1 << 3);
				if(ch == 'u') mask = mask | (1 << 4);
				
			}
			F[mask]++;
		}
			ll res=0;
			for(int i=0;i<=31;i++){
				for(int j=i+1;j<=31;j++){
					if((i|j)==31){
						res+=F[i]*F[j];	
					}
				}
			}
			res = res + (F[31] * (F[31] - 1)) / 2;
			
		
		cout<<res<<"\n";
		}
	}
    
  




