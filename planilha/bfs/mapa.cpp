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

bool oob(pii p, int l, int c){
  return p.f < 0 || p.f >= l || p.s < 0 || p.s >= c;
}

vector<pii>
moves = {make_pair(0, -1), make_pair(0, 1), make_pair(1, 0), make_pair(-1, 0)};

int main(){ _
  int l, c;
  cin >> l >> c;
  vector<string> mapa(l, "");
  pii o;
  for (int i = 0; i < l; i++){
    cin >> mapa.at(i);
    int k = mapa.at(i).find('o');
    if (k != string::npos){
      o = make_pair(i, k);
    }
  }
  vector<vector<bool>> visited(l, vector<bool>(c, false)); 
  queue<pii> q;
  q.push(o);
  pii aux;
  while (true){
    if (q.empty()){
      break;
    }
    aux = q.front();
    q.pop();

    if (visited[aux.f][aux.s]){
      continue;
    }
    visited[aux.f][aux.s] = true;
    for (auto move: moves){
      pii pos = {aux.f + move.f, aux.s + move.s};
      if (!oob(pos, l, c) && mapa[pos.f][pos.s] == 'H' && !visited[pos.f][pos.s]){
        q.push(pos);
      }
    }

  }
  cout << aux.f + 1 << " " << aux.s + 1 << endl;
  exit(0);
}
