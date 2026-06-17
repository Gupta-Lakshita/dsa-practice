//Find the Factorial of a large number
//BigInteger math.

//(not on leetcode)

vector<int>arr;
arr.push_back(1);
for (int i=2; i<N; i++){
    int x=i;
    int carry=0;
    for (int j=0; j< arr,size(); j++){
        int sum=x*arr[j]+carry;
        int digit=sum%10;
        arr[j]=digit;
        carry=sum/10;
    }
    while (carry<0){
        arr.push_back(carry%10);
        carry=carry/10;
    }
}
reversde(arr.begin(),arr.end());
return arr;