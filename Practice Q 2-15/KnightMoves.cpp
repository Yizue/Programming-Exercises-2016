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

static const int ROW = 8;
static const int COL = 8;

class Vertex
{
    public:
        int x, y;
        vector<Vertex*> adj;
        bool visited;
        int dist;

        Vertex()
        {
            x=y=dist=0;
            visited=false;
        }

        void setCords (int xC, int yC)
        {
            x=xC;
            y=yC;
        }

        void addEdge(Vertex* v)
        {
            adj.push_back(v);
        }
};

int bfs(Vertex* source, Vertex* target, Vertex board[][COL])
{
    queue<Vertex*> aQueue;
    aQueue.push(source);
    source->visited = true;

    if(source == target)
        return 0;

    while(!aQueue.empty())
    {
        Vertex* u = aQueue.front();
        aQueue.pop();
        //cout << "In " << u->x << "," << u->y << endl;

        if( (u->x)-2 >= 0)
        {
            if( (u->y)-1 >= 0)
                u->addEdge(&board[(u->x)-2][(u->y)-1]);
            if( (u->y)+1 < COL)
                u->addEdge(&board[(u->x)-2][(u->y)+1]);
        }
        if( (u->x)+2 < ROW)
        {
            if( (u->y)-1 >= 0)
                u->addEdge(&board[(u->x)+2][(u->y)-1]);
            if( (u->y)+1 < COL)
                u->addEdge(&board[(u->x)+2][(u->y)+1]);
        }
        if( (u->y)-2 >= 0)
        {
            if( (u->x)-1 > 0)
                u->addEdge(&board[(u->x)-1][(u->y)-2]);
            if( (u->x)+1 < ROW)
                u->addEdge(&board[(u->x)+1][(u->y)-2]);
        }
        if( (u->y)+2 < COL)
        {
            if( (u->x)-1 >= 0)
                u->addEdge(&board[(u->x)-1][(u->y)+2]);
            if( (u->x)+1 < ROW)
                u->addEdge(&board[(u->x)+1][(u->y)+2]);
        }

        for (unsigned i=0; i< u->adj.size(); i++)
        {
            Vertex* v = u->adj.at(i);
            //cout << "V: " << v->x << "," << v->y << endl;
            if(!v->visited)
            {
         		  v->dist = (u->dist)+1;
         		  v->visited = true;
         		  //cout << "V Dist: " << v->dist << endl;
         		  if(v == target)
                      return v->dist;
         		  aQueue.push(v);
            }
        }
    }
    return -1;
}

int main(){
	FASTER;

    char y1,y2;
    int x1,x2;

    while (scanf(" %c %d %c %d",&y1,&x1,&y2,&x2) == 4)
    {
        Vertex board[ROW][COL];

        for(int i=0; i<ROW; i++)
            for(int j=0; j<COL; j++)
                board[i][j].setCords(i,j);

        Vertex* src = &board[int(y1)-int('a')][x1-1];
        Vertex* tgt = &board[int(y2)-int('a')][x2-1];
        printf("To get from %c%d to %c%d takes %d knight moves.\n", y1,x1,y2,x2, bfs(src, tgt, board));
    }
	return 0;
}
