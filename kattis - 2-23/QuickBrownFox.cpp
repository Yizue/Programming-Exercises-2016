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
	cin.ignore();
	cin.sync();

	while(t--)
    {
        int arr[26] = {0};
        string s, msg="";
        getline(cin,s);
        for(int i=0;i<s.length();i++)
        {
            int c = tolower(s.at(i)) - int('a');
            if(c>=0 && c<26)
                arr[c]++;
        }
        for(int j=0;j<26;j++)
        {
            if(arr[j]==0)
                msg+=char(int('a')+j);
        }
        if(msg.length()==0)
            cout << "pangram" << endl;
        else
            cout << "missing " << msg << endl;
    }


	return 0;
}
