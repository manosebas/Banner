//
//  Grade.cpp
//  19_ProyectoFinal

#include "Grade.hpp"
#include <iostream>

Grade::Grade(){}

Grade::Grade(float nota){
    setNota(nota);
}

void Grade::setNota(float nota){
    this->nota = nota;

    if(nota >= 91){
        letra = 'A';
    }else{
        if(nota >= 81 and nota < 91){
            letra = 'B';
        }else{
            if(nota >= 71 and nota < 81){
                letra = 'C';
            }else{
                if(nota >= 61 and nota < 71){
                    letra = 'D';
                }else{
                    letra = 'F';
                }
            }
        }
    }
}

float Grade::getNota(){
    return this->nota;
}

char Grade::getLetra(){
    return this->letra;
}

