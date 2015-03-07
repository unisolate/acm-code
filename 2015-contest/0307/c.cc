#include <cstdio>
#include <iostream>
#include <string>
#include <map>
#include <cstring>
using namespace std;
map<string, int> v;
int l, t;
bool k,f[55555];
string s;
void dfs(int p) {
	if(k)
		return;
	if(f[p])
		return f[p];
    if (p == l){
    	puts("YES");
    	k=true;
        return;
    }
    if (p + 1 < l && v[s.substr(p, 2)])
        dfs(p + 2);
    if (v[s.substr(p, 1)])
        dfs(p + 1);
}
int main() {
    v["h"] = v["li"] = v["na"] = v["k"] = v["rb"] = v["cs"] = v["fr"] =v["be"] =v["mg"] =v["ca"] =v["sr"] =v["ba"] =v["ra"] =
    v["sc"] =v["y"] =v["ti"] =v["zr"] =v["hf"] =v["rf"] =v["v"] =v["nb"] =v["ta"] =v["db"] =v["cr"] =v["mo"] =v["w"] =v["sg"] =
    v["mn"] =v["tc"] =v["re"] =v["bh"] =v["fe"] =v["ru"] =v["os"] =v["hs"] =v["co"] =v["rh"] =v["ir"] =v["mt"] =
    v["ni"] =v["pd"] =v["pt"] =v["ds"] =v["cu"] =v["ag"] =v["au"] =v["rg"] =v["zn"] =v["cd"] =v["hg"] =v["cn"] =
    v["b"] =v["al"] =v["ga"] =v["in"] =v["tl"] =v["c"] =v["si"] =v["ge"] =v["sn"] =v["pb"] =v["fl"] =
    v["n"] =v["p"] =v["as"] =v["sb"] =v["bi"] =v["o"] =v["s"] =v["se"] =v["te"] =v["po"] =v["lv"] =
    v["f"] =v["cl"] =v["br"] =v["i"] =v["at"] =v["he"] =v["ne"] =v["ar"] =v["kr"] =v["xe"] =v["rn"] =
    v["la"] =v["ce"] =v["pr"] =v["nd"] =v["pm"] =v["sm"] =v["eu"] =v["gd"] =v["tb"] =
    v["dy"] =v["ho"] =v["er"] =v["tm"] =v["yb"] =v["lu"] =
    v["ac"] =v["th"] =v["pa"] =v["u"] =v["np"] =v["pu"] =v["am"] =v["cm"] =
    v["bk"] =v["cf"] =v["es"] =v["fm"] =v["md"] =v["no"] =v["lr"] =1;
    scanf("%d", &t);
    while (t--) {
    	memset(f,false,sizeof(f));
        cin >> s;
        l = s.length();
        k=false;
        dfs(0);
        if(!k)
            puts("NO");
    }
    return 0;
}