#include <iostream>
#include <fstream>
#include <sstream>
#include "abm.hpp" 


void clearConsole();
void pauseConsole();

void showMenu() 
{
    std::cout << "----- MENÚ -----" << std::endl;
    std::cout << "1. Cargar invitado" << std::endl;
    std::cout << "2. Eliminar invitado" << std::endl;
    std::cout << "3. Modificar datos de invitado" << std::endl;
    std::cout << "4. Listar todos los invitados" << std::endl;
    std::cout << "5. Buscar un invitado por código" << std::endl;
    std::cout << "6. Salir" << std::endl;
    std::cout << "Ingrese una opción: ";
}



void create(Invitado invitados[], int& numInvitado)
{  
    clearConsole();
    //verificar que no supere el máximo establecido en la constante global MAX_CUSTOMERS. 
    if (numInvitado >= MAX_INVITADOS) 
    {
        std::cout << "No se pueden agregar más invitados." <<std::endl;
        return;
    }

    //creo una variable newCustomer del tipo "struct Customer"
    //esto es la representación en memoria de un cliente.
    Invitado newInvitado;
    
    std::ifstream file("invitados.csv");
    if (file.is_open()) 
    {
        newInvitado.code = invitados[numInvitado-1].code + 1;
    }
    else
    {
       newInvitado.code = (numInvitado + 1) + 99; 
    }
    
    std::cout << "Ingrese el nombre del invitado: ";
    std::cin >> newInvitado.nombre;

    //etc...
    std::cout << "Ingrese el apellido del invitado: ";
    std::cin >> newInvitado.apellido;

    //en este caso usamos ignore() (una única vez) y getline para
    //poder persistir un string con espacios
    std::cout << "Ingrese la dirección del invitado: ";
    std::cin.ignore();
    std::getline(std::cin, newInvitado.direccion);

	//en este caso usamos ignore() (una única vez) y getline para
    //poder persistir un string con espacios
    std::cout << "Confirma asistencia\n 0 SI 1 NO: ";
    std::cin >> newInvitado.check;

    //agrego al arreglo general de clientes el nuevo cliente
    //todo esto está en memoria, todavía falta guardar en el archivo
    //con la función save()
    invitados[numInvitado] = newInvitado;
    numInvitado++;

    std::cout << "Invitado agregado correctamente." << std::endl;
    //pauseConsole();
}

void remove(Invitado invitados[], int& numInvitados) 
{
    clearConsole();
    int code;
    std::cout << "Ingrese el código del invitado a dar de baja: ";
    std::cin >> code;

    int position = -1;
    for (int i = 0; i < numInvitados; i++) 
    {
        if (invitados[i].code == code) 
        {
            position = i;
            break;
        }
    }

    if (position != -1) 
    {
        for (int i = position; i < numInvitados - 1; i++) 
        {
            invitados[i] = invitados[i + 1];
        }
        numInvitados--;
        std::cout << "Invitado eliminado correctamente." << std::endl;
    } 
    else 
    {
        std::cout << "Invitado no encontrado." << std::endl;
    }
    pauseConsole();
}

void update(Invitado invitados[], int numInvitados) 
{
    clearConsole();
    int code;
    std::cout << "Ingrese el código del invitado a modificar: ";
    std::cin >> code;

    int position = -1;
    for (int i = 0; i < numInvitados; i++) 
    {
        if (invitados[i].code == code) 
        {
            position = i;
            break;
        }
    }

    if (position != -1) 
    {
        std::cout << "Invitado encontrado:" << std::endl;
        std::cout << "Código: " << invitados[position].code << std::endl;
        std::cout << "Nombre: " << invitados[position].nombre << std::endl;
        std::cout << "Apellido: " << invitados[position].apellido << std::endl;
        std::cout << "Dirección: " << invitados[position].direccion << std::endl;
		std::cout << "Confirmo: " << invitados[position].check << std::endl;

        std::cout << "Ingrese el nuevo nombre del invitado: ";
        std::cin >> invitados[position].nombre;

        std::cout << "Ingrese el nuevo apellido del invitado: ";
        std::cin >> invitados[position].apellido;

        std::cout << "Ingrese la nueva dirección del invitado: ";
        std::cin.ignore();
        std::getline(std::cin, invitados[position].direccion);

		std::cout << "Confirma asistencia\n 0 SI 1 NO: ";
    	std::cin >> invitados[position].check;

        std::cout << "Invitado modificado correctamente." << std::endl;
    } 
    else 
    {
        std::cout << "Invitado no encontrado." << std::endl;
    }
    pauseConsole();
}

