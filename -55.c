#include <stdio.h>
int main(){
    int m,n,x1,y1,e1,n1,f1,x2,y2,e2,n2,f2;
    scanf("%d%d%d%d%d%d%d%d%d%d%d%d",&m,&n,&x1,&y1,&e1,&n1,&f1,&x2,&y2,&e2,&n2,&f2);
    while (f1||f2){
        while (f1)
        {
            for(int i=0;i<n1&&f1-->0;i++){
                y1++;
                if(y1>=n)y1=0;
            }
        }
        while (f2)
        {
            /* code */
        }
    }
}