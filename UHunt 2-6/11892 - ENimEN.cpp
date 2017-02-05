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

    int test;
    cin >> test;

    for(int i=0; i<test; i++)
    {
        int heaps;
        cin >> heaps;

        int heapNum;
        int singleCount=0, multiCount=0;

        for(int j=0; j<heaps; j++)
        {
            cin >> heapNum;
            if(heapNum == 1)
            {
                singleCount++;
            }
            else
            {
                multiCount++;
            }
        }

        if(singleCount % 2 == 1)
        {
            cout << "poopi" << endl;
        }
        else
        {
            if(multiCount != 0)
            {
                cout << "poopi" << endl;
            }
            else
            {
                cout << "piloop" << endl;
            }
        }

    }

	return 0;
}
