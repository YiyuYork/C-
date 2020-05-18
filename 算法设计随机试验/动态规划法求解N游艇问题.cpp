#include<iostream>
#define N 6
using namespace std;

void Floyd(int arc[N][N],int dist[N][N]){
	int i,j,k;
	//初始化矩阵dist
	for(i=0;i<N;i++)
		for(j=0;j<N;j++)
			dist[i][j]=arc[i][j];
	
	for(k=0;k<N;k++)
		for(i=0;i<N;i++)
			for(j=0;j<N;j++)
				if(dist[i][k]+dist[k][j]<dist[i][j])
					dist[i][j]=dist[i][k]+dist[k][j];
}

int main(){
	int fee[N][N]={{0,3,15,18,29,34},
				 {3,0,1, 17,18,23},
				 {15,1,0,10,12,15},
				 {18,17,10,0,4, 7},
				 {29,18,12,4,0, 1},
				 {34,23,15,7,1, 0}};
	int dist[N][N];
	Floyd(fee,dist);
	int a = dist[0][N-1];
	cout<<"最短路径:"<<a<<endl;
	return 0;
}
