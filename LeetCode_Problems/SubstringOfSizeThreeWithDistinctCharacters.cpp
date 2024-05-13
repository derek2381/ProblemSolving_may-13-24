// problem link
// https://leetcode.com/problems/substrings-of-size-three-with-distinct-characters/description/

class Solution {
public:
    int countGoodSubstrings(string s) {
        int count = 0;
        map<char,int> mp;
        if(s.length() < 3){
            return 0;
        }else{
            for(int i = 0;i < 3;i++){
                if(mp.count(s[i]) == 0){
                    mp[s[i]] = 1;
                }else{
                    mp[s[i]] += 1;
                }
            }

            int si = 0;

            for(int i = 3;i < s.length();i++){
                if(mp.size() == 3){
                    count++;
                }

                if(mp[s[si]] == 1){
                    mp.erase(s[si]);
                    si++;
                }else{
                    mp[s[si]] -= 1;
                    si++;
                }

                mp[s[i]]++;
            }
            if(mp.size() == 3){
                count++;
            }
            return count;
        }
    }
};
