#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int set[101];

int getParent(int n){
    if(set[n] == n)
        return n;
    else
        return set[n] = getParent(set[n]);
}

bool cmp(vector<int> a, vector<int> b){
    return a[2] < b[2];    
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    sort(costs.begin(), costs.end(), cmp);
    
    for(int i=0;i<n;i++){
        set[i] = i;
    }
    
    for(int i=0;i<costs.size();i++){
        int start = getParent(costs[i][0]);
        int end = getParent(costs[i][1]);
        int cost = costs[i][2];
        
        if(start != end){
            answer += cost;
            set[end] = start;
        }
    }
    
    return answer;
}