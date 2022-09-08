#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
 
//boj_16953
//�׸��� 

long long A;
long long B;
int cnt;

long long cal(long long num){
	cnt++;
	//���� ¦���� ���
	if(num%2==0){
		return num/2;
	} 
	//���� 1�ΰ��
	else if(num%10==1){
		return num/10;
	}
	//���� Ȧ���ΰ��
	else{
		return -1;
	}
}

void Input(){
	cin>>A;
	cin>>B;
}

void Solve(){
	while(true){
		if(B<=A || B==-1){
			break;
		}
		//cout<<cal(B)<<endl;
		B=cal(B);
	}
	
	if(B!=A){
		cout<<-1;
	}
	else cout<<cnt+1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	//freopen("input.txt", "rt", stdin);
	
	Input();
	Solve();
	
	return 0;
} 
