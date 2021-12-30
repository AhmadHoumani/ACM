//https://leetcode.com/problems/search-in-rotated-sorted-array
class Solution {
public:
 
int findP(vector<int>v){
	int n=v.size();
	if (n==2){
		return -1;
	}else if(v[0]<v[n-1]){
		return 0;
	}
	int lm=v[0],rm=v[n-1],l=0,r=n-1;
	while(l<r){
		int mid=l + (r - l) / 2;
		cout<<mid<<endl;
		if(v[mid]<v[mid+1] && v[mid-1]>v[mid]){
			return mid;
		}else if(v[mid]<v[r]){
			r=mid-1;
		}else{
			l=mid+1;
		}
	}
	
	return r;
}
int search(vector<int>& nums, int target) {
        int peak=findP(nums);
        if(peak==-1){
        	if(nums[0]==target){
        		return 0;
			}else if(nums[1]==target){
				return 1;
			}else{
				return -1;
			}
		}
		
        int l=0,r=nums.size()-1;
        if(target==nums[peak]){
        	return peak;
		}else if(target>nums[r]){
			r=peak;
		}else{
			l=peak;
		}
		
		while(l<=r){
			int mid=l + (r - l) / 2;
			if(nums[mid]==target){
				return mid;
			}else if(nums[mid]>target){
				r=mid-1;
			}else{
				l=mid+1;
			}
		}
		return -1;
    }


};
