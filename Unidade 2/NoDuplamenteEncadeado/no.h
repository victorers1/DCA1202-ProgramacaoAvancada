#ifndef NO_H
#define NO_H

template <class T>
class No{
public:
    No();
    No(T v);
    void setProx(No<T> *prox);
    void setAnte(No<T> *ante);
    void setV(T v);
    T getV();
    No<T> *getProx();
    No<T> *getAnte();
private:
    T v;
    No<T> *prox;
    No<T> *ante;
};

template <class T>
T No<T>::getV(){
    return v;
}

template<class T>
void No<T>::setV(T v){
    this->v = v;
}

template <class T>
No<T>::No(){
}

template <class T>
No<T>::No(T v){
    this->v = v;
}

template <class T>
void No<T>::setProx(No<T> *prox){
    this->prox = prox;
}

template <class T>
void No<T>::setAnte(No<T> *ante){
    this->ante = ante;
}

template <class T>
No<T> *No<T>::getProx(){
    return prox;
}

template <class T>
No<T> *No<T>::getAnte(){
    return ante;
}

#endif // NO_H
