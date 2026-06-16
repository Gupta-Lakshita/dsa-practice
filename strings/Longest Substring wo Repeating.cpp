//Longest Substring Without Repeating Characters
//approach: sliding window using 2 pointers
//empty window > keep expanding > condition violate > move left ptr

int fnc(string s)  // int lengthOfLongestSubstring(string s)
{
    vector<int> hash(256, -1);

    int l = 0;
    int r = 0;
    int maxlen = 0;

    while (r < s.length())
    {
        if (hash[s[r]] != -1)
        {
            if (hash[s[r]] >= l)
            {
                l = hash[s[r]] + 1;
            }
        }

        int len = r - l + 1;

        maxlen = max(maxlen, len);

        hash[s[r]] = r;

        r++;
    }

    return maxlen;
}