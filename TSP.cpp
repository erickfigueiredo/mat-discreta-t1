#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int calcDist(const vector<int> &route, const vector<vector<int>> &mtrDist) {
    int total = mtrDist[0][route[0]] + mtrDist[route[route.size() - 1]][0];

    /*
    * temos que somar a distancia da cidade do caixeiro
    * até a primeira cidade da rota, e devemos somar a distância da
    * ultima cidade da rota até a cidade do caixeiros
    */

    for (int i = 0; i < route.size() - 1; i++)
        total += mtrDist[route[i]][route[i + 1]];

    return total;
}

int main() {
    int n, aux, minDist;
    bool isFirstMin = false;

    //le a matriz n*n de distancias
    cin >> n;

    vector<vector<int>> mtrDist(n);
    vector<int> pointsIDs, bestRoute;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> aux;

            mtrDist[i].push_back(aux);
        }
    }

    for (int i = 0; i < n - 1; i++)
        pointsIDs.push_back(i + 1);

    do {
        int auxDist = calcDist(pointsIDs, mtrDist);

        if (!isFirstMin) {
            minDist = auxDist;
            isFirstMin = true;
        } else if (auxDist < minDist) {
            minDist = auxDist;
            bestRoute = pointsIDs;
        }
    } while (next_permutation(pointsIDs.begin(), pointsIDs.end()));

    cout << minDist << '\n';

    //imprime a melhor rota
    cout << "0 -> ";
    for (int i = 0; i < n - 1; i++) 
        cout << bestRoute[i] << " -> ";

    cout << "0\n";

    return 0;
}
