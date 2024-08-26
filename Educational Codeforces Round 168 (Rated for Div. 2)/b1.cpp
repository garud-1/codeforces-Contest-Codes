#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Macro to help iterate
#define rep(i, a, b) for(int i = a; i < b; i++)

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s, p;
        cin >> s >> p;

        // Create a 2D vector representation of the grid
        vector<vector<char>> v(2, vector<char>(n));
        rep(i, 0, n) v[0][i] = s[i];
        rep(i, 0, n) v[1][i] = p[i];

        // Counting the number of free and blocked cells
        int dot_cnt = 0, cnt = 0;
        rep(i, 0, 2) {
            rep(j, 0, n) {
                if (v[i][j] == '.') dot_cnt++;
                if (v[i][j] == '*') cnt++;
            }
        }

        // If there are no free cells and no blocked cells
        if (dot_cnt == 0 && cnt == 0) {
            cout << 0 << "\n";
            continue;
        }

        // Reset count for the number of cells meeting the criteria
        cnt = 0;

        // Check for the condition described in the problem
        rep(j, 0, n - 2) {
            if (v[1][j] == '*' && v[1][j + 2] == '*' && v[0][j + 1] == '.') {
                cnt++;
            }
            else if (v[0][j] == '*' && v[0][j + 2] == '*' && v[1][j + 1] == '.') {
                cnt++;
            }
        }
        
        cout << cnt << endl;
    }
    return 0;
}
