#ifndef __REDSOCIAL_H__
#define __REDSOCIAL_H__

#include <string>
#include <map>
#include <unordered_map>
#include <set>
using namespace std;

class RedSocial{
  public:
    RedSocial();

    const set<int> & usuarios() const; // O(1)
    string obtener_alias(int id) const; // O(log n)
    const set<string> & obtener_amigos(int id) const; // O(log n)
    const set<string> & obtener_conocidos(int id) const; // O(log n)
    int cantidad_amistades() const; // O(1)

    void registrar_usuario(string alias, int id); // O(log n) + O(1) promedio
    void eliminar_usuario(int id); // sin requerimiento
    void amigar_usuarios(int id_A, int id_B); // sin requerimiento
    void desamigar_usuarios(int id_A, int id_B); // sin requerimiento
    
    int obtener_id(string alias) const; // O(1) promedio
    const set<string> & conocidos_del_usuario_mas_popular() const; // O(1)

  private:
  struct node {
    int id;
    string alias;
    set<string> amigos;
    node* izquierdo;
    node* derecho;
  };

  set<int> _usuarios;
  set<int,int> _amistades;
  int _cantidad_amistades;
  set<string> _conocidos_mas_popular;
  node* _primero;
  
    /* completar... */
};

#endif
