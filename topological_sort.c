#include <stdio.h>

int v[10],adj[10][10];
void dfs(int);
int n;
int sort[10];
int sindex  = 0;
int main(){
    
    printf("Enter the number of edges in the graph\n");
    scanf("%d",&n);
    printf("\nEnter the adjacency matrix\n");
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&adj[i][j]);
        }
    }

    printf("\n The traversal is:\n");

    for(int i=1;i<=n;i++){
        if(v[i] == 0){
            dfs(i);
            sort[sindex++] = i; 
        }
    }
    for(int i=sindex-1; i>=0; i--){
        printf("%d - ",sort[i]);
    }

    return 0;
}

void dfs(int ver){
    v[ver] = 1;
    // printf("%d ",ver);
    for(int j=1;j<=n;j++){
        if(adj[ver][j]==1 && v[j]==0){
            dfs(j);
            sort[sindex++] = j;
        }
    }
}