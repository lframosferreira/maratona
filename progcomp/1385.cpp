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
typedef vector<vi> vvi;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

// retorna inteiro reporesnetado na string de a ate b incluso
int f(string &txt, int a, int b){
    return stoi(txt.substr(a, b-a));
}

int main(){ 
    int C; cin >> C;
    while (C--){
        vvi vals(6, vi(6));
        string line; cin >> line;
        int j = 1;
        while (isdigit(line[j])) j+=2;
        int n=line[j-2]-'0';
        vector<string> names(5);
        vector<string> nums(5);
        string tp;
        int ppl=0;
        while (cin >> line){
            if (line.substr(0, 2) == "TP"){
                tp=line.substr(2, string::npos);
                break;
            }
            int idx=0;
            ppl++;
            while (!isdigit(line[idx])) idx++;
            names[ppl] = line.substr(0, idx);
            nums[ppl]=line.substr(idx, string::npos);
        }
        


        
        // printando solução
        // for (int i = 1; i <= n; i++) cout << "P" << i << " ";
        // cout << "Totals" << endl;


    }


    exit(0);
}
