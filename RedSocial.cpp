#include "RedSocial.h"
#include <iostream>
using namespace std;

RedSocial::RedSocial(){
}

const set<int> & RedSocial::usuarios() const{
    // borrar todo esto y escribir algo correcto
    static set<int> basura = {314};
    return basura;
}
string RedSocial::obtener_alias(int id) const{
    // borrar todo esto y escribir algo correcto
    return "basura";
}
const set<string> & RedSocial::obtener_amigos(int id) const{
    // borrar todo esto y escribir algo correcto
    static set<string> basura = {"basura"};
    return basura;
}

const set<string> & RedSocial::obtener_conocidos(int id) const{
    // borrar todo esto y escribir algo correcto
    static set<string> basura = {"basura"};
    return basura;
}
int RedSocial::cantidad_amistades() const{
    return -1;
}

void RedSocial::registrar_usuario(string alias, int id){

}

void RedSocial::eliminar_usuario(int id){

}

void RedSocial::amigar_usuarios(int id_A, int id_B){

}

void RedSocial::desamigar_usuarios(int id_A, int id_B){

}

int RedSocial::obtener_id(string alias) const{
    return -1;
}
const set<string> & RedSocial::conocidos_del_usuario_mas_popular() const{
	static set<string> basura = {"basura"};
    return basura;
}