void read(Invitado invitados[], int numInvitados) 
{
    clearConsole();
    
    if (numInvitados == 0) 
    {
        std::cout << "No hay invitados cargados." << std::endl;
        return;
    }

    for (int i = 0; i < numInvitados; i++) 
    {
        std::cout << "Código: " << invitados[i].code << std::endl;
        std::cout << "Nombre: " << invitados[i].nombre << std::endl;
        std::cout << "Apellido: " << invitados[i].apellido << std::endl;
        std::cout << "Dirección: " << invitados[i].direccion << std::endl;
		std::cout << "Confirmo: " << invitados[i].check << std::endl;
        std::cout << "-------------------" << std::endl;
    }
    pauseConsole();
}

void find(Invitado invitados[], int numInvitado) 
{
    clearConsole();
    int code;
    std::cout << "Ingrese el código del invitado a buscar: ";
    std::cin >> code;

    int position = -1;
    for (int i = 0; i < numInvitado; i++) 
    {
        if (invitados[i].code == code) 
        {
            position = i;
            break;
        }
    }

    if (position != -1) 
    {
        std::cout << "Invitado encontrado:" << std::endl;
        std::cout << "Código: " << invitados[position].code << std::endl;
        std::cout << "Nombre: " << invitados[position].nombre << std::endl;
        std::cout << "Apellido: " << invitados[position].apellido << std::endl;
        std::cout << "Dirección: " << invitados[position].direccion << std::endl;
		std::cout << "Confirmo: " << invitados[position].check << std::endl;
    }
    else 
    {
        std::cout << "Invitado no encontrado." << std::endl;
    }
    pauseConsole();
}

void save(Invitado invitados[], int numInvitado) 
{
    clearConsole();
    std::ofstream file("invitados.csv");
    if (file.is_open()) 
    {
        for (int i = 0; i < numInvitado; i++) 
        {
            file << invitados[i].code << "," << invitados[i].nombre << ","
                    << invitados[i].apellido << "," << invitados[i].direccion << "," << invitados[i].check << "," << std::endl;
        }
        file.close();
        std::cout << "Invitados guardados en el archivo invitados.csv." << std::endl;
    } 
    else 
    {
        std::cout << "No se pudo abrir el archivo." << std::endl;
    }
    pauseConsole();
}

int loadInvitadosFromFile(Invitado invitados[]) 
{
    std::ifstream file("invitados.csv");
    if (file.is_open()) 
    {
        std::string linea;
        int numInvitados = 0;

        while (std::getline(file, linea)) 
        {
            //defino el flujo de cadena, para poder procesarlo después.
            std::istringstream iss(linea);
            //declaro una variable field que va a determinar cada campo
            //el campo es la intersección de la columna y la fila es el dato.
            std::string field;
             
            /*obtengo el campo "code" y lo guardo en la 
            posisción correcta del arreglo. 
            También lo "casteo" (convierto)
            de string a entero:*/
            std::getline(iss, field, ',');
            invitados[numInvitados].code = std::stoi(field);

            /*obtengo el campo "name":*/
            std::getline(iss, field, ',');
            invitados[numInvitados].nombre = field;
            
            /*obtengo el campo "surname":*/
            std::getline(iss, field, ',');
            invitados[numInvitados].apellido = field;
            
            /*obtengo el campo "address":*/
            std::getline(iss, field, ',');
            invitados[numInvitados].direccion = field;

			std::getline(iss, field, ',');
           invitados[numInvitados].check;
            //incremento la cantidad de clientes.
            numInvitados++;
        }
        file.close();
        return numInvitados;
    } 
    else 
    {
        std::cout << "No se pudo abrir el archivo." << std::endl;
        return 0;
    }
}



void pauseConsole()
{
    std::cout << "Presione una tecla para continuar..." << std::endl;
    std::cin.ignore();
    std::cin.get();
}

void clearConsole()
{
    #ifdef __unix__
        system("clear");
    #elif __APPLE__
        system("clear");
    #elif defined(_WIN32) || defined(WIN32) || defined(WIN64)
        system("cls");
    #endif // defined
}