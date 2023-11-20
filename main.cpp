#include <iostream>
#include <vector>

using namespace std;

int main() {
    int L, C, P;

    // Pergunta ao usuário o número de linhas e colunas
    cout << "Digite o numero de linhas (L) e colunas (C): ";
    cin >> L >> C;

    // Pergunta ao usuário o número de pixels pretos
    cout << "Digite o numero de pixels pretos (P): ";
    cin >> P;

    // Inicializa uma matriz para representar os pixels pretos
    vector<vector<int>> black(L, vector<int>(C, 0));

    // Pede ao usuário as coordenadas dos pixels pretos e marca na matriz
    cout << "Digite as coordenadas dos pixels pretos:" << endl;
    for (int i = 0; i < P; i++) {
        int Xi, Yi;
        cout << "Pixel " << i+1 << ": ";
        cin >> Xi >> Yi;
        black[Xi-1][Yi-1] = 1;
    }

    int white = 0;

    // Conta os pixels brancos adjacentes aos pixels pretos
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < C; j++) {
            if (!black[i][j]) {
                if (i > 0 && black[i-1][j] == 1) white++;
                if (i < L-1 && black[i+1][j] == 1) white++;
                if (j > 0 && black[i][j-1] == 1) white++;
                if (j < C-1 && black[i][j+1] == 1) white++;
            }
        }
    }

    // Imprime o resultado
    cout << "Numero de pixels brancos adjacentes: " << white << endl;

    return 0;
}