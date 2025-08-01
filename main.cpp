//#include <windows.h>
#include <iostream>
#include <string>
#include <iomanip>

#include <sstream>
#include <fstream> // manejo de archivos
#include <cstdio> // remove y rename archivos

/* Se usan en algo?
#include <iterator>
//#include <vector>
#include <conio.h>
//#include <cstdlib>
//#include <algorithm>
*/


using namespace std;

void Administrador();
void Menu_Principal();
void Ventas();
void Altas_Prod();
void Altas_Usuarios();
void Mostrar_Inventario();
void Administrar_cuentas();
void Mostrar_Cuentas();
void consultar();
void baja_producto();
void baja_usuarios();
void Modificar_producto();
void consultar_usuario();
void Modificar_usuario();
//
bool validar_credenciales(int tipo_usuario);
void Ordenar_productos(int tipo);
void Menu_Inventario();


int MPrincipal, MAdministrador;
string nombre, contrasena;
// bool accesoConcedido = false; // se reemplazo por la funcion: validar_credenciales


struct Usuario
{
  string NUsuario;
  string NContra;
  int Tipo;
  int Status;
};
int totalUsuarios=3;
Usuario usuarios[100] = {
  {"admin","123",1,1},
  {"vend1","123",2,1},
  {"vend2","123",2,1}
};
struct Productos
{
  string id;
  string NProducto;
  float PrecioC;
  float PrecioV;
  int Existencias;
  int NivelReor;
  int ProdStatus;
};
int totalProductos = 5;
Productos productos [100] // en plural es mas explicito que es una lista / array
{
  {"1","agua", 13.39, 18.55, 12, 4, 1},
  {"2","leche", 12.35, 15.50, 16, 5, 1},
  {"3","huevos", 22.40, 30.39, 20, 7, 1},
  {"4","pan", 5.50, 7.95, 18, 6, 1},
  {"5","refresco", 10.99, 14.75, 30, 8, 1}
};


int main (){
    do{
        Menu_Principal();
    } while (MPrincipal != 3);  
    return 0;
}

bool validar_credenciales(int tipo_usuario){
    cout<<"Ingrese usuario: ";
    cin>>nombre;
    cout<<"Ingrese contraseña: ";
    cin>>contrasena;
    for (int i = 0; i < totalUsuarios; ++i){
        if (usuarios[i].NUsuario==nombre && usuarios[i].NContra==contrasena && usuarios[i].Tipo == tipo_usuario && usuarios[i].Status == 1){
            return true;
        }
    }
    return false;
}


void Menu_Principal (){
    cout<<"\n1. Administrador \n";
    cout<<"2. Ventas \n";
    cout<<"3. Salir \n";
    cout<<"Opcion: ";
    cin>> MPrincipal;
    switch (MPrincipal){
        case 1:
            if (validar_credenciales(1)){
                Administrador();
            } else {
                cout << "\nUsuario o contraseña incorrectos. \n" << endl;
            }
            break;
        case 2:
            if (validar_credenciales(2)){
                Ventas();
            } else {
                cout << "\nUsuario o contraseña incorrectos. \n" << endl;
            }
            break;
        case 3:
            break;
        default:
            cout<< "\nOpcion no valida \n";
        break;
    }
}
void Administrador (){
    do{
        cout<<"\nBienvenido al Menu de administrador \n";
        cout<<"1. Altas \n";
        cout<<"2. Bajas \n";
        cout<<"3. Consultas \n";
        cout<<"4. Modificaciones \n";
        cout<<"5. Mostrar inventario \n";
        cout<<"6. Administracion de cuentas de usuarios \n";
        cout<<"7. Corte caja general \n";
        cout<<"8. Regresar al menu anterior \n";
        cout<<"Opcion: ";
        cin>>MAdministrador;
        switch (MAdministrador){
            case 1:
                Altas_Prod();
                break;
            case 2:
                baja_producto();
                break;
            case 3:
                consultar();
                break;
            case 4:
                Modificar_producto();
                break;
            case 5:
                Menu_Inventario();
                break;
            case 6:
                Administrar_cuentas();
                break;
            case 7:
                // TODO: Crear funcion de corte de caja
                break;
            case 8:
                // Menu_Principal();
                break;
            default:
                cout<<"Opcion incorrecta. Intente de nuevo"<<endl;
                break;
        }
    } while (MAdministrador != 8);
}


void Ventas(){
   // TODO: Crear funcion de Ventas
   cout << "Deberia mostar ventana ventas...\n";
}

