#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    bool answer = true;
    
    if(s.length() != 4 && s.length() != 6)
        return false;
    
    for(int i=0;i<s.length();i++){
        if((int)s[i] < 48 || (int)s[i] > 57)
            return false;
    }
    return answer;
}