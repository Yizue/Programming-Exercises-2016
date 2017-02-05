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

/*
4 5
1 2 100
1 3 100
1 4 1
2 3 100
3 4 1
9 14
1 2 9
6 9 8
2 4 9
2 3 9
4 5 1
4 3 9
5 9 2
9 8 9
7 8 9
7 9 5
6 7 9
5 6 4
5 8 7
7 5 9
0 0
*/

class Vertex
{
    public:
       int id;
        vector< pair<Vertex*,int> > adj;
        bool visited;

        Vertex(int n)
        {
            id = n;
            visited = false;
        }

        void addEdge(Vertex* v, int w)
        {
            adj.push_back(make_pair(v,w));
        }
};

int dfs(Vertex* source, int max_ppa, int sizeG)
{
    int c=1;
    bool inS[sizeG];
    for(int k=0; k<sizeG; k++)
        inS[k]=false;
    stack<Vertex*> aStack;
    aStack.push(source);

    while(!aStack.empty())
    {
        Vertex* u = aStack.top();
        aStack.pop();
        u->visited = true;

        for(unsigned i=0; i< u->adj.size(); i++)
        {
            pair<Vertex*,int> v = u->adj.at(i);

            if (!v.first->visited && v.second==max_ppa && !inS[v.first->id])
            {
                c++;
                aStack.push(v.first);
                inS[v.first->id]=true;
            }
        }
    }
    return c;
}

int main()
{
    FASTER;

    int n,m,v1,v2,ppa;
    scanf("%d %d", &n, &m);
    while(n!=0 && m!=0)
    {
    	vector<Vertex*> G;
    	int max_ppa=0;
    	for(int i=0; i<n; i++)
		{
			Vertex* v = new Vertex(i);
			G.push_back(v);
		}
        while(m--)
        {
            scanf("%d %d %d", &v1, &v2, &ppa);

            if(ppa > max_ppa)
                max_ppa=ppa;

			G.at(v1-1)->addEdge(G.at(v2-1), ppa);
			G.at(v2-1)->addEdge(G.at(v1-1), ppa);
        }

        int ans=2, test;

		for(int i=0; i<G.size(); i++)
		{
			if(!G.at(i)->visited)
			{
				test = dfs(G.at(i), max_ppa, G.size());
				if(test>ans)
					ans=test;
			}
		}
		printf("%d\n", ans);

		for(int j=0; j<G.size(); j++)
			delete G.at(j);

		scanf("%d %d", &n, &m);
    }

    return 0;
}
