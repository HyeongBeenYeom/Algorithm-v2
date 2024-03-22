#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> g(101);

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    
    vector<vector<bool>> g(n+1,vector<bool>(n+1,false));
    
    for(int i=0;i<results.size();i++){
        g[results[i][0]][results[i][1]] = true;
    }
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                if(g[j][i] && g[i][k]){
                    g[j][k] = true;
                }
            }
        }
    }
    
    for(int i=1;i<=n;i++){
        int cnt=0;
        for(int j=1;j<=n;j++){
            if(g[i][j] || g[j][i])
                cnt++;
        }
        if(cnt == n-1)
            answer++;
    }
    
    return answer;
}