//
//  Student.hpp
//  19_ProyectoFinal

#ifndef Student_hpp
#define Student_hpp

#include "ArrayList.hpp"
#include "User.hpp"
#include "Course.hpp"
#include <string>
#include <stdio.h>
#include <cstdlib>
#include <iostream>

class Course;

class Student : public User{
private:
    std::string carrera;
    float gpa{0.0f};
    ArrayList <Course*> clases;
public:
    Student();
    Student(std::string, std::string, std::string, std::string, std::string, std::string);
    void setCarrera(std::string);
    void addClass(Course* clases);
    void calculateGPA();
    std::string getCarrera();
    ArrayList <Course*> getClases();
    float getGPA();
    std::string to_string() override;
};

#endif
