string minWindow(string s, string t) {
        int m=s.size(), n=t.size();
        map<char, int> mp;
        
        int ans = INT_MAX; 
        int start = 0; 
        
        for(auto x:t)
            mp[x]++;
        
        int count = mp.size();
        
        int i = 0, j = 0;

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
        if (ans != INT_MAX)
            return s.substr(start, ans);
        else
            return "";
}
