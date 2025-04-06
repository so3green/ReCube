#include <stdio.h>
#include <stdint.h>
#include <time.h>

#define data_len 100
int data[data_len] = {3,2,1};
int answer[3] = {-1,-2,-3};
int newData[data_len]={0};
int flag=0;
int dataInit(){
    for(int i=0;i<3;i++){
        newData[i]=answer[i];
    }
    for (int i = 0; i < 100; i++)
    {
        newData[i+3]=data[i];
    }
    
}
int solve_x2(int d1,int d2){
    if((d1+d2)==0){
        return 1;
    }else{
        return 0;
    }
}

int Solver(){
    do{
        flag=0;
        for(int i=1;i<100;i++){
            if(solve_x2(newData[i-1],newData[i])==1){
                newData[i-1]=0;
                newData[i]=0;
                flag = 1;
            }
        }
    }while(flag==0);
}

int main(){
    dataInit();
    Solver();
    for (int i = 0; i < 103; i++)
    {
        printf("%d,",newData[i]);
    }
    
}