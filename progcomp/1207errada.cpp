// pescoço pra baixo é canela
//
//
//
// ENVIAR PRA TER ERRO

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
typedef vector<ll> vll; const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

struct Category{
    int b;
    int all_v;

    bool operator < (const Category &other) const{
        return (b-all_v) < (other.b - other.all_v);
    }
};

int main(){ 
    int N, M; 
    while (cin >> N >> M){
        vector<vector<int>> g(N+M+5);
        vector<int> costs(N+1);
        for (int i = 1; i <= N; i++) cin >> costs[i];
        vector<int> qnt_categoria(M+1);
        vector<int> beneficios(M+1);
        for (int i = 1; i <= M; i++) cin >> qnt_categoria[i];
        for (int i = 1; i <= M; i++){
            cin >> beneficios[i]; 
            int v;
            for (int k = 0; k < qnt_categoria[i]; k++){
                cin >> v;
                g[v].pb(i+N);
                g[i+N].pb(v);
            }
        }
        vector<Category> categorias(M+1);
        for (int i = 1; i <= M; i++){
            int all_v=0;
            for (int j: g[i+N]) all_v+=costs[j];
            categorias[i] = {beneficios[i], all_v};
        }
        int ans = 0;
        vector<bool> vodkas_compradas(N+1, false);
        vector<bool> categorias_cobertas(M+1, false);
        while (1){
            bool achei=false;
            for (int i = 1; i <= M; i++){
                if (categorias_cobertas[i]) continue;
                auto c = categorias[i];
                if (c.b - c.all_v >= 0){
                    achei=true;
                    categorias_cobertas[i]=true;
                    ans += c.b - c.all_v;
                    for (int vodka: g[i+N]){
                        if (!vodkas_compradas[vodka]){
                            vodkas_compradas[vodka]=true;
                            for (int cat: g[vodka]){
                                categorias[cat-N].all_v-=costs[vodka];
                            }
                        }
                    }
                }
            }
            if (!achei) break;
        }
        cout << ans << endl;

    }

    exit(0);
}
