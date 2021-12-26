//https://leetcode.com/problems/move-zeroes
void moveZeroes(vector<int>& nums) {
         for(int i=0,cur=0;i<nums.size();i++){
             if(nums[i]!=0){
                 swap(nums[cur],nums[i]);
                 cur++;
             }
         }
        
  }
