#include <stdio.h>
#include <iostream>
#define N 15
using namespace std;
int main(){
    int i,j,k,a[N][N];
    for(i=0;i<N;i++)
    for(j=0;j<N;j++)
    a[i][j]=0; /*��ʼֵΪ��*/
    j=N/2;
    a[0][j]=1; /*ȷ��1��λ��*/ 
    for(k=2;k<=N*N;k++){
                        i--;
                        j++;
                        if(i<0)
                        i=N-1; /*�г���*/
                        else if(j>N-1)
                        j=0; /*�г���*/ 
                        if(a[i][j]==0)
                        a[i][j]=k; /*������˳��ȷ����ֵλ��*/
                        else{i=(i+2)%N;
                        j=(j-1+N)%N;
                        a[i][j]=k; /*��������ʱ���ֵ�λ��*/}}
                        printf("\n");
                        for(i=0;i<N;i++){
                                         printf("  ");
                                         for(j=0;j<N;j++)
                                         printf("%3d",a[i][j]); /*��ʾ�÷���*/
                                         printf("\n");}
                                         system("pause");
                                         return 0;
                                         }
