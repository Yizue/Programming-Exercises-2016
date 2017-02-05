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

    int n, m;
    cin >> n >> m;

    int nHigh = 2*n, mHigh = 3*m;
    int nDiv = n/3, mDiv = m/2;
    int nRem = n%3, mRem = m%2;

    while(nDiv>0 && mDiv>0)
    {
        if(nHigh+2 <= mHigh+3)
        {
            nHigh+=2;
            mDiv--;

            nRem++;
            if(nRem%3!=0)
                nDiv--;
        }
        else
        {
            mHigh+=3;
            nDiv--;

            mRem++;
            if(mRem%2!=0)
                mDiv--;
        }
    }

    if(nHigh > mHigh)
        cout << nHigh;
    else
        cout << mHigh;

	return 0;
}
