// pescoço pra baixo é canela

#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define dbg(x) cout << #x << " = " << x << endl

typedef long long ll;
typedef pair<int , int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _
    while (1){
        int N; cin >> N;
        if (N==0) break;
        vector<vector<int>> pilhas(3, vector<int>(N));
        for (int i = 0; i < N; i++){
            for (int j = 0; j < 3; j++){
                cin >> pilhas[j][i];
                pilhas[j][i] %= 3;
            }
        }
        int p0=0,p1=0,p2=0;
        while (1){
            if (p0==N and p1==N and p2==N){
                cout << 1 << endl;
                exit(0);
            }

            while (p0<N-1 and v[0][p0]==0) p0++;
            while (p1<N-1 and v[1][p1]==0) p1++;
            while (p2<N-1 and v[2][p2]==0) p2++;
            if (
        }
    }    
    exit(0);
}
