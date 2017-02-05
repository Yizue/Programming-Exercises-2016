#include <bits/stdc++.h>
using namespace std;

#define MEM(arr,val)memset((arr),(val), sizeof (arr))
#define PI (acos(0)*2.0)
#define FASTER ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<int,double> id;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector< pair<ii,id> > vid;


ll gcd(ll a,ll b){return b == 0 ? a : gcd(b,a%b);}
ll lcm(ll a,ll b){return a*(b/gcd(a,b));}

/**
 * __builtin_popcount(int d) // count bits
 * strtol(s, &end, base); // convert base number
 */
//----------------------------------------------------------------------//

class Vertex
{
    public:
        int val;
        vector< pair<Vertex*,double> > adj;
        bool popped;
        double dist;

        Vertex(int n)
        {
            val=n;
            dist=INFINITY;
            popped = false;
        }

        void addEdge(Vertex* v, double area)
        {
            adj.push_back(make_pair(v, area));
            v->adj.push_back(make_pair(this, area));
        }
};

struct comp
{
   bool operator()(const Vertex* l, const Vertex* r)
   {
       return l->dist > r->dist;
   }
};

double dijk(Vertex* source, int target)
{
    priority_queue< Vertex*, vector<Vertex*>, comp > pQueue;
    source->dist=0.0;
    pQueue.push(source);

    while(!pQueue.empty())
    {
        Vertex* u = pQueue.top();
        pQueue.pop();

        u->popped = true;
        if(u->val==target)
            return u->dist;

        for (unsigned i=0; i< u->adj.size(); i++)
        {
            Vertex* v = u->adj.at(i).first;
            if(!v->popped)
            {
                if(u->dist + u->adj.at(i).second < v->dist)
                {
                    v->dist = (u->dist)+(u->adj.at(i).second);
                }
                pQueue.push(v);
            }
        }
    }
    return -1.0;
}

int main(){
	FASTER;

    int n;
    while(scanf(" %d",&n), n!=0)
    {
        vector<Vertex*> G;
        while(n--)
        {
            int a,b,h;
            scanf(" %d %d %d",&a,&b,&h);
            double area = (a+b)*h/(2.0);

            int aI=-1, bI=-1;
            for(int i=0; i<G.size(); i++)
            {
                if(G.at(i)->val==a)
                    aI=i;
                if(G.at(i)->val==b)
                    bI=i;
            }
            if(aI!=-1 && bI!=-1)
                G.at(aI)->addEdge(G.at(bI), area);
            else if(aI!=-1)
            {
                Vertex* w = new Vertex(b);
                w->addEdge(G.at(aI), area);
                G.push_back(w);
            }
            else if(bI!=-1)
            {
                Vertex* v = new Vertex(a);
                v->addEdge(G.at(bI), area);
                G.push_back(v);
            }
            else
            {
                Vertex* v = new Vertex(a);
                Vertex* w = new Vertex(b);
                v->addEdge(w, area);
                G.push_back(v);
                G.push_back(w);
            }
        }
        int s,t;
        scanf(" %d %d",&s,&t);
        double minA=INFINITY, test;

        if(s==t)
        {
            minA=0;
        }
        else
        {
            for(int i=0; i<G.size(); i++)
            {
                if(G.at(i)->val==s)
                {
                    test=dijk(G.at(i),t);
                    if(test < minA)
                    minA=test;
                }
                for(int j=0; j<G.size(); j++)
                {
                    G.at(j)->dist=INFINITY;
                    G.at(j)->popped=false;
                }
            }
        }
        printf("%.2f\n", minA*0.02);

        for(int j=0; j<G.size(); j++)
            delete G.at(j);
        G.clear();
    }

	return 0;
}
