//
//  UnderGraduateStudent.hpp
//  19_ProyectoFinal

#ifndef UnderGraduateStudent_hpp
#define UnderGraduateStudent_hpp

#include "Student.hpp"
#include "Proxy.hpp"
#include <string.h>

class UnderGraduateStudent : public Student{
private:
    Proxy representante;
public:
    UnderGraduateStudent();
    UnderGraduateStudent(std::string, std::string, std::string, std::string, std::string, std::string, Proxy);
    void setRepresentante(Proxy);
    Proxy *getRepresentante();
    std::string to_string() override;
};

#endif
