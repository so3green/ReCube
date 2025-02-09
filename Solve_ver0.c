#include <stdio.h>
#include <stdint.h>

#define data_len 100
int new_data[100] = {3,2,-2,-3,2,2,1,-1,-2};

int main(){
    uint8_t flag = 1;
    uint8_t checker = 0;
    uint8_t len = 0;
    int data[100] = {0};
    int set_data[100] = {0};

    for(uint8_t num=0;num<100;num++){
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
}
