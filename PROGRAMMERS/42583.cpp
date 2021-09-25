#include <string>
#include <vector>
#include <queue>

//프로그래머스_다리를 지나는 트럭_#42583 

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int time=1;
    int wSum=0;
    queue<pair<int,int> > bridge;
    queue<int> waiting;
    
    for(int i=0; i<truck_weights.size();i++){
    	waiting.push(truck_weights[i]);
	}
	
	bridge.push(make_pair(time, waiting.front()));
	wSum+=waiting.front();
	waiting.pop();
	
	while(!bridge.empty()){
		//매초 시간은 간다. 
		time++;
		
		int frontCarTime=bridge.front().first;
		int frontCar=bridge.front().second;
		
		//선두 차가 다리를 다 건넜다면 
		if(time-frontCarTime==bridge_length){
			wSum-=frontCar;
			bridge.pop();
		} 
		
		if(!waiting.empty()){
			int carW=waiting.front();
			
			//자동차가 다리에 진입이 가능하다면 
			if(bridge.size()<bridge_length && wSum+carW<=weight){
				wSum+=carW;
				bridge.push(make_pair(time,carW));
				waiting.pop();
			}
		}
		
	}
	
	return time;
}
