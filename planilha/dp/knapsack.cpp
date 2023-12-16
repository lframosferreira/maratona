#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back()

typedef long long ll;
typedef pair<int , int> pii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int w[100];
int v[100];

int main(){ 
    int N, W; cin >> N >> W;
    vector<vector<ll>> best(N+1, vector<ll>(W+1, 0));
        for (int i = 0; i < N; i++){
        cin >> w[i] >> v[i];
    }
    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= W; j++){
            best[i][j] = best[i-1][j];
            if (w[i-1] <= j){
                best[i][j] = max(best[i][j], best[i-1][j - w[i-1]] + v[i-1]);
            }
        }
    }
    cout << best[N][W] << endl;

    exit(0);
} 

