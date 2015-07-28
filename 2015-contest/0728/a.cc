#include <cstdio>
#define mx 64
using namespace std;
char mp[mx][mx];
int main() {
    int t, n;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
            scanf("%s", mp[i]);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (mp[i][j] == '.')
                    continue;
                if (mp[i][j] == 'R') {
                    ans++;
                    for (int x = i, y = j; x >= 0 && y >= 0 && x < n && y < n; x++, y++) {
                        if (mp[x][y] == 'G')
                            mp[x][y] = 'B';
                        else if(mp[x][y]=='.')
                        	break;
                        else mp[x][y] = '.';
                    }
                }
                if (mp[i][j] == 'B') {
                    ans++;
                    for (int x = i, y = j; x >= 0 && y >= 0 && x < n && y < n; x++, y--) {
                        //System.out.println(x+" "+y);
                        if (mp[x][y] == 'G')
                            mp[x][y] = 'R';
                        else if(mp[x][y]=='.')
                        	break;
                        else mp[x][y] = '.';
                    }
                }
                if (mp[i][j] == 'G') {
                    ans++;
                    ans++;
                    for (int x = i, y = j; x >= 0 && y >= 0 && x < n && y < n; x++, y++) {
                        if (mp[x][y] == 'G')
                            mp[x][y] = 'B';
                        else if(mp[x][y]=='.')
                        	break;
                        else mp[x][y] = '.';
                    }
                    //mp[i][j] = 'G';
                    for (int x = i, y = j; x >= 0 && y >= 0 && x < n && y < n; x++, y--) {
                        if (mp[x][y] == 'G')
                            mp[x][y] = 'R';
                        else if(mp[x][y]=='.')
                        	break;
                        else mp[x][y] = '.';
                    }
                }
                //                    for(int x = 0;x<n;x++){
                //                        for(int y = 0;y<n;y++){
                //                            System.out.print(mp[x][y]);
                //                        }
                //                        System.out.println();
                //                    }
                //                    System.out.println();
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}