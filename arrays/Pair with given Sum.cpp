//Two Sum - Pair with given Sum
//given int n, vector book w int target
// approach: hashing (hashmap)

// string read( int n, vector<int> book, int target)
// {
//     map<int,int>mpp;
//     for (int n=0,i<n,i++){
//         int a = book[i];
//         int more=target-a;
//         if (mpp.find(more)!=mpp.end()){
//             return "yes";
//             return(mpp[more], i);
//         }
//         mpp[a]=i;
//     }
//     else return "no";
// }

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    map<int,int>mpp;
    int n= nums.size();
    for (int i=0;i<n;i++){
        int a = nums[i];
        int more=target-a;
        if (mpp.find(more)!=mpp.end()){
            return{mpp[more], i};
        }
        mpp[a]=i;
    }
    return {-1,-1};
}
};