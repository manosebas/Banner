#ifndef RunTimeExeptions_h
#define RunTimeExeptions_h

#include <stdexcept>

class EmptyList: public std::runtime_error{
public: EmptyList(): std::runtime_error("Lista Vacia"){}
};

class IndexOutOfBounds: public std::runtime_error{
public: IndexOutOfBounds(): std::runtime_error("Indice fuera de los limites"){}
};

class EmptyArrayList: public std::runtime_error{
public: EmptyArrayList(): std::runtime_error("Arreglo Vacio"){}
};

class BannerIDNotFound: public std::runtime_error{
public: BannerIDNotFound(): std::runtime_error("Banner ID no encontrado"){}
};

class InvalidCredentials: public std::runtime_error{
public: InvalidCredentials(): std::runtime_error("Credenciales no validas"){}
};

class NRCNotFound: public std::runtime_error{
public: NRCNotFound(): std::runtime_error("NRC no encontrado"){}
};

class FileNotFound: public std::runtime_error{
public: FileNotFound(): std::runtime_error("Archivo no encontrado"){}
};

#endif
