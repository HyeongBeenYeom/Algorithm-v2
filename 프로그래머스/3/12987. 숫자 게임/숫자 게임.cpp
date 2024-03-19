#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool visited[100001];

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    int tmp;
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    for(int i=0;i<A.size();i++){
        tmp = upper_bound(B.begin(), B.end(), A[i]) - B.begin();
        if(tmp == B.size())
            break;
        else{
            if(!visited[tmp]){
                answer++;
                visited[tmp] = true;
            }
            else{
                for(int j=tmp+1;j<=B.size();j++){
                    if(j==B.size())
                        return answer;
                    if(!visited[j]){
                        answer++;
                        visited[j] = true;
                        break;
                    }                    
                }
            }
        }
    }
    
    return answer;
}