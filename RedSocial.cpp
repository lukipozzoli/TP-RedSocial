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
    auto busqueda = _amigos.find(id);
    if(busqueda != _amigos.end()){
       const set<string> &resultado = busqueda->second;
        return resultado;
    } else {
        return;
    }
}

const set<string> & RedSocial::obtener_conocidos(int id) const{
    // O(log n)
    static set<string> basura = {"basura"};
    return basura;
}

int RedSocial::cantidad_amistades() const{ //Prototipada
    //O(1)
    return _amistades.size();
}

void RedSocial::registrar_usuario(string alias, int id){ //A medias
    //O(log n) + O(1) promedio
    _usuarios.insert(id,alias);
    _id.insert(id);
    _aliases.insert(alias,id);
    _amigos.insert(id,null);
    _amistades.insert(id,null);
    //Faltan las amistades y movidas
}

void RedSocial::eliminar_usuario(int id){ //Prototipada
    //Sin requerimiento
    _usuarios.erase(id); //Borro de la lista de usuarios
    
    string alias_eliminar = obtener_alias(id);//Borro de la lista de alias
    _aliases.erase(alias_eliminar);

    auto amigos =  _amigos.find(id);
    amigos = amigos->second;
    string alias_eliminar = obtener_alias(id);
    for(auto it : _amigos){ //Lo borro a id como amigo de todos sus amigos
        it.second.erase(alias_eliminar);
    }

    amigos = _amistades.find(id);
    amigos = amigos->second;
    for(auto it : _amistades){ //Lo borro como amigo de sus amigos
        it.second.erase(id);
    }

    _amigos.erase(id); //Lo borro de la lista de amigos
    _amistades.erase(id); //Lo borro de la lista de amistades
}

void RedSocial::amigar_usuarios(int id_A, int id_B){ //Prototipada
    //Sin requerimiento
    auto amistadesA = _amistades.find(id_A);
    amistadesA->second.insert(id_B); //Meto B como amigo de A
    auto amigosA = _amigos.find(id_A);
    string aliasB = obtener_alias(id_B);
    amistadesA->second.insert(aliasB); //Meto B como amigo de A

    auto amistadesB = _amistades.find(id_B);
    amistadesB->second.insert(id_A); //Meto A como amigo de B
    auto amigosB = _amigos.find(id_B);
    string aliasA = obtener_alias(id_A);
    amistadesB->second.insert(alias_A); //Meto A como amigo de B
}

void RedSocial::desamigar_usuarios(int id_A, int id_B){
    //Sin requerimiento
    auto amigosA = _amigos.find(id_A);
    string aliasB = obtener_alias(id_B);
    amigosA->second.erase(aliasB); //Borro B de _amigos de A

    auto amigosB = _amigos.find(id_B);
    string aliasA = obtener_alias(id_A);
    amigosB->second.erase(aliasA); //Borro A de _amigos de B

    amigosA = _amistades.find(id_A);
    amigosA->second.erase(id_B); //Borro B de _amistades de A

    amigosB = _amistades.find(id_B);
    amigosB->second.erase(id_A); //Borro A de _amistades de B

}

int RedSocial::obtener_id(string alias) const{ //Prototipada
    //O(1) promedio
    return _aliases(id);
}

const set<string> & RedSocial::conocidos_del_usuario_mas_popular() const{
    //O(1)
	static set<string> basura = {"basura"};
    return basura;
}

