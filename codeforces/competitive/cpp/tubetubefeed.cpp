#include<bits/stdc++.h>
using namespace std;
int q,n,t,p,o;
int a[101],b[101];
int main()
{
	scanf("%d",&q);
	while (q--)
	{
		o=p=-1;
		scanf("%d %d",&n,&t);
		for (int i=1;i<=n;i++)scanf("%d",&a[i]);
		for (int i=1;i<=n;i++)scanf("%d",&b[i]);
		for (int i=1;i<=n;i++)
		if (a[i]+i-1<=t&&o<=b[i])o=b[i],p=i;
		printf("%d\n",p);
	}
}