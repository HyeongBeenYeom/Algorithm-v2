#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

map<int, long long> m;
set<int> s;

int solution(vector<int> food_times, long long k) {
    int answer = 0;
    long long size = food_times.size();
    long long remain = size;
    long long now,prev=0;
    long long finish=0;
    
    if(k < size)
        return k+1;
    
    for(int i=0;i<size;i++){
        m[food_times[i]]++;
        s.insert(food_times[i]);
    }
    
    for(auto& t:s){
        now = t;
        long long tmp = (now - prev) * remain;
        if(finish + tmp > k)
            break;
        finish += tmp;
        remain -= m[t];
        prev = now;
    }
    
    if(remain == 0)
        return -1;
    
    long long idx = k - finish;
    vector<pair<int,int>> ret;
    for(int i=0;i<size;i++){
        if(food_times[i] >= now)
            ret.push_back({food_times[i], i+1});
    }
    idx %= ret.size();
    answer = ret[idx].second;
    return answer;
}