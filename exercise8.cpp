#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<sstream>
using namespace std;

int min_dst(vector<float> &dist , vector<bool> &visited){
    float mindist=10000,minidx=-1;
    for(int i=0; i<dist.size();i++){
        if(!visited[i] && dist[i] < mindist){
            mindist=dist[i];
            minidx=i;
        }
    }
    return minidx;
}
void find_graph(vector<vector<float>>&gr, int start,int dest){
    int n=gr[0].size();
    vector<float> dist(n,100000);
    vector<bool> visited(n,false);
    unordered_map<int , int>child;
    dist[start]=0;
    for(int j=0; j<n-1; j++){
        int u=min_dst(dist , visited);
        if(u==-1||u==dest)break;
        visited[u]=true;
        for(int v=0; v<n; v++){
            if(!visited[v]&&gr[u][v]&&dist[u]!=100000 && dist[u]+gr[u][v]< dist[v] & gr[u][v]!= 1){
                dist[v]=dist[u]+gr[u][v];
                child[u]=v;
            }
        }
    }
    while(start!=dest){
        cout<<start<<endl;
        start=child[start];
    }
    cout<<start<<endl;
}
int main(){
    int n;
    cin>>n;
    vector<vector<float>>gr(n,vector<float>(n,0));
    for(int i=0; i<2*n; i++){
        string x;
        cin>>x;
        if(x== "."){
            continue;
        }
        string y;
        stringstream ss(x);
        while(getline(ss , y , ';')){
            string t;
            stringstream ss(y);
            vector<string> v;
            while(getline(ss , t , ',')){
                v.push_back(t);
            }
            if(i<n){
                gr[i][stoi(v[0])]=stoi(v[1]);
            }
            else{
                gr[i-n][stoi(v[0])]=stoi(v[1])/gr[i-n][stoi(v[0])];
            }
        }
    }
    int start;
    int dest;
    cin>>start>>dest;
    find_graph(gr,start,dest);
    return 0;
}