#include <string>
#include <vector>
#include <queue>

//���α׷��ӽ�_�ٸ��� ������ Ʈ��_#42583 

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
		//���� �ð��� ����. 
		time++;
		
		int frontCarTime=bridge.front().first;
		int frontCar=bridge.front().second;
		
		//���� ���� �ٸ��� �� �ǳԴٸ� 
		if(time-frontCarTime==bridge_length){
			wSum-=frontCar;
			bridge.pop();
		} 
		
		if(!waiting.empty()){
			int carW=waiting.front();
			
			//�ڵ����� �ٸ��� ������ �����ϴٸ� 
			if(bridge.size()<bridge_length && wSum+carW<=weight){
				wSum+=carW;
				bridge.push(make_pair(time,carW));
				waiting.pop();
			}
		}
		
	}
	
	return time;
}
