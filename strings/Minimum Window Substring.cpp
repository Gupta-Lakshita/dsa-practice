//Minimum Window Substring
//Smallest window in a String containing all characters of other String
//Sliding window + two HashMaps.

class Solution {
public:
    string minWindow(string s, string t) {

        vector<int> hash(256, 0);

        int l = 0, r = 0;
        int minLen = 1e9;
        int startIndex = -1;
        int cnt = 0;
        int n = s.size();
        int m = t.size();

        for (int i = 0; i < m; i++) {
            hash[t[i]]++;
        }

        while (r < n) {
            if (hash[s[r]] > 0)
                cnt++;

            hash[s[r]]--;

            while (cnt == m) {
                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    startIndex = l;
                }

                hash[s[l]]++;

                if (hash[s[l]] > 0)
                    cnt--;

                l++;
            }

            r++;
        }

        return startIndex == -1 ? "" : s.substr(startIndex, minLen);
    }
};