void Menu_Inventario(){
    int opcion;
    do{
        cout<<"\nOrdenado por:\n";
        cout<<"1. Por Id\n";
        cout<<"2. Por nombre\n";
        cout<<"3. Regresar al menu anterior\n";
        cout<<"Opcion: ";
        cin>>opcion;
    
        switch(opcion){
            case 1:
                Ordenar_productos(1);
                Mostrar_Inventario();
                break;
            case 2:
                Ordenar_productos(2);
                Mostrar_Inventario();
                break;
            case 3:
                Ordenar_productos(1); // se ordena por id para futuros recorridos de la lista de estructuras.
                break;
            default:
                cout<<"\nOpcion incorrecta\n";
    
        }
    }while(opcion != 3);
}

void Ordenar_productos(int tipo){
    Productos temp;
    // bubble sort por id
    if(tipo==1){
        for (int i = 0; i < totalProductos - 1; i++) {
            for (int j = 0; j < totalProductos - i - 1; j++) {
                if (productos[j].id > productos[j + 1].id) {
                    temp = productos[j];
                    productos[j] = productos[j + 1];
                    productos[j + 1] = temp;
                }
            }
        }
    }
    // bubble sort por nombre
    if(tipo==2){
        for (int i = 0; i < totalProductos - 1; i++) {
            for (int j = 0; j < totalProductos - i - 1; j++) {
                if (productos[j].NProducto > productos[j + 1].NProducto) {
                    temp = productos[j];
                    productos[j] = productos[j + 1];
                    productos[j + 1] = temp;
                }
            }
        }
    }
}

void Mostrar_Inventario(){
    char resurtir;
    cout<<left<<setw(10)<<"ID"<<setw(15)<<"Producto"<<setw(10)<<"PC"<<setw(10)<<"PV"<<setw(20)<<"Existencias"<<setw(10)<<"NR"<<setw(5)<<"Resurtir"<<endl;
    for (int i = 0; i < totalProductos; i++){
        if (productos[i].Existencias <= productos[i].NivelReor){
            resurtir = '*';
        } else{
            resurtir = ' ';
        }
        if (productos[i].ProdStatus != 0){  
            cout<<setw(10)<<productos[i].id
                <<setw(15)<<productos[i].NProducto
                <<setw(10)<<productos[i].PrecioC
                <<setw(10)<<productos[i].PrecioV
                <<setw(20)<<productos[i].Existencias
                <<setw(10)<<productos[i].NivelReor
                <<setw(5)<< resurtir << endl;
        }
    }
}


void Administrar_cuentas(){
    int opcion;
    do {
        cout<<"\nBienvenido al administrador de cuentas \n";
        cout<<"1. Altas \n";
        cout<<"2. Bajas \n";
        cout<<"3. Consultas \n";
        cout<<"4. Modificaciones \n";
        cout<<"5. Mostrar cuentas de usuario \n";
        cout<<"6. Regresar al menu anterior \n";
        cout<<"Opcion: ";
        cin>>opcion;
        switch (opcion){
            case 1:
                Altas_Usuarios();
                break;
            case 2:
                baja_usuarios();
                break;
            case 3:
                consultar_usuario();
                break;
            case 4:
                Modificar_usuario();
                break;
            case 5:
                Mostrar_Cuentas();
                break;
            case 6:
                break;
            default:
                cout<< "Opcion no valida \n";
                break;
        }
    } while (opcion != 6);
}

void Altas_Prod (){
    do {
        bool producto_nuevo = true;
        string prod_temp;
        // int i = totalProductos; // no es necesario crear una nueva variable, se puede usar la de totalProductos;
        cout<<"Producto: ";
        cin>>prod_temp;
        if (prod_temp == "*" ){
            // Administrador();
            break;
        }  

        for (int j = 0; j < totalProductos; j++){
            if (productos[j].NProducto == prod_temp && productos[j].ProdStatus == 1){
                cout<<"\nEl producto ya existe. Intenta de nuevo\n";
                // Altas_Prod ();
                producto_nuevo = false;
                break; // con 'break' nos salimos del for y se inicia de nuevo el ciclo do while. No es necesario volver a mandar a la funcion Altar_Prod().
            }  
            if (productos[j].NProducto == prod_temp && productos[j].ProdStatus == 0){
                productos[j].ProdStatus = 1;
                cout<<"\nProducto vuelto a dar de alta \n";
                // Altas_Prod ();
                producto_nuevo = false;
                break;
            }
        }

        if(producto_nuevo){
            float pc, pv;
            int existencias, nivel_reorden;

            productos[totalProductos].NProducto = prod_temp;
            cout<<"ID: ";
            cin>>productos[totalProductos].id;
            do{
                cout<<"Precio compra: ";
                cin>>pc;
                cout<<"Precio venta: ";
                cin>>pv;
                if(pv <= pc){
                    cout << "Precio de venta no valido. Favor de ingresar de nuevo.\n";
                }
            }while(pv <= pc);
            productos[totalProductos].PrecioC = pc;
            productos[totalProductos].PrecioV = pv;

            do{
                cout<<"Existencias: ";
                cin>>existencias;
                cout<<"Nivel de reorden: ";
                cin>>nivel_reorden;
                if(existencias <= nivel_reorden){
                    cout<<"Existencias menores al nivel de reorden. Favor de intentar de nuevo.\n";
                }
            }while(existencias <= nivel_reorden);
            productos[totalProductos].Existencias = existencias;
            productos[totalProductos].NivelReor = nivel_reorden;

            productos[totalProductos].ProdStatus = 1;
            totalProductos++;
            Mostrar_Inventario();
        }
    } while (true);
}


