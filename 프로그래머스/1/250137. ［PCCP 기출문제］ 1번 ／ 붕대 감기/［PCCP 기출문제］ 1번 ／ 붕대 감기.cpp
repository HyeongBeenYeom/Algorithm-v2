#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = 0;
    int t,x,y;
    t = bandage[0];
    x = bandage[1];
    y = bandage[2];
    int curh = health;
    int a=0;
    int cont=0;
    for(int i=0;i<=attacks[attacks.size()-1][0];i++){
        if(attacks[a][0] == i){
            cont = 0;
            curh -= attacks[a][1];
            a++;
            if(curh <= 0){
                return -1;
            }
        }
        else{
            curh += x;
            cont++;
            if(cont == t){
                curh += y;
                cont = 0;
            }
            if(curh > health)
                curh = health;
        }
    }
    return curh;
}