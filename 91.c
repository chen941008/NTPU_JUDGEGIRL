#include <stdio.h>
#include <stdbool.h>
int main (void)
{
    int time=0;
    bool first=true;
    while (1) {
        if(!first){
            printf("\n");
        }
        else first=false;
        time++;
        int n,high[55]={0},sum=0,average=0,count=0;
        scanf("%d",&n);
        if(n==0)break;
        for(int i=0;i<n;i++){
            scanf("%d",&high[i]);
            sum+=high[i];
        }
        average=sum/n;
        for(int i=0;i<n;i++){
            if(high[i]>average)count+=high[i]-average;
        }
        printf("Set #%d\n",time);
        printf("The minimum number of moves is %d.",count);

    }
        return 0;
}