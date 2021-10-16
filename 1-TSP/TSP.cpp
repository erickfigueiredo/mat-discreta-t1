#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>

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

int main(int argc, char **argv) {
    int n, aux, minDist;
    bool isFirstMin = false;
    srand(time(NULL));
    
    //le a matriz n*n de distancias
    if(argc > 1) n = atoi(argv[1]); //se tivermos parametros entra no modo de teste de tempo e aloca a matriz automaticamente
    else cin >> n;

    vector<vector<int>> mtrDist(n);
    vector<int> pointsIDs, bestRoute;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            //seta as posiçoes da matriz aleatoriamente
            if(argc > 1) aux = rand() % 1000;
            else cin >> aux;
            mtrDist[i].push_back(aux);
        }
    }

    for (int i = 0; i < n - 1; i++)
        pointsIDs.push_back(i + 1);

    do {
        int auxDist = calcDist(pointsIDs, mtrDist);
        //assume como melhor rota a primeira(so executa na primeira iteração :)
        if (!isFirstMin) {
            minDist = auxDist;
            bestRoute = pointsIDs;
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
