#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    int l = 0, r = distance;
    sort(rocks.begin(), rocks.end());
    
    while(l <= r){
        int mid = (l+r)/2;
        int prev = 0, cnt = 0;
        
        for(int i=0;i<rocks.size();i++){
            if(rocks[i] - prev < mid){
                cnt++;
            }
            else
                prev = rocks[i];
        }
        
        if(distance - prev < mid)
            cnt++;
        
        if(cnt <= n){
            answer = max(answer,mid);
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
    }
    return answer;
}