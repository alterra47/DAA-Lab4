#include<stdio.h>
int indegree[100];
int a[100][100];
int stack[100];
int top=-1;
void topsort_rsrc(int n){
	for(int i=0;i<n;i++){
		for(int j=0; j<n; j++){
			if(a[i][j]==1)indegree[j]++;
		}
	}
	for(int i=0;i<n;i++){
		if(indegree[i]==0){
			stack[++top]=i;
			break;
		}
	}
	while(top>=0){
		int i = stack[top--]; 
		printf("%d ", i);
		for(int j=0; j<n; j++){
			if(a[i][j]==1){
				indegree[j]--;
				if(indegree[j]==0)stack[++top]=j;
			}
		}
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
		indegree[i]=0;
	}
	topsort_rsrc(n);
}
