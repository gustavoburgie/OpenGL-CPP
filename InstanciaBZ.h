#ifndef InstanciaBZ_hpp
#define InstanciaBZ_hpp
#include <iostream>
using namespace std;

#include "Ponto.h"
#include "Bezier.h"
#include "ListaDeCoresRGB.h"

typedef void TipoFuncao();

class InstanciaBZ{

public:
    InstanciaBZ() = default;
    InstanciaBZ(Bezier *Curva);     // Cria uma instancia e associa uma cruza a ela

    TipoFuncao *modelo = nullptr;   // Referencia para a funcao que desenha o modelo
    Bezier *Curva = nullptr;        // referencia para a curva onde esta' a instancia
    Ponto Posicao = Ponto(0,0,0);
    Ponto Escala = Ponto(1,1,1);
    float Rotacao = 0;
    int nroDaCurva = 0;             // Nro da curva onde esta' o personagem
    int proxCurva = 0;              // Nro da curva para onde ira' o personagem
    int cor = rand() % 100;
    float Velocidade = 1;
    float tAtual = 0;               // Valor do t onde esta' o personagem
    int direcao = 1;                // Andando do fim para o inicio, ou ao contrario
    
    void desenha();
    void AtualizaPosicao(double tempoDecorrido);
    Ponto ObtemPosicao();
};

#endif