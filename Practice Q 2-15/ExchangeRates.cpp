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
Sample Input:

! 6 shirt = 15 sock
! 47 underwear = 9 pant
? sock = shirt
? shirt = pant
! 2 sock = 1 underwear
? pant = shirt
.
*/

class Vertex
{
    public:
        string name;
        vector< pair<Vertex*,int> > adj;
        bool visited;

        Vertex(string n)
        {
            name = n;
            visited = false;
        }

        void addEdge(Vertex* v, int w)
        {
            adj.push_back(make_pair(v,w));
        }
};

bool dfs(Vertex* source, Vertex* target, ii* exch)
{
    bool found=false;
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

            if (!v.first->visited)
            {
                exch->first *= v.second;

                for(unsigned j=0; j< v.first->adj.size(); j++)
                {
                    pair<Vertex*,int> w = v.first->adj.at(j);
                    if(w.first->name==u->name)
                        exch->second *= w.second;
                }

                if(v.first->name==target->name)
                {
                    found = true;
                    break;
                }
                aStack.push(v.first);
            }
        }
    }
    return found;
}

int main(){
	FASTER;

    vector<Vertex*> G;

	char r, ign, it1[20], it2[20];
	int val1, val2;

	scanf(" %c", &r);
	while(r!='.')
    {
        if(r=='!')
        {
            scanf(" %d %s %c %d %s", &val1, it1, &ign, &val2, it2);
            bool uB=false,vB=false;
            Vertex *x, *y;

            for(int i=0; i<G.size(); i++)
            {
                Vertex* w = G.at(i);
                if(w->name==it1)
                {
                    uB=true;
                    x=w;
                }
                else if(w->name==it2)
                {
                    vB=true;
                    y=w;
                }
            }
            if(!uB && !vB)
            {
                Vertex *u = new Vertex(it1);
                Vertex *v = new Vertex(it2);

                u->addEdge(v, val1);
                G.push_back(u);
                v->addEdge(u, val2);
                G.push_back(v);
            }
            else if(uB && !vB)
            {
                Vertex *v = new Vertex(it2);
                v->addEdge(x, val2);
                G.push_back(v);

                x->addEdge(v, val1);
            }
            else if(!uB && vB)
            {
                Vertex *u = new Vertex(it1);
                u->addEdge(y, val1);
                G.push_back(u);

                y->addEdge(u, val2);
            }
            else
            {
                x->addEdge(y, val1);
                y->addEdge(x, val2);
            }
        }
        else
        {
            scanf(" %s %c %s", it1, &ign, it2);

            Vertex *u,*v;
            bool uB=false,vB=false;

            for(int i=0; i<G.size(); i++)
            {
                Vertex* w = G.at(i);
                if(w->name==it1)
                {
                    uB=true;
                    u=w;
                }
                else if(w->name==it2)
                {
                    vB=true;
                    v=w;
                }
            }
            if(!uB || !vB)
            {
                printf("? %s = ? %s\n", it1, it2);
            }
            else
            {
                ii exch(1,1);
                bool found = dfs(u,v,&exch);

                for(int j=0; j<G.size(); j++)
                    G.at(j)->visited = false;

                if(!found)
                    printf("? %s = ? %s\n", it1, it2);
                else
                {
                    int GCD = gcd(exch.first,exch.second);
                    printf("? %d %s = ? %d %s\n", (exch.first/GCD), it1, (exch.second/GCD), it2);
                }
            }
        }
        scanf(" %c", &r);
    }

    for(int k=0; k<G.size(); k++)
        delete G.at(k);

	return 0;
}
