/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main()
{
    int m,k;
    scanf("%d %d",&m ,&k);
    if(k==0 && m==1) printf("0 0");
    if(k==0 && m>1) printf("-1 -1");
    else{
        char maxi[m];
        int i = 0;
        int maxi_k = k;
        while(i<m){
            if(maxi_k>10){
                maxi[i++] = '9';
                maxi_k-=9;
            }
            else{
                maxi[i++] = maxi_k +'0';
                maxi_k-=maxi_k;
            }
        }
        char mini[m];
        int j = m-1;
        mini[0] = 1;
        int mini_k = k-1;
        while(j>0){
            if(mini_k>=10){
                mini[j--] = '9';
                mini_k-=9;
            }
            else{
                mini[j--] = mini_k +'0';
                mini_k-=mini_k;
            }
        }
        if(mini_k>=9){
                printf("-1 -1"); return 0;
        }
        else{
                mini[j--] += mini_k +'0';
                mini_k-=mini_k;
        }
        if(mini_k==0 && maxi_k==0){
            for(int i=0;i<m;i++){
                printf("%c",maxi[i]);
            }
            printf(" ");
            for(int i=0;i<m;i++){
                printf("%c",mini[i]);
            }
        }
        else{
            printf("-1 -1");
        }
    }

    return 0;
}


