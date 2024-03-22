#include <string>
#include <vector>

using namespace std;

string s = "AEIOU";
string t = "";
int cnt = -1;
int answer=0;

void DFS(string word){
    cnt++;
    if(word == t){
        answer = cnt;
        return;
    }
    if(word.length() >= 5)
        return;
    for(int i=0;i<s.length();i++){
        DFS(word+s[i]);
    }
}

int solution(string word) {
    t = word;
    DFS("");
    return answer;
}