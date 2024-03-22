#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>

using namespace std;

map<pair<int,int>, bool> v;
map<pair<pair<int,int>,pair<int,int>>, bool> e;
int dx[8] = {-1,-1,0,1,1,1,0,-1};
int dy[8] = {0,1,1,1,0,-1,-1,-1};

int solution(vector<int> arrows) {
    int answer = 0;
    
    int start_x = 0,start_y=0;
    v[{start_x,start_y}] = true;
    
    for(int i=0;i<arrows.size();i++){
        int d = arrows[i];
        for(int j=0;j<2;j++){
            int new_x = start_x + dx[d];
            int new_y = start_y + dy[d];
            
            if(v[{new_x, new_y}] == true && e[{{start_x,start_y}, {new_x,new_y}}] == false){
                e[{{start_x,start_y}, {new_x,new_y}}] = true;
                e[{{new_x, new_y}, {start_x,start_y}}] = true;
                answer++;
                start_x = new_x;
                start_y = new_y;
                continue;
            }
            v[{new_x, new_y}] = true;
            e[{{start_x,start_y}, {new_x,new_y}}] = true;
            e[{{new_x, new_y}, {start_x,start_y}}] = true;
            start_x = new_x;
            start_y = new_y;
        }
    }
    
    return answer;
}