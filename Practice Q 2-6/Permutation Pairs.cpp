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

typedef vector<string> vs;

int main(){
	FASTER;
	
	int t;
	cin >> t;
	
	for(int i=0; i<t; i++)
	{
	    int k;
	    string s;
	    cin >> k >> s;
	    
	    vs v;

	    sort(s.begin(), s.end());
	    
        do
        {
            v.push_back(s);
        }
        while ( next_permutation(s.begin(), s.end()) );
        
        cout << v.at(k) << ' ' << v.at(v.size() - k - 1) << '\n';
	}
	
	return 0;
}