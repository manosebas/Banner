//
//  Faculty.cpp
//  19_ProyectoFinal

#ifndef Faculty_hpp
#define Faculty_hpp
#include "User.hpp"
#include "ArrayList.hpp"
#include "Course.hpp"
#include <string>

class Course;

class Faculty : public User {
private:
    std::string carrera;
    int totalCursos;
    ArrayList <Course*> cursos;
public:
    Faculty();
    Faculty(std::string, std::string, std::string, std::string, std::string, std::string);
    void setCarrera(std::string);
    void setCursos(Course*cursos);
    std::string getCarrera();
    ArrayList <Course*> getCursos();
    std::string to_string() override;
};

#endif
