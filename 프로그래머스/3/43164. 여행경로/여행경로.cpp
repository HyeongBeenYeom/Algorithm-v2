#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool used[99990001];
vector<string> ret;
vector<string> tmp;
int idx=0;

void DFS(string depart, int val, vector<vector<string>> tickets){
    tmp.push_back(depart);
    if(val == tickets.size()){
        cout << '\n';
        if(ret.empty()){
            ret = tmp;
        }
        else{
            for(int i=0;i<tmp.size();i++){
                if(ret[i] > tmp[i]){
                    ret = tmp;
                    break;
                }
                else if(ret[i] < tmp[i])
                    break;
            }
        }
    }
    else{
        for(int i=0;i<tickets.size();i++){
            if(!used[i] && depart == tickets[i][0]){
                used[i] = true;
                DFS(tickets[i][1], val+1, tickets);
                used[i] = false;
                tmp.erase(tmp.end()-1);
            }
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    
    DFS("ICN", 0, tickets);
    
    return ret;
}