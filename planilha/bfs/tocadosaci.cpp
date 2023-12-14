#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define f first
#define s second
#define pb pushback()

typedef long long ll;
typedef pair<int , int> pii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int N = 1000;
const int M = 1000;
int v[N][M];
bool visited[N][M] = {false};
vector<pii> moves = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};

bool oob(pii p, int n, int m){

    return p.f < 0 || p.f >= n ||  p.s < 0 || p.s >= m;
}

int main(){ 
    int n, m;
    cin >> n >> m;
    pii start, end;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> v[i][j];
            if (v[i][j] == 2){
                start = {i, j};
            }
            if (v[i][j] == 3){
                end = {i, j};
            }
        }
    }
    queue<pair<pii, int>> q;
    q.push({start, 0});
    int count = 0;
    int res = -1;
    while (!q.empty()){
        pair<pii, int> aux = q.front();
        q.pop();
        visited[aux.f.f][aux.f.s] = true;

        if (v[aux.f.f][aux.f.s] == 3){
            res = aux.s;
            break;
        }
        for (auto move: moves){
            pii next = {aux.f.f + move.f, aux.f.s + move.s};
            if (v[next.f][next.s] == 0){
                continue;
            }
            if (!oob(next, n, m) && !visited[next.f][next.s]){

                q.push({next, aux.s + 1});
            }
        }

    }
    cout << res + 1<< endl;
    exit(0);
}
