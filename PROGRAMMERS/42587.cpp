#include <string>
#include <vector>
#include <queue>

//PROGRAMMERS_«¡∏∞≈Õ #42587

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer=0;
    int cnt=0;
    queue<pair<int,int> > Q;
    priority_queue<int> pQ;
    
    for(int i=0; i<priorities.size(); i++){
        Q.push(make_pair(i,priorities[i]));
        pQ.push(priorities[i]);
    }
    
    while(!Q.empty()){
        int idx=Q.front().first;
        int val=Q.front().second;
        Q.pop();
        
        if(pQ.top()==val){
            pQ.pop();
            cnt++;
            if(idx==location){
                answer=cnt;
                break;
            }
        }
        
        else{
            Q.push(make_pair(idx,val));
        }
    }
    return answer;
}
