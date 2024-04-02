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

int pilhas[3][110];
int N;

int check(int p0, int p1, int p2){
    if (p0==N and p1==N and p2==N){
        return 1;
    }

    while (p0<N and pilhas[0][p0]==0) p0++;
    while (p1<N and pilhas[1][p1]==0) p1++;
    while (p2<N and pilhas[2][p2]==0) p2++;

    if (p0==N and p1==N and p2==N){
        return 1;
    }

    if (p0==N and p1==N) return 0;
    if (p2==N and p1==N) return 0;
    if (p0==N and p2==N) return 0;

    if ((pilhas[0][p0]+pilhas[1][p1]+pilhas[2][p2])%3==0) return check(p0+1, p1+1, p2+1);

    if (pilhas[0][p0]==1) return check(p0+1, p1+1, p2) or check(p0+1, p1, p2+1);
    if (pilhas[1][p1]==1) return check(p0+1, p1+1, p2) or check(p0, p1+1, p2+1);
    if (pilhas[2][p2]==1) return check(p0, p1+1, p2+1) or check(p0+1, p1, p2+1);

    return 0;
}

int main(){ _
    while (1){
        cin >> N;
        if (N==0) break;
        for (int i = 0; i < N; i++){
            for (int j = 0; j < 3; j++){
                cin >> pilhas[j][i];
                pilhas[j][i] %= 3;
            }
        }
        if (check(0, 0, 0)) cout << 1 << endl;
        else cout << 0 << endl;
    }    
    exit(0);
}
