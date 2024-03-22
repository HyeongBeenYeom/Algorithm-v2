#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

vector<unordered_set<int>> dp(8);

int cal(int N, int k){
    int ret = N;
    for(int i=0;i<k;i++){
        ret = ret*10 + N;
    }
    return ret;
}

int solution(int N, int number) {
    int answer = 0;
    
    if(number == N)
        return 1;
    
    dp[0].insert(N);
    
    for(int i=1;i<8;i++){
        dp[i].insert(cal(N,i));
        
        for(int j=0;j<i;j++){
            for(int k=0;k<i;k++){
                if(j+k+1 == i){
                    for(auto a:dp[j]){
                        for(auto b:dp[k]){
                            dp[i].insert(a+b);
                            if(a-b>0)
                                dp[i].insert(a-b);
                            dp[i].insert(a*b);
                            if(a/b != 0)
                                dp[i].insert(a/b);
                        }
                    }
                }
            }
        }
        if(dp[i].find(number) != dp[i].end())
            return i+1;
    }
    return -1;
}