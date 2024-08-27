#include "UserManager.hpp"
#include "FacultyManager.hpp"
#include "StudentManager.hpp"
#include "User.hpp"
#include "ArrayList.hpp"
#include "RunTimeExceptions.h"
#include <iostream>

UserManager::UserManager(){}

UserManager::UserManager(FacultyManager* ObfacultyManager, StudentManager* ObstudentManager){

    this->ObfacultyManager = ObfacultyManager;
    this->ObstudentManager = ObstudentManager;

    ArrayList<Faculty *> profesores = this->ObfacultyManager->getAllFaculty();
    ArrayList<Student *> estudiantes = this->ObstudentManager->getAllStudents();


    for(int i=0; i< profesores.getSize(); i++){
        this->usuarios.addObject((profesores)[i]);
    }

    for(int i=0; i< estudiantes.getSize(); i++){
        this->usuarios.addObject((estudiantes)[i]);
    }
}

User *UserManager::ObvalidateCredentials(std::string usuario, std::string contrasenia){
    int x=0;
    for (int i = 0; i < this->usuarios.getSize(); i++){
        if(this->usuarios[i]->getUsuario() == usuario && this->usuarios[i]->getContrasenia() == contrasenia){
            x=1;
            return this->usuarios[i];
        }
    }
    if(x==0){
        throw InvalidCredentials();
    }
    return nullptr;
}

void UserManager::editUser(User* usuario){

    int index=0;
    for(int i=0; i<this->usuarios.getSize();i++){
        if(this->usuarios[i]==usuario){
            index = i;
        }
    }

    std::string nombre;
    std::string apellido;
    std::string usuario0;
    std::string contrasenia;

    int opcion = 0;
    while ( true )
    {
        std::cout << "\n******** EDITAR DATOS ********" << std::endl;
        std::cout << " 1.Nombre" << std::endl;
        std::cout << " 2.Apellido" << std::endl;
        std::cout << " 3.Usuario" << std::endl;
        std::cout << " 4.Contasenia" << std::endl;
        std::cout << " Opcion:";
        std::cin >> opcion;

        if (opcion==1 or opcion==2 or opcion==3 or opcion==4){
            opcion = opcion;
            break;
        }
        else{
            std::cout << "Opcion invalida, vuelva a intentar" << std::endl;

        }
    }

    if (opcion==1){
        std::cout <<"Ingrese el Nuevo Nombre: ";
        std::cin >> nombre;
        this->usuarios[index]->setNombre(nombre);
    }
    if (opcion==3){
        std::cout <<"Ingrese el Nuevo Apellido: ";
        std::cin >> apellido;
        this->usuarios[index]->setApellido(apellido);
    }
    if (opcion==3){
        std::cout <<"Ingrese el Nuevo Usuario: ";
        std::cin >>usuario0;
        this->usuarios[index]->setUsuario(usuario0);
    }
    if (opcion==4){
        std::cout <<"Ingrese la Nueva Contrasenia: ";
        std::cin >> contrasenia;
        this->usuarios[index]->setContrasenia(contrasenia);
    }
}

void UserManager::showUser(){
    std::cout << "******** USUARIOS ********" << std::endl;
    for(int i=0; i < this->usuarios.getSize(); i++){
        std::cout << std::to_string(i) + "  " + this->usuarios[i]->to_string() << std::endl;
    }

}

ArrayList <User*> UserManager::getAllUsers(){
    return this->usuarios;
}

std::string UserManager::getNewBannerID(){
    std::string BannerID;
    int bID;
    std::string banner = usuarios[usuarios.getSize()]->getBannerID();
    int intnb = stoi(banner);
    bID = intnb + 1;
    BannerID = std::to_string(bID);
    return BannerID;
}

void UserManager::addNewUser(User* usuario){
    Student* Obopcion = dynamic_cast<Student*>(usuario);
    if(Obopcion != NULL)
    {
        User* opcion2 = dynamic_cast<User*>(Obopcion);
        this-> usuarios.addObject(opcion2);
    }
    else
    {
        Faculty* Obopcion = dynamic_cast<Faculty*>(usuario);

        if(Obopcion != NULL){
            User* opcion2 = dynamic_cast<User*>(Obopcion);
            this-> usuarios.addObjectAt(opcion2, 0);
        }
    }
}

void UserManager::deletUser(User* usuario){
    int index=0;
    for(int i=0; i < this->usuarios.getSize(); i++){
        if(this->usuarios[i]==usuario){
            index = i;
        }
    }
    Student* Obopcion = dynamic_cast<Student*>(usuario);
    if(Obopcion != NULL)
    {
        this->ObstudentManager->deleteStudent(Obopcion);
    }
    else
    {
        Faculty* Obopcion = dynamic_cast<Faculty*>(usuario);
        if(Obopcion != NULL){
            this->ObfacultyManager->deleteFaculty(Obopcion);
        }
    }
    this->usuarios.deleteObjectAt(index);
}
