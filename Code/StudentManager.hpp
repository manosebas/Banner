#ifndef StudentManager_hpp
#define StudentManager_hpp

class UserManager;

#include "Student.hpp"
#include "ArrayList.hpp"
#include "Proxy.hpp"
#include "UnderGraduateStudent.hpp"
#include "GraduateStudent.hpp"
#include "UserManager.hpp"
#include <string>

class StudentManager{
private:
    ArrayList <Student*> estudiantes;
    UserManager *userManager;
    const char* pathUnderGraduate;
    const char* pathGraduate;
    int totalEstudiantes;
    int totalEstudiantes1;
    void loadUnderGrads(int);
    void updateUnderGrads();
    void loadGrads(int);
    void updateGrads();

public:
    StudentManager();
    StudentManager(const char* pathUnderGraduate, const char* pathGraduate, int totalEstudiantes, int totalEstudiantes1);
    void createNewStudent(UserManager*);
    Student *getStudentByID(std::string);
    ArrayList <Student*> getAllStudents();
    void editStudent(Student*);
    void showStudents();
    void deleteStudent(Student*);
};

#endif
