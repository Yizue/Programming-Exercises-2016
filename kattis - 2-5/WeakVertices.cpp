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
    while (t != -1)
    {
        int adj[t][t];
        for (int i=0; i<t; i++)
        {
            for (int j=0; j<t; j++)
            {
                cin >> adj[i][j];
            }
        }

        if(t == 1)
        {
            cout << 0;
        }
        else if(t == 2)
        {
            cout << 0 << ' ' << 1;
        }
        else
        {
            int weak[t];
            for (int a=0; a<t; a++)
            {
                weak[a] = 0;
            }

            for (int l=0; l<t; l++)
            {
                for (int m=0; m<t; m++)
                {
                    if(adj[l][m] == 1)
                    {
                        for(int n=0; n<t; n++)
                        {
                            if(adj[m][n] == 1 && adj[n][l] == 1 && (m != n) && (l != n) )
                            {
                                weak[l] = 1;
                            }
                        }
                    }
                }
            }

            for (int z=0; z<t; z++)
            {
                if(weak[z] == 0)
                    cout << z << ' ';
            }
        }

        cout << endl;

        cin >> t;
    }

	return 0;
}
