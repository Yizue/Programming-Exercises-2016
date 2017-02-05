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

	string read,in,x,yS,r,op;
    int y, sI;
    vector< pair<int,string> > defs;

    getline(cin,read);
    while(!cin.eof())
    {
        sI = read.find(' ');
        in = read.substr(0, sI);
        read = read.substr(sI+1);

        if(in=="def")
        {
            sI = read.find(' ');
            x = read.substr(0, sI);
            yS = read.substr(sI+1);
            y = atoi(yS.c_str());

            int ind=-1;
            for(int i=0; i<defs.size(); i++)
            {
                if(defs.at(i).second==x)
                {
                    ind=i;
                    break;
                }
            }
            if(ind==-1)
                defs.push_back(make_pair(y,x));
            else
            {
                defs.at(ind).first=y;
            }
        }
        else if(in=="calc")
        {
            bool err=false;
            int ans=0;
            string feed = read;
            op = "+";
            do
            {
                sI = feed.find(' ');
                r = feed.substr(0, sI);

                int ind=-1;
                for(int i=0; i<defs.size(); i++)
                {
                    if(defs.at(i).second==r)
                    {
                        ind=i;
                        break;
                    }
                }
                if(ind==-1)
                {
                    err=true;
                    break;
                }
                else
                {
                    if(op=="+")
                        ans+=defs.at(ind).first;
                    else if(op=="-")
                        ans-=defs.at(ind).first;
                }

                op = feed.substr(sI+1,1);
                if(op!="=")
                    feed = feed.substr(sI+3);
            } while(op!="=");

            if(err)
                cout << read << " unknown" << endl;
            else
            {
                int ind=-1;
                for(int i=0; i<defs.size(); i++)
                {
                    if(defs.at(i).first==ans)
                    {
                        ind=i;
                        break;
                    }
                }
                if(ind==-1)
                    cout << read << " unknown" << endl;
                else
                    cout << read << " " << defs.at(ind).second << endl;
            }

        }
        else if(in=="clear")
        {
            defs.clear();
        }

        getline(cin,read);
    }

	return 0;
}
