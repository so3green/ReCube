#include <stdio.h>
#include <stdint.h>
#include <time.h>

//Make data
int TrySum=1;
#define SolveSum 40
int mainData[SolveSum]={-2,2,3,-2,2,-3,3,-2,2,-3,3,-1,1,-3,3,-1,1,-3,-2,2,-2,-1,-2,2,1,-1-3,-1,-2,1};
int AnswerSum=0;

//Time
long cpu_time;
double sec;

//one simulation
#define data_len 100
//int data[data_len] = {4,3,2,1};
int answer[3] = {-3,-2,-1};
int newData[data_len]={0};
int flagData[data_len]={0};
int checksum=0;
int flag=0;

/*
int dataInit(){
    for(int i=0;i<4;i++){
        newData[i]=answer[i];
    }
    for (int i = 0; i < TrySum; i++)
    {
        newData[i+4]=data[i];
    }  
}
*/

int dataInit(){
    for(int i=0;i<3;i++){
        newData[i]=answer[i];
    }
    newData[3]=mainData[0];
}

int dataFormat(){
    newData[AnswerSum]=mainData[TrySum];
    TrySum++;
}

int solve_x2(int d1,int d2){
    if((d1+d2)==0){
        if((d1==0)||(d2==0)){
            return 0;
        }else{
            return 1;
        }
    }else{
        return 0;
    }
}

int Solver(){
    do{
        flag=0;
        checksum=0;
        for(int i=0;i<100;i++){
            flagData[i]=0;
        }
        for(int i=0;i<100;i++){
            if(solve_x2(newData[i],newData[i+1])==1){
                newData[i]=0;
                newData[i+1]=0;
                flag=1;
            }
        }
        for(int i=0;i<100;i++){
            if(newData[i]!=0){
                flagData[checksum]=newData[i];
                checksum++;
            }
        }
        for(int i=0;i<100;i++){
            newData[i]=flagData[i];
        }
    }while(flag==1);
}
int SolveSys(){
    AnswerSum=0;
    for(int i=0;i<100;i++){
        if(newData[i]!=0){
            AnswerSum++;
        }
    }
    dataFormat();
    Solver();
}
int main(){
    dataInit();
    Solver();
    AnswerSum=0;
    for(int i=0;i<100;i++){
        if(newData[i]!=0){
            AnswerSum++;
        }
    }printf("%d,",AnswerSum);
    for(int i=1;i<SolveSum;i++){
        SolveSys();
        
        AnswerSum=0;
        for(int i=0;i<100;i++){
            if(newData[i]!=0){
                AnswerSum++;
            }
        }printf("%d,",AnswerSum);
    }
    cpu_time = clock();
    sec = (double)cpu_time/CLOCKS_PER_SEC;
    printf("\nTime:%fs",sec);
}