#include "Capture.h"
#include <stdio.h>
#include <stdbool.h>
void CaptureOppPieces(int board[4][4], int turn) {
    bool have_level_0=false;//我方有0 level
    int new_board[6][6]={0};
    for(int i=0;i<6;i++){
        for(int j=0;j<6;j++){
            new_board[i][j]=-1;
            if(turn==board[i][j])have_level_0=true;
            if((i<5&&i>0)&&(j<5&&j>0))new_board[i][j]=board[i-1][j-1];
        }
    }
    int n=8;
    if(turn){//    我方奇
        while (n--){//找對手的level從大到小殺掉(找偶數) 奇殺偶
            int arr[16]={0};//存殺人的棋
            for(int i=1;i<5;i++){
               for(int j=1;j<5;j++){
                    if((n-1)*2==new_board[i][j]){//找到目標
                        for(int k=i-1;k<=i+1;k++){//搜尋其周圍
                            for(int l=j-1;l<=j+1;l++){
                                if(l==j&&k==i)continue;
                                if(new_board[i][j]==14&&new_board[k][l]==1)continue;
                                if((new_board[i][j]>new_board[k][l])&&(new_board[k][l]!=-1)){ 
                                    arr[new_board[k][l]]++;
                                }
                            }
                        }
                        for(int a=15;a>=0;a-=2){
                            if(arr[a]!=0)printf("%d is captured by %d\n",new_board[i][j],a);
                        }
                    }
                }
            }
            if(have_level_0&&n==8){ //找 level 0 去殺 level 7
                for(int i=1;i<5;i++){
                    for(int j=1;j<5;j++){
                        if(new_board[i][j]==turn){
                            for(int k=i-1;k<=i+1;k++){
                                for(int l=j-1;l<=j+1;l++){
                                    if(l==j&&k==i)continue;
                                    if(new_board[k][l]==14){
                                        printf("14 is captured by 1\n");
                                        break;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    else {//    我方偶
        while (n--){//找對手的level從大到小殺掉(找奇數) 偶殺雞
            int arr[16]={0};//存殺人的棋
            for(int i=1;i<5;i++){
               for(int j=1;j<5;j++){
                    if((n-1)*2+1==new_board[i][j]){//找到目標
                        for(int k=i-1;k<=i+1;k++){//搜尋其周圍
                            for(int l=j-1;l<=j+1;l++){
                                if(l==j&&k==i)continue;
                                if(new_board[i][j]==14&&new_board[k][l]==1)continue;
                                if((new_board[i][j]-new_board[k][l]>=1)&&(new_board[k][l]!=-1)){ 
                                    arr[new_board[k][l]]++;
                                }
                            }
                        }
                        for(int a=14;a>=0;a-=2){
                            if(arr[a]!=0)printf("%d is captured by %d\n",new_board[i][j],a);
                        }
                    }
                }
            }
            if(have_level_0&&n==8){ //找 level 0 去殺 level 7
                for(int i=1;i<5;i++){
                    for(int j=1;j<5;j++){
                        if(new_board[i][j]==turn){
                            for(int k=i-1;k<=i+1;k++){
                                for(int l=j-1;l<=j+1;l++){
                                    if(l==j&&k==i)continue;
                                    if(new_board[k][l]==14){
                                        printf("15 is captured by 0\n");
                                        break;
                                    }
                                }
                            }
                        }
                    }
                }  
            }
        }
    }
}