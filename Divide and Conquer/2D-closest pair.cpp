#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp(vector<int>& a, vector<int>& b) {
    return a[1] < b[1];
}

int sp(vector<vector<int>>& s) {
    if(s.size() == 1) return INT_MAX;
    // find median line, divide the points into two parts SL and SR，SL and SR are sorted by y
    int mid = s.size() / 2;
    sort(s.begin(), s.end(), cmp);
    vector<vector<int>> SL(s.begin(), s.begin() + mid);
    vector<vector<int>> SR(s.begin() + mid, s.end());
    int xmid = s[mid][0];  // x coordinate of the median line
    int d = min(sp(SL), sp(SR));
    // merge SL and SR into S
    vector<vector<int>> S;
    
    return d;
} 

int main() {
    vector<vector<int>> points = {{6, 5}, {3, 6}, {1, 7}, {4, 8}, {8, 1}, {2, 3}, {5, 4}, {7, 2}};
    sort(points.begin(), points.end(), cmp);
    // for(auto p : points) {
    //     cout << p[0] << " " << p[1] << endl;
    // }
    cout << sp(points) << endl;
    return 0;

}

// #include <iostream>
// #include <algorithm>
// #include <vector>
// using namespace std;

// bool cmp(vector<int>& a, vector<int>& b) {
//     return a[1] < b[1];
// }

// int sp(vector<vector<int>>& s) {
//     if(s.size() == 1) return INT_MAX;
//     // find median line, divide the points into two parts SL and SR，SL and SR are sorted by y
//     int mid = s.size() / 2;
//     vector<vector<int>> SL(s.begin(), s.begin() + mid);
//     vector<vector<int>> SR(s.begin() + mid, s.end());
//     int xmid = s[mid][0];  // x coordinate of the median line
//     int d = min(sp(SL), sp(SR));
//     // merge SL and SR into S
//     vector<vector<int>> S;
//     merge(SL.begin(), SL.end(), SR.begin(), SR.end(), back_inserter(S), cmp);
//     // find points in S that are within d distance from xmid
//     vector<vector<int>> S2;
//     for(auto p : S) {
//         if(abs(p[0] - xmid) < d) S2.push_back(p);
//     }
//     // find the closest pair in S2
//     for(int i = 0; i < S2.size(); i++) {
//         for(int j = i + 1; j < S2.size(); j++) {
//             if(S2[j][1] - S2[i][1] >= d) break;
//             d = min(d, abs(S2[j][0] - S2[i][0]) + abs(S2[j][1] - S2[i][1]));
//         }
//     }
//     return d;
// } 

// int main() {
//     vector<vector<int>> points = {{6, 5}, {3, 6}, {1, 7}, {4, 8}, {8, 1}, {2, 3}, {5, 4}, {7, 2}};
//     sort(points.begin(), points.end(), cmp);
//     // for(auto p : points) {
//     //     cout << p[0] << " " << p[1] << endl;
//     // }
//     cout << sp(points) << endl;
//     return 0;

// }