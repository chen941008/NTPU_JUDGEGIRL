#include <stdio.h>
int max(int a,int b){
    if(a>b)return a;
    return b;
}
int main(){
    int n,arr[100]={0},index[200]={0},ans=0,sum=0;//index[0]for -100
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int temp;
        scanf("%d",&temp);
        if(temp==0)arr[i]=-1;
        else arr[i]=temp;
    }
    for(int i=0;i<n;i++){
        sum+=arr[i];
        if(sum==0)ans=i+1;
        else{
            if(index[sum+100]==0)index[sum+100]=i;
            else ans=max(ans,i-index[sum+100]);
        }
    }
    printf("%d\n",ans);
}