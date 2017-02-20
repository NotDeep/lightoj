/*
 #pragma warning (disable: 4786)
 #pragma comment (linker, "/STACK:0x800000")
 */
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <iterator>
#include <utility>
using namespace std;

template< class T > T _abs(T n)
{
	return (n < 0 ? -n : n);
}
template< class T > T _max(T a, T b)
{
	return (!(a < b) ? a : b);
}
template< class T > T _min(T a, T b)
{
	return (a < b ? a : b);
}
template< class T > T sq(T x)
{
	return x * x;
}
template< class T > T gcd(T a, T b)
{
	return (b != 0 ? gcd<T>(b, a%b) : a);
}
template< class T > T lcm(T a, T b)
{
	return (a / gcd<T>(a, b) * b);
}
template< class T > bool inside(T a, T b, T c)
{
	return a<=b && b<=c;
}


#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define F(i, n) for(int (i)=0;(i)<(n);++(i))
#define rep(i, s, t) for(int (i)=(s);(i)<=(t);++(i))
#define urep(i, s, t) for(int (i)=(s);(i)>=(t);--(i))
#define repok(i, s, t, o) for(int (i)=(s);(i)<=(t) && (o);++(i))
#define MEM0(addr) memset((addr), 0, sizeof((addr)))
#define MP(x, y) make_pair(x, y)
#define REV(s, e) reverse(s, e)
#define SET(p) memset(pair, -1, sizeof(p))
#define CLR(p) memset(p, 0, sizeof(p))
#define MEM(p, v) memset(p, v, sizeof(p))
#define CPY(d, s) memcpy(d, s, sizeof(s))
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define SZ(c) (int)c.size()
#define PB(x) push_back(x)
#define ff first
#define ss second
#define ll long long
#define ld long double
#define pii pair< int, int >
#define psi pair< string, int >
#define ls u << 1
#define rs u << 1 | 1
#define lson l, mid, u << 1
#define rson mid, r, u << 1 | 1
#define debug(x) cout << #x << " = " << x << endl
const int N = 110, M = 510;
const double PI = acos(-1.0);

const int maxn = 110;
const int maxm = maxn * maxn;
const int inf = 1 << 29;
const ll mod = 3221225473;
const double eps = 1e-10;

int a[2*maxn+5][maxn+5],dp[2*maxn+5][maxn+5];
int main()
{
	//READ("in.txt");
	int T,n,i,j,ca=0;
	cin>>T;
	while(T--)
	{
		cin>>n;
		memset(a,0,sizeof(a));
		memset(dp,0,sizeof(dp));
		for( i=1;i<=n;i++)
			for(j=1;j<=i;j++)
				cin>>a[i][j];
		for(i=n+1;i<=2*n-1;i++)
			for(j=1;j<=2*n-i;j++)
				 cin>>a[i][j];
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=i;j++)
			 dp[i][j]=max(dp[i-1][j-1],dp[i-1][j])+a[i][j];
		}
		for(i=n+1;i<=2*n-1;i++)
		{
			for(j=1;j<=2*n-i;j++)
			  dp[i][j]=max(dp[i-1][j],dp[i-1][j+1])+a[i][j];
		}
		ca++;
		cout<<"Case "<<ca<<": "<<dp[2*n-1][1]<<endl;
	}
	return 0;
}