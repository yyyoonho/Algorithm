#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdlib>

using namespace std;

//1107
//���Ʈ����
//��Ž�� ����غ��� �ϴ�.
//�ð����⵵�� ����غ���.
//���ܸ� �� ì����. 

int N,M;
bool remoteBtn[11];

int SizeCheck(int num)
{
	if(num==0)
	{
		return 1;
	}
	
	int size=0;
	while(num>0)
	{
		size++;
		num/=10;
	}
	return size;
}

bool CanPushBtn(int num)
{
	if(num==0)
	{
		if(remoteBtn[num]) return true;
		else return false;
	}
	
	while(num>0)
	{
		if(remoteBtn[num%10]){
			num/=10;
			continue;
		}
		else
			return false;
	}
	
	return true;
}

void Input(){
	memset(remoteBtn, true, sizeof(remoteBtn));
	cin>>N>>M;
	
	int tmpBroken;
	for(int i=0; i<M; i++)
	{
		cin>>tmpBroken;
		remoteBtn[tmpBroken]=false;
	}
}

void Solve(){
	int minAns=abs(100-N);

	for(int i=0; i<=1000001; i++)
	{
		// i�� ���� �� �ִٸ� 
		if(CanPushBtn(i))
		{
			int tmpAns=abs(N-i)+SizeCheck(i);
			minAns=min(minAns,tmpAns);
		}
	}
	
	cout<<minAns;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("input.txt", "rt", stdin);
	
	Input();
	Solve();
	
	return 0;
} 
