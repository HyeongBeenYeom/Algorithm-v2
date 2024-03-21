#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    vector<vector<int>> g(n+1);
    
    for(int i=0;i<edge.size();i++){
        g[edge[i][0]].push_back(edge[i][1]);
        g[edge[i][1]].push_back(edge[i][0]);
    }
    
    vector<int> dist(n+1, -1);
    queue<int> q;
    
    dist[1] = 0;
    q.push(1);
    
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        
        for(int next : g[cur]){
            if(dist[next] == -1){
                dist[next] = dist[cur] + 1;
                q.push(next);
            }
        }
    }
    
    int maximum = *max_element(dist.begin(), dist.end());
    
    for(int i=1;i<dist.size();i++){
        if(dist[i] == maximum)
            answer++;
    }
    return answer;
}