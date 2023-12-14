#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb pushback()

typedef long long ll;
typedef pair<int , int> pii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

bool oob(pii p){return p.f < 0 || p.f >= 8 || p.s < 0 || p.s >= 8;}

vector<pii> moves = {{-2, -1}, {-2, 1}, {2, -1}, {2, 1}, {1, 2}, {-1, 2}, {1, -2}, {-1, -2}};

int main(){ _ 
    int t; cin >> t;

    string p1, p2;
    while (t--){

        bool visited[8][8] = {false};
        int res = -1;
        cin >> p1 >> p2;
        pii spos = {p1[0] - 97, p1[1] - 48 - 1};
        pii epos = {p2[0] - 97, p2[1] - 48 - 1};
        queue<pair<pii, int>> q;
        q.push({spos, 0});
        while (!q.empty()){
            pair<pii, int> aux = q.front();
            q.pop();
            visited[aux.f.f][aux.f.s] = true;
            if (aux.f == epos){
                res = aux.s;
                break;
            }
            for (auto move: moves){
                pii next = {aux.f.f + move.f, aux.f.s + move.s};
                if (!oob(next) && !visited[next.f][next.s]){
                    q.push({next, aux.s + 1});
                }
            }

        }
        cout << res << endl;
    }
    exit(0);
}
