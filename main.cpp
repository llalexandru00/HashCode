#include <bits/stdc++.h>

using namespace std;

int n, m;
char p;
struct poza {
    int poz;
    set<string> val;
}s[100005];
int Poz[100005];
vector<int> Sol;
int Ans[100005];

bool comp2(poza A, poza B)
{
    return A.poz<B.poz;
}

int dif(int x, int y)
{
    int comune=0;
    for (auto i : s[x].val)
        if (s[y].val.find(i)!=s[y].val.end())
            comune++;
    return min(comune, (int)min(s[x].val.size()-comune, s[y].val.size()-comune));
}

int check(int st, int dr)
{
    int score=0;
    for (int i=st; i<dr; i++)
        score+=dif(i, i+1);
    return score;
}

int main()
{
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    srand(time(NULL));
    cin>>n;
    for (int i=0; i<n; i++)
    {
        cin>>p>>m;
        for (int j=1; j<=m; j++)
        {
            string x;
            cin>>x;
            s[i+1].val.insert(x);
        }
        s[i+1].poz=i;
    }
    random_shuffle(s+1, s+n+1);
    cerr<<"Ok"<<endl;
    for (int i=2; i<=n; i++)
    {
        for (int j=i; j<=n; j++)
        {
            if (dif(i-1, j)>=3)
            {
                swap(s[i], s[j]);
                break;
            }
        }
        if (i%100==0)
            cerr<<i<<endl;
    }
    cout<<n<<endl;
    for (int i=1; i<=n; i++)
        cout<<s[i].poz<<endl;
    return 0;
}
