//Product of Array Except Self
//approach:
//o(n) space: prefix vector, suffic vector, ans vector

// int n=nums.size();
// vector<int>ans(n,1);
// vector<int>prefix;
// prefix[0]=1;
// for(int i=0;i<n;i++){
//     prefix[i]=prefix[i-1]*nums[i-1];
// }
// vector<int>suffix;
// suffix[n-1]=1;
// for(int i=n-2;i>=0;i--){
//     suffix[i]=suffix[i+1]*nums[i+1];
// }
// for (int i=0;i<n;i++){
//     ans[i]=prefix[i]*suffix[i];
// }
// return ans;

//o(1) space, w/o per suf vectors
int n=nums.size();
vector<int>ans(n,1);
for(int i=1;i<n;i++){
    ans[i]=ans[i-1]*nums[i-1];
}
int suffix =1;
for(int i=n-2;i>=0;i--){
    suffix *= nums[i+1];
    ans[i] *= suffix;
}
return ans;