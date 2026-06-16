//Longest Consecutive Sequence
//approach:

//better:
int longestSuccessiveElements(vector<int>& nums) {
    if (nums.size() == 0) return 0;

    sort(nums.begin(), nums.end());

    int n = nums.size();
    int lastSmaller = INT_MIN;
    int cnt = 0;
    int longest = 1;

    for (int i = 0; i < n; i++) {
        if (nums[i] - 1 == lastSmaller) {
            cnt += 1;
            lastSmaller = nums[i];
        }
        else if (lastSmaller != nums[i]) {
            cnt = 1;
            lastSmaller = nums[i];
        }

        longest = max(longest, cnt);
    }

    return longest;
}

//optimal:
//iterate once to put into set:N
//iterate thru set; for numbers with no smaller values also in the set-iterate more: 2N
//TC: O(1) (0(N): rare when collisions)
//SC: O(N)

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if (n==0) return 0;
        int longest =1;
        unordered_set<int> st;
        for (int i =0; i<n; i++){
            st.insert(nums[i]);
        }
        for (auto it : st){
            if (st.find(it-1)==st.end()){
                int cnt=1;
                int x=it;

                while (st.find(x+1)!=st.end()){
                    x=x+1;
                    cnt=cnt+1;
                }
                longest=max(longest, cnt);
            }
        }
        return longest;
        
    }
};