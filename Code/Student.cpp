//
//  Studnt.c pp
//  19_ProyectoFinal

#include "Student.hpp"
#include "Course.hpp"
#include "Grade.hpp"
#include <iostream>
#include "ArrayList.hpp"
#include "User.hpp"

Student::Student(){}

Student::Student(std::string _bannerID, std::string _nombre, std::string _apellido, std::string _usuario,
                  std::string _contrasenia, std::string carrera):User(_bannerID, _nombre, _apellido, _usuario, _contrasenia), carrera(carrera){
    this->carrera = carrera;
}

void Student::setCarrera(std::string carrera){
    this->carrera = carrera;
}

void Student::addClass(Course* _clase){
    this->clases.addObject(_clase);
}

void Student::calculateGPA(){
    gpa = 0.0;
    for(int i=0; i< this->clases.getSize(); i++){
        gpa += this->clases[i]->getGradeByStudent(this)->getNota();
    }
    gpa = (gpa / this->clases.getSize());
}

std::string Student::getCarrera(){
    return this->carrera;
}


float Student::getGPA(){
    return this->gpa;
}


ArrayList <Course*> Student::getClases(){
    return this->clases;
}

std::string Student::to_string(){
    return User::to_string() + " " + this->getCarrera();
    // return User::to_string() + " " + this->carrera + "GPA: " + std::to_string(this->gpa);

}
