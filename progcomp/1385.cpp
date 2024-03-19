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

int main(){ _
    int C; cin >> C;
    while (C--){
        vvi vals(7, vi(7));
        string line; cin >> line;
        int j = 1;
        while (isdigit(line[j])) j+=2;
        int n=line[j-2]-'0';
        
        vector<string> names(n+1);
        vector<string> nums(n+1);
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
        
        for (int i =1; i <= n; i++) { 
            for (int l = 1; l < nums[i].length()-3; l++){
                for (int m = l+1; m < nums[i].length()-2; m++){
                    for (int r = m+1; r < nums[i].length()-1; r++){
                        int n1, n2, n3, t;
                        n1=stoi(nums[i].substr(0, l));
                        n2=stoi(nums[i].substr(l, m-l));
                        n3=stoi(nums[i].substr(m, r-m));
                        t=stoi(nums[i].substr(r, string::npos));
                        if (n1+n2+n3==t){
                            vals[i][1]=n1;
                            vals[i][2]=n1;
                            vals[i][3]=n1;
                            vals[i][4]=n1;
                        }
                    }
                }
            }
        }
        for (int i = 1; i <= ppl; i++){
           for (int k = 1; k <= n+1; k++){
                cout << nums[i][k] << " ";
            } 
            cout << endl;
        } 

        // printando solução
        // for (int i = 1; i <= n; i++) cout << "P" << i << " ";
        // cout << "Totals" << endl;


    }


    exit(0);
}
