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

int main(){
	FASTER;

    int n,m,x1,x2,y1,y2,r;
    vii rec1, rec2, cir;
    vi rad;
    char s[10];
    scanf("%d",&n);
    while(n--)
    {
        scanf(" %s",s);
        if(s[0]=='r')
        {
            scanf(" %d %d %d %d",&x1,&y1,&x2,&y2);
            rec1.push_back(make_pair(x1,y1));
            rec2.push_back(make_pair(x2,y2));
        }
        else
        {
            scanf(" %d %d %d",&x1,&y1,&r);
            cir.push_back(make_pair(x1,y1));
            rad.push_back(r);
        }
    }
    scanf("%d",&m);
    while(m--)
    {
        int ans=0;
        scanf(" %d %d",&x1,&y1);
        for(int i=0; i<rec1.size(); i++)
        {
            if(rec1.at(i).first<=x1 && rec1.at(i).second<=y1 && rec2.at(i).first>=x1 && rec2.at(i).second>=y1)
                ans++;
        }
        for(int j=0; j<cir.size(); j++)
        {
            if( sqrt( pow(x1-cir.at(j).first,2) + pow(y1-cir.at(j).second,2) ) <= rad.at(j) )
                ans++;
        }
        printf("%d\n",ans);
    }
	return 0;
}
