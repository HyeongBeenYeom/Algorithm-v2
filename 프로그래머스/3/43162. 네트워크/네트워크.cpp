#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

queue<int> q;
bool visited[201];

void BFS(int a, vector<vector<int>> route, int n){
    q.push(a);
    visited[a] = true;
    int idx;
    
    while(!q.empty()){
        idx = q.front();
        q.pop();
        for(int i=0;i<n;i++){
            if(i != idx && route[idx][i] == 1 && !visited[i]){
                q.push(i);
                visited[i] = true;
            }
        }
    }    
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
        
    for(int i=0;i<n;i++){
        if(!visited[i]){
            BFS(i, computers, n);
            answer++;
        }
    }
    return answer;
}