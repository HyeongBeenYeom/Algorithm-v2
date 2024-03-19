#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    map<string, int> music;
    map<string, map<int, int>> musiclist;
    
    for(int i=0;i<genres.size();i++){
        music[genres[i]] += plays[i];
        musiclist[genres[i]][i] = plays[i];
    }
    
    while(!music.empty()){
        string str;
        int num = 0;
        for(auto m : music){
            if(m.second > num){
                str = m.first;
                num = m.second;
            }
        }
        
        for(int i=0;i<2;i++){
            int val=0, idx=-1;
            for(auto ml : musiclist[str]){
                if(ml.second > val){
                    val = ml.second;
                    idx = ml.first;
                }
            }
            
            if(idx == -1)
                break;
            answer.push_back(idx);
            musiclist[str].erase(idx);
        }
        
        music.erase(str);
    }
    return answer;
}