#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int t;  
    cin >> t;

    while (t--) {
        long long x, y, z;
        cin >> x >> y >> z;

        long long dx = abs(x);
        long long dy = abs(y);

        // Calculate minimum moves required for each direction
        long long movesX = (dx + z - 1) / z;  // Ceiling of dx / z
        long long movesY = (dy + z - 1) / z;  // Ceiling of dy / z

        long long totalMoves = movesX + movesY;

        // Ensure the number of moves is such that Freya lands exactly on (dx, dy)
        if (totalMoves % 2 == 1) {
            if (movesX > movesY) {
                movesX++;
            } else {
                movesY++;
            }
            totalMoves++;
        }

        cout << totalMoves << endl;
    }

    return 0;
}
