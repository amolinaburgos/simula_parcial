#include <iostream>
#include <fstream>
#include <sstream>
#include "abm.cpp" 



using namespace std;



int main() 
{

    int numInvitados = loadInvitadosFromFile(invitados);
    std::cout << "INVITADOS CARGADOS:   " << numInvitados << std::endl;
    
    
    
    int option;
    do 
    {
        showMenu();

        std::cin >> option;

        switch (option) 
        {
            case 1:
                create(invitados, numInvitados);
                clearConsole();
                break;
            case 2:
                remove(invitados, numInvitados);
                break;
            case 3:
                update(invitados, numInvitados);
                break;
            case 4:
                read(invitados, numInvitados);
                break;
            case 5:
                find(invitados, numInvitados);
                break;
            case 6:
                save(invitados, numInvitados); // GUARDO AL SALIR!!!!
                std::cout << "Saliendo..." << std::endl;
                break;
            default:
                std::cout << "Opción inválida. Intente nuevamente." << std::endl;
                break;
        }

        std::cout << std::endl;
    } while (option != 6);

    return 0;
}
