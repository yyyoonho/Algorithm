#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cmath>

//BOJ #14890 경사로 

using namespace std;

int N,L; 
int totalCnt;
int map[100][100];
bool check[100][100];

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "rt", stdin);
	cin>>N>>L;
	
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			cin>>map[i][j];
		}
	}
	
	//행 
	memset(check, false, sizeof(check)); 
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			
			if(j==N-1){
				totalCnt++;
				break;
			}
			
			if(map[i][j]==map[i][j+1]) continue;
			
			else{
				int car = abs(map[i][j]-map[i][j+1]);
				if(car>1) break;
				
				//오르막
				if(map[i][j]<map[i][j+1]){
					//범위체크
					if((j-(L-1))<0) break;
					
					bool flag=true;
					
					//경사로 설치 
					for(int k=0; k<L; k++){
						if(check[i][j-k]==false && map[i][j]==map[i][j-k]){
							check[i][j-k]=true;
						}
						else{
							flag=false;
							break;
						} 
					} 
					
					if(flag==false) break;
				}
				
				//내리막 
				else if(map[i][j]>map[i][j+1]){
					//범위체크
					if((j+L)>N) break;
					
					bool flag=true;
					
					//경사로 설치
					for(int k=1; k<=L; k++){
						if(check[i][j+k]==false && map[i][j+1]==map[i][j+k]){
							check[i][j+k]=true;
						}
						else{
							flag=false;
							break;
						}
					}
					
					if(flag==false) break;
				}
				
			}
			
		}
	}
	
	//열
	memset(check, false, sizeof(check)); 
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			
			if(j==N-1){
				totalCnt++;
				break;
			}
			
			if(map[j][i]==map[j+1][i]) continue;
			
			else{
				int car = abs(map[j][i]-map[j+1][i]);
				if(car>1) break;
				
				//오르막
				if(map[j][i]<map[j+1][i]){
					//범위체크
					if((j-(L-1))<0) break;
					
					bool flag=true;
					
					//경사로 설치 
					for(int k=0; k<L; k++){
						if(check[j-k][i]==false && map[j][i]==map[j-k][i]){
							check[j-k][i]=true;
						}
						else{
							flag=false;
							break;
						} 
					} 
					
					if(flag==false) break;
				}
				
				//내리막 
				else if(map[j][i]>map[j+1][i]){
					//범위체크
					if((j+L)>N) break;
					
					bool flag=true;
					
					//경사로 설치
					for(int k=1; k<=L; k++){
						if(check[j+k][i]==false && map[j+1][i]==map[j+k][i]){
							check[j+k][i]=true;
						}
						else{
							flag=false;
							break;
						}
					}
					
					if(flag==false) break;
				}
				
			}
			
		}
	}
	
	cout<<totalCnt<<endl;
	
	return 0;
}
