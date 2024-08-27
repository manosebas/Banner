#ifndef CourseManager_hpp
#define CourseManager_hpp

#include "ArrayList.hpp"
#include "Course.hpp"
#include "StudentManager.hpp"
#include "Faculty.hpp"
#include "FacultyManager.hpp"
#include <string>

class CourseManager{
    private:
        ArrayList <Course*> cursos;
        const char* pathCursos;
        StudentManager *studentManager;
        FacultyManager *facultyManager;
        void loadCourses(int, int);
        void updateCourses();
        int numeroEstudiantes;
        int totalCursos;
        ArrayList<Grade*> notas;
        ArrayList<Student*> estudiantes;
    public:
        CourseManager(const char* pathCursos, StudentManager* studentManager, FacultyManager* facultyManager, int numeroEstudiantes, int totalCursos);
        void createNewCourse();
        void editCourse(Course* cursos);
        void showCourses();
        void showClassByID(std::string nrc);
        void deleteCourse(Course*);
        Course *getClassporID(std::string );
        void showList(Course*);

};

#endif
