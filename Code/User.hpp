//
//  User.hpp
//  19_ProyectoFinal

#ifndef User_hpp
#define User_hpp

#include <string>

class User{
private:
    std::string bannerID;
    std::string nombre;
    std::string apellido;
    std::string contrasenia;
    std::string nombreCuentaUsuario;
public:
    User();
    User(std::string bannerID, std::string nombre, std::string apellido, std::string contrasenia, std::string nombreCuentaUsuario);
    void setBannerID(std::string bannerID);
    void setNombre(std::string nombre);
    void setApellido(std::string apellido);
    void setContrasenia(std::string contrasenia);
    void setUsuario(std::string nombreCuentaUsuario);
    std::string getBannerID();
    std::string getNombre();
    std::string getApellido();
    std::string getUsuario();
    std::string getContrasenia();
    virtual std::string to_string();
};

#endif
