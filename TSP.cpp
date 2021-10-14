#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int n;
    vector <int> pointsIDs;

    cin >> n;

    for(int i = 0; i < n; i++) pointsIDs.push_back(i+1);

    do{
        for(int i = 0; i < n; i++) cout << pointsIDs[i] << ' ';
        cout << endl;
    } while(next_permutation(pointsIDs.begin(), pointsIDs.end()));

    //return 0;
}