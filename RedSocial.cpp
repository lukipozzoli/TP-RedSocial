#include "RedSocial.h"
#include <iostream>
using namespace std;

RedSocial::RedSocial(){
}

const set<int> & RedSocial::usuarios() const{ //Prototipada
    // O(1)
    return _id;
}

string RedSocial::obtener_alias(int id) const{ //Prototipada
    // O(log n)
    auto busqueda = _usuarios.find(id);
    if(busqueda != _usuarios.end()){
        return busqueda->second;
    } else {
        return "No encontrado";
    }
}

const set<string> & RedSocial::obtener_amigos(int id) const{ //Prototipada
    //O(log n)

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

