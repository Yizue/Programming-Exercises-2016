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

/**
sample input

1111 0100 0200 2222
1111 0301 0500 4444
2222 0200 0200 3333
3333 0250 1000 1111
7777 1000 2000 7777
0000
0050 1111
0152 1111 
0200 1111
0225 2222
0270 1111
0320 1111
0320 3333
0899 3000
1250 3333
1250 7777
9000
0000
3000 1111
9000
*/

int main(){
	FASTER;
	
	int t;
	cin >> t;
	
	
	cout << "CALL FORWARDING OUTPUT" << '\n';
	for(int i=0; i<t; i++)
	{
	    vii st, td, cl;
	    int r1, r2, r3, r4;
	    
	    cin >> r1;
	    while(r1 != 0)
	    {
	        cin >> r2 >> r3 >> r4;
	        st.push_back(make_pair(r1, r4));
	        td.push_back(make_pair(r2, r3));
	        cin >> r1;
	    }
	    
	    cin >> r1;
	    while(r1 != 9000)
	    {
	        cin >> r2;
	        cl.push_back(make_pair(r1, r2));
	        cin >> r1;
	    }
	    
	    cout << "SYSTEM " << i + 1 << endl;
	    
	    for(int j=0; j<cl.size(); j++)
	    {
	        int t = cl.at(j).first;
	        int sta = cl.at(j).second;
	        int fin = sta;
	        bool end = false, found;
	        int count = 0;
	        
	        while (!end)
	        {
	            found = false;
	            if(st.empty())
	            {
	                end = true;
	            }
	            else
	            {
    	            for(int k=0; k<st.size(); k++)
    	            {
    	                if(fin == st.at(k).first && (t >= td.at(k).first) && (t <= (td.at(k).first + td.at(k).second) ) )
    	                {
    	                    fin = st.at(k).second;
    	                    found = true;
    	                    count++;
    	                }
    	            }
    	            if(fin == sta && count != 0 )
    	            {
    	                fin = 9999;
    	                end = true;
    	            }
    	            if(!found)
    	            {
    	                end = true;
    	            }
	            }
	        }
	        
	        cout << "AT " << setfill('0') << setw(4) << t << " CALL TO "
	             << setfill('0') << setw(4) << sta << " RINGS "
	             << setfill('0') << setw(4) << fin << endl;
	        
	    }
	}
	cout << "END OF OUTPUT" << endl;
	
	return 0;
}