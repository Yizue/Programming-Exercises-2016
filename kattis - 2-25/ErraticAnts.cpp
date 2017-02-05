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
class Vertex
{
    public:
        int x,y;
        vector<Vertex*> adj;
        bool visited;
        int dist;

        Vertex(int xC, int yC)
        {
            x = xC;
            y = yC;
            dist = 0;
            visited = false;
        }

        void addEdge(Vertex* v)
        {
            adj.push_back(v);
            v->adj.push_back(this);
        }
};

int bfs(Vertex* source, int xC, int yC)
{
    queue<Vertex*> aQueue;
    aQueue.push(source);
    source->visited = true;

    while(!aQueue.empty())
    {
        Vertex* u = aQueue.front();
        aQueue.pop();

        for (unsigned i=0; i< u->adj.size(); i++)
        {
            Vertex* v = u->adj.at(i);
            if(!v->visited)
            {
         		  v->dist = (u->dist)+1;
         		  v->visited = true;
         		  if(v->x == xC && v->y == yC)
                      return v->dist;
         		  aQueue.push(v);
            }
        }
    }
    return -1;
}

int main(){
	FASTER;

	int n;
	scanf(" %d",&n);
    while(n--)
    {
       int m;
       scanf(" %d",&m);

       vector<Vertex*> G;
       int xC=0,yC=0;
       Vertex* v = new Vertex(xC,yC);
       Vertex* prev=v;
       G.push_back(v);
       while(m--)
       {
           char c;
           scanf(" %c",&c);
           switch(c)
           {
               case 'N':yC++;break;
               case 'S':yC--;break;
               case 'E':xC++;break;
               case 'W':xC--;break;
           }
           int ind=-1;
           for(int i=0; i<G.size(); i++)
           {
               if(G.at(i)->x==xC && G.at(i)->y==yC)
               {
                   ind=i;
                   break;
               }
           }
           if(ind==-1)
           {
               Vertex* u = new Vertex(xC,yC);
               u->addEdge(prev);
               prev=u;
               G.push_back(u);
           }
           else
           {
               G.at(ind)->addEdge(prev);
               prev=G.at(ind);
           }


       }
        if(xC==0 && yC==0)
            printf("0\n");
        else
            printf("%d\n", bfs(v, xC, yC));

        for(int j=0; j<G.size(); j++)
            delete G.at(j);
        G.clear();
    }

	return 0;
}
