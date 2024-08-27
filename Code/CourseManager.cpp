#include "CourseManager.hpp"
#include "ArrayList.hpp"
#include "Course.hpp"
#include "StudentManager.hpp"
#include "Faculty.hpp"
#include "FacultyManager.hpp"
#include <iostream>
#include <fstream>

CourseManager::CourseManager(const char *pathCursos, StudentManager* studentManager , FacultyManager* facultyManager, int totalCursos, int n_estudiantes){

    this->studentManager = studentManager;
    this->facultyManager = facultyManager;
    this->pathCursos = pathCursos;
    loadCourses(totalCursos, n_estudiantes);
}

void CourseManager::loadCourses(int totalCursos, int n_estudiantes){

    int creditos;
    std::string pathInfoCurso;
    std::string banIDFac;
    std::string banIDStud;
    std::string NRC;
    float nota;
    Student* Obestudiante;
    Course* ObnuevoCurso;
    Grade* Obnota;
    Faculty* Obprofesor;
    std::ifstream input;
    std::ifstream input1;

    input.open(this->pathCursos);
    if(input.is_open()){
        input >> totalCursos;

        for(int i=0; i<totalCursos; i++){
            input >> NRC >> creditos >> banIDFac >> pathInfoCurso;
            Obprofesor = this->facultyManager->getFacultyByID(banIDFac);
            ObnuevoCurso = new Course(NRC, Obprofesor, creditos);
            Obprofesor->setCursos(ObnuevoCurso);
            this->cursos.addObject(ObnuevoCurso);

            input1.open(pathInfoCurso);

            if(input1.is_open()){

                input1 >> n_estudiantes;
                for(int j=0; j< n_estudiantes; j++){
                    input1 >> banIDStud >> nota;
                    Obestudiante = this->studentManager->getStudentByID(banIDStud);
                    Obnota = new Grade(nota);
                    ObnuevoCurso->addStudentGrade(Obestudiante,Obnota);
                    Obestudiante->addClass(ObnuevoCurso);
                }
            }
            input1.close();
        }
    }
    input.close();
}

void CourseManager::updateCourses(){

    Faculty* profesor;
    std::ofstream output0;
    std::ofstream output1;
    std::string ArchCursostxt;

    output0.open("Courses.txt",std::ios::trunc);

    if(output0.is_open()){
        std::string Tc = std::to_string(totalCursos);
        output0 << Tc;

        for(int i=0; i< totalCursos; i++)
        {
            profesor = this->cursos[i]->getProfesor();
            ArchCursostxt = this->cursos[i]->getNRC()+profesor->getBannerID()+".txt";
            output0 << this->cursos[i]->to_string() << " " << ArchCursostxt;
            std::cout<<"\n";

            output1.open(ArchCursostxt, std::ios::trunc);

            if(output1.is_open()){
                std::string Te = std::to_string(numeroEstudiantes);
                output1 << Te;

                for(int j=0; j< numeroEstudiantes; j++)
                {
                    this->estudiantes = this->cursos[i]->getAllStudents();
                    this->notas = this->cursos[i]->getAllGrades();
                    output1 << this->estudiantes[i]->getBannerID() << " " << this->notas[j]->getNota();
                    std::cout << std::endl;
                }
            }
            output1.close();
        }
    }
    output0.close();
}

void CourseManager::createNewCourse(){
    std::string NRC;
    std::string banIDFac;
    std::string banIDStud;
    Course * ObnuevoCurso;
    Faculty* Obprofesor;
    Student* Obestudiante;
    Grade* Obnota;
    float nota;
    int totalEstudiantes;
    int totalCreditos;

    std::cout << "--- Curso Nuevo ---" << std::endl;
    std::cout<< "NRC: ";
    std::cin >> NRC;
    std::cout<< "BannerID del Profesor: ";
    std::cin >> banIDFac;
    Obprofesor = this->facultyManager->getFacultyByID(banIDFac);
    std::cout<< "Creditos Totales: ";
    std::cin >> totalCreditos;
    ObnuevoCurso = new Course(NRC, Obprofesor, totalCreditos);
    Obprofesor->setCursos(ObnuevoCurso);

    std::cout<< "Total de Estudiantes: ";
    std::cin >> totalEstudiantes;
    std::cout<< "Lista de estudiantes y notas: ";
    for(int i=0; i< totalEstudiantes; i++){
        std::cout << "BannerID del Estudiante " <<i <<": ";
        std::cin >> banIDStud;
        Obestudiante = this->studentManager->getStudentByID(banIDStud);
        Obestudiante->addClass(ObnuevoCurso);
        std::cout << "Nota " <<i <<": ";
        std::cin >> nota;
        Obnota = new Grade(nota);
        ObnuevoCurso->addStudentGrade(Obestudiante, Obnota);
    }

    totalCursos = totalCursos + 1;
    numeroEstudiantes = totalEstudiantes;
    this->updateCourses();
}

