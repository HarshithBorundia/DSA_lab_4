/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
void solve(int *maxi,int a[],int n,int k,int i){
    if(k==0){
        (*maxi)++;
        return;
    }
    if(i==n) return;
    if(a[i]<=k)
    solve(maxi,a,n,k-a[i],i);
    solve(maxi,a,n,k,i+1);
    
}
int main()
{
    int n,k;
    scanf("%d %d",&n ,&k);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",a+i);
    }
    int maxi = 0;
    solve(&maxi,a,n,k,0);
    printf("%d",maxi);

    return 0;
}

