#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
 
using namespace std;
 
 
int main()
{
	int t,a,b;
	scanf("%d",&t);
	int kase=1;
	while(t--)
	{
		scanf("%d%d",&a,&b);
		printf("Case %d: %d\n",kase++,a+b);
	}
}