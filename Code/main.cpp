//
//  main.cpp
//  19_ProyectoFinal

#include "Course.hpp"
#include "CourseManager.hpp"
#include "Student.hpp"
#include "StudentManager.hpp"
#include "UnderGraduateStudent.hpp"
#include "User.hpp"
#include "UserManager.hpp"
#include "Faculty.hpp"
#include "FacultyManager.hpp"
#include "Proxy.hpp"
#include "GraduateStudent.hpp"
#include "Grade.hpp"
#include "ArrayList.hpp"
#include "RunTimeExceptions.h"
#include <iostream>
#include <fstream>

using namespace std;

int main() {

    int opcion;
    char opcion1;
    int opcion2;
    int totalEstudiantes = 0;
    int totalEstudiantes1 = 0;
    int totalProfesores= 0;
    int totalCursos = 0;
    int numeroEstudiantes = 0;
    string usuario;
    string contrasenia;
    string nrc;
    string banner0;
    string banner1;
    string banner2;
    User* ObUsuario = NULL;
    User* ObUsuario2 = NULL;
    Faculty* ObProfesor = NULL;
    Faculty* ObProfesor2 = NULL;
    Faculty* ObProfesor3 = NULL;
    Student* ObEstudiante = NULL;
    Student* ObEstudiante2 = NULL;
    Student* ObEstudiante3 = NULL;
    Course* ObCurso = NULL;
    StudentManager ObStudentManager("./estudiantes_posgrado.txt", "./estudiantes_pregrado.txt", totalEstudiantes, totalEstudiantes1);
    FacultyManager ObFacultyManager("./profesores.txt", totalProfesores);
    CourseManager ObCourseManager("./Courses.txt", &ObStudentManager, &ObFacultyManager, totalCursos, numeroEstudiantes);
    UserManager ObUserManager(&ObFacultyManager, &ObStudentManager);

    //MENU PRINCIPAL
    do{
        cout << "\n**************************************************************" << endl;
        cout << " 1.Administrar el Sistema" << endl;
        cout << " 2.Acceso de Usuario " << endl;
        cout << " 3.Salir"<<endl;
        cout << " Opcion:";
        cin >> opcion;
        switch (opcion) {
        case 1:
            do {
                cout << endl;
                cout << " 1.Administrar Todos los Usuarios" << endl;
                cout << " 2.Administrar Todos los Estudiantes " << endl;
                cout << " 3.Administrar Todos los Profesores"<< endl;
                cout << " 4.Administrar Todos los Cursos"<< endl;
                cout << " 5.Regresar"<<endl;
                cout << " Opcion:";
                cin >> opcion1;
                cout << endl;
                switch (opcion1) {
                case '1':
                        do{                            
                            cout << endl;
                            cout << " 1.Mostrar Usuarios" << endl;
                            cout << " 2.Editar Usuario " << endl;
                            cout << " 3.Regresar"<<endl;
                            cout << " Opcion:";
                            cin >> opcion2;
                            cout << endl;
                            switch (opcion2) {
                                case 1:
                                    cout << endl;
                                    ObUserManager.showUser();
                                    break;
                                case 2:
                                    cout << endl;
                                    cout << "Ingrese el BannerID del Usuario a Editar: ";
                                    cin >> banner0;
                                    ObEstudiante2 = ObStudentManager.getStudentByID(banner0);
                                    if(ObEstudiante2 != nullptr){
                                        ObUsuario2 = dynamic_cast<User*>(ObEstudiante2);
                                    }
                                    ObProfesor2 = ObFacultyManager.getFacultyByID(banner0);
                                    if(ObProfesor2 != nullptr){
                                        ObUsuario2 = dynamic_cast<User*>(ObProfesor2);
                                    }
                                    ObUserManager.editUser(ObUsuario2);
                                    break;
                                default:
                                    cout << "Opcion Incorrecta, vuelva a intentar" << endl;
                                    break;
                            }

                        }while (opcion2 != 3);
                    break;
                case '2':
                    do{
                        cout << endl;
                        cout << " 1.Crear Estudiante" << endl;
                        cout << " 2.Editar Estudiante " << endl;
                        cout << " 3.Mostrar Estudiantes " << endl;
                        cout << " 4.Borrar Estudiante " << endl;
                        cout << " 5.Regresar"<<endl;
                        cout << " Opcion:";
                        cin >> opcion2;
                        cout << endl;
                        switch (opcion2) {
                            case 1:
                                ObStudentManager.createNewStudent(&ObUserManager);
                                break;
                            case 2:
                                cout << "Ingrese el BannerID del Usuario a Editar: ";
                                cin >> banner0;
                                ObEstudiante = ObStudentManager.getStudentByID(banner0);
                                ObStudentManager.editStudent(ObEstudiante);
                                break;
                            case 3:
                                ObStudentManager.showStudents();
                                break;
                            case 4:
                                cout << "Ingrese el BannerID del Usuario a Borrar: ";
                                cin >> banner0;
                                ObEstudiante = ObStudentManager.getStudentByID(banner0);
                                ObStudentManager.deleteStudent(ObEstudiante);
                                break;
                            default:
                                cout << "Opcion Incorrecta, vuelva a intentar" << endl;
                                break;
                        }
                    }while (opcion2 != 5);
                    break;

                case '3':
                    do{
                        cout << endl;
                        cout << " 1.Crear Profesor" << endl;
                        cout << " 2.Editar Profesor " << endl;
                        cout << " 3.Mostrar Profesores " << endl;
                        cout << " 4.Borrar Profesor " << endl;
                        cout << " 5.Regresar"<<endl;
                        cout << " Opcion:";
                        cin >> opcion2;
                        cout << endl;
                        switch (opcion2) {
                            case 1:
                                ObFacultyManager.createNewFaculty(&ObUserManager);
                                break;
                            case 2:
                                cout << "Ingrese el BannerID del Profesor a Editar: ";
                                cin >> banner1;
                                ObProfesor = ObFacultyManager.getFacultyByID(banner1);
                                ObFacultyManager.editFaculty(ObProfesor);
                                break;
                            case 3:
                                ObFacultyManager.showFaculty();
                                break;
                            case 4:
                                cout << "Ingrese el BannerID del Profesor a Borrar: ";
                                cin >> banner1;
                                ObProfesor = ObFacultyManager.getFacultyByID(banner1);
                                ObFacultyManager.deleteFaculty(ObProfesor);
                                break;
                            default:
                                cout << "Opcion Incorrecta, vuelva a intentar" << endl;
                                break;
                        }
                    }while (opcion2 != 5);
                    break;
                case '4':
                    do{
                        cout << endl;
                        cout << " 1.Crear Curso" << endl;
                        cout << " 2.Editar Curso " << endl;
                        cout << " 3.Mostrar Cursos " << endl;
                        cout << " 4.Borrar Curso " << endl;
                        cout << " 5.Asociar Profesor a Curso " << endl;
                        cout << " 6.Asociar Estudiante a Curso " << endl;
                        cout << " 7.Mostrar Lista de Cursos (Asociados)" << endl;
                        cout << " 8.Regresar"<<endl;
                        cout << " Opcion:";
                        cin >> opcion2;
                        cout << endl;
                        switch (opcion2) {
                            case 1:
                                ObCourseManager.createNewCourse();
                                break;
                            case 2:
                                cout << "Ingrese el NRC del Curso a Editar: ";
                                cin >> nrc;
                                ObCurso = ObCourseManager.getClassporID(nrc);
                                ObCourseManager.editCourse(ObCurso);
                                break;
                            case 3:
                                ObCourseManager.showCourses();
                                break;
                            case 4:
                                cout << "Ingrese el NRC del Curso a Editar: ";
                                cout << "NRC: ";
                                cin >> nrc;
                                ObCurso = ObCourseManager.getClassporID(nrc);
                                ObCourseManager.deleteCourse(ObCurso);
                                break;
                            case 5:
                                cout << "Ingrese el NRC del Curso a Asociar: ";
                                cin >> nrc;
                                ObCurso = ObCourseManager.getClassporID(nrc);
                                ObCourseManager.editCourse(ObCurso);
                                cout << "Ingrese el BannerID del Profesor a Asociar: ";
                                cin >> banner2;
                                ObProfesor3 = ObFacultyManager.getFacultyByID(banner2);
                                ObProfesor3->setCursos(ObCurso);
                                break;
                            case 6:
                                cout << "Ingrese el NRC del Curso a Asociar: ";
                                cin >> nrc;
                                ObCurso = ObCourseManager.getClassporID(nrc);
                                ObCourseManager.editCourse(ObCurso);
                                cout << "Ingrese el BannerID del Estudiante a Asociar: ";
                                cin >> banner2;
                                ObEstudiante3 = ObStudentManager.getStudentByID(banner2);
                                ObEstudiante3->addClass(ObCurso);
                                break;

                            case 7:
                                cout << "Ingrese el NRC del Curso a Mostrar: ";
                                cin >> nrc;
                                ObCurso = ObCourseManager.getClassporID(nrc);
                                ObCourseManager.showList(ObCurso);
                                break;
                            default:
                                cout << "Opcion Incorrecta, vuelva a intentar" << endl;
                                break;
                        }
                    }while (opcion2 != 8);
                    break;
                default:
                    cout << "Opcion Incorrecta, vuelva a intentar" << endl;
                    break;
                }
            } while (opcion1 != '5');
            break;



        case 2: //Acceso de Usuario -->
            cout << "\n**************************************************************" << endl;
            cout << "Validacion de Credenciales..."<<endl;
            cout << "Ingrese Usuario: ";
            cin>>usuario;
            cout << "Ingrese Contraseña: ";
            cin>>contrasenia;

            ObUsuario = ObUserManager.ObvalidateCredentials(usuario,contrasenia);
            if(ObUsuario != nullptr)

                cout << endl;
                cout << " 1.Mostrar datos" << endl;
                cout << " 2.Editar datos " << endl;
                cout << " 3.Regresar"<<endl;
                cout << " Opcion:"; cin >> opcion1;
                cout << endl;
            break;

        case 3:
            cout<<"Saliendo ..."<< endl;
            break;
        default:
            cout << "Opcion Incorrecta, vuelva a intentar" << endl;
            break;
        }
    }while (opcion != 3);

    return 0;
}

