#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    int start, end;
    int tmp;
    
    for(int i=0;i<stations.size();i++){      
        if(i==0){
            start = 1;
            end = stations[i] - w;
        }
        else{
            start = stations[i-1] + w + 1;
            end = stations[i] - w;
        }
        tmp = end - start;
        if(tmp <= 0)
            continue;
        else if(tmp%(2*w+1) == 0)
            answer += tmp/(2*w+1);
        else
            answer += tmp/(2*w+1) + 1;
    }
    start = stations[stations.size()-1] + w;
    end = n;
    tmp = end - start;
    if(tmp <= 0)
        return answer;
    else if(tmp%(2*w+1) == 0)
        answer += tmp/(2*w+1);
    else
        answer += tmp/(2*w+1) + 1;

    return answer;
}