#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdlib>

using namespace std;

//1107
//브루트포스
//완탐도 고려해봄직 하다.
//시간복잡도를 계산해보자.
//예외를 잘 챙기자. 

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
		// i를 누를 수 있다면 
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
