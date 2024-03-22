#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    
    map<string, int> c;
    for(int i=0;i<clothes.size();i++){
        c[clothes[i][1]] += 1;
    }
    for(auto a : c){
        answer *= (a.second + 1);
    }
    return --answer;
}