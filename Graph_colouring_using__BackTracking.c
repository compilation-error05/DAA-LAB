#include<stdio.h>
#include<stdlib.h>
int node,v,e,a,b,k;
int g[50][50];int col[50];
void next_color(int k,int v);
int main(){
    printf("Enter the no.of vertices::\n");
    scanf("%d",&v);
    printf("Enter the no.of edge::\n");
    scanf("%d",&e);
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            g[i][j]=0;
        }
    }
    printf("Enter the vertex b/w which we want an edge::\n");
    for(int i=0;i<e;i++){
        int a,b;
        scanf("%d" "%d",&a,&b);
        g[a][b]=1;
        g[b][a]=1;
    }
    next_color(0,v);//starting_node,no. ofvertex

}
void display(int n){
    for(int i=0;i<n;i++){
        printf("Color of [%d]node:%d \n",i+1,col[i]);
    }
}
void next_color(int k,int n){
    if(n==k){//when all the nodes are done::base case
        display(k);
        return;
    }
    col[k]=1;
    for(int i=0;i<k;i++){
        if(g[i][k]!=0 && col[k]==col[i]){/*edges are not disconnected && 
        col are same then to change the current color we update it by:+1*/
            col[k]=col[i]+1;
        }
    }
    next_color(k+1,n);
}