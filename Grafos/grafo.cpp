#include <iostream>
#include <vector>

using namespace std;

#define vec vector<vector<pair<int,int> > >
//holi boli :v
int main()
{
    int n,m;
    cin>>n>>m;
    vec graph(n);
    vector<int> pesos(m);

    int a,b,p;
    for(int i=0;i<m;++i)
    {
        cin>>a>>b>>p;
        graph[a].push_back(make_pair(b,p));
    }

    for(int i=0; i<n; ++i){

        cout<<"nodo: "<<i<<endl;
        for(int j=0; j<graph[i].size(); ++j){

            cout<<"a nodo "<<graph[i][j].first<<" con peso: "<<graph[i][j].second<<endl;
        }
        cout<<endl;
    }

    return 0;
}
