#include <bits/stdc++.h>

using namespace std;

void swap(int& a, int& b)
{
    int aux = a;
    a = b;
    b = aux;
};

int main()
{
    int count = 0;
    vector<pair<int, int>> p;
    int n; cin >> n;
    int v[n];
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    };

    for (int i = 0; i < n; i++)
    {
        int* min = &v[i];
        int curr_j;
        bool troca = false;
        for (int j = i + 1; j < n; j++)
        {
            if (v[j] < *min)
            {
            min = &v[j]; 
            curr_j = j; 
            troca = true; 
            }
        }
        if (troca)
        {
            auto aux = v[i];
            v[i] = *min;
            *min = aux;
            count++;
            p.push_back({i, curr_j});
        }
    }
  
    cout << count << endl;
    for (auto e: p)
    {
        cout << e.first << " " << e.second << endl;
    }

};