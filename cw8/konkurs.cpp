#include<cstdio>
main(){int n,k=2;scanf("%d",&n);for(;n%k?k++:printf("%d ",k,n/=k););}
