#include <string>
#include <vector>
#include <queue>
#include <sstream>
#include <iostream>
#include <map>

using namespace std;

priority_queue<int> max_pq;
priority_queue<int, vector<int>, greater<int>> min_pq;
map<int,int> cnt;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    
    char c;
    int n;
    for(int i=0;i<operations.size();i++){
        stringstream ss(operations[i]);
        ss >> c;
        ss >> n;
        
        if(c == 'I'){
            max_pq.push(n);
            min_pq.push(n);
            cnt[n]++;
        }
        else if(c == 'D'){
            if(n == 1){
                if(!max_pq.empty()){
                    cnt[max_pq.top()]--;
                    max_pq.pop();                    
                }                
            }
            else if(n == -1){
                if(!min_pq.empty()){
                    cnt[min_pq.top()]--;
                    min_pq.pop();                    
                }
            }
            while(!max_pq.empty() && cnt[max_pq.top()] == 0)
                max_pq.pop();
            while(!min_pq.empty() && cnt[min_pq.top()] == 0)
                min_pq.pop();
        }        
    }
    while(!max_pq.empty() && cnt[max_pq.top()] == 0)
                max_pq.pop();
    while(!min_pq.empty() && cnt[min_pq.top()] == 0)
        min_pq.pop();
    if(max_pq.empty() || min_pq.empty()){
        answer.push_back(0);
        answer.push_back(0);
    }
    else{
        answer.push_back(max_pq.top());
        answer.push_back(min_pq.top());
    }
    return answer;
}