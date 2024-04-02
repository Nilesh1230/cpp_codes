#include<stdio.h>
#include<math.h>
#include<stdbool.h>
#include<float.h>

typedef struct{
    double x,y;
}point;

double dist(point a,point b){
    return sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2));
}
int main(){
    int n;
    scanf("%d",&n);
    point points[n];
    for(int i=0; i<n; i++){
        scanf("%lf %lf",&points[i].x,&points[i].y);
    }
    double total=0.0;
    double key[n];
    bool mstset[n];
    for(int i=0; i<n; i++){
        key[i]=DBL_MAX;
        mstset[i]=false;
    }
    key[0]=0.0;
    for(int count=0; count<n-1; count++){
        double min=DBL_MAX;
        int min_idx;
        for(int v=0; v<n; v++){
            if(mstset[v]==false && key[v]<min){
                min=key[v];
                min_idx=v;
            }
        }
        int u=min_idx;
        mstset[u]=true;
        for(int v=0; v<n; v++){
            if(!mstset[v]&&dist(points[u],points[v])<key[v]){
                key[v]=dist(points[u],points[v]);
            }
        }
    }
    for(int i=0; i<n; i++){
        total+=key[i];
    }
    printf("%.7f\n",total);
    return 0;
}