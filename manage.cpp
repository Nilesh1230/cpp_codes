#include<iostream>
#include<vector>
using namespace std;
#define inf 10000000
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>graph(n,vector<int>(n,inf));
    for(int i=0; i<n; i++){
        graph[i][i]=0;
    }
    for(int i=0; i<m; i++){
        int x,y;
        cin>>x>>y;
        graph[x][y]=1;
        graph[y][x]=1;
    }
    
    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                graph[i][j]=min(graph[i][j],graph[i][k]+graph[k][j]);
            }
        }
    }
    int u,v;
    cin>>u>>v;
    int t=graph[u][v];
    int q;
    cin>>q;
    int c[q];
    for(int i=0;i<q;i++){
        cin >> c[i];
    }
    for(int i=0; i<q; i++){
        if((graph[u][c[i]]+graph[c[i]][v])>t){
            cout<<"NO"<<endl;
        }else{
            cout<<"YES"<<endl;
        }
    }
    return 0;
}
    
