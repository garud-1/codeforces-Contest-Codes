#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <cstring>
using namespace std;

void solve() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, d, k;
        cin >> n >> d >> k;
        
        vector<int> day_count(n + 2, 0); // n+2 to safely handle ri + 1
        
        for (int i = 0; i < k; ++i) {
            int li, ri;
            cin >> li >> ri;
            day_count[li]++;
            day_count[ri + 1]--;
        }
        
        // Compute the number of jobs for each day
        vector<int> jobs_count(n + 1, 0);
        int current_jobs = 0;
        for (int day = 1; day <= n; ++day) {
            current_jobs += day_count[day];
            jobs_count[day] = current_jobs;
        }
        
        // Determine maximum overlaps for brother
        int max_jobs = -1, best_brother_day = 1;
        for (int start_day = 1; start_day <= n - d + 1; ++start_day) {
            int end_day = start_day + d - 1;
            int total_jobs = 0;
            for (int day = start_day; day <= end_day; ++day) {
                total_jobs += jobs_count[day];
            }
            if (total_jobs > max_jobs) {
                max_jobs = total_jobs;
                best_brother_day = start_day;
            }
        }
        
        // Determine minimum overlaps for mother
        int min_jobs = INT_MAX, best_mother_day = 1;
        for (int start_day = 1; start_day <= n - d + 1; ++start_day) {
            int end_day = start_day + d - 1;
            int total_jobs = 0;
            for (int day = start_day; day <= end_day; ++day) {
                total_jobs += jobs_count[day];
            }
            if (total_jobs < min_jobs) {
                min_jobs = total_jobs;
                best_mother_day = start_day;
            }
        }
        
        cout << best_brother_day << " " << best_mother_day << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
