//
//  Proxy.cpp
//  19_ProyectoFinal

#include "Proxy.hpp"
#include <iostream>

Proxy::Proxy(){}

Proxy::Proxy(std::string _nombre, std::string _apellido, std::string _email, std::string _numeroTelefonico):
nombre(_nombre), apellido(_apellido), email(_email), numeroTelefonico(_numeroTelefonico){}

void Proxy::setNombre(std::string nombre){
    this->nombre = nombre;
}

void Proxy::setApellido(std::string apellido){
    this->apellido = apellido;
}

void Proxy::setEmail(std::string email){
    this->email = email;
}

void Proxy::setNumeroTelefonico(std::string numeroTelefonico){
    this->numeroTelefonico = numeroTelefonico;
}

std::string Proxy::getNombre(){
    return this->nombre;
}

std::string Proxy::getApellido(){
    return this->apellido;
}

std::string Proxy::getEmail(){
    return this->email;
}

std::string Proxy::getNumeroTelefonico(){
    return this->numeroTelefonico;
}

std::string Proxy::to_string(){
    return this->getNombre() + " " + this->getApellido() + " " + this->getEmail() + " " + this->getNumeroTelefonico();
}
