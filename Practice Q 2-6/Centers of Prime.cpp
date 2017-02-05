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

bool isPrime (int num)
{
    if (num == 1)
        return true;
    else if (num == 2)         
        return true;
    else if (num % 2 == 0)
        return false;
    else
    {
        bool prime = true;
        int divisor = 3;
        double num_d = static_cast<double>(num);
        int upperLimit = static_cast<int>(sqrt(num_d) +1);
        
        while (divisor <= upperLimit)
        {
            if (num % divisor == 0)
                prime = false;
            divisor +=2;
        }
        return prime;
    }
}

int main(){
	FASTER;
    
    int t;
    cin >> t;
    
    for (int i=0; i<t; i++)
    {
        int n, c;
        vi p;
        
        cin >> n >> c;
        cout << n << ": ";
        
        for(int j=1; j<=n; j++)
        {
            if(isPrime(j) == true)
                p.push_back(j);
        }
        
        bool isOdd;
        int cP;
        
        if(p.size() % 2 == 1)
        {
            isOdd =true;
            cP = c*2 - 1;
        }
        else
        {
            isOdd =false;
            cP = c*2;
        }
        
        int st, fin, center;
        
        if(cP >= p.size())
        {
            st=0;
            fin=p.size() - 1;
        }
        else if(isOdd)
        {
            center = (p.size() - 1)/2;
            st = center - ((cP - 1)/2);
            fin = center + ((cP - 1)/2);
        }
        else
        {
            center = p.size()/2;
            st = center - c;
            fin = center + c - 1;
        }
        
        for(int k=st; k<=fin; k++)
        {
            cout << p.at(k) << ' ';
        }
        cout << "\n";
    }

	return 0;
}





















