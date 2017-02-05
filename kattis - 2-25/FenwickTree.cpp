#include <bits/stdc++.h>
using namespace std;

#define MEM(arr,val)memset((arr),(val), sizeof (arr))
#define PI (acos(0)*2.0)
#define FASTER ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

ll gcd(ll a,ll b){return b == 0 ? a : gcd(b,a%b);}
ll lcm(ll a,ll b){return a*(b/gcd(a,b));}

/**
 * __builtin_popcount(int d) // count bits
 * strtol(s, &end, base); // convert base number
 */
//----------------------------------------------------------------------//

ll getSum(ll BIT[], int ind)
{
    ll sum=0;

    while (ind>0)
    {
        sum+=BIT[ind];
        ind-=ind&(-ind);
    }
    return sum;
}

void upd(ll BIT[], int n, int ind, ll val)
{
    while(ind<=n)
    {
       BIT[ind]+=val;
       ind+=ind&(-ind);
    }
}

int main()
{
    FASTER;

    int n,q;
    scanf(" %d %d", &n,&q);
    ll BIT[n+1];
    for(int i=1; i<=n; i++)
        BIT[i]=0;

    while(q--)
    {
        char op;
        scanf(" %c", &op);
        if(op=='+')
        {
            int x,y;
            scanf(" %d %d", &x,&y);
            upd(BIT, n, x+1, y);
        }
        else if(op=='?')
        {
            int z;
            scanf(" %d", &z);
            printf("%lld\n", getSum(BIT, z));
        }
    }

    return 0;
}
