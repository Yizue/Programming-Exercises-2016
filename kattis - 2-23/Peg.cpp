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

    char arr[7][7];
    for(int i=0;i<7;i++)
    {
        for(int j=0;j<7;j++)
        {
            if( (i==0||i==1||i==5||i==6) && (j==0||j==1||j==5||j==6) )
            {
                arr[i][j]='-';
            }
            else
                scanf(" %c", &arr[i][j]);
        }
    }
    int mov=0;
    for(int k=0;k<7;k++)
    {
        for(int l=0;l<7;l++)
        {
            if(arr[k][l]=='.')
            {
                if(k-2>=0 && arr[k-1][l]=='o' && arr[k-2][l]=='o')
                    mov++;
                if(k+2<7 && arr[k+1][l]=='o' && arr[k+2][l]=='o')
                    mov++;
                if(l-2>=0 && arr[k][l-1]=='o' && arr[k][l-2]=='o')
                    mov++;
                if(l+2<7 && arr[k][l+1]=='o' && arr[k][l+2]=='o')
                    mov++;
            }
        }
    }
    cout << mov;
	return 0;
}
