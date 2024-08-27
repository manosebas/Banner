//
//  Grade.hpp
//  19_ProyectoFinal

#ifndef Grade_hpp
#define Grade_hpp
#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <string.h>

class Grade{
private:
    float nota;
    char letra;
public:
    Grade();
    Grade(float);
    void setNota(float);
    float getNota();
    char getLetra();
};
#endif