void Modificar_producto(){
    do{
        int indice, opcion;
        bool producto_encontrado = false;
        string prod_temp;
        cout<<"\nProducto a modificar: ";
        cin>>prod_temp;
        if (prod_temp == "*" ){
            // Administrador();
            break;
        }

        for (int j = 0; j < totalProductos; j++){
            if (productos[j].NProducto == prod_temp && productos[j].ProdStatus == 1){
                indice = j;
                producto_encontrado = true;
                break;
            }  
        }

        if(producto_encontrado){
            do{
                cout<<"\nProducto: "<<prod_temp<<endl;
                cout<<"\n1. Precio de compra\n";
                cout<<"2. Precio de Venta\n";
                cout<<"3. Existencias\n";
                cout<<"4. Nivel de reorden\n";
                cout<<"5. Regresar al menu anterior\n";
                cout<<"Opcion: ";
                cin>>opcion;
                
                switch (opcion){
                    case 1:
                        cout<<"\nNuevo Precio compra: ";
                        cin>>productos[indice].PrecioC;
                        cout<<"\nPrecio de compra actualizado\n";
                        break;
                    case 2:
                        cout<<"\nNuevo Precio venta: ";
                        cin>>productos[indice].PrecioV;
                        cout<<"\nPrecio de venta actualizado\n";
                        break;
                    case 3:
                        cout<<"\nNuevo Existencias: ";
                        cin>>productos[indice].Existencias;
                        cout<<"\nExistencias actualizadas\n";
                        break;
                    case 4:
                        cout<<"\nNuevo Nivel de reorden: ";
                        cin>>productos[indice].NivelReor;
                        cout<<"\nNivel de reorden actualizado\n";
                        break;
                    case 5:
                        break; // se regresa al menu anterior
                    default:
                        cout<<"\nOpcion incorrecta.\n";
                        break;
                }
            }while(opcion != 5);
        }else{
            cout<<"\nNo se encontro el producto. Intenta de nuevo.\n";
        }
    }while (true);
}


void Modificar_usuario(){
    do{
        bool usuario_encontrado = false;
        string usu;
        cout<<"Usuario a modificar: ";
        cin>>usu;
        if (usu == "*" ){
            break;
        }

        for (int j = 0; j < totalUsuarios; j++){
            if (usuarios[j].NUsuario == usu && usuarios[j].Status == 1){
                // TODO: Agregar menu?
                cout<<"Nuevo Usuario: ";
                cin>>usuarios[j].NUsuario;
                cout<<"Nueva contraseña: ";
                cin>>usuarios[j].NContra;
                cout<<"Nueva Tipo: ";
                cin>>usuarios[j].Tipo;
                cout<<"\nSe modifico el usuario con exito."<<endl;
                usuario_encontrado = true;
                break;
            }
        }

        if(!usuario_encontrado){
            cout<<"No se encontro el usuario. Intenta de nuevo"<<endl;
        }
    } while (true);
}


void Altas_Usuarios(){
    do {
        bool usuario_nuevo = true;
        string usua;
        cout<<"\nUsuario: ";
        cin>>usua;
        if (usua == "*" ){
            break;
        }  

        for (int j = 0; j < totalUsuarios; j++){
            if (usuarios[j].NUsuario == usua && usuarios[j].Status == 1){
                cout<<"\nEl usuario ya existe. Intenta de nuevo\n";
                usuario_nuevo = false;
                break;
            }  
            
            if (usuarios[j].NUsuario == usua && usuarios[j].Status == 0){
                usuarios[j].Status = 1;
                cout<<"\nUsuario vuelto a dar de alta \n";
                usuario_nuevo = false;
                break;
            }
        }

        if(usuario_nuevo){
            usuarios[totalUsuarios].NUsuario = usua;
            cout<<"Contraseña: ";
            cin>>usuarios[totalUsuarios].NContra;
            cout<<"Tipo: ";
            cin>>usuarios[totalUsuarios].Tipo;
            usuarios[totalUsuarios].Status = 1;
            totalUsuarios++;
            Mostrar_Cuentas();
        }
    } while (true);
}


