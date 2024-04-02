#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
unordered_map<int,int>colors;

bool is_valid_color(int node,int color,const vector<vector<int>> &graph){
    for(int neighbor:graph[node]){
        if(colors.find(neighbor)!=colors.end()&& colors[neighbor]==color){
            return false;
        }
    }
    return true;
}
bool color_graph(int node,int N,const vector<vector<int>>&graph){
    if(node==N+1){
        return true;
    }
    for(int color : {0,1}){
        if(is_valid_color(node,color,graph)){
            colors[node]=color;
            if(color_graph(node+1,N,graph)){
                return true;
            }
            colors.erase(node);
        }
    }
    return false;
}
int main(){
    int N,M;
    cin>>N>>M;
    vector<vector<int>>graph(N+1);
    for(int i=0; i<M; ++i){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    if(color_graph(1,N,graph)){
        int min_red_nodes=N;
        for(int i=1; i<=N; ++i){
            colors.clear();
            if(color_graph(1,N,graph)){
                int red_nodes=0;
                for(const auto& entry:colors){
                    if(entry.second==0){
                        red_nodes++;
                    }
                }
    min_red_nodes=min(min_red_nodes,red_nodes);
            }
        }
        cout<<min_red_nodes<<endl;
    }else{
        cout<<"NO"<<endl;
    }
    return 0;
}