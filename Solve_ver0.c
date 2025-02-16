#include <stdio.h>
#include <stdint.h>
#include <time.h>

#define data_len 250
int new_data[data_len] = {1,2,3,-3,-2,-1,2,-3,3,-2,1,2,3,-3,-2,-1,2,-3,3,-2,1,2,3,-3,-2,-1,2,-3,3,-2,1,2,3,-3,-2,-1,2,-3,3,-2,1,2,3,-3,-2,-1,2,-3,3,-2,1,2,3,-3,-2,-1,2,-3,3,-2,1,2,3,-3,-2,-1,2,-3,3,-2,1,2,3,-3,-2,-1,2,-3,3,-2,1,2,3,-3,-2,-1,2,-3,3,-2,1,2,3,-3,-2,-1,2,-3,3,-2,1,2,3,-3,-2,-1,2,-3,3,-2,1,2,3,-3,-2,-1,2,-3,3,-2,1,2,3,-3,-2,-1,2,-3,3,-2,1,2,3,-3,-2,-1,2,-3,3,-2,1,2,3,-3,-2,-1,2,-3,3,-2,1,2,3,-3,-2,-1,2,-3,3,-2,1,2,3,-3,-2,-1,2,-3,3,-2,1,2,3,-3,-2,-1,2,-3,3,-2,1,2,3,-3,-2,-1,2,-3,3,-2,1,2,3,-3,-2,-1,2,-3,3,-2,1,2,3,-3,-2,-1,2,-3,3,-2,};
int base_data[3]={-1,-2,-3};

int main(){
    int flag = 1;
    int checker = 0;
    int len = 0;
    int data[data_len] = {0};
    int set_data[data_len] = {0};
    long cpu_time;
    double sec;
    for(int i=0;i<3;i++){
        data[i]=base_data[i];
    }
    for(uint8_t num=3;num<data_len;num++){
        if(new_data[num]!=0){
            data[checker]=new_data[num];
            checker++;
        }
    }
    len = checker;
    while(flag){
        flag=0;
        for (int j = 1; j <10; j++){
            if(data[j]!=0){
                if((data[j]+data[j-1])==0){
                    data[j]=0;
                    data[j-1]=0;
                    flag=1;
                }
            }
        }


        checker = 0;
        for(int i=0;i<len;i++){
            set_data[i]=0;
        }
        for(uint8_t num=0;num<len;num++){
            if(data[num]!=0){
                printf("%d -> %d",data[num],set_data[checker]);
                set_data[checker]=data[num];
                printf("||%d == %d\n",data[num],set_data[checker]);
                checker++;
            }
        }
        len=checker;
        for(int j=0;j<len;j++){
            data[j]=set_data[j];
        }
        printf("\n");
        printf("%d\n",flag);
    }
    for(int j=0;j<checker;j++){
        printf("%d,",data[j]);
    }
    printf("\n\nsize : %d",checker);
    cpu_time = clock();
    sec = (double)cpu_time/CLOCKS_PER_SEC;
    printf("\n実行時間:%fs",sec);

}