void Mostrar_Cuentas(){
    cout<<setw(10)<<"Usuario"<<setw(15)<<"Contraseña"<<setw(10)<<"Tipo"<<setw(10)<<"Status"<<endl;
    for (int i = 0; i < totalUsuarios; i++){
        if (usuarios[i].Status != 0){
            cout<<setw(10)<<usuarios[i].NUsuario<<setw(15)<<usuarios[i].NContra<<setw(10)<<usuarios[i].Tipo<<setw(10)<<usuarios[i].Status<<endl;
        }
    }
}


void consultar(){
    string prod_temp;
    do{
        bool producto_encontrado = false;
        cout<<"Nombre de producto a consultar: ";
        cin>>prod_temp;
        if (prod_temp == "*"){
            break;
        }

        char resurtir;
        for (int i = 0; i < totalProductos; i++){
            if (productos[i].NProducto == prod_temp && productos[i].ProdStatus == 1){
                cout<<setw(10)<<"ID"<<setw(15)<<"Producto"<<setw(10)<<"PC"<<setw(10)<<"PV"<<setw(20)<<"Existencias"<<setw(10)<<"NR"<<setw(5)<<"Resurtir"<<endl;
                if (productos[i].Existencias <= productos[i].NivelReor){
                    resurtir = '*';
                } else{
                    resurtir = ' ';
                }
                cout<<setw(10)<<productos[i].id
                    <<setw(15)<<productos[i].NProducto
                    <<setw(10)<<productos[i].PrecioC
                    <<setw(10)<<productos[i].PrecioV
                    <<setw(20)<<productos[i].Existencias
                    <<setw(10)<<productos[i].NivelReor
                    <<setw(5)<< resurtir << endl;
                producto_encontrado = true;
                break;
            } 
        }

        if (!producto_encontrado){
            cout << "Poducto no encontrado. Favor de ingresar de nuevo.\n";
        }
    } while (true);
}


void consultar_usuario(){
    int i = 0;
    string usu;
    do{
        bool usuario_encontrado = false;
        cout<<"Usuario: ";
        cin>>usu;
        if (usu == "*"){
            break;
        }

        for (int i = 0; i < totalUsuarios; i++){
            if (usuarios[i].NUsuario == usu && usuarios[i].Status == 1){
                cout<<setw(10)<<"Usuario"<<setw(15)<<"Contraseña"<<setw(10)<<"Tipo"<<setw(10)<<"Status"<<endl;
                cout<<setw(10)<<usuarios[i].NUsuario<<setw(15)<<usuarios[i].NContra<<setw(10)<<usuarios[i].Tipo<<setw(10)<<usuarios[i].Status<<endl;
                usuario_encontrado = true;
                break;
            }
        }

        if(!usuario_encontrado){
            cout<<"No se encontro el usuario"<<endl;
        }
    } while (true);
}


void baja_producto(){
    do{
        string Prod;
        bool producto_encontrado = false;
        cout<<"Producto: ";
        cin>>Prod;
        if(Prod == "*" ){
            // Administrador(); // no se debe mandar a la funcion que esta llamando
            break;
        }    
        for (int i = 0; i < totalProductos; i++){
            if (productos[i].NProducto == Prod && productos[i].ProdStatus == 1){
                productos[i].ProdStatus = 0;
                cout<<"\nProducto dado de baja con exito \n";
                // baja_producto();
                producto_encontrado = true;
                break; // con el break es suficiente porque tienes un do while. El break rompe el for y regresa al while.
            }  
            if (productos[i].NProducto == Prod && productos[i].ProdStatus == 0){
                cout<<"Producto ya dado de baja \n";
                // baja_producto();
                producto_encontrado = true;
                break;
            }
        }
        if(!producto_encontrado){
            cout << "\nNo se encontro el producto. Intenta de nuevo.\n";
        }
    }while (true);
}


void baja_usuarios(){
    do{
        string usu;
        bool usuario_encontrado = false;
        cout<<"Usuario: ";
        cin>>usu;
        if (usu == "*" ){
            break;
        }    
        
        for (int i = 0; i < totalUsuarios; i++){
            if (usuarios[i].NUsuario == usu && usuarios[i].Status == 1){
                usuarios[i].Status = 0;
                cout<<"Usuario dado de baja con exito \n";
                usuario_encontrado = true;
                break;
            } 
        }
        if(!usuario_encontrado){
            cout<<"Usuario no encontrado"<<endl;
        }
    }while (true);
}
