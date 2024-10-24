#include <stdio.h>
#include <stdbool.h>

int main(){
    int n;
    scanf("%d",&n);
    while (n--)
    {   
        bool is_die=false;
        int radish[5]={0},n,m,poisoned=0;
        for(int i=1;i<5;i++){
            scanf("%d",&radish[i]);
            if(i>2)radish[i]=-radish[i];
        }
        scanf("%d%d",&n,&m);
        while (1)
        {
            int status;
            scanf("%d",&status);
            if(status==-1)break;
            m-=n*poisoned;
            if(m<=0)is_die=true;
            m+=radish[status];
            if(m<=0)is_die=true;
            if(status==4)poisoned++;
        }
        if(is_die)printf("bye~Rabbit\n");
        else printf("%d\n",m);
    }
    
}