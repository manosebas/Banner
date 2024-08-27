//
//  UnderGraduateStudent.cpp
//  19_ProyectoFinal

#include "UnderGraduateStudent.hpp"
#include "Student.hpp"
#include "Proxy.hpp"
#include <iostream>

UnderGraduateStudent::UnderGraduateStudent(){}

UnderGraduateStudent::UnderGraduateStudent(std::string _bannerID, std::string _nombre, std::string _apellido, std::string _contrasenia, std::string _usuario, std::string _carrera, Proxy _representante): Student(_bannerID, _nombre, _apellido, _contrasenia, _usuario, _carrera), representante(_representante){
}

void UnderGraduateStudent::setRepresentante(Proxy representante){
    this->representante = representante;
}

Proxy *UnderGraduateStudent::getRepresentante(){
    return &representante;
}

std::string UnderGraduateStudent::to_string(){
    return Student::to_string() + " " + this->getRepresentante()->to_string();
}
