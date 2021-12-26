//https://leetcode.com/problems/container-with-most-water

int maxArea(vector<int>& height) {
	int n=height.size();
    int l=0,r=n-1,mx=0,area=1;
    while(l<r){
    	area=(r-l)*(min(height[l],height[r]));
    	mx=max(mx,area);
    	if(height[l]<height[r]){
    		l++;
		}else{
			r--;
		}
	}
         return mx;
} 
