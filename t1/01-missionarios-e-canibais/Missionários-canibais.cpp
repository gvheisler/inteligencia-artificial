#include <iostream>
#include <cstdlib>

#define TAM 3

class Estado {
public:
    int M; // Número de missionários na margem esquerda
    int C; // Número de canibais na margem esquerda
    bool PosicaoDoBarco; // false para margem esquerda, true para margem direita

    Estado(int m, int c, bool pos) : M(m), C(c), PosicaoDoBarco(pos) {}

    bool regras_validas() const {
        if (M < C && M != 0 && PosicaoDoBarco) {
            std::cout << "Lado esquerdo com mais canibais!\n";
            return false;
        }
        if ((TAM - M) < (TAM - C) && (TAM - M) != 0 && !PosicaoDoBarco) {
            std::cout << "Lado direito com mais canibais!\n";
            return false;
        }
        return true;
    }

    void toma_acao(int acao) {
        if (acao == 0) { // envia 1 missionário
            if (!PosicaoDoBarco && M >= 1) {
                M--;
                PosicaoDoBarco = true;
            } else if (PosicaoDoBarco && (TAM - M) >= 1) {
                M++;
                PosicaoDoBarco = false;
            }
        } else if (acao == 1) { // envia 2 missionários
            if (!PosicaoDoBarco && M >= 2) {
                M -= 2;
                PosicaoDoBarco = true;
            } else if (PosicaoDoBarco && (TAM - M) >= 2) {
                M += 2;
                PosicaoDoBarco = false;
            }
        } else if (acao == 2) { // envia 1 missionário e 1 canibal
            if (!PosicaoDoBarco && M >= 1 && C >= 1) {
                M--;
                C--;
                PosicaoDoBarco = true;
            } else if (PosicaoDoBarco && (TAM - M) >= 1 && (TAM - C) >= 1) {
                M++;
                C++;
                PosicaoDoBarco = false;
            }
        } else if (acao == 3) { // envia 1 canibal
            if (!PosicaoDoBarco && C >= 1) {
                C--;
                PosicaoDoBarco = true;
            } else if (PosicaoDoBarco && (TAM - C) >= 1) {
                C++;
                PosicaoDoBarco = false;
            }
        } else if (acao == 4) { // envia 2 canibais
            if (!PosicaoDoBarco && C >= 2) {
                C -= 2;
                PosicaoDoBarco = true;
            } else if (PosicaoDoBarco && (TAM - C) >= 2) {
                C += 2;
                PosicaoDoBarco = false;
            }
        }
    }

    bool verifica_vitoria() const {
        return M == TAM && C == TAM && PosicaoDoBarco == true;
    }
};

int main() {
    Estado estadoInicial(TAM, TAM, false);

    int escolha = -1;
    do {
        std::cout << "\n----------------\n";
        std::cout << "|Esquerda: " << estadoInicial.M << " " << estadoInicial.C << "|\t|Direita: " << (TAM - estadoInicial.M) << " " << (TAM - estadoInicial.C) << "|\n";
        if (!estadoInicial.PosicaoDoBarco) {
            std::cout << "Barco esta do lado esquerdo\n";
        } else {
            std::cout << "Barco esta do lado direito\n";
        }
        std::cout << "----------------\n";

        if (estadoInicial.verifica_vitoria()) {
            std::cout << "\nParabéns! Você ganhou!\n";
            break;
        }

        if (estadoInicial.regras_validas()) {
            std::cin >> escolha;
            estadoInicial.toma_acao(escolha);
        } else {
            break;
        }
    } while (escolha != -1);

    return 0;
}
