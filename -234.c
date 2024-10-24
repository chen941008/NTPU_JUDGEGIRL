#include <stdio.h>
#include <math.h>

int main(){
    long long int factor[500]={0},factor_count=0;
    long long int a,b,c,times;
    scanf("%lld%lld%lld",&a,&b,&c);
    times= floor(pow(c,0.5))+1;
    for (int i = 1; i <= times; i++) {
        if (c % i == 0) { 
            factor[factor_count++] = i; 
            if (i != c / i) { 
                factor[factor_count++] = c / i; 
            }
        }
    }
    
}