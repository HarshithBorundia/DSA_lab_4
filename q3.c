/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
void solve(int i,int a[],int t[],int *maxi,int k,int n,int rating){
    if(i==n){
        if(*maxi<rating) *maxi = rating;return;
    }
    solve(i+1,a,t,maxi,k,n,rating);
    if(t[i]<=k){
        solve(i+1,a,t,maxi,k-t[i],n,rating+a[i]);
    }
}
int main()
{
    
    int n;
    scanf("%d",&n);
    int k;
    scanf("%d",&k);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",a+i);
    }
    int t[n];
    for(int i=0;i<n;i++){
        scanf("%d",t+i);
    }
    int maxi = 0;
    solve(0,a,t,&maxi,k,n,0);
    printf("%d",maxi);

    return 0;
}

