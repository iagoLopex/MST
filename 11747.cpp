#include <bits/stdc++.h>
			
using namespace std;

int c[1005];
			
int find(int k){
	if(c[k]==k) return k;
	return c[k] = find(c[k]);
}			
			
int main(){ 
	
	int v, e, i, a, b, P;
	cin >> v >> e;
	while(v || e){
		
		bool ok = true;
		
		vector<pair<int, pair<int,int> >>ad;
		vector<int>arest;
		
		for(i=0; i<v; i++) c[i] = i;
		
		for(i=0; i<e; i++){
			cin >> a >> b >> P;
			
			ad.push_back({P,{a,b}});
		}
		sort(ad.begin(),ad.end());
		
		for(i=0; i<e; i++){
			
			int u = ad[i].second.first;
			int v = ad[i].second.second;
			int p = ad[i].first;
			
			int pu = find(u);
			int pv = find(v);
			
			if(pu != pv){
				c[pu] = pv;
			}
			else{//nao faz parte da arvore 
				ok = false;
				arest.push_back(p);
			}
		}
		if(ok){ 
			cout << "forest\n";
		}
		else{
			for(i=0; i<arest.size(); i++){
				cout << arest[i];
				if(i<arest.size()-1) cout << " ";
			}
			cout << endl;
		} 
		
		cin >> v >> e;
	}		
}			
