#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct cmp{
    bool operator()(vector<int> a, vector<int> b){
        return a[1] > b[1];
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    
    sort(jobs.begin(), jobs.end());
    priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
    int t = 0, i = 0;
    
    while(i < jobs.size() || !pq.empty()){
        if(jobs.size() > i && t >= jobs[i][0]){
            pq.push(jobs[i++]);
            continue;
        }    
        if(!pq.empty()){
            t += pq.top()[1];
            answer += t - pq.top()[0];
            pq.pop();
        }
        else{
            t = jobs[i][0];
        }
    }
    
    return answer/jobs.size();
}