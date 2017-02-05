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
        int arr[9][9];
        for(int j=0; j<9; j+=2)
        {
            for(int k=0; k<(j+1); k+=2)
            {
                cin >>  arr[j][k];
            }
        }

        for(int a=2; a<9; a+=2)
        {
            for(int b=1; b<a; b+=2)
            {
                arr[a][b] = (arr[a-2][b-1] - arr[a][b-1] - arr[a][b+1]) / 2;
            }
        }

        for(int c=1; c<9; c+=2)
        {
            for(int d=0; d<=c; d++)
            {
                arr[c][d] = arr[c+1][d] + arr[c+1][d+1];
            }
        }

        for(int x=0; x<9; x++)
        {
            for(int y=0; y<(x+1); y++)
            {
                if(y != x)
                    cout << arr[x][y] << ' ';
                else
                    cout << arr[x][y];
            }
            cout << endl;
        }

    }

	return 0;
}
