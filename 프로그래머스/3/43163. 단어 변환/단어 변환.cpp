#include <string>
#include <vector>
#include <iostream>

using namespace std;

int ret = 1000000000;
bool visited[51] = {false,};

void DFS(string begin, string target, vector<string> words, int val){
    int diff=0;
    
    for(int i=0;i<words.size();i++){
        diff = 0;
        if(!visited[i]){
            for(int j=0;j<begin.length();j++){
                if(begin[j] != words[i][j]){
                    diff++;
                }
            }
            if(diff == 1){
                if(words[i] == target){
                    ret = min(ret,val+1);
                }
                else{
                    visited[i] = true;
                    DFS(words[i],target,words,val+1);
                    visited[i] = false;
                }
            }
        }
        
    }
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    bool test = false;
    
    for(int i=0;i<words.size();i++){
        if(target == words[i]){
            test = true;
            break;
        }
    }
    
    if(test){
        DFS(begin,target,words,0);
    }
    else
        return 0;
    
    return ret;
}