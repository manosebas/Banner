#include "StudentManager.hpp"
#include "Student.hpp"
#include "Proxy.hpp"
#include "UnderGraduateStudent.hpp"
#include "GraduateStudent.hpp"
#include "UserManager.hpp"
#include "ArrayList.hpp"
#include "RunTimeExceptions.h"
#include <iostream>
#include <fstream>

StudentManager::StudentManager(){}

StudentManager::StudentManager(const char* pathUnderGraduate, const char* pathGraduate, int totalEstudiantes, int totalEstudiantes_1){

    this->pathUnderGraduate = pathUnderGraduate;
    this->pathGraduate = pathGraduate;
    this->loadUnderGrads(totalEstudiantes);
    this->loadGrads(totalEstudiantes_1);
}

void StudentManager::loadUnderGrads(int totalEstudiantes){
    std::ifstream input;
    Student* ObnuevoEstudiante;
    std::string bannerID;
    std::string nombre;
    std::string apellido;
    std::string contrasenia;
    std::string usuario;
    std::string carrera;
    std::string ProxyNombre;
    std::string ProxyApellido;
    std::string ProxyEmail;
    std::string ProxyTelefono;

    input.open(this->pathUnderGraduate);

    if(input.is_open()){
        input >> totalEstudiantes;
        for(int i=0; i<totalEstudiantes; i++)
        {
            input >> bannerID >> nombre >> apellido >> usuario >> contrasenia >> carrera >> ProxyNombre >> ProxyApellido >> ProxyApellido >> ProxyTelefono;
            Proxy representante(ProxyNombre, ProxyApellido, ProxyApellido, ProxyTelefono);
            ObnuevoEstudiante = new UnderGraduateStudent(bannerID, nombre, apellido, contrasenia, usuario, carrera, representante);
            this->estudiantes.addObject(ObnuevoEstudiante);
        }
    }
    else{
        throw FileNotFound();
    }
    input.close();
}
void StudentManager::loadGrads(int totalEstudiantes_1){
    std::ifstream input;
    Student* ObnuevoEstudiante1;
    std::string bannerID;
    std::string nombre;
    std::string apellido;
    std::string usuario;
    std::string contrasenia;
    std::string carrera;
    std::string nivel;
    input.open(this->pathGraduate);

    if(input.is_open()){
        input >> totalEstudiantes_1;
        for(int i=0; i<totalEstudiantes_1; i++)
        {
            input >> bannerID >> nombre >> apellido >> usuario >> contrasenia >> carrera >> nivel;
            ObnuevoEstudiante1 = new GraduateStudent(bannerID, nombre, apellido, contrasenia, usuario, carrera, nivel);
            this->estudiantes.addObject(ObnuevoEstudiante1);
        }
    }
    else{
        throw FileNotFound();
    }
    input.close();
}

void StudentManager::updateUnderGrads(){
    std::ofstream output;
    output.open("estudiantes_pregrado.txt", std::ios::trunc);

    if(output.is_open()){
        std::string Etotales = std::to_string(totalEstudiantes);
        output << Etotales;
        for(int i=0; i< totalEstudiantes; i++)
        {
            UnderGraduateStudent* ObunderGradStud = dynamic_cast<UnderGraduateStudent*>(estudiantes[i]);
            output << ObunderGradStud->to_string();
            std::cout << std::endl;
        }
    }
    output.close();

}

void StudentManager::updateGrads(){
    std::ofstream output;

    output.open("estudiantes_posgrado.txt", std::ios::trunc);

    if(output.is_open()){
        std::string Etotales = std::to_string(totalEstudiantes1);
        output << Etotales;
        for(int i=0; i< totalEstudiantes1; i++)
        {
            GraduateStudent* ObgradEstud = dynamic_cast<GraduateStudent*>(estudiantes[i]);
            output << ObgradEstud->to_string();
            std::cout << std::endl;
        }
    }
    output.close();
}

void StudentManager::createNewStudent(UserManager *userManager){
    this->userManager = userManager;
    Student* ObnuevoEstudiante;
    std::string bannerID = this->userManager->getNewBannerID();
    std::string nivel;
    std::string nombre;
    std::string apellido;
    std::string email;
    std::string telefono;
    std::string nombre0;
    std::string apellido0;
    std::string contrasenia0;
    std::string usuario0;
    std::string carrera0;

    int opcion;
    while ( true )
    {
        std::cout << std::endl;
        std::cout << "¿Que tipo de estudiante es su nuevo usario?" << std::endl;
        std::cout << " 1.UnderGraduate" << std::endl;
        std::cout << " 2.Graduate" << std::endl;
        std::cout << " Opcion:"; std::cin >> opcion;
        std::cout << std::endl;

        if (opcion==1 or opcion==2){
            opcion = opcion;
            break;
        }
        else{
            std::cout << "Opcion invalida, vuelva a intentar" << std::endl;

        }
    }

        std::cout << "Ingrese el Nombre: ";
        std::cin >> nombre0;
        std::cout << "Ingrese el Apellido: ";
        std::cin >> apellido0;
        std::cout << "Ingrese la Contrasena: ";
        std::cin >> contrasenia0;
        std::cout << "Ingrese el Usuario: ";
        std::cin >> usuario0;

        if (opcion == 1){
            std::cout << "Ingrese la Carrera:";
            std::cin >> carrera0;
            std::cout << "Ingrese el Nombre: ";
            std::cin >> nombre;
            std::cout << "Ingrese el Apellido: ";
            std::cin >> apellido;
            std::cout << "Ingrese el Email: ";
            std::cin >> email;
            std::cout << "Ingrese el Numero de telefono: ";
            std::cin >> telefono;
            Proxy representante(nombre, apellido, email, telefono);
            this->estudiantes.addObject(new UnderGraduateStudent( bannerID, nombre0, apellido0, contrasenia0, usuario0, carrera0, representante));
            ObnuevoEstudiante = this->estudiantes[this->estudiantes.getSize()];
            User* Obestudiante = dynamic_cast<User*>(ObnuevoEstudiante);
            this->userManager->addNewUser(Obestudiante);
            totalEstudiantes += 1;
            this->updateUnderGrads();
        }
        if(opcion == 2){
            std::cout << "Ingrese la Carrera:";
            std::cin >> carrera0;
            std::cout << "Ingrese el Nivel: ";
            std::cin >> nivel;
            this->estudiantes.addObject(new GraduateStudent( bannerID, nombre0, apellido0,  contrasenia0, usuario0, carrera0, nivel));
            ObnuevoEstudiante = this->estudiantes[this->estudiantes.getSize()];
            User* Obestudiante = dynamic_cast<User*>(ObnuevoEstudiante);
            this->userManager ->addNewUser(Obestudiante);
            totalEstudiantes1 += 1;
            this->updateGrads();
        }
}

