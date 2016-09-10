#include <fstream>
#include <iostream>
#define lg long double
using namespace std;
 
struct Player {
    string name;
    lg kda;
};
 
Player players[10];
 
void solve() {
    bool uninstall;
    int cases, i, j;
    lg d, k, minKda;
    cin >> cases;
    for (i = 0; i < cases; i++) {
        for (j = 0; j < 10; j++) {
            cin >> players[j].name >> k >> d;
            players[j].kda = k/d;
            minKda = min(players[j].kda, minKda);
        }
        for (j = 0; j < 10; j++) {
            if (j < 5) {
                uninstall = (players[j].kda == minKda) || (players[j].kda < ((lg)1/3));
            } else {
                uninstall = (players[j].kda < ((lg)1/2));
            }
            if (uninstall) cout << players[j].name << " plz uninstall\n";
        }
    }
}
 
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    // ========== //
    solve();
    return 0;
}