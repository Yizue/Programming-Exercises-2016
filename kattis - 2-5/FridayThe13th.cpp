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

    int t;
    cin >> t;

    for(int i=0; i<t; i++)
    {
        int d, m;

        cin >> d >> m;

        int days[m];
        for (int l=0; l<m; l++)
            cin >> days[l];

        int dayOf = 0, total13 = 0;

        for (int j=0; j<m; j++)
        {
            if(dayOf == 0 && days[j] >= 13)
                total13++;
            dayOf += (days[j])%7;
            dayOf = dayOf%7;

        }

        cout << total13 << endl;
    }

	return 0;
}
