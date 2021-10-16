#include <iostream>
#include <vector>
#include <algorithm>

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

int main() {
    int n;
    cin >> n;

    vector<bool> combination(n);
    vector<int> nodes(n);

    int numCombinations = 1 << n;

    for (int i = 0; i < n; i++)
        nodes[i] = i + 1;

    for (int i = 1; i < numCombinations; i++) {
        vector <int> perm;
        toBinary(combination, i);

        // Aqui exibe a combinação
        for (int i = 0; i < combination.size(); i++) {
            if (combination[i])
                perm.push_back(nodes[i]);
        }

        do {
            for(int i = 0; i < perm.size(); i++) cout << perm[i] << ' ';
            cout << '\n';
        } while(next_permutation(perm.begin(), perm.end()));
        cout << '\n';
    }

    return 0;
}
