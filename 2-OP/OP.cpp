#include <iostream>
#include <vector>
#include <algorithm>
#define MAX  123456789
using namespace std;

void toBinary(vector<bool>& c, int num, int cursor = 1) {
    if (num == 1) {
        c[c.size() - cursor] = true;
        return;
    }

    if (num % 2 == 0) {
        c[c.size() - cursor] = false;
    }
    else {
        c[c.size() - cursor] = true;
    }

    toBinary(c, num / 2, ++cursor);
}

int calcScore(const vector<int> &perm,const vector<int> &scores){
    int total = 0;
    for(int i = 0;i<perm.size();i++){
         total+= scores[perm[i]-1];
    }
    return total;
}
int calcDist(const vector<int> &route, const vector<vector<int>> &mtrDist) {
    int total = mtrDist[0][route[0]-1];
    /*
    * temos que somar a distancia do ponto de partida
    * até a primeiro ponto da rota, e devemos somar a distância do ultimo ponto
    * da rota até o ponto de chegada
    */

    int i = 0;
    for (i; i < route.size() - 1; i++){
        total += mtrDist[route[i]][route[i + 1]-1];
    }
    total+= mtrDist[route[i]][mtrDist[0].size()-1];  
    return total;
}


int main() {
    int n,timeLimit;
    cin >> n;
    
    //vetor auxiliar para gera as combinaçoes
    vector<bool> combination(n-2);
    //vetor com as cidades cidades
    vector<int> nodes(n-2);
    //vetor com o score de cada cidade, score[i] = score da cidade i+1 
    vector<int> scores(n-2);
    
    //le os scores
    for(int i = 0;i < n-2;i++){cin >> scores[i];}

    cin >> timeLimit;
    
    //le a matriz de distancia
    vector<vector<int>> mtrDist(n-1);

    for(int i =0;i<n-1;i++){
        for(int j = 0; j<n-1;j++){
            int aux;
            cin >> aux;
            mtrDist[i].push_back(aux);
        }
    }
    
    //2^(n-2) nao consideramos a oriem nem o destino
    int numCombinations = 1 << (n-2);

    for (int i = 0; i < n-2; i++)
        nodes[i] = i + 1;
    
    //valores finais que serao atualizados a cada permutação melhor 
    int scoreTotal = 0;
    int disTotal = MAX;
    vector<int> bestRoute;
    
    //gera todas as combinações e permuta cada combinção
    for (int i = 1; i < numCombinations; i++) {
        vector <int> perm;
        //combination tem o valor de i em binario
        toBinary(combination, i);

        // Aqui perm recebe a combinação equivalente a i em binario
        for (int i = 0; i < combination.size(); i++) {
            if (combination[i])
                perm.push_back(nodes[i]);
        }
        
        //permuta a combinação atual
        do {
            
            int auxDist = calcDist(perm,mtrDist);
            int auxScore = calcScore(perm,scores);

            if(auxDist <= timeLimit and auxScore > scoreTotal){
                disTotal = auxDist;
                scoreTotal = auxScore;
                bestRoute = perm;
            }

        } while(next_permutation(perm.begin(), perm.end()));   
    }

    //imprime a distancia/tempo gasto o score e melhor rota
    if(disTotal == MAX){
        disTotal = mtrDist[0][n-2];
    }
    cout << disTotal << " ";
    cout << scoreTotal << "\n0 -> ";
    for(int i = 0;i< bestRoute.size();i++){
        cout << bestRoute[i] << " -> ";
    }
    cout << n-1 << "\n";

    return 0;
}
