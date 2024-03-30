#include <iostream>
#include <queue>
#include <unordered_set>
using namespace std;

#define TAM 3

struct Estado {
    int barco; // 0 para esquerda, 1 para direita
    int missionarios_esq;
    int canibais_esq;
    int missionarios_dir;
    int canibais_dir;
};

bool estado_valido(int missionarios, int canibais) {
    // Verifica se o estado é válido (sem violar as regras do problema)
    return (missionarios >= canibais || missionarios == 0) && (TAM - missionarios >= TAM - canibais || TAM - missionarios == 0);
}

vector<Estado> gerar_estados_possiveis(const Estado& estado_atual) {
    vector<Estado> estados;
    Estado novo_estado;

    // Gera todos os movimentos possíveis do barco
    for (int i = 1; i >= 0; i--) { // i = 1: envia 1 missionário, i = 0: envia 1 canibal
        for (int j = 2; j >= 1; j--) { // j = 2: envia 2 missionários, j = 1: envia 2 canibais
            // Cada movimento é tentado de ambos os lados do rio
            if (estado_atual.barco == 0) {
                novo_estado = estado_atual;
                if (i == 1) { // Enviar 1 missionário
                    novo_estado.missionarios_esq--;
                    novo_estado.missionarios_dir++;
                } else { // Enviar 1 canibal
                    novo_estado.canibais_esq--;
                    novo_estado.canibais_dir++;
                }
            } else {
                novo_estado = estado_atual;
                if (i == 1) { // Enviar 1 missionário
                    novo_estado.missionarios_dir--;
                    novo_estado.missionarios_esq++;
                } else { // Enviar 1 canibal
                    novo_estado.canibais_dir--;
                    novo_estado.canibais_esq++;
                }
            }

            // Verifica se o novo estado é válido
            if (estado_valido(novo_estado.missionarios_esq, novo_estado.canibais_esq) &&
                estado_valido(novo_estado.missionarios_dir, novo_estado.canibais_dir)) {
                novo_estado.barco = 1 - estado_atual.barco; // Muda a posição do barco
                estados.push_back(novo_estado);
            }
        }
    }
    return estados;
}

bool estado_objetivo(const Estado& estado) {
    return estado.missionarios_esq == 0 && estado.canibais_esq == 0;
}

bool bfs() {
    queue<Estado> fila;
    unordered_set<int> visitados;
    Estado estado_inicial = {0, TAM, TAM, 0, 0}; // Estado inicial
    fila.push(estado_inicial);

    while (!fila.empty()) {
        Estado estado_atual = fila.front();
        fila.pop();

        if (estado_objetivo(estado_atual)) {
            // Imprimir a solução
            cout << "Solucao encontrada!" << endl;
            return true;
        }

        // Gera os próximos estados possíveis
        vector<Estado> proximos_estados = gerar_estados_possiveis(estado_atual);
        for (const auto& prox_estado : proximos_estados) {
            // Verifica se o estado já foi visitado
            int hash_value = prox_estado.missionarios_esq * 1000 + prox_estado.canibais_esq * 100 + prox_estado.missionarios_dir * 10 + prox_estado.canibais_dir;
            if (visitados.find(hash_value) == visitados.end()) {
                fila.push(prox_estado);
                visitados.insert(hash_value);
            }
        }
    }
    return false;
}

int main() {
    if (!bfs()) {
        cout << "Nao foi possivel encontrar uma solucao!" << endl;
    }
    return 0;
}
