// pescoço pra baixo é canela

#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

#define dbg(x) cout << #x << " = " << x << endl

typedef long long ll;
typedef pair<int , int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

vi saida;

bool solve(vi &entrada){
    if (entrada==saida) return true;
    if (entrada.size() >= saida.size()) return false;
    bool can = false;
    for (int i = 0; i < entrada.size(); i++){
        // pra esquerda
        if (i > entrada.size()/2){
            vi aux(entrada.begin(), entrada.begin() + i);
            for (int j = 0; j < entrada.size() - i; j++) {
                aux[aux.size()-1-j]+=entrada[i+j+1];
            }
            if (!can) can = can or solve(aux);
        } else {
            vi aux(entrada.begin() + i, entrada.end());
            reverse(aux.begin(), aux.end());
            for (int j = 0; j < i; j++) {
                aux[aux.size()-1-j]+=entrada[i-j];
            }
            if (!can) can = can or solve(aux);
        }
        // pra direita
        if (i > entrada.size()/2){
            vi aux(entrada.begin(), entrada.begin() + i);
            reverse(aux.begin(), aux.end());
            for (int j = 0; j < i; j++) {
                aux[j]+=entrada[i+j+1];
            }
            if (!can) can = can or solve(aux);
        } else {
            vi aux(entrada.begin() + i, entrada.end());
            for (int j = 0; j < entrada.size() - i; j++) {
                aux[j]+=entrada[i-j];
            }
            if (!can) can = can or solve(aux);
        }
    }
    return can;
}

int main(){ _
    int N, M;
    while (cin >> N){
        vi entrada(N);
        for (int& i: entrada) cin >> i;
        cin >> M;
        saida.resize(M);
        for (int& i: saida) cin >> i;
        if (solve(entrada)) cout << "S" << endl;
        else cout << "N" << endl;
    }
    exit(0);
}
