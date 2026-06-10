//Maximum Subarray Sum - Kadane's Algorithm
//subarray: contiguous
//version 1: simplest
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int maxi = INT_MIN;

        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];

            maxi = max(maxi, sum);

            if(sum < 0)
                sum = 0;
        }

        return maxi;
    }
};

//version 2: starting and ending
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n= nums.size();
        int maxi= INT_MIN;
        int sum=0;
        int ansStart=-1;
        int ansEnd =-1;
        int start =0;
        for (int i=0; i<n; i++){
            if (sum==0) start = i;
            sum=sum+ nums[i];
            if (sum>maxi){
                maxi=sum;
                ansStart= start;
                ansEnd =i;
            }
            if (sum<0){
                sum=0;
            }
        }
        return maxi;
    }
};

//version 3: if maxi negative, put 0
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n= nums.size();
        int maxi= INT_MIN;
        int sum=0;
        int ansStart=-1;
        int ansEnd =-1;
        int start =0;
        for (int i=0; i<n; i++){
            if (sum==0) start = i;
            sum=sum+ nums[i];
            if (sum>maxi){
                maxi=sum;
                ansStart= start;
                ansEnd =i;
            }
            if (sum<0){
                sum=0;
            }
            if (maxi<0){
                maxi=0;
            }
        }
        return maxi;
    }
};