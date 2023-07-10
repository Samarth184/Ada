#include <stdio.h>

int q[10];
int f, r;
int v[10],adj[10][10];
int n;
void bfs(int);

int main(){
    int ver=0;
    printf("Enter the number of vertices in the di-graph\n");
    scanf("%d",&n);
    printf("\nEnter the adjacency matrix\n");
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&adj[i][j]);
        }
    }
    printf("\nEnter the source vertex:\n");
    scanf("%d",&ver);
    printf("\nThe bfs traversal from node %d is:\n",ver);
    bfs(ver);
    return 0;
}

void bfs(int ver){
    v[ver] = 1;
    f = 1;
    r = 1;
    q[r] = ver;
    
    while(f<=r){
        printf("%d ",q[f]);
        for(int j=1;j<=n;j++){
            
            if(adj[q[f]][j] == 1 && v[j]==0){
                q[++r] = j;
                v[j] = 1;
            }
            
        }
        f++;
    }
}