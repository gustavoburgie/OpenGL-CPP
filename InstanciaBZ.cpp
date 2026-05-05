#include "InstanciaBZ.h"
#include "Poligono.h"
#include "unistd.h"

InstanciaBZ::InstanciaBZ(Bezier *curva) : InstanciaBZ(){
    Curva = curva;
}

Ponto InstanciaBZ::ObtemPosicao(){
    return Posicao; 
}

void InstanciaBZ::AtualizaPosicao(double tempoDecorrido){
    //atualizar o ponto de alguma forma em relação ao tAtual
    double deslocamento = Velocidade*tempoDecorrido;
    double deltaT = Curva->CalculaT(deslocamento);

    // cout << "deslocamento: " << deslocamento << " \n" << endl;
    // cout << "deltaT: " << deltaT << " \n" << endl;

    
    if(direcao == 1)
    tAtual += deltaT;
    else
    tAtual -= deltaT;

    if(tAtual >= 1.0){
        tAtual = 1.0;
        //trocar a curva pra alguma aleatória conectada no ponto final
    }
    else if(tAtual <= 0.0){
        tAtual = 0.0;
        //trocar a curva pra alguma aleatória conectada no ponto inicial
    }

    Ponto posicaoAntiga = Posicao;

    Posicao = Curva->Calcula(tAtual);   //retorna o ponto na curva

    double deltaX = Posicao.x - posicaoAntiga.x;
    double deltaY = Posicao.y - posicaoAntiga.y;

    Posicao.set(Posicao.x + deltaX, Posicao.y + deltaY);

    double angulo = atan2(Posicao.x, Posicao.y);

    double graus = angulo * 180/M_PI;    //transforma de radianos para graus

    Rotacao = graus;
}

void InstanciaBZ::desenha(){
    glPushMatrix();
        glTranslatef(Posicao.x, Posicao.y, 0);
        glRotatef(Rotacao, 0, 0, 1);
        glScalef(Escala.x, Escala.y, Escala.z);
        
        defineCor(cor);
        modelo();       //desenha o poligono
        Curva->Traca();
    glPopMatrix();
}