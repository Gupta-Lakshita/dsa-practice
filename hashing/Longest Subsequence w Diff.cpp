//Longest Subsequence w Diff 0/1
//approach: HashMap Dynamic Programming problem 
//where values (not indices) are used as DP states

int maxLenSub(vector<int>& arr)
{
    unordered_map<int, int> dp;
    int ans = 0;

    for (int x : arr)
    {
        int best = 0;

        if (dp.count(x - 1))
            best = max(best, dp[x - 1]);

        if (dp.count(x))
            best = max(best, dp[x]);

        if (dp.count(x + 1))
            best = max(best, dp[x + 1]);

        dp[x] = best + 1;
        ans = max(ans, dp[x]);
    }

    return ans;
}
