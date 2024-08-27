#include "FacultyManager.hpp"
#include "ArrayList.hpp"
#include "Faculty.hpp"
#include "UserManager.hpp"
#include <iostream>
#include <fstream>

//FacultyManager::FacultyManager(){}

FacultyManager::FacultyManager(const char* pathFaculty, int profesoresTotal){
    this->pathFaculty = pathFaculty;
    loadFaculty(profesoresTotal);
}

void FacultyManager::loadFaculty(int totalProfesores){
    std::ifstream input;
    Faculty* Profesor;
    std::string contrasenia;
    std::string usuario;
    std::string carrera;
    std::string BannerID;
    std::string nombre;
    std::string apellido;

    input.open(this->pathFaculty);

    if(input.is_open()){
        input >> totalProfesores;
        for(int i=0; i < totalProfesores; i++){
            input >> BannerID >> nombre >> apellido >> contrasenia >> usuario >> carrera;
            Profesor = new Faculty(BannerID, nombre, apellido, contrasenia, usuario, carrera);
            this->profesores.addObject(Profesor);
        }
    }
    input.close();
}
void FacultyManager::updateFaculty(){
    std::ofstream output;
    output.open("profesores.txt", std::ios::trunc);

    if(output.is_open()){
        std::string pT = std::to_string(profesoresTotal);
        output << pT;
        for(int i=0; i< profesoresTotal; i++){
            output << this->profesores[i]->to_string();
        }
    }
    output.close();
}

void FacultyManager::createNewFaculty(UserManager *userManager){
    this->userManager = userManager;

    Faculty* Profesor;
    std::string BannerID = userManager->getNewBannerID();
    std::string nombre;
    std::string apellido;
    std::string contrasenia;
    std::string usuario;
    std::string carrera;

    std::cout << "********** Nuevo Estudiante **********: " << std::endl;
    std::cout << "Nombre: ";
    std::cin >> nombre;
    std::cout << "Apellido: ";
    std::cin >> apellido;
    std::cout << "Contrasenia: ";
    std::cin >> contrasenia;
    std::cout << "Usuario: ";
    std::cin >> usuario;
    std::cout << "Carrera:";
    std::cin >> carrera;

    this->profesores.addObject(new Faculty(BannerID, nombre, apellido,  contrasenia, usuario, carrera));
    Profesor = this->profesores[this->profesores.getSize()-1];
    User* profesor = dynamic_cast<User*>(Profesor);
    this->userManager-> addNewUser(profesor);
    profesoresTotal += 1;
    this->updateFaculty();
}

Faculty *FacultyManager::getFacultyByID(std::string BannerID){
    int x=0;

    for (int i = 0; i < this->profesores.getSize(); i++){
        if(this->profesores[i]->getBannerID() == BannerID) {
            x=1;
            return this->profesores[i];
        }
    }
    if(x==0){
        throw BannerIDNotFound();
    }
    return nullptr;

}

ArrayList <Faculty*> FacultyManager::getAllFaculty(){
    return this->profesores;

}

void FacultyManager::editFaculty(Faculty* profesor){
    std::string nombre;
    std::string apellido;
    std::string usuario;
    std::string contrasenia;
    std::string carrera;

    int index = 0;
    for(int i=0; i<this->profesores.getSize();i++){
        if(this->profesores[i]==profesor){
            index = i;
        }
    }

    int opcion;
    while ( true )
    {
        std::cout << std::endl;
        std::cout << "\nEditar..." << std::endl;
        std::cout << " 1.Nombre" << std::endl;
        std::cout << " 2.Apellido" << std::endl;
        std::cout << " 3.Usuario" << std::endl;
        std::cout << " 4.Contasenia" << std::endl;
        std::cout << " 5.Carrera" << std::endl;
        std::cout << " Opcion:"; std::cin >> opcion;
        std::cout << std::endl;

        if (opcion==1 or opcion==2 or opcion==3 or opcion==4 or opcion == 5){
            opcion = opcion;
            break;
        }
        else
            std::cout << "Opcion invalida, vuelva a intentar" << std::endl;
    }

    if (opcion==1){
        std::cout <<"Ingrese el Nuevo Nombre: ";
        std::cin >> nombre;
        this->profesores[index]->setNombre(nombre);
    }
    if (opcion==3){
        std::cout <<"Ingrese el Nuevo Apellido: ";
        std::cin >> apellido;
        this->profesores[index]->setApellido(apellido);
    }
    if (opcion==3){
        std::cout <<"Ingrese el Nuevo Usuario: ";
        std::cin >> usuario;
        this->profesores[index]->setUsuario(usuario);
    }
    if (opcion==4){
        std::cout <<"Ingrese la Nueva Contasenia: ";
        std::cin >> contrasenia;
        this->profesores[index]->setContrasenia(contrasenia);
    }
    if (opcion==5){
        std::cout <<"Ingrese la Nueva Carrera: ";
        std::cin >> carrera;
        this->profesores[index]->setCarrera(carrera);
    }
        this->updateFaculty();
}

void FacultyManager::showFaculty(){
    std::cout << "********** PROFESORES **********" << std::endl;
    for(int i=0; i < this->profesores.getSize(); i++){
        std::cout << std::to_string(i) + "  " + this->profesores[i]->to_string() << std::endl;
    }
}

void FacultyManager::deleteFaculty(Faculty* profesor){
    int index = 0;
    for(int i=0; i<this->profesores.getSize();i++){
        if(this->profesores[i]==profesor){
            index = i;
        }
    }
    this->profesores.deleteObjectAt(index);
    profesoresTotal -= 1;
    this->updateFaculty();
}
