#include "RedSocial.h"
#include <iostream>
using namespace std;

RedSocial::RedSocial(){
}

const set<int> & RedSocial::usuarios() const{ //Prototipada
    // O(1)
    return _usuarios;
}

string RedSocial::obtener_alias(int id) const{ //Prototipada
    // O(log n)
    string res;
    if(_primero == nullptr){
        return;
    }
    node *current = _primero;
    while(current != nullptr){
        if(current->id == id){
            return current->alias;
        } else if (id < current->id){
            current = current->izquierdo;
        } else {
            current = current->derecho;
        }
    }
    return res;
}

const set<string> & RedSocial::obtener_amigos(int id) const{ //Prototipada
    //O(log n)
    set<string> res;
    if(_primero == nullptr){
        return res;
    }
    node *current = _primero;
    while(current != nullptr){
        if(current->id == id){
            res = current->amigos;
            return res;
        } else if(current->id > id){
            current = current->izquierdo;
        } else {
            current = current->derecho;
        }
    }
}

const set<string> & RedSocial::obtener_conocidos(int id) const{
    // O(log n)
    static set<string> basura = {"basura"};
    return basura;
}
int RedSocial::cantidad_amistades() const{
    //O(1)
    return _amistades.size();
}

void RedSocial::registrar_usuario(string alias, int id){
    //O(log n) + O(1) promedio

}

void RedSocial::eliminar_usuario(int id){
    //Sin requerimiento

}

void RedSocial::amigar_usuarios(int id_A, int id_B){
    //Sin requerimiento

}

void RedSocial::desamigar_usuarios(int id_A, int id_B){
    //Sin requerimiento

}

int RedSocial::obtener_id(string alias) const{
    //O(1) promedio
    return -1;
}
const set<string> & RedSocial::conocidos_del_usuario_mas_popular() const{
    //O(1)
	static set<string> basura = {"basura"};
    return basura;
}

