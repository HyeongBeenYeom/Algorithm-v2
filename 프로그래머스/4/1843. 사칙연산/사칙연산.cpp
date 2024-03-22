#include <vector>
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;

int dp[200][200] ;
int dp2[200][200];

int solution(vector<string> arr)
{
    int answer = -1;
    int n = arr.size()/2+1;
    
    memset(dp,-100000,40000);
    memset(dp2, 100000, 40000);
    
    for(int i=0;i<n;i++){
        dp[i][i] = stoi(arr[i*2]);
        dp2[i][i] = stoi(arr[i*2]);
    }
    
    for(int i=1;i<n;i++){
        for(int j=0;j<n-i;j++){
            int k = j+i;
            for(int l = j;l<k;l++){
                if(arr[l*2+1] == "-"){
                    dp[j][k] = min(dp[j][l] - dp2[l+1][k],dp[j][k]);
                    dp2[j][k] = max(dp2[j][l] - dp[l+1][k],dp2[j][k]);
                }
                else{
                    dp[j][k] = min(dp[j][l] + dp[l+1][k],dp[j][k]);
                    dp2[j][k] = max(dp2[j][l] + dp[l+1][k],dp2[j][k]);
                }
            }
        }
    }
    return dp2[0][n-1];
}