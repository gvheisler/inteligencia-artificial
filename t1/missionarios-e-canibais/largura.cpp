#include <stdio.h>
#include <iostream>

#define TAM 3

int esq[TAM] = {TAM,TAM};
int dir[TAM] = {0,0};

bool lado_barco = false; //true == lado direito

void printa_lados(){
    printf("\n----------------\n");
    printf("|Esquerda: %d %d|\t|Direita: %d %d|\n", esq[0], esq[1], dir[0], dir[1]);
    if(!lado_barco){
        printf("Barco esta do lado esquerdo");
    }else{
        printf("Barco esta do lado direito");
    }
    printf("\n----------------\n");
}

bool regras_validas(){
    if(esq[0]<esq[1]&&esq[0]!=0&&lado_barco==true){
        printf("Lado esquerdo com mais canibais!");
        return false;
    }
    if(dir[0]<dir[1]&&dir[0]!=0&&lado_barco==false){
        printf("Lado direito com mais canibais!");
        return false;
    }
    return true;
}

void toma_acao(int acao){
    if(acao == 0){ //envia 1 missionario
        if(!lado_barco){
            if(esq[0]>=1){
                esq[0]-=1;
                dir[0]+=1;
                lado_barco = !lado_barco;
            }
        }else{
            if(dir[0]>=1){
                dir[0]-=1;
                esq[0]+=1;
                lado_barco = !lado_barco;
            }
        }
    }
    if(acao == 1){ //envia 2 missionarios
        if(!lado_barco){
            if(esq[0]>=2){
                esq[0]-=2;
                dir[0]+=2;
                lado_barco = !lado_barco;
            }
        }else{
            if(dir[0]>=2){
                dir[0]-=2;
                esq[0]+=2;
                lado_barco = !lado_barco;
            }
        }
    }
    if(acao == 2){ //envia 1 missionario e 1 canibal
        if(!lado_barco){
            if(esq[0]>=1&&esq[1]>=1){
                esq[0]-=1;
                esq[1]-=1;
                dir[0]+=1;
                dir[1]+=1;
                lado_barco = !lado_barco;
            }
        }else{
            if(dir[0]>=1&&dir[1]>=1){
                dir[0]-=1;
                dir[1]-=1;
                esq[0]+=1;
                esq[1]+=1;
                lado_barco = !lado_barco;
            }
        }
    }

    if(acao == 3){ // envia 1 canibal
        if(!lado_barco){
            if(esq[1] >= 1){
                esq[1] -= 1;
                dir[1] += 1;
                lado_barco = !lado_barco;
            }
        } else {
            if(dir[1]>=1){
                dir[1]-=1;
                esq[1]+=1;
                lado_barco = !lado_barco;
            }
        }
    }

    if(acao == 4){ // envia 2 canibais
        if(!lado_barco){
            if(esq[1]>=2){
                esq[1]-=2;
                dir[1]+=2;
                lado_barco = !lado_barco;
            }
        } else {
            if(dir[1]>=2){
                dir[1]-=2;
                esq[1]+=2;
                lado_barco = !lado_barco;
            }
        }
    }
}

void verifica_vitoria(){
    if(dir[0]==TAM&&dir[1]==TAM){
        printf("\nParabens! Voce ganhou!\n");
        exit(0);
    }
}

int main(){
    int escolha = -1;
    do{
        printa_lados();
        verifica_vitoria();
        if(regras_validas()){
            scanf("%d", &escolha);
            toma_acao(escolha);
        }else{
            break;
        }
    } while (escolha!=-1);
    
    

}