
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

    bool debugging = false;

    int n,p;
    ll ans=0, a=0;
    cin >> n >> p;
    string r;
   // getline(cin, r);
    string h = "half", hp = "halfplus";
   // stack<string> s;
    vector<string> s;


    for(int i=0; i<n; i++)
    {
        //getline(cin,r);
        cin >> r;
        if (debugging)  cout << "R: " << r << endl;
        //s.push(r);
        s.push_back(r);
    }

    while(!s.empty())
    {
        string st1 = s[s.size()-1];//s.top();
        //s.pop();
        s.erase(s.end());

        if (debugging)  cout << "st1: " << st1 << endl;
        if(st1==hp)
        {
            ans+=((a/2)*p+(p/2));
        }
        else if(st1==h)
        {
            ans+=(a/2)*p;
        }
        if(a==0)
            a=1;
        if(!s.empty())
        {
            string st2=s[s.size()-1];//s.top();
            if(st2=="halfplus")
            {
                a=(a*2)+1;
            }
            else if(st2=="half")
            {
                a=a*2;
            }
        }
    }

    cout << ans << endl;

	return 0;
}
