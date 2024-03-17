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
    cout << fixed << setprecision(5);
    double A, B, C; cin >> A >> B >> C;
    if (A==0){
        cout << "Impossivel calcular" << endl;
        exit(0);
    }
    double delta = B*B - 4 * A * C;
    if (delta < 0){
        cout << "Impossivel calcular" << endl;
        exit(0);
    }
    double R1 = (-B + sqrt(delta))/(2*A);
    double R2 = (-B - sqrt(delta))/(2*A);
    cout << "R1 = " << R1 << endl;
    cout << "R2 = " << R2 << endl;
    exit(0);
}
