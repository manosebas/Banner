//
//  GraduateStudent.cpp
//  19_ProyectoFinal

#include "GraduateStudent.hpp"
#include "Student.hpp"
#include <iostream>

GraduateStudent::GraduateStudent(){}

GraduateStudent::GraduateStudent(std::string bannerID, std::string nombre, std::string apellido,
    std::string contrasenia, std::string usuario, std::string carrera,std::string _nivel):
    Student(bannerID, nombre, apellido, contrasenia, usuario, carrera), nivel(_nivel){}

void GraduateStudent::setNivel(std::string nivel){
    this->nivel = nivel;
}

std::string GraduateStudent::getNivel(){
    return this->nivel;
}

std::string GraduateStudent::to_string(){
    return Student::to_string() + " " + this->getNivel();
}
