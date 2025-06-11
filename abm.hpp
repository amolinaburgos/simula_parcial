#include <iostream>
#ifndef ABM_HPP
#define ABM_HPP

struct Invitado 
{
    int code;
	bool check;
    std::string nombre;
    std::string apellido;
    std::string direccion;
};
const int MAX_INVITADOS = 100;
Invitado invitados[MAX_INVITADOS];

    
    

class Abm {
public:
    int loadInvitadosFromFile(Invitado invitados[]);
    void save(Invitado invitados[], int numInvitados); 
    void find(Invitado invitados[], int numInvitados);
    void read(Invitado invitados[], int numInvitados);
    void update(Invitado invitados[], int numInvitados);
    void remove(Invitado invitados[], int& numInvitados);
    void create(Invitado invitados[], int& numInvitados);
    void showMenu();
    // Otras operaciones...
};


#endif