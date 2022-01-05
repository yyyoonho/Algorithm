#include <stdio.h>
#include <algorithm>
#include <queue>
#include <iostream>
#include <vector>

using namespace std;

//백준_1991_트리순회 

struct Node{
	char left;
	char right;
};

int N; 
Node dataE[27];

void preOrder(char node){
	if(node=='.') return;
	
	cout<<node;
	preOrder(dataE[node-'A'].left);
	preOrder(dataE[node-'A'].right);
}

void inOrder(char node){
	if(node=='.') return;
	
	inOrder(dataE[node-'A'].left);
	cout<<node;
	inOrder(dataE[node-'A'].right);
}

void postOrder(char node){
	if(node=='.') return;
	postOrder(dataE[node-'A'].left);
	postOrder(dataE[node-'A'].right);
	cout<<node;
}

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "rt", stdin);
	cin>>N;
	
	char a1,b1,c1;
	for(int i=0; i<N; i++){		
		cin>>a1>>b1>>c1;
		dataE[a1-'A'].left=b1;
		dataE[a1-'A'].right=c1;
	}
	
	preOrder('A');
	cout<<endl;
	inOrder('A');
	cout<<endl;
	postOrder('A');
	cout<<endl;
	
	return 0; 
}
