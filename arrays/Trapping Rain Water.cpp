//Trapping Rain Water
//given array with height
//approach: minimum (left max boundary, right max boundary) controls water
//sc=o(n) prefix array approach
class Solution {
public:
    int trap(vector<int>& height) {
        int n= height.size();
        vector<int> lmax(n,0);
        vector<int>rmax(n,0);
        lmax[0]=height[0];
        rmax[n-1]=height[n-1];
        for(int i=1;i<n;i++){
            lmax[i]=max(lmax[i-1],height[i]);
        }
        for(int i=n-2;i>=0;i--){
            rmax[i]=max(rmax[i+1],height[i]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=(min(lmax[i],rmax[i])-height[i]);
        }
        return ans;
    }
};

//sc=o(1) 2 pointer approach
class Solution {
public:
    int trap(vector<int>& height) {
        int ans=0;
        int n=height.size();
        int lmax=0;
        int rmax=0;
        int l=0;
        int r=n-1;
        while(l<r){
            lmax=max(lmax, height[l]);
            rmax=max(rmax, height[r]);
        if(lmax<rmax){
            ans+=(lmax-height[l]);
            l++;
        }
        else{
            ans+=(rmax-height[r]);
            r--;
        }
        }
        return ans;
    }
};