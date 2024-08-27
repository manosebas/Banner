#ifndef Course_hpp
#define Course_hpp

#include "ArrayList.hpp"
#include "Student.hpp"
#include "Faculty.hpp"
#include "Grade.hpp"
#include <string>

class Student;
class Faculty;
//
//  Course.cpp
//  19_ProyectoFinal


class Course{
    private:
        std::string nrc;
        Faculty *profesor;
        ArrayList <Student*> estudiantes;
        ArrayList <Grade*> notas;
        int totalCreditos;
    public:
        Course();
        Course(std::string nrc, Faculty* profesor, int totalCreditos);
        void setProfesor(Faculty* profesor);
        void addStudentGrade(Student* estudiante, Grade* nota);
        Faculty *getProfesor();
        std::string getNRC();
        Grade *getGradeByStudent(Student*);
        ArrayList<Student*> getAllStudents();
        ArrayList<Grade*> getAllGrades();
        std::string to_string();
        void setNRC(std::string);
        void setCreditos(int);
        int getCreditos();



};

#endif
