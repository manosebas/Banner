//
//  User.cpp
//  19_ProyectoFinal

#include "User.hpp"
#include <iostream>


User::User(){ }

User::User(std::string _bannerID, std::string _nombre, std::string _apellido, std::string _contrasenia, std::string _usuario):
bannerID(_bannerID), nombre(_nombre), apellido(_apellido), contrasenia(_contrasenia), nombreCuentaUsuario(_usuario){}

void User::setBannerID(std::string bannerID){
    this->bannerID = bannerID;
}

void User::setNombre(std::string nombre){
    this->nombre = nombre;
}

void User::setApellido(std::string apellido){
    this->apellido = apellido;
}

void User::setContrasenia(std::string contrasenia){
    this->contrasenia = contrasenia;
}

void User::setUsuario(std::string nombreCuentaUsuario){
    this-> nombreCuentaUsuario = nombreCuentaUsuario;
}

std::string User::getBannerID(){
    return this->bannerID;
}

std::string User::getNombre(){
    return this->nombre;
}

std::string User::getApellido(){
    return this->apellido;
}

std::string User::getContrasenia(){
    return this->contrasenia;
}

std::string User::getUsuario(){
    return this->nombreCuentaUsuario;
}

std::string User::to_string(){
    return this->getBannerID() + " " + this->getNombre() + " " + this->getApellido() + " " + this->getUsuario() + " " + this->getContrasenia();
}
