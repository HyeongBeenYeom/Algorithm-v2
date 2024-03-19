#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    
    int tmp_n = n;
    int tmp_s = s;
    int base = s/n;
    int remain;
    
    if(base == 0){
        answer.push_back(-1);
    }
    else{
        remain = s%n;
        for(int i=0;i<n; i++){
            if(remain>0){
                answer.push_back(base+1);
                remain--;
            }
            else{
                answer.push_back(base);
            }
        }
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}