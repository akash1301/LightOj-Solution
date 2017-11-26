/////////////////////// All Is Well /////////////////////////

#include <bits/stdc++.h>

#define FOR(i, s, e) for(int i=s; i<e; i++)
#define loop(i, n) for(int i=0; i<n; i++)
#define CIN   ios_base::sync_with_stdio(0); cin.tie(0)
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
#define CASE(n) printf("Case %d: ",++n)
#define CASE_COUT cout<<"Case "<<++cas<<": "
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

int str2int(string s)
{
    stringstream ss(s);
    int x;
    ss >> x;
    return x;
}

string int2str(int a)
{
    stringstream ss;
    ss << a;
    string str = ss.str();
    return str;
}

string char2str(char a)
{
    stringstream ss;
    ss << a;
    string str = ss.str();
    return str;
}

ll bigMod(ll n,ll power,ll MOD)
{
    if(power==0)
        return 1;
    if(power%2==0)
    {
        ll ret=bigMod(n,power/2,MOD);
        return ((ret%MOD)*(ret%MOD))%MOD;
    }
    else return ((n%MOD)*(bigMod(n,power-1,MOD)%MOD))%MOD;
}

ll modInverse(ll n,ll MOD)
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

ll MOD(ll n,ll mod)
{
    if(n>=0)
        return n%mod;
    else if(-n==mod)
        return 0;
    else
        return mod+(n%mod);
}

dd mat[105][105],X[105];
int n;
bool g[105][105];

void GaussianElimination()
{
    for(int j=1;j<=n;j++)
    {
        for(int i=1;i<=n;i++)
        {
            if(i>j)
            {
                dd c=mat[i][j]/mat[j][j];
                for(int k=1;k<=n+1;k++)
                {
                    mat[i][k]=mat[i][k] - (c*mat[j][k]);
                }
            }
        }
    }
    X[n]=mat[n][n+1]/mat[n][n];
    for(int i=n-1;i>=1;i--)
    {
        dd sum=0;
        for(int j=i+1;j<=n;j++)
        {
            sum+=mat[i][j] * X[j];
        }
        X[i]=(mat[i][n+1] - sum)/mat[i][i];
    }
}


int main()
{
//    read();
    int t,cas=0;
    getint(t);
    while(t--)
    {
        mem(g,0);
        int m;
        getint(m);
        loop(i,m)
        {
            int a,b;
            sf("%d %d",&a,&b);
            g[a][b]=1;
        }
        mem(mat,0.0);
        mem(X,0);
        for(int i=1; i<=100; i++)
        {
            if(i==100)
            {
                mat[i][i]=1.0;
                continue;
            }
            bool ff=0;
            for(int j=1; j<=100;j++)
            {
                if(g[i][j])
                {
                    mat[i][i]=1.0;
                    mat[i][j]=-1.0;
                    ff=1;
                }
            }
            if(!ff)
            {
                for(int j=i; j<=100; j++)
                {
                    if(i+6>=j)
                    {
                        if(i==j)
                            mat[i][j]=1.0;
                        else
                        {
                            mat[i][j]=-1.0/6.0;
                        }
                    }
                }
                for(int k=1;k<=6;k++)
                {
                    if(i+k>100)
                    {
                        mat[i][i]-=1.0/6.0;
                    }
                }
                mat[i][101]=1.0;
            }
        }

//        for(int i=1;i<=100;i++)
//        {
//            for(int j=1;j<=100;j++)
//                cout<<mat[i][j]<<" ";
//            cout<<endl;
//        }

//        cout<<mat[1][2]<<endl;

        n=100;
        GaussianElimination();

//        for(int i=1;i<=100;i++)
//            cout<<X[i]<<endl;

        CASE(cas);
        pf("%.10lf\n",X[1]);

    }
    return  0;

}
