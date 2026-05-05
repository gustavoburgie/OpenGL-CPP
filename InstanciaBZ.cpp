#include "InstanciaBZ.h"
#include "Poligono.h"
#include "unistd.h"
#include "Ponto.h"

void SorteiaProximaCurva(InstanciaBZ &inst);
extern vector <Bezier> vetBez;

InstanciaBZ::InstanciaBZ(Bezier *curva) : InstanciaBZ(){
    Curva = curva;
}

Ponto InstanciaBZ::ObtemPosicao(){
    return Posicao; 
}

void InstanciaBZ::AtualizaPosicao(double tempoDecorrido){
    double deslocamento = Velocidade*tempoDecorrido;
    double deltaT = Curva->CalculaT(deslocamento);

    if(direcao == 1)
    tAtual += deltaT;
    else
    tAtual -= deltaT;

    //sorteia a prox curva
    if (!jaSorteou) {
        if ((direcao == 1 && tAtual >= 0.5) || (direcao == -1 && tAtual <= 0.5)) {
            SorteiaProximaCurva(*this);     // passa essa instância para a função global
            jaSorteou = true;
        }
    }

    //troca as curvas
    if(tAtual >= 1.0 || tAtual <= 0.0){
        nroDaCurva = proxCurva;
        direcao = proxDirecao;
        
        Curva = &vetBez.at(nroDaCurva); 

        if (direcao == 1) {
            tAtual = 0.0;
        } else {
            tAtual = 1.0;
        }

        jaSorteou = false; 
    }

    Posicao = Curva->Calcula(tAtual);   //retorna o ponto na curva

    //tfuturo pra não ficar dando umas "travadas"
    double tFuturo = tAtual + 0.01;

    Ponto PontoFuturo = Curva->Calcula(tFuturo);

    double dX = PontoFuturo.x - Posicao.x;
    double dY = PontoFuturo.y - Posicao.y;

    if (direcao == -1) {
        dX = -dX;
        dY = -dY;
    }

    if (dX != 0 || dY != 0) {
        double angulo = atan2(dY, dX); 
        double graus = angulo * 180.0 / M_PI;   //transforma de radianos pra graus
        
        Rotacao = graus;
    }
}

void InstanciaBZ::desenha(){
    glPushMatrix();
        glTranslatef(Posicao.x, Posicao.y, 0);
        glRotatef(Rotacao, 0, 0, 1);
        glScalef(Escala.x, Escala.y, Escala.z);
        
        defineCor(cor);
        modelo();       //desenha o poligono
        // Curva->Traca();
    glPopMatrix();
}