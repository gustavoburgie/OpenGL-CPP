#ifndef InstanciaBZ_hpp
#define InstanciaBZ_hpp
#include <iostream>
using namespace std;

#include "Ponto.h"
#include "Bezier.h"

class InstanciaBZ{

public:
    InstanciaBZ();
    InstanciaBZ(Bezier *Curva); // Cria uma instancia e associa uma cruza a ela
    //TipoFuncao *modelo; // Referencia para a funcao que desenha o modelo
    Bezier *Curva; // referencia para a curva onde esta' a instancia
    Ponto Posicao, Escala;
    float Rotacao;
    int nroDaCurva; // Nro da curva onde esta' o personagem
    int proxCurva; // Nro da curva para onde ira' o personagem
    int cor;
    float Velocidade;
    float tAtual; // Valor do t onde esta' o personagem
    int direcao; // Andando do fim para o inicio, ou ao contrario
    void desenha();
    void AtualizaPosicao(float tempoDecorrido);
    Ponto ObtemPosicao();
};

#endif