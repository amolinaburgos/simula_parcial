#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Cliente 
{
    int id;
    string nombre;
};

const int MAXCLIENTES = 100;

Cliente clientes[MAXCLIENTES];
int cantClientes = 0;

const string ARCHIVO = "parcial.txt";

void loadData();
void saveData();
void mostrarClientes();
void deleteCliente();
void addCliente();
int idLetra();
void editarCliente();
void findCliente();
void showMenu();
void clearConsole();
void run(int opcion);


int main ()
{
    clearConsole();
    loadData();
    int opcion;
    do 
    {
        showMenu();
        cin >> opcion;
        run(opcion);
    }while(opcion != 0);
    saveData();
    return 0;

}




void loadData()
{
    ifstream archivo(ARCHIVO);
    if (!archivo.is_open())
        {
            cout << "ERROR Cargando datos de archivo" << endl;
            return;
        }

    cantClientes = 0;
    
    while (archivo >> clientes[cantClientes].id)
                    {
                        archivo.ignore();
                        getline(archivo, clientes[cantClientes].nombre);
                        
                        cantClientes++;
                        if (cantClientes >=MAXCLIENTES) break;
                    }
        archivo.close();
        cout << "Registros cargados: " << cantClientes <<endl;
}


void saveData()
{
    ofstream archivo(ARCHIVO);
    if (!archivo.is_open())
    {
        cout <<"Error al guardar datos"<<endl;
        return;
    }

    for (int i = 0; i < cantClientes; i++)
    {
        archivo << clientes[i].id << " "
                << clientes[i].nombre <<"\n";
    }
    archivo.close();
    cout<< "Datos de cliente guardados" <<endl;
}

int idLetra()
{
    int newID = 149;
    for (int i = 0; i < cantClientes; i++)
        {
            if (clientes[i].id > newID) 
            {
            newID = clientes[i].id;
            }
        }
    return "c", newID + 1;
}



void addCliente()
{
    clearConsole();
    if(cantClientes >= MAXCLIENTES)
    {
        cout << "Se alcanzo el limite de clientes" << endl;
        return;
    }

    clientes[cantClientes].id = idLetra();
    cout << "Numero de ID: " << clientes[cantClientes].id <<endl;

    cout <<"Nombre: ";
    cin.ignore();
    getline(cin, clientes[cantClientes].nombre);

    cantClientes++;
    cout << "Cliente agregado exitosamente" << endl;

    saveData();

}

void mostrarClientes()
{
    clearConsole();
    if (cantClientes == 0)
    {
        cout <<"No hay clientes registrados" << endl;
        return;
    }

    cout << "\nLISTA DE CLIENTES" << endl;
    cout << "==========================================" << endl;
    cout << "ID\t\tNombre\t" << endl;
    cout << "------------------------------------------" << endl;

    for (int i = 0; i < cantClientes; i++)
    {
        cout << "C" << clientes[i].id << "\t\t"
            << clientes[i].nombre << endl;
    }
    cout << "==========================================" << endl;
    cout << "Total clientes: " << cantClientes << endl;
    
}


void deleteCliente()
{
    if (cantClientes == 0)
    {
        cout << "No hay clientes para eliminar" <<endl;
        return;
    }

    mostrarClientes();
    int idDel;
    cout << "ID a eliminar: ";
    cin >> idDel;

    int posicion = -1;
    for (int i = 0; i < cantClientes; i++)
    {
        if(clientes[i].id == idDel)
        {
            posicion = i;
            break;
        }
    }

    if (posicion == -1) 
        {
            cout << "Cliente no encontrado" << endl;
            return;
        }

    for (int i = posicion; i < cantClientes - 1; i++) 
        {
            clientes[i] = clientes[i + 1];
        }

    cantClientes--;
    cout << "Cliente eliminado" << endl;
    saveData();

}



void showMenu() {
    
    cout << "\n==============================" << endl;
    cout << "GESTION DE CLIENTES - TP PARCIAL." << endl;
    cout << "=================================\n" << endl;
    cout << "1. ALTA CLIENTE" << endl;
    cout << "2. BAJA CLIENTE" << endl;
    cout << "3. MODIFICAR CLIENTE" << endl;
    cout << "4. LISTAR CLIENTES" << endl;
    cout << "5. BUSCAR CLIENTE" << endl;
    cout << "0. SALIR" << endl;
    cout << "Seleccione opción: ";
}




void editarCliente()
    {
        if(cantClientes == 0)
        {
            cout << "No hay clientes para modificar" <<endl;
            return;
        }
        mostrarClientes();
        int idEdit;
        cout <<"ID a modificar (increse solo el ID numerico): ";
        cin >> idEdit;
        int posicion = -1;
        for(int i = 0; i <cantClientes; i++)
        {
            if(clientes[i].id == idEdit) 
            {
                posicion = i;
                break;
            }
        }
        if (posicion == -1) 
        {
            cout << "ID no encontrado" << endl;
            return;
        }
        cout << "Nuevo nombre: " << endl;
        cin.ignore();
        getline(cin, clientes[posicion].nombre);

        cout << "Datos de cliente actualizados" << endl;
        saveData();

}

void findCliente()
{
    if (cantClientes == 0)
        {
            cout<<"No hay clientes registrados" <<endl;
            return;
        }

    int idBuscar;
    cout << "Ingrese el numero de ID que desea buscar: ";
    cin >> idBuscar;


    int posicion = -1;
    for(int i = 0; i < cantClientes; i++)
    {
        if(clientes[i].id == idBuscar)
        {
            posicion = i;
            break;
        }
    }

    

    if (posicion == -1) 
        {
            cout << "Cliente no encontrado" << endl;
            return;
        }
    cout << "Cliente encontrado: " << endl;
    cout << "Nombre: "<< clientes[posicion].nombre << endl;

}




void run(int opcion) {
    switch(opcion) {
        case 1: addCliente(); break;
        case 2: deleteCliente(); break;
        case 3: editarCliente(); break;
        case 4: mostrarClientes(); break;
        case 5: findCliente(); break;
        case 0: cout << "Saliendo del sistema..." << endl; break;
        default: cout << "Opción inválida" << endl;
    }
}




void clearConsole()
{
    // Limpia la consola según el sistema operativo
    #ifdef __unix__
        system("clear");
    #elif __APPLE__
        system("clear");
    #elif defined(_WIN32) || defined(WIN32) || defined(WIN64)
        system("cls");
    #endif // defined
}