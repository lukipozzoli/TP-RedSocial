#include "RedSocial.h"
#include <iostream>
using namespace std;

RedSocial::RedSocial(){
    _cantidad_amistades = 0;
    _id_popular;
    _conocidos_facha = {};
}

const set<int> & RedSocial::usuarios() const{ //Cumple
    // O(1)
    return _id;
}

string RedSocial::obtener_alias(int id) const{ //Prototipada Luki
    // O(log n)
    auto busqueda = _usuarios.find(id);
    if(busqueda != _usuarios.end()){
        return busqueda->second;
    } else {
        return "No encontrado";
    }
}

const set<string> & RedSocial::obtener_amigos(int id) const {
    //O(log n)
    auto busqueda = _amigos.find(id);
    static set<string> resultado;
    resultado.clear();
    if(busqueda != _amigos.end()){
        resultado = busqueda->second;
    }
    return resultado;
}

const set<string>& RedSocial::obtener_conocidos(int id) const {
    set<string> amigos_usuario;
    amigos_usuario = obtener_amigos(id);
    
    if(amigos_usuario.size()>0){
    static set<string> resultado = amigos_usuario;

    for(auto &it : amigos_usuario){
        int id_current = obtener_id(it);
        set<string> amigos_current = obtener_amigos(id_current);
        resultado.merge(amigos_current);
    }
    for(auto &it : amigos_usuario){
        resultado.erase(it);
    }
    resultado.erase(obtener_alias(id));
    return resultado;
    
    } else {
        static set<string> resultado;
        return resultado;
    }
}

int RedSocial::cantidad_amistades() const{ //Prototipada Luki
    //O(1)
    return _cantidad_amistades;
}

void RedSocial::registrar_usuario(string alias, int id){//Luki
    //O(log n) + O(1) promedio
    if(_usuarios.size() == 0){
        _id_popular = id;
    }
    _usuarios[id] = alias;
    _id.insert(id);
    _aliases.insert(make_pair(alias,id));
}

void RedSocial::eliminar_usuario(int id){ //Prototipada Luki
    //Sin requerimiento

    int amigos_usuario;
    amigos_usuario = _amistades[id].size();
    _cantidad_amistades -= amigos_usuario;
    

    //Borrarlo de _amistades
    _amistades.erase(id);
    //Borrarlo de _amistades de otros
    for(auto &it : _amistades){
        it.second.erase(id);
    }

    //Borrarlo de _amigos
    _amigos.erase(id); 
    //Borrarlo de _amigos de otros
    for(auto &it : _amigos){
        it.second.erase(obtener_alias(id));
    }

    //Borrarlo de _aliases
    _aliases.erase(obtener_alias(id));
    //Borrarlo de _usuarios
    _usuarios.erase(id);
    //Borrarlo de id
    _id.erase(id);

    identificar_popular();

}

void RedSocial::amigar_usuarios(int id_A, int id_B){ //Prototipada Luki
    //Sin requerimiento
    _amistades[id_A].insert(id_B);
    _amigos[id_A].insert(obtener_alias(id_B));

    _amistades[id_B].insert(id_A);
    _amigos[id_B].insert(obtener_alias(id_A));

    _cantidad_amistades++;

    identificar_popular();
}

void RedSocial::desamigar_usuarios(int id_A, int id_B){//Prototipada Luki
    //Sin requerimiento
   /* auto amigosA = _amigos.find(id_A);
    string aliasB = obtener_alias(id_B);
    amigosA->second.erase(aliasB); //Borro B de _amigos de A

    auto amigosB = _amigos.find(id_B);
    string aliasA = obtener_alias(id_A);
    amigosB->second.erase(aliasA); //Borro A de _amigos de B

    amigosA = _amistades.find(id_A);
    amigosA->second.erase(id_B); //Borro B de _amistades de A

    amigosB = _amistades.find(id_B);
    amigosB->second.erase(id_A); //Borro A de _amistades de B
*/
    _amistades[id_A].erase(id_B);
    _amigos[id_A].erase(obtener_alias(id_B));

    _amistades[id_B].erase(id_A);
    _amigos[id_B].erase(obtener_alias(id_A));

    _cantidad_amistades--;

    identificar_popular();
    
}

int RedSocial::obtener_id(string alias) const{ //Luki NO CUMPLE ORDEN
    //O(1) promedio
    auto usuario = _aliases.find(alias);
    int res = usuario->second;
    return res;
}

const set<string> & RedSocial::conocidos_del_usuario_mas_popular() const{
    //O(1)
    return obtener_conocidos(_id_popular);
}

void RedSocial::identificar_popular(){
    int amistades_popular = _amistades[_id_popular].size();
    for(auto& it: _amistades){
        if(_id_popular != it.first){
            if(it.second.size() > amistades_popular){
                _id_popular = it.first;
            }
        }
    }
}