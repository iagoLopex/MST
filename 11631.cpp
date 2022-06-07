#include <bits/stdc++.h>

using namespace std;
//vetor de pai



int find(int k, int *c){
    if(c[k] == k){
        return k;
    }
    return c[k] = find(c[k], c);
}

int main(){
    
    int v, e, i, a, b, P, st, sm;
    cin >> v >> e;
    while(v || e){
        
        vector<pair<int,pair<int,int>>>ad;
        //inicializar
        int c[v];
        for(i=0; i<v; i++){c[i]=i;}
        st=0;
        sm=0;
        for(i=0; i<e; i++){
            cin >> a >> b >> P;
            st+=P;    
            ad.push_back({P,{a,b}});
        }            
        
        sort(ad.begin(), ad.end());
                    
        for(i=0; i<e; i++){
                    
            int u = ad[i].second.first;
            int v = ad[i].second.second;
            int p = ad[i].first;
            
            //pais ancestrais
            int pu = find(u, c);
            int pv = find(v, c);
            
            //se as arvores sao diferentes eu somo e uno ambas
            if(pu != pv){
                sm+=p;
                c[pu]=pv;
            }    
        }
        cout << st-sm << endl;
        
        cin >> v >> e;
    }
}
