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

struct Compare {
    bool operator ()(const pii& a, const pii& b){
        if (a.s <= b.s) return true;
        return a.f <= b.f;
    }
};

int main(){ _
    int N, K; cin >> N >> K;
    vector<map<int, int>> hand(N+1);
    for (int i = 1; i <= N; i++){
        string game; cin >> game;
        int val;
        for (auto c: game){
            switch (c){
                case 'A':
                    val = 1;
                    break;
                case '2':
                    val = 2;
                    break;
                case '3':
                    val = 3;
                    break;
                case '4':
                    val = 4;
                    break;
                case '5':
                    val = 5;
                    break;
                case '6':
                    val = 6;
                    break;
                case '7':
                    val = 7;
                    break;
                case '8':
                    val = 8;
                    break;
                case '9':
                    val = 9;
                    break;
                case 'D':
                    val = 10;
                    break;
                case 'Q':
                    val = 11; 
                    break;
                case 'J':
                    val = 12;
                    break;
                case 'K':
                    val = 13;
                    break;
                default:
                    val = -1;
                    break;
            }
            if (val==-1) cout << "ERRO" << endl;
            hand[i][val]++; 
        }
    }
    int has_joker = K;
    int can_discard_joker = false;
    int curr_player = K;
    int winner = -1;
    for (int i = 1; i<= N; i++){
        if (has_joker != i){
            if (hand[i].begin()->second == 4) {
                winner = i;
                break;
            }
        }
    }
    if (winner==-1) while (true){
        if (has_joker == curr_player and can_discard_joker){
            has_joker = has_joker < N ? has_joker + 1 : 1;
            can_discard_joker = false;

            if (hand[curr_player].begin()->second == 4) {
                winner = curr_player;
                break;
            }

            curr_player = has_joker;
            continue;
        }
        can_discard_joker = true;

        // grab min from hand and pass to next
        int next_player = curr_player < N ? curr_player + 1 : 1;
        int mn = INF;
        int k = -1;
        for (auto [ke, v] : hand[curr_player]){
            if (v < mn){
                mn=v;
                k = ke;
            } else if (v==mn) {
               if (ke < k){
                    k = ke;
                } 
            }
        }
        hand[curr_player][k]--;
        if (!hand[curr_player][k]) hand[curr_player].erase(k);
        hand[next_player][k]++;

        if (has_joker != curr_player){
            if (hand[curr_player].begin()->second == 4) {
                winner = curr_player;
                break;
            }
        }

        curr_player = next_player;
    }

    cout << winner << endl;
    exit(0);
}
