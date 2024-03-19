#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

bool visited[9];
set<string> s;

void DFS(int idx, vector<string> user, vector<string> banned){
    if(idx == banned.size()){
        string str = "";
        for(int i=0;i<user.size();i++){
            if(visited[i]){
                str += to_string(i);
            }            
        }
        s.insert(str);
        return;
    }
    
    for(int i=0;i<user.size();i++){
        bool flag = true;
        
        if(banned[idx].length() != user[i].length() || visited[i])
            continue;
        
        for(int j=0;j<banned[idx].length();j++){
            if(banned[idx][j] == '*')
                continue;
            if(banned[idx][j] != user[i][j]){
                flag = false;
                break;
            }
        }
        
        if(flag == true){
            visited[i] = true;
            DFS(idx+1, user, banned);
            visited[i] = false;
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    
    DFS(0,user_id,banned_id);
    answer = s.size();
    return answer;
}