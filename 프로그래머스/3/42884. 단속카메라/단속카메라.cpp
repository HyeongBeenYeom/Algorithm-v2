#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 1;
    
    sort(routes.begin(), routes.end());
    
    int start = routes[0][0], end = routes[0][1];
    
    for(int i=1;i<routes.size();i++){
        if(routes[i][0] > end){
            answer++;
            start = routes[i][0];
            end = routes[i][1];
        }
        else if(routes[i][0] <= end){
            start = routes[i][0];
            if(routes[i][1] < end)
                end = routes[i][1];
        }
    }
    return answer;
}