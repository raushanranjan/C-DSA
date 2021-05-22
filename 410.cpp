#include<bits/stdc++.h>
using namespace std;

int count(int s[], int m, int n){
    long long int dp[n+1];
    for (int i=1; i<n+1; i++)
    dp[i]=0;
    dp[0]=1;
    // here permutaion was not desired so, we have taken 1 coin at a time. 
    // for every possible subsum. which fixed the posotion of coin left to right,
    // in lower to higher denomination.  
    for(int i =0; i<m; i++){
        for(int j= s[i]; j<n+1;j++){
            int k= j - s[i];
            if (k>=0){
                dp[j]=dp[j]+dp[k];
                
            }
        }

    }
    return dp[n];

}

int main(){
    int n= 10;
    int m= 4;
    int s[m] = {2,5,3,6};
    cout<<count(s, m, n)<<endl;
    return 0;
}