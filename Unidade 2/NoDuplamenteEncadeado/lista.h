#ifndef LISTA_H
#define LISTA_H

#include <cstdlib>
#include <iostream>
#include <no.h>

using namespace std;

template <class T>
class Lista{
public:
    Lista();
    Lista(No<T> *n);
    void AddFim(No<T> *n);
    void RemFim();
    void RemIni();
    void print();
private:
    No<T> *head;
    No<T> *end;
};

template <class T>
void Lista<T>::print(){
    No<T> *aux;
    aux = head;
    do{
        cout<<aux->getV()<<endl;
        aux = aux->getProx();
    }
    while(aux);
}

template <class T>
Lista<T>::Lista(){
    end = head = NULL;
}

template <class T>
Lista<T>::Lista(No<T> *n){
    head = n;
    end = n;
    n->setProx(NULL);
    n->setAnte(NULL);
}

template <class T>
void Lista<T>::AddFim(No<T> *n){
    end->setProx(n);
    n->setAnte(end);
    n->setProx(NULL);
    end = n;
}

template <class T>
void Lista<T>::RemFim(){
}

template <class T>
void Lista<T>::RemIni(){
    No<T> *aux;
    aux = head;

    head = head->getProx();
    head->setAnte(NULL);
    delete aux;

}



#endif // LISTA_H
