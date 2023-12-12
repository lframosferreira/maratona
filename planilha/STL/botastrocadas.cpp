#include <bits/stdc++.h>

using namespace std;

int main(){

   int n, m; char l;
   cin>>n;
   vector<int> esq(31, 0);
   vector<int> dir(31, 0);
   while (n--){
       cin>>m>>l;
       l == 'E' ? esq[m - 30]++ : dir[m-30]++;
   }
   int res = 0;
   for (int i=0; i<31;i++){
    res += min(dir[i], esq[i]);
   }
    cout << res << endl;

    return 0;
};
