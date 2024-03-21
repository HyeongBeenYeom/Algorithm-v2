#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s) {
    string answer = "";
    
    int idx=0;
    for(int i=0;i<s.length();i++){
        if(s[i] == ' '){
            idx = 0;            
        }            
        else if(idx%2==0){
            s[i] = toupper(s[i]);
            idx++;
        }
        else{
            s[i] = tolower(s[i]);
            idx++;
        }
    }
    
    return s;
}