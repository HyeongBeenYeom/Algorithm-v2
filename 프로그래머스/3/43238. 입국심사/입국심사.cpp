#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    
    sort(times.begin(), times.end());
    long long l = 1;
    long long r = n * (long long)times.back();
    
    while(l <= r){
        long long mid = (r+l)/2;
        long long tmp=0;
        
        for(int i=0;i<times.size();i++){
            tmp += (mid/(long long)times[i]);
        }
        
        if(tmp >= n){
            r = mid - 1;
            answer = mid;
        }
        else
            l = mid + 1;
    }
    return answer;
}