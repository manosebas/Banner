//
//  Course.cpp
//  19_ProyrctoFinal

#include "Course.hpp"
#include "Faculty.hpp"
#include "Grade.hpp"
#include "ArrayList.hpp"
#include "Student.hpp"
#include <iostream>

Course::Course(){}

Course::Course(std::string _nrc, Faculty *_profesor, int _totalCreditos):nrc(_nrc), profesor(_profesor),totalCreditos(_totalCreditos){}

void Course::setProfesor(Faculty *profesor){
    this->profesor = profesor;
}

void Course::addStudentGrade(Student* _estudiante, Grade* _nota){
    this->estudiantes.addObject(_estudiante);
    this->notas.addObject(_nota);
}

Faculty* Course::getProfesor(){
    return profesor;
}

std::string Course::getNRC(){
    return nrc;
}

Grade *Course::getGradeByStudent(Student *estudiante){

    for(int i=0; i < estudiantes.getSize(); i++){
        if(this->estudiantes[i]->getBannerID() == estudiante->getBannerID()){
            return notas[i];
        }
    }
    return NULL;
}

ArrayList<Student*> Course::getAllStudents(){
    return this->estudiantes;
}

ArrayList<Grade*> Course::getAllGrades(){
    return this->notas;
}

std::string Course::to_string(){
    return this->nrc + " " + std::to_string(this->getCreditos()) + " " + this->profesor->getBannerID();
}

void Course::setNRC(std::string nrc){
    this->nrc = nrc;
}

void Course::setCreditos(int totalCreditos){
    this->totalCreditos = totalCreditos;
}

int Course::getCreditos(){
    return totalCreditos;
}
