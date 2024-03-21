#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int arr[31];

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n;
    
    sort(lost.begin(),lost.end());
    sort(reserve.begin(), reserve.begin());
    
    for(int i=0;i<lost.size();i++){
        arr[lost[i]]--;
        answer--;
    }
    for(int i=0;i<reserve.size();i++){
        arr[reserve[i]]++;
        if(arr[reserve[i]] == 0)
            answer++;
    }
    
    for(int i=0;i<lost.size();i++){
        int l = lost[i];
        if(arr[l] == 0)
            continue;
        if(arr[l-1] == 1){
            arr[l-1]--;
            arr[l]++;
            answer++;
        }
        else if(arr[l+1] == 1){
            arr[l+1]--;
            arr[l]++;
            answer++;
        }
    }
    return answer;
}