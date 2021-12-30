//https://leetcode.com/problems/find-minimum-in-rotated-sorted-array
class Solution {
public:
    int findMin(vector<int>& v) {
        int n=v.size();
	if (n==1){
		return v[0];
	}
		if(n==2){
        	if(v[0]>v[1]){
        		return v[1];
			}else{
				cout<<v[0];
			}
		}
	if(v[0]<v[n-1]){
		return v[0];
	}
	int lm=v[0],rm=v[n-1],l=0,r=n-1;
	while(l<=r){
		int mid=l + (r - l) / 2;
		if(l!=n-1 && v[mid]<v[mid+1] && v[mid-1]>v[mid]){
			return v[mid];
		}else if(v[mid]<v[r]){
			r=mid-1;
		}else{
			l=mid+1;
		}
	}
	return v[n-1];
    }
};
    
