#include <stdio.h>
#include <algorithm>
#include <queue>
#include <iostream>
#include <vector>

using namespace std;

//����_1837_��ȣ����

string P;
int K; 
bool visit[1000002]; // false->�Ҽ�, true->�Ҽ��ƴ� 

bool check(int num){
	int sum=0;
	
	//�־��� ��P�� �� �ڸ�������(ū �ڸ�������) �������.
	for(int i=0; P[i]; i++)
		sum=(sum*10+(P[i]-'0'))%num;
		
	if(sum==0) return true;
	return false; 
}

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "rt", stdin);
	cin>>P>>K;
	
	bool state = true;
	int minPrime=0;
	
	for(int i=2; i<K; i++){
		if(visit[i]==true) continue; //�����佺�׳׽� �� ü Ȯ�� 
		
		if(check(i)){ // k���� ���� ���� ������ ���ٸ� -> Bad ��й�ȣ. 
			state=false;
			minPrime=i;
			break;
		}
		
		for(long long j=(long long)i*i; j<K; j+=i) // �����佺�׳׽��� ü -> ����ΰ͵� true 
			visit[j]=true; 
	}
	
	if(state) cout<<"GOOD";
	else cout<<"BAD"<<" "<<minPrime; 

	
	return 0; 
}
