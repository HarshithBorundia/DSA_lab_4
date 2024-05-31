/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
void solve(int i,long long k,char arr[],long long l,long long r,long long n ,int*cnt){
    if(k<0) return;
    if(i==n && k==0){
        if(l<=atoll(arr) && r>=atoll(arr))
        (*cnt)++;
        return;
    }
    if(i==n) return;
    if (arr[i] != '?') {
        solve(i + 1, k, arr, l, r, n, cnt);
        return;
    }
    for(int ind = (i==0?1:0);ind<10;ind++){
            arr[i]=ind +'0';
            solve(i+1,k-ind,arr,l,r,n ,cnt);
            arr[i] = '?';
    }
    
}
int main()
{
    long long n,k,l,r;
    scanf("%lld %lld %lld %lld", &n, &k ,&l ,&r);
    char arr[n];
    scanf("%s",arr);
    int sum = 0;
    for(int i=0;i<n;i++){
        if(arr[i]>='0' && arr[i]<='9'){
            sum+= arr[i]-'0';
        }
    }
    k-=sum;
    int cnt = 0;
    solve(0,k,arr,l,r,n,&cnt);
    printf("%d",cnt);
    return 0;
}

