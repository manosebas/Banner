//
//  Header.hpp
//  02_SolucionTarea01_C

#ifndef ArrayList_hpp
#define ArrayList_hpp

#include <stdio.h>
#include "RunTimeExceptions.h"

template <typename T>
class Nodo{

    private:
        T valor;
        Nodo * siguiente{nullptr};
        Nodo* anterior{nullptr};
    public:
        Nodo(T val):valor(val){}
        void setValor(T valor){
            this->valor=valor;
        }
        T getValor(){
            return valor;
        }
        void setSiguienteNodo(Nodo* siguiente){
            this->siguiente= siguiente;
        }
        Nodo* getSiguienteNodo(){
            return siguiente;
        }
        void setAnteriorNodo(Nodo* anterior){
            this->anterior= anterior;
        }
        Nodo* getAnteriorNodo(){
            return anterior;
        }
};

template <typename T>
class ArrayList
{
    private:
        int size{0};
        Nodo<T>* primero{nullptr};
        Nodo<T>* ultimo{nullptr};
    public:

        ArrayList(){}

        int getSize(){
            return this->size;
        }
        void addObject(T val){
            Nodo<T> * nodo = new Nodo<T>(val);
            if(size==0){
                primero = nodo;
                ultimo = nodo;
            }else{
                nodo->setAnteriorNodo(ultimo);
                ultimo->setSiguienteNodo(nodo);
                ultimo = nodo;
            }
            size++;
        }

        void deleteObjectAt(unsigned int index){
            if(size == 0){
                throw EmptyArrayList();
            }else{
                if(index + 1 <= size){
                    Nodo<T> *nodo = primero;
                    for(int i=0; i != index; i=i+1){
                        nodo = nodo->getSiguienteNodo();
                    }
                    Nodo<T> *reemplazar = nodo;
                    Nodo<T> *anterior = nodo->getAnteriorNodo();
                    Nodo<T> *siguiente = nodo->getSiguienteNodo();

                    if(anterior == nullptr or siguiente == nullptr){
                        if(anterior == nullptr and siguiente != nullptr){
                            primero = siguiente;
                        }else if (siguiente == nullptr and anterior != nullptr){
                            ultimo = anterior;
                        }else{
                            primero = nullptr;
                            ultimo = nullptr;
                        }
                        delete reemplazar;
                    }else{
                        siguiente->setAnteriorNodo(anterior);
                        anterior->setSiguienteNodo(siguiente);
                        delete reemplazar;
                    }
                    size--;
                }else{
                    throw IndexOutOfBounds();
                }
            }
        }

        void addObjectAt(T valor, int index){
            if(size == 0){
                throw IndexOutOfBounds();
            }else{
                if(index+1 <= size){
                    Nodo<T> *nuevoNodo = new Nodo<T>(valor);
                    Nodo<T> *actual = primero;

                    for(int i=0; i!=index; i++){
                        actual = actual->getSiguienteNodo();
                    }

                    Nodo<T> *anterior = actual->getAnteriorNodo();
                    Nodo<T> *siguiente = actual->getSiguienteNodo();

                    if(anterior == nullptr or siguiente == nullptr){
                        if(anterior == nullptr and siguiente != nullptr){
                            primero = nuevoNodo;
                            nuevoNodo->setSiguienteNodo(actual);
                            actual->setAnteriorNodo(nuevoNodo);
                        }else if (siguiente == nullptr and anterior != nullptr){
                            nuevoNodo->setSiguienteNodo(ultimo);
                            nuevoNodo->setAnteriorNodo(anterior);
                            anterior->setSiguienteNodo(nuevoNodo);
                            actual->setAnteriorNodo(nuevoNodo);
                        }
                    }else{
                        nuevoNodo->setSiguienteNodo(actual);
                        nuevoNodo->setAnteriorNodo(anterior);
                        anterior->setSiguienteNodo(nuevoNodo);
                        actual->setAnteriorNodo(nuevoNodo);
                    }
                    size++;
                }else{
                    throw IndexOutOfBounds();
                }
            }
        }

        T operator[](int index){
            if(size == 0){
                throw EmptyArrayList();
            }else{
                if(index+1 <= size){
                    Nodo<T> *nodo = primero;
                    for(int i=0; i!=index; i++){
                        nodo = nodo->getSiguienteNodo();
                    }
                    return nodo->getValor();
                }else{
                    throw IndexOutOfBounds();
                }
            }
        }

};

#endif
