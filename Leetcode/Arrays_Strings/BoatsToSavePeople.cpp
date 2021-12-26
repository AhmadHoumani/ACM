//https://leetcode.com/problems/boats-to-save-people/
 int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int l=0,r=people.size()-1;
        int bc=0;
        while(l<r){
        	if(people[l]+people[r]<=limit){
        		l++,r--,bc++;
			}else if(people[l]+people[r]>limit){
				r--,bc++;
			}
		}
        if(l==r){
            bc++;
        }
		return bc;
    }
