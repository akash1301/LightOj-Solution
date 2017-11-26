/////////////////////// All Is Well /////////////////////////

#include <bits/stdc++.h>

#define FOR(i, s, e) for(int i=s; i<e; i++)
#define loop(i, n) for(int i=0; i<n; i++)
#define getint(n) scanf("%d", &n)
#define pb(a) push_back(a)
#define ll long long int
#define ull unsigned long long int
#define dd double
#define SZ(a) int(a.size())
#define read() freopen("input.txt", "r", stdin)
#define write() freopen("output.txt", "w", stdout)
#define mem(a, v) memset(a, v, sizeof(a))
#define all(v) v.begin(), v.end()
#define pi acos(-1.0)
#define pf printf
#define sf scanf
#define mp make_pair
#define paii pair<int, int>
#define padd pair<dd, dd>
#define pall pair<ll, ll>
#define fr first
#define sc second
#define CASE(n) printf("Case %d:\n",++n)
#define inf 1000000000
#define EPS 1e-9

using namespace std;

//8 way moves
//int fx[]={0,0,1,-1,1,1,-1,-1};
//int fy[]={1,-1,0,0,1,-1,1,-1};

//knight moves
//int fx[]={-2,-2,-1,-1,1,1,2,2};
//int fy[]={-1,1,-2,2,-2,2,-1,1};

//Bit operation
int SET(int n,int pos)
{
    return n=n | (1<<pos);
}
int RESET(int n,int pos)
{
    return n=n & ~(1<<pos);
}
int CHECK(int n,int pos)
{
    return (bool) (n & (1<<pos));
}


int bigMod(int n,int power,int MOD)
{
    if(power==0)
        return 1;
    if(power%2==0)
    {
        int ret=bigMod(n,power/2,MOD);
        return ((ret%MOD)*(ret%MOD))%MOD;
    }
    else return ((n%MOD)*(bigMod(n,power-1,MOD)%MOD))%MOD;
}

int modInverse(int n,int MOD)
{
    return bigMod(n,MOD-2,MOD);
}

int POW(int x, int y)
{
    int res= 1;
    for ( ; y ; )
    {
        if ( (y&1) )
        {
            res*= x;
        }
        x*=x;
        y>>=1;
    }
    return res;
}

int inverse(int x)
{
    dd p=((dd)1.0)/x;
    return (p)+EPS;
}

int gcd(int a, int b)
{
    while(b) b^=a^=b^=a%=b;
    return a;
}

int nC2(int n)
{
    return n*(n-1)/2;
}

int MOD(int n,int mod)
{
    if(n>=0)
        return n%mod;
    else if(-n==mod)
        return 0;
    else
        return mod+(n%mod);
}

int tree[1005][1005],mapa[1005][1005];

void update(int x,int y)
{
    while(x<=1001)
    {
        int yy=y;
        while(yy<=1001)
        {
            tree[x][yy]+=1;
            yy+=(yy & -yy);
        }
        x+=(x & -x);
    }
}

int query(int x,int y)
{
    int xx=0;
    while(x>0)
    {
        int yy=y;
        while(yy>0)
        {
            xx+=tree[x][yy];
            yy-=(yy & -yy);
        }
        x-=(x & -x);
    }
    return xx;
}

int main()
{
    int t,cas=0;
    //write();
    getint(t);
    while(t--)
    {
        for(int i=0; i<1005; i++)
        {
            for(int j=0; j<1005; j++)
            {
                tree[i][j]=0;
                mapa[i][j]=0;
            }
        }
        int q;
        getint(q);
        CASE(cas);
        while(q--)
        {
            int x,y,p;
            sf("%d %d %d",&p,&x,&y);
            x++;
            y++;
            if(p==0)
            {
                if(!mapa[x][y])
                {
                    update(x,y);
                    mapa[x][y]=1;
                }
            }
            else
            {
                int x1,y1;
                sf("%d %d",&x1,&y1);
                x1++;
                y1++;
                int ans=query(x1,y1)-query(x-1,y1)-query(x1,y-1)+query(x-1,y-1);
                //cout<<"asasasas "<<query(x1,y1)<<" "<<query(x-1,y1-1)<<" "<<query(x1-1,y-1)<<" "<<query(x-1,y-1)<<endl;
                pf("%d\n",ans);
            }
        }
    }

    return  0;

}
