#include<stdio.h>
int visited[100];
int a[100][100];
int stack[100];
int top=-1;
void dfs(int n, int i){
	if(visited[i]==1)return;
	else{
		visited[i]=1;
		for(int j=0; j<n; j++){
			if(a[i][j]==1 && visited[j]==0){
				//printf("%d\n",j);
				dfs(n,j);
			}
		}
		stack[++top]=i;
	}
}
void topsort_dfs(int n){
	for(int j=0;j<n;j++){
		dfs(n, j);
	}
	while(top>=0){
		printf("%d ", stack[top--]);
	}
	printf("\n");
}
int main(){
	int n;
	printf("Enter no of vertices:\n");
	scanf("%d", &n);
	printf("Enter adjacency matrix:\n");
	for(int i=0;i<n;i++){
		for(int j=0; j<n; j++)
			scanf("%d",&a[i][j]);
		visited[i]=0;
	}
	topsort_dfs(n);
}
