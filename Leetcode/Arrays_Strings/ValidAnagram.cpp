class Solution {
public:
    int arrs[26];
    int arrt[26];
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()){
            return false;
        }
        
        for(int i=0;i<s.size();i++){
            arrs[s[i]-'a']++;
            arrt[t[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            if(arrs[i]!=arrt[i]){
                // cout<<arrt[i]<<" ";
                return false;
            }
        }
        return true;
    }
};
