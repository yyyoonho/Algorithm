#include <algorithm>
#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

//백준_15686_치킨배달 

int N,M; 
int map[51][51];
vector<pair<int,int> > home;
vector<pair<int,int> > dak;
int chosenDak[14];
int dakIdx=0;
int top=0;

int minDis=2147483647;

int distance(){
	int sum=0;
	
	for(int i=0; i<home.size(); i++){
		int tmpDis=2147483647;
		for(int j=0; j<top; j++){
			tmpDis=min(tmpDis,abs(home[i].first-dak[chosenDak[j]].first)
				+abs(home[i].second-dak[chosenDak[j]].second));
		}
		sum+=tmpDis;
	}
	return sum;
}

void choiceDak(int next){
	if(top==M){
		minDis=min(minDis,distance());
		return;
	}
	
	for(int i=next; i<dak.size(); i++){
		chosenDak[top++]=i;
		choiceDak(i+1);
		top--;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "rt", stdin);
	cin>>N>>M;
	
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			cin>>map[i][j];
			if(map[i][j]==1) home.push_back(make_pair(i,j));
			if(map[i][j]==2) dak.push_back(make_pair(i,j));
		}
	}
	
	//치킨집뽑기
	choiceDak(0);
	
	cout<<minDis<<endl;

	return 0; 
}
