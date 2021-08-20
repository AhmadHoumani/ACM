//https://www.hackerearth.com/practice/basic-programming/bit-manipulation/basics-of-bit-manipulation/practice-problems/algorithm/sum-of-numbers-9/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lld;
typedef unsigned long long ull;
const lld pi = 3.14159265358979323846;
const ll MOD = 1000000007;


signed main() {
    
   ll tt,n,tar;
   cin>>tt;
   while(tt--){
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cin>>tar;
	int bit=1<<n;
	bool hap=false;
	for(int mask=0;mask<bit;mask++){
		ll sum=0;
		for(int i=0;i<n;i++){
			int f=1<<i;
			if((mask & f)!=0){
				sum+=a[i];
			}
		}
		if(sum==tar){
		hap=true;
		break;
	}
	}
		if(hap){
			cout<<"YES"<<"\n";
		}else{
			cout<<"NO"<<"\n";
		}
   }
   }
