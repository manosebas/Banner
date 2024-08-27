//
//  GraduateStudent.hpp
//  19_ProyectoFinal

#ifndef GraduateStudent_hpp
#define GraduateStudent_hpp

#include <stdio.h>
#include "Student.hpp"
#include <string>

class GraduateStudent: public Student{
private:
    std::string nivel;
public:
    GraduateStudent();
    GraduateStudent(std::string, std::string, std::string, std::string, std::string, std::string, std::string);
    void setNivel(std::string);
    std::string getNivel();
    std::string to_string() override;
};

#endif
