//
//  Faculty.hpp
//  19_ProyectoFinal

#include "Faculty.hpp"
#include "User.hpp"
#include "Course.hpp"
#include "ArrayList.hpp"
#include <iostream>

Faculty::Faculty(){}

Faculty::Faculty(std::string _bannerID, std::string _nombre, std::string _apellido, std::string _contrasenia, std::string _usuario, std::string _carrera):User(_bannerID, _nombre, _apellido, _contrasenia, _usuario), carrera(_carrera){}

void Faculty::setCarrera(std::string carrera){
    this->carrera = carrera;
}

void Faculty::setCursos(Course* _curso){
    this->cursos.addObject(_curso);
}

std::string Faculty::getCarrera(){
    return this->carrera;
}

ArrayList <Course *> Faculty::getCursos(){
    return this->cursos;
}

std::string Faculty::to_string(){
    return User::to_string() + " " + this->getCarrera();
}