Student *StudentManager::getStudentByID(std::string bannerID){
    int x=0;
    for (int i = 0; i < this->estudiantes.getSize(); i++){
        if(this->estudiantes[i]->getBannerID() == bannerID) {
            x=1;
            return this->estudiantes[i];
        }
    }
    if(x==0){
        throw BannerIDNotFound();
    }
    return nullptr;
}

ArrayList<Student*> StudentManager::getAllStudents(){
    return this->estudiantes;
}

void StudentManager::editStudent(Student *estudiante){

    int index = 0;
    for(int i=0; i<this->estudiantes.getSize();i++){
        if(this->estudiantes[i]==estudiante){
            index = i;
        }
    }
    std::string nombre;
    std::string apellido;
    std::string usuario;
    std::string contrasenia;
    std::string carrera;
    std::string nivel;

    int opcion;
    while ( true )
    {
        std::cout << "Editar Estudiante de Tipo..." << std::endl;
        std::cout << " 1.UnderGraduate" << std::endl;
        std::cout << " 2.Graduate" << std::endl;
        std::cout << " Opcion:";
        std::cin >> opcion;

        if (opcion==1 or opcion==2){
            opcion = opcion;
            break;
        }
        else
            std::cout << "Opcion Invalida, vuelva a intentar" << std::endl;
        }

        if(opcion == 1)
            this->updateUnderGrads();
        if(opcion == 2)
            this->updateGrads();

        if(opcion == 1){
            int opcion;
            while ( true )
            {
                std::cout << "Dato a Editar..." << std::endl;
                std::cout << " 1.Nombre" << std::endl;
                std::cout << " 2.Apellido" << std::endl;
                std::cout << " 3.Usuario" << std::endl;
                std::cout << " 4.Contasenia" << std::endl;
                std::cout << " 5.Carrera" << std::endl;
                std::cout << " Opcion:";
                std::cin >> opcion;

                if (opcion==1 or opcion==2 or opcion==3 or opcion==4 or opcion==5){
                    opcion = opcion;
                    break;
                }
                else
                    std::cout << "Opcion Invalida, vuelva a ingresar" << std::endl;
            }

            if (opcion==1){
                std::cout <<"Ingrese el Nuevo Nombre: ";
                std::cin >> nombre;
                this->estudiantes[index]->setNombre(nombre);
            }
            if (opcion==2){
                std::cout <<"Ingrese el Nuevo Apellido: ";
                std::cin >> apellido;
                this->estudiantes[index]->setApellido(apellido);
            }
            if (opcion==3){
                std::cout <<"Ingrese el Nuevo Usuario: ";
                std::cin >> usuario;
                this->estudiantes[index]->setUsuario(usuario);
            }
            if (opcion==4){
                std::cout <<"Ingrese la Nueva Contasenia: ";
                std::cin >> contrasenia;
                this->estudiantes[index]->setContrasenia(contrasenia);
            }
            if (opcion==5){
                std::cout <<"Ingrese la Nueva Carrera: ";
                std::cin >> carrera;
                this->estudiantes[index]->setCarrera(carrera);
            }
        }

}

void StudentManager::showStudents(){

    std::cout << "******** ESTUDIANTES *********" << std::endl;

    for(int i=0; i < this->estudiantes.getSize(); i++){
        std::cout << std::to_string(i) + "  " + this->estudiantes[i]->to_string() << std::endl;
    }
}

void StudentManager::deleteStudent(Student* estudiante){

    int index = 0;
    for(int i=0; i < this->estudiantes.getSize(); i++){
        if(this->estudiantes[i]==estudiante){
            index = i;
        }
    }

    int opcion;
    while ( true )
    {
        std::cout << "Estudiante a Borrar...." << std::endl;
        std::cout << " 1.UnderGraduate" <<std::endl;
        std::cout << " 2.Graduate" << std::endl;
        std::cout << " Opcion:";
        std::cin >> opcion;

        if (opcion==1 or opcion==2){
            opcion = opcion;
            break;
        }
        else
            std::cout << "Opcion Invalida, vuelva a intentar" << std::endl;
    }

    this->estudiantes.deleteObjectAt(index);
    if(opcion == 1){
        totalEstudiantes -= 1;
        this->updateUnderGrads();
    }

    if(opcion == 2){
        totalEstudiantes -= 1;
        this->updateGrads();
    }
}


