#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iomanip> 
using namespace std;

int main() {
    int t, friends, n, v;
    int cases = 1;
    scanf("%d", &t);
    while (t--) {
        cin >> friends;
        unordered_map<int, unordered_set<int>> stamps; //unordered_(set and map) : time(O(1))
        vector<double> res(friends, 0);

        for (int i = 0;i < friends;i++) {
            cin >> n;
            while (n--) {
                cin >> v;
                if (stamps.find(v)==stamps.end()) stamps[v] = unordered_set<int>();
                stamps[v].insert(i); //1,2,3: 3-0,2  1-0  2-0,1,2  4-1,2  5-1  6-2
            }
        }
        int totalUnique = 0;
        for (auto& it : stamps) {
            if (it.second.size() == 1) {
                totalUnique++;
                res[*it.second.begin()]++;
            }
        }
        cout << "Case " << cases++ << ":";
        for (auto& u : res)
            cout << " " << setprecision(6) << fixed << u/ totalUnique * 100<< "%";
        cout << endl;
    }
}