void CourseManager::editCourse(Course *curso){

    int index = 0;
    for(int i=0; i<this->cursos.getSize();i++){
        if(this->cursos[i]==curso){
            index = i;
        }
    }

    Faculty* Obprofesor;
    Student* Obestudiante;
    Grade* Obnota;
    std::string NRC;
    std::string banner0;
    std::string banner1;
    int nota;
    int NumeroEstudiantes;
    int creditos;

    int opcion;
    while ( true )
    {
        std::cout << "\nEditar..." << std::endl;
        std::cout << " 1.NRC" << std::endl;
        std::cout << " 2.Creditos" << std::endl;
        std::cout << " 3.Profesor" << std::endl;
        std::cout << " 4.Lista de Estudiantes y Notas" << std::endl;
        std::cout << " Opcion:";
        std::cin >> opcion;

        if (opcion==1 or opcion==2 or opcion==3 or opcion==4){
            opcion = opcion;
            break;
        }
        else
            std::cout << "Opcion invalida, vuelva a intentar" << std::endl;
    }
    if (opcion==1){
        std::cout <<"Ingrese el Nuevo NRC: ";
        std::cin >> NRC;
        this->cursos[index]->setNRC(NRC);
    }
    if (opcion==2){
        std::cout <<"Ingrese el Nuevo Numero de Creditos: ";
        std::cin >> creditos;
        this->cursos[index]->setCreditos(creditos);
    }
    if (opcion==3){
        std::cout <<"Ingrese el BannerID del Nuevo Profesor: ";
        std::cin >> banner0;
        Obprofesor= this->facultyManager->getFacultyByID(banner0);
        this->cursos[index]->setProfesor(Obprofesor);
    }
    if (opcion==4){
        std::cout<< "Lista de Estudiantes y Notas .... ";
        std::cout << "Ingrese Nuevo Numero de Estudiantes: ";
        std::cin >> NumeroEstudiantes;
        for(int i=0; i< NumeroEstudiantes; i++){
            std::cout << "Ingrese BannerID del Nuevo Estudiante " <<i <<": ";
            std::cin >> banner1;
            Obestudiante = this->studentManager->getStudentByID(banner1);
            Obestudiante->addClass(curso);
            std::cout << "Ingrese Nueva Nota " <<i <<": ";
            std::cin >> nota;
            Obnota = new Grade(nota);
            curso->addStudentGrade(Obestudiante, Obnota);
            numeroEstudiantes = NumeroEstudiantes;
        }
    }
    this->updateCourses();
}

void CourseManager::showCourses(){
    std::cout << "********** CURSOS **********" << std::endl;
    for(int i=0; i < this->cursos.getSize(); i++){
        std::cout << std::to_string(i) + "  " + this->cursos[i]->to_string() << std::endl;
    }
}

Course *CourseManager::getClassporID(std::string NRC)
{
    int x=0;
    for (int i = 0; i < this->cursos.getSize(); i++){
        if(this->cursos[i]->getNRC() == NRC){
            x=1;
            return this->cursos[i];
        }
    }

    if(x==0){
        throw NRCNotFound();
    }
    return nullptr;
    }

void CourseManager::showClassByID(std::string NRC){

    for (int i = 0; i < this->cursos.getSize(); i++){
        if(this->cursos[i]->getNRC() == NRC){
            std::cout << this->cursos[i]->to_string();
        }
        else{
            throw NRCNotFound();
        }
    }
}

void CourseManager::deleteCourse(Course *curso){

    int index = 0;
    for(int i=0; i<this->cursos.getSize();i++){
        if(this->cursos[i]==curso){
            index = i;
        }
    }
    this->cursos.deleteObjectAt(index);
    totalCursos = totalCursos - 1;
    this->updateCourses();
}

void CourseManager::showList(Course* curso){

    int index = 0;
    for(int i=0; i<this->cursos.getSize();i++){
        if(this->cursos[i]==curso){
            index = i;
        }
    }

    for(int j=0; j< numeroEstudiantes; j++)
    {
        this->estudiantes = this->cursos[index]->getAllStudents();
        this->notas = this->cursos[index]->getAllGrades();

        std::cout << this->estudiantes[j]->getBannerID() + " " + std::to_string(this->notas[j]->getNota());
    }

}
