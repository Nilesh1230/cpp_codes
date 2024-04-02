#include<stdio.h>
struct Assign{
    int deadline;
    int time;
    int index;
};

void min_lat(struct Assign assign[],int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n-i-1; j++){
            if(assign[j].deadline>assign[j+1].deadline){
                struct Assign temp=assign[j];
                assign[j]=assign[j+1];
                assign[j+1]=temp;
            }
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n-i-1; j++){
            if(assign[j].deadline==assign[j+1].deadline){
                if(assign[j].time>assign[j+1].time){
                    struct Assign temp=assign[j];
                    assign[j]=assign[j+1];
                    assign[j+1]=temp;
                }
            }
        }
    }
    int current=0;
    int total=0;
    for(int i=0; i<n; i++){
        printf("%d ",assign[i].index);
        current+=assign[i].time;
        int lateness=current-assign[i].deadline;
        if(lateness<0){
            lateness=0;
        }
        total+=lateness;
    }
    printf("%d ",total);
}
int main(){
    int n;
    scanf("%d",&n);
    struct Assign assign[n];
    for(int i=0; i<n; i++){
        scanf("%d ",&assign[i].deadline);
        assign[i].index=i+1;
    }
     for(int i=0; i<n; i++){
        scanf("%d",&assign[i].time);
     }
     min_lat(assign,n);
     return 0;
}