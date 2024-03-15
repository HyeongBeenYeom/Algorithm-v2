#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

vector<vector<int>> orders;

void backtracking(int remain, int idx, vector<int> order){
    
    if(remain <= 0){
        orders.push_back(order);
        return;
    }
    
    for(int i = idx; i < order.size(); i++){
        order[i]++;
        backtracking(remain-1,i,order);
        order[i]--;
    }
}
int sim(vector<int> order, vector<vector<int>> reqs){
    priority_queue<int,vector<int>,greater<int>> pq[order.size()];
    int ret = 0;
    
    for(int i=1;i<order.size();i++){
        for(int j=0;j<order[i];j++){
            pq[i].push(0);
        }
    }
    
    for(auto req:reqs){
        int a = req[0];
        int b = req[1];
        int c = req[2];
        
        int t = pq[c].top();
        pq[c].pop();
        
        if(t > a){
            ret += t-a;
            pq[c].push(t+b);
        }
        else if(t == a){
            pq[c].push(t+b);
        }
        else{
            pq[c].push(a+b);
        }
                     
    }
    return ret;
}

int solution(int k, int n, vector<vector<int>> reqs) {
    int answer = 100000000;
    
    vector<int> kind(k+1,1);
    backtracking(n-k,1,kind);
    
    for(auto order:orders){
        answer = min(answer,sim(order,reqs));
    }
    return answer;
}