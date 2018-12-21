#include<stdlib.h>
#include<stdio.h>
int main(){

int year,month,temp,time,flag,day;
int a,b,c,x=0,y;
int sum;
while(1){
    printf("Enter year and month: ");
    scanf("%d %d",&year,&month);
    flag=0;
    printf("\n%4d / %2d \n",year,month);
    printf("\nSUN\tMON\tTUE\tWED\tTHU\tFRI\tSAT\t\n");
    temp=(year-1)/4-(year-1)/100+(year-1)/400+year-1;
    time=temp%7+1;
    if(year%4==0&&year%100!=0||year%400==0)
        flag=1;

        if(month-1==0){
            day=0;
            y=31;
        }else if(month-1==1){
            day=31;
            y=28+flag;
        }else if(month-1==2){
            day=59+flag;
            y=31;
        }else if(month-1==3){
            day=90+flag;
            y=30;
        }else if(month-1==4){
            day=120+flag;
            y=31;
        }else if(month-1==5){
            day=151+flag;
            y=30;
        }else if(month-1==6){
            day=181+flag;
            y=31;
        }else if(month-1==7){
            day=212+flag;
            y=31;
        }else if(month-1==8){
            day=243+flag;
            y=30;
        }else if(month-1==9){
            day=273+flag;
            y=31;
        }else if(month-1==10){
            day=304+flag;
            y=30;
        }else if(month-1==11){
            day=334+flag;
            y=31;
        }

    time=(time+day)%7+1;
    for(b=0;b<time-1;b++){
        printf("\t");
        x=(time-1);
    }
    for(c=1;c<=y;c++){
        if(x==7){
            printf("\n");x=0;
        }
        printf("%3d\t",c);
        x++;
     }
    printf("\n\n");
    }
 return 0;
}
