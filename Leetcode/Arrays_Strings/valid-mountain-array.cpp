//https://leetcode.com/problems/valid-mountain-array
//Took time because I did not read the question well.

bool validMountainArray(vector<int>& arr) {
        int n=arr.size();
        if(n<3){
            return false;
        }
        if(arr[0]>arr[1]){
            return false;
        }
        int inc=0,dec=0,c1=0,c2=0;
        for(int i=0;i<n-1;i++){
            if(arr[i]<arr[i+1]){
                if(c2==1){
                    dec=1;
                }
                if(c1==0){
                    c1=1;
                }else if(c1==1 && inc==1){
                    return false;
                }
                
            }else if(arr[i]>arr[i+1]){
               if(c1==1){
                   inc=1;
               }
                if(c2==0){
                    c2=1;
                }else if(c2==1 && dec==1){
                    return false;
                }
            }
            else{
                return false;
            }
        }
        if(c1==1 && c2==1){
        return true;
    }
        return false;
    }
