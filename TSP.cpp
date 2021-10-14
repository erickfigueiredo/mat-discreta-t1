#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int dist(const vector<int> & route, const vector<vector<int>> &mtrDist){
    int total = mtrDist[0][route[0]] + mtrDist[route[route.size()-1]][0]; //temos que somar a distancia da cidade do caixeiro
                                                                          // ate a primeira cidade da rota, e devemos somar a distancia da
                                                                          // ultima cidade da rota até a cidadd do caixeiros
    for(int i = 0;i<route.size()-1;i++){
        total += mtrDist[route[i]][route[i+1]];
    }
    return total;
}

int main() {

    int n;
    
    //le a matriz n*n de distancias
    cin >> n;
    vector<vector<int>> mtrDist(n);
    for(int i =0;i<n;i++){
        for(int j = 0;j<n;j++){
            int aux;
            cin >> aux;
            mtrDist[i].push_back(aux);
        }     
    }

    vector <int> pointsIDs; //vetor com uma rota inicial que sera permutado
    vector <int> bestRoute; //vetor que conterá a melhor a cada permutação
    int disMin = 123456789;

    for(int i = 0; i < n-1; i++) pointsIDs.push_back(i+1);
    
    //gera todas a n! permutações e calcula sua distancia
    do{
        int auxDist = dist(pointsIDs,mtrDist);
        if(auxDist < disMin){
            disMin = auxDist;
            bestRoute = pointsIDs;
        }
    } while(next_permutation(pointsIDs.begin(), pointsIDs.end()));
    
    //imprime a melhor rota
    cout << "0 -> ";        
    for(int i =0;i<n-1;i++){
        cout << bestRoute[i] << " -> ";
    }
    cout << "0\n";
    return 0;
}
