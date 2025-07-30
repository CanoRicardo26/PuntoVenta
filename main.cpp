//#include <windows.h>
#include <iostream>
#include <iterator>
#include <string>
//#include <vector>
#include <iomanip>
#include <conio.h>
//#include <cstdlib>
//#include <algorithm>

using namespace std;

void Administrador ();
void Menu_Principal ();
void Ventas ();
void Altas_Prod ();
void Altas_Usuarios ();
void Mostrar_Inventario ();
void Administrar_cuentas ();
void Mostrar_Cuentas ();
void Mostrar_Cuentas ();
void consultar();
void baja_producto();
void baja_usuarios();
void Modificar_producto();
void consultar_usuario();
void Modificar_usuario();
int MPrincipal, MAdministrador,AdmiCuent;
string nombre, Contrasena;
bool accesoConcedido = false;
struct Usuario
{
  string NUsuario;
  string NContra;
  int Tipo;
  int Status;
};
int totalUsuarios=3;
Usuario Usuarios[100] = {
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
Productos producto [100]
{
  {"1","agua", 13.39, 18.55, 12, 4, 1},
  {"2","leche", 12.35, 15.50, 16, 5, 1},
  {"3","huevos", 22.40, 30.39, 20, 7, 1},
  {"4","pan", 5.50, 7.95, 18, 6, 1},
  {"5","refresco", 10.99, 14.75, 30, 8, 1}
};
void Menu_Principal ()
{
  cout<<"1. Administrador \n";
  cout<<"2. Ventas \n";
  cout<<"3. Salir \n";
  cin>> MPrincipal;
  switch (MPrincipal)
  {
   case 1:
   cout<<"ingrese usuario \n";
   cin>> nombre;
   cout<<"ingrese contraseña \n";
   cin>> Contrasena;
   for (int i = 0; i < totalUsuarios; ++i) 
   {
   if (Usuarios[i].NUsuario==nombre && Usuarios[i].NContra==Contrasena && Usuarios[i].Tipo == 1 && Usuarios[i].Status == 1)
   {
     accesoConcedido = true;
     Administrador();
      break;
     }
   }
   break;
   case 2:
   cout<<"ingrese usuario \n";
  cin>> nombre;
  cout<<"ingrese contraseña \n";
  cin>> Contrasena;
  for (int i = 0; i < totalUsuarios; ++i) 
  {
  if (Usuarios[i].NUsuario==nombre && Usuarios[i].NContra==Contrasena && Usuarios[i].Tipo == 2 && Usuarios[i].Status == 1)
  {
    accesoConcedido = true;
    Ventas();
     break;
    }
  }
   break;
   case 3:
   break;
   default:
   cout<< "Opcion no valida \n";
   break;
 }
}
void Administrador ()
{
 
    if (accesoConcedido) {
      do
      {
      cout<<"Bienvenido al Menu de administrador \n";
      cout<<"1. Altas \n";
      cout<<"2. Bajas \n";
      cout<<"3. Consultas \n";
      cout<<"4. Modificaciones \n";
      cout<<"5. Mostrar inventario \n";
      cout<<"6. Administracion de cuentas de usuarios \n";
      cout<<"7. Corte caja general \n";
      cout<<"8. Regresar al menu anterior \n";
      cin>>MAdministrador;
      switch (MAdministrador)
      {
      case 1:
      Altas_Prod ();
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
      Mostrar_Inventario ();
      break;
      case 6:
      Administrar_cuentas ();
      break;
      case 7:
      
      break;
      case 8:
      Menu_Principal();
      break;
      default:
        break;
      }
      } while (MAdministrador != 8);
  } else {
      cout << "Usuario o contraseña incorrectos. \n" << endl;
      Menu_Principal();
  }
  
}
void Ventas () 
{
  
  if (accesoConcedido) {
    cout<<"1. Altas \n";
} else {
    cout << "Usuario o contraseña incorrectos." << endl;
    Menu_Principal();
}
}
void Mostrar_Inventario ()
{
  
cout<<setw(10)<<"ID"<<setw(15)<<"Producto"<<setw(10)<<"PC"<<setw(10)<<"PV"<<setw(20)<<"Existencias"<<setw(10)<<"NR"<<endl;
  for (int i = 0; i < totalProductos; i++)
  if (producto[i].ProdStatus != 0)
  {  
  cout<<setw(10)<<producto[i].id<<setw(15)<<producto[i].NProducto<<setw(10)<<producto[i].PrecioC<<setw(10)<<producto[i].PrecioV<<setw(20)<<producto[i].Existencias<<setw(10)<<producto[i].NivelReor<<endl;
  }
}
void Administrar_cuentas ()
{
  do
  {
  cout<<"Bienvenido al administrador de cuentas \n";
  cout<<"1. Altas \n";
  cout<<"2. Bajas \n";
  cout<<"3. Consultas \n";
  cout<<"4. Modificaciones \n";
  cout<<"5. Mostrar cuentas de usuario \n";
  cout<<"6. Regresar al menu anterior \n";
  cin>>AdmiCuent;
  switch (AdmiCuent)
  {
    case 1:
    Altas_Usuarios ();
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
    Mostrar_Cuentas ();
    break;
    case 6:
    Administrador ();
    break;
  default:
  cout<< "Opcion no valida \n";
    break;
  }
} while (AdmiCuent != 6);
}

void Altas_Prod (){
  int j = 0;
      do
  {
    string prod_temp;
    int i = totalProductos;
    cout<<"Producto: ";
    cin>>prod_temp;
    if (prod_temp == "*" )
    {
      Administrador();
    }  
    for (j; j < totalProductos; j++)
    {
      if (producto[j].NProducto == prod_temp && producto[j].ProdStatus == 1)
      {
        cout<<"Producto existente \n";
        Altas_Prod ();
      }  
      if (producto[j].NProducto == prod_temp && producto[j].ProdStatus == 0)
      {
        producto[j].ProdStatus = 1;
        cout<<"Producto vuelto a dar de alta \n";
        Altas_Prod ();
      }
      }
    producto[i].NProducto = prod_temp;
    cout<<"ID: ";
    cin>>producto[i].id;
    cout<<"Precio compra: ";
    cin>>producto[i].PrecioC;
    cout<<"Precio venta: ";
    cin>>producto[i].PrecioV;
    cout<<"Existencias: ";
    if(producto[i].PrecioC >= producto[i].PrecioV){
        cout << "Precio de venta no valido. Favor de ingresar de nuevo.\n";
            break;
    }
    cin>>producto[i].Existencias;
    cout<<"Nivel de reorden: ";
    cin>>producto[i].NivelReor;
    if (producto[i].Existencias <= producto[i].NivelReor)
    {
      cout<<"Existencias menores al nivel de reorden. Favor de intentar de nuevo.\n";
        break;
    }
    producto[i].ProdStatus = 1;
    totalProductos++;
    Mostrar_Inventario();
  } while (true);
    }
void Modificar_producto()
{
    int j = 0;
        do
    {
      int i = totalProductos;
      string prod_temp;
      cout<<"Producto a modificar: ";
      cin>>prod_temp;
      if (prod_temp == "*" )
      {
        Administrador();
      }  
      for (j; j < totalProductos; j++)
      {
        if (producto[j].NProducto == prod_temp && producto[j].ProdStatus == 1)
        {
          producto[i].NProducto = prod_temp;
          cout<<"Nuevo ID: ";
          cin>>producto[i].id;
          cout<<"Nuevo Precio compra: ";
          cin>>producto[i].PrecioC;
          cout<<"Nuevo Precio venta: ";
          cin>>producto[i].PrecioV;
          cout<<"Nuevo Existencias: ";
          cin>>producto[i].Existencias;
          cout<<"Nuevo Nivel de reorden: ";
          cin>>producto[i].NivelReor;
          if (producto[i].PrecioC >= producto[i].PrecioV || producto[i].Existencias <= producto[i].NivelReor)
          {
            cout<<"No cumple requisitos \n";
            Modificar_producto();
          }
        }  
        if (producto[i].NProducto == prod_temp && producto[i].ProdStatus == 0)
        {
          cout<<"Producto no disponible, dado de baja \n";
          Modificar_producto();
        }
        }
    } while (true);
}
void Modificar_usuario()
{
    int j = 0;
        do
    {
      string usu;
      cout<<"Usuario a modificar: ";
      cin>>usu;
      if (usu == "*" )
      {
        Administrar_cuentas();
      }  
      for (j; j < totalUsuarios; j++)
      {
        if (Usuarios[j].NUsuario == usu && Usuarios[j].Status == 1)
        {
          cout<<"Nuevo Usuario: ";
          cin>>Usuarios[j].NUsuario;
          cout<<"Nueva contraseña: ";
          cin>>Usuarios[j].NContra;
        }  
        if (Usuarios[j].NUsuario == usu && Usuarios[j].Status == 0)
        {
          cout<<"Usuario no disponible, dado de baja \n";
          Modificar_usuario();
        }
        }
    } while (true);
}
void Altas_Usuarios ()
{
  int j = 0;
      do
  {
    string usua;
    int i = totalUsuarios;
    cout<<"Usuario: ";
    cin>>usua;
    if (usua == "*" )
    {
      Administrar_cuentas();
    }  
    for (j; j < totalUsuarios; j++)
    {
      if (Usuarios[j].NUsuario == usua && Usuarios[j].Status == 1)
      {
        cout<<"Usuario existente \n";
        Altas_Usuarios ();
      }  
      if (Usuarios[j].NUsuario == usua && Usuarios[j].Status == 0)
      {
        Usuarios[j].Status = 1;
        cout<<"Usuario vuelto a dar de alta \n";
        Altas_Usuarios ();
      }
      }
    Usuarios[i].NUsuario = usua;
    cout<<"Contraseña: ";
    cin>>Usuarios[i].NContra;
    Usuarios[j].Tipo = 2;
    Usuarios[j].Status = 1;
    totalUsuarios++;
    Mostrar_Cuentas();
  } while (true);
    }
void Mostrar_Cuentas ()
{
  cout<<setw(10)<<"Usuario"<<setw(15)<<"Contraseña"<<setw(10)<<"Tipo"<<setw(10)<<"Status"<<endl;
  for (int i = 0; i < totalUsuarios; i++)
  if (Usuarios[i].Status != 0)
  {
    cout<<setw(10)<<Usuarios[i].NUsuario<<setw(15)<<Usuarios[i].NContra<<setw(10)<<Usuarios[i].Tipo<<setw(10)<<Usuarios[i].Status<<endl;
  }
}
void consultar()
{
int i = 0;
string prod_temp;
do
{
  cout<<"Nombre de producto a consultar: ";
  cin>>prod_temp;
  if (prod_temp == "*")
    {
      break;
    } 
  for (int i = 0; i < totalProductos; i++)
  {
    if (producto[i].NProducto == prod_temp && producto[i].ProdStatus == 1)
    {
      cout<<setw(10)<<"ID"<<setw(15)<<"Producto"<<setw(10)<<"PC"<<setw(10)<<"PV"<<setw(20)<<"Existencias"<<setw(10)<<"NR"<<endl;
      cout<<setw(10)<<producto[i].id<<setw(15)<<producto[i].NProducto<<setw(10)<<producto[i].PrecioC<<setw(10)<<producto[i].PrecioV<<setw(20)<<producto[i].Existencias<<setw(10)<<producto[i].NivelReor<<endl;
    } 
    if (producto[i].NProducto == prod_temp && producto[i].ProdStatus == 0)
    {
      cout<<"Producto dado de baja previamente \n";
    }
    if (producto[i].NProducto != prod_temp){
        cout << "Poducto no existente. Favor de ingresar de nuevo.\n";
    }
}
} while (true);
}
void consultar_usuario()
{
int i = 0;
string usu;
do
{
  cout<<"Usuario: ";
  cin>>usu;
  if (usu == "*")
    {
      break;
    } 
  for (int i = 0; i < totalUsuarios; i++)
  {
    if (Usuarios[i].NUsuario == usu && Usuarios[i].Status == 1)
    {
      cout<<setw(10)<<"Usuario"<<setw(15)<<"Contraseña"<<setw(10)<<"Tipo"<<setw(10)<<"Status"<<endl;
      cout<<setw(10)<<Usuarios[i].NUsuario<<setw(15)<<Usuarios[i].NContra<<setw(10)<<Usuarios[i].Tipo<<setw(10)<<Usuarios[i].Status<<endl;
    } 
    if (Usuarios[i].NUsuario == usu && Usuarios[i].Status == 0)
    {
      cout<<"Usuario dado de baja previamente \n";
    }
}
} while (true);
}
void baja_producto()
{
  do
{
string Prod;
cout<<"Producto: ";
cin>>Prod;
if (Prod == "*" )
{
  Administrador ();
}    
for (int i = 0; i < totalProductos; i++)
{
  if (producto[i].NProducto == Prod && producto[i].ProdStatus == 1)
  {
    producto[i].ProdStatus = 0;
    cout<<"Producto dado de baja con exito \n";
    baja_producto();
  }  
  if (producto[i].NProducto == Prod && producto[i].ProdStatus == 0)
  {
    cout<<"Producto ya dado de baja \n";
    baja_producto();
  }
}
}while (true);
}
void baja_usuarios()
{
  do
{
string usu;
cout<<"Usuario: ";
cin>>usu;
if (usu == "*" )
{
  Administrar_cuentas();
}    
for (int i = 0; i < totalUsuarios; i++)
{
  if (Usuarios[i].NUsuario == usu && Usuarios[i].Status == 1)
  {
    Usuarios[i].Status = 0;
    cout<<"Usuario dado de baja con exito \n";
    baja_usuarios ();
  }  
  if (Usuarios[i].NUsuario == usu && Usuarios[i].Status == 0)
  {
    cout<<"Usuario previamente dado de baja\n";
    baja_usuarios ();
  }
}
}while (true);
}
int main ()
{
do
{
  Menu_Principal();
} while (MPrincipal != 3);    
  return 0;
}