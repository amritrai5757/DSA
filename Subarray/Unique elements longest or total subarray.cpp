TC=o(nlogn)
int lengthOfLongestSubstring(string s) {
        int i=0,j=0;
        map<char,int>m;
        int mx=0;
        while(j<s.size()){
            m[s[j]]++;   
            while(m.size()<j+1-i){   //while(unique char< substring size)        //For Longest substring with k unique char i,e chars can repeat: while(m.size()>k) :while(unique char>k)
                    m[s[i]]--;
                    if(m[s[i]]==0)m.erase(s[i]);
                    i++;
            }
            if(m.size()==j-i+1)mx=max(mx,j+1-i);                                 //For longest substring with k unique char: if(m.size()==k)
                                                                                 //TotalSubarrays with k unique char += (j-i+1);
            j++;
        }
        return mx;                                                               //For longest substring with k unique char: if(mx>=k)return mx; else return -1;
        //return totalsubarrays with k unique char;
}



// MINIMUM WINDOW SUBSTRING  :  Give a substring of s such that every character in t is included in that substring

string minWindow(string s, string t) {
        int m=s.size(), n=t.size();
        map<char, int> mp;
        
        for(auto x:t)  mp[x]++;
        
        int count = mp.size();
        int i = 0, j = 0 , start=0 , ans=INT_MAX;  // ans means length of required substring.

        while (j < s.length()) {
            mp[s[j]]--;
            if (mp[s[j]] == 0) count--;
 
            while (count == 0) {         // Till all element of t are present in current substring with respected amount of frequecies
                    if (ans > j - i + 1) {
                        ans = j - i + 1;
                        start = i;
                    }
                    mp[s[i]]++;         // Removing elements of s from left
                    if (mp[s[i]] > 0)   // if any 1 frquency of any element of t becomes less
                        count++;
                    i++;
            }
            
            j++;
        }
        if (ans != INT_MAX) return s.substr(start, ans);
        else return "";
}
