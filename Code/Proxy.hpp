//
//  Proxy.h pp
//  19_ProyectoFinal

#ifndef Proxy_hpp
#define Proxy_hpp

#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <string.h>

class Proxy{
private:
    std::string nombre;
    std::string apellido;
    std::string email;
    std::string numeroTelefonico;
public:
    Proxy();
    Proxy(std::string, std::string, std::string, std::string);
    void setNombre(std::string);
    void setApellido(std::string);
    void setEmail(std::string);
    void setNumeroTelefonico(std::string);
    std::string getNombre();
    std::string getApellido();
    std::string getEmail();
    std::string getNumeroTelefonico();
    std::string to_string();
};


#endif
