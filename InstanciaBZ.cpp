#include "InstanciaBZ.h"
#include "Poligono.h"

InstanciaBZ::InstanciaBZ(){
    Poligono p;
    p.LePoligono("./entradas/Carro.txt");
    //associar a função p.desenhaPoligono() ao ponteiro *modelo
}

InstanciaBZ::InstanciaBZ(Bezier *curva) : InstanciaBZ(){
    Curva = curva;
    cor = Curva->cor;
}

Ponto InstanciaBZ::ObtemPosicao(){
    return Posicao; 
}

void InstanciaBZ::AtualizaPosicao(float tempoDecorrido){
    //atualizar o ponto de alguma forma em relação ao tAtual
}

void InstanciaBZ::desenha(){
    glPushMatrix();
        glTranslatef(Posicao.x, Posicao.y, 0);
        glRotatef(Rotacao, 0, 0, 1);
        glScalef(Escala.x, Escala.y, Escala.z);
        
        //desenhar o bagulho

    glPopMatrix();
}