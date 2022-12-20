#include <iostream>
#include <fstream>
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <iomanip>
#include <sstream>
#include <string>
#include <math.h>
using namespace std;

string today()//Fecha de del sistema
{
    auto t = time(nullptr);
    auto tm = *localtime(&t);

    ostringstream oss;
    oss <<  put_time(&tm, "%d-%m-%Y");
    auto str = oss.str();
    return str;
  }

void aux(int sub){

  switch (sub) {
    case 1: cout << "\n\n\t --Bienvenido a tu NOTEPAD-- (ver 0.2)\n\n\n\n\n\t\t  by Zent || ESIME Cul\n\n\n\n\n\tConsulta manuales y actualizaciones en\n\thttps://github.com/Zentyon/Final_Proyect";
          break;
  }
  Sleep(2500);
  system("CLS");
}

class heart //Clase Raíz
{
  protected:
    string actual;
  public:
    int size = 0;
    heart(){size = load_setup();}
    ~heart(){}
    int load_setup() //Carga el valor del setup como int
    {
      string str;
      int num = 0, size = str.size();
      ifstream base;
      base.open("setup.txt", ios :: in);
        getline(base, str);
        for(int i = 0; i < str.size(); i++) {
        num *= 10;
        num += str[i]-'0';
      }
      base.close();
      return num;}

    void save_setup(int input) //Guarda el valor del setup como string
    {
        string str;
        int num = load_setup();
        ofstream save;
          stringstream s;
          save.open("setup.txt", ios::out);
          num = num + input;
          s << num;
          str = s.str();
          save << str;
        save.close();}

    string current()  //Carga el valor del setup como string
    {
      ifstream add;
      add.open("setup.txt", ios :: in);
      getline(add,actual);
      add.close();
      return actual;}
};

class notepad : public heart //Clase Heredada
{
protected:
  string day, month, year;
  string aviso = "This is a Test";
	string title;
	string texto;
	string linea;
  string nombre;
public:
  void save();
  void read(int);
  void delit(int);
  void popup();
  void name(int);

};

 void notepad :: save(){
    fflush(stdin);
    save_setup(1);
    nombre = current() + ".txt";
    ofstream nota;
    nota.open(nombre.c_str(), ios::out); //abre el archivo

    cout << "\t\t--NUEVA NOTA--\n(Introduce los datos y presiona ENTER para confirmar)\n" << endl;
    cout << "Titulo: ";
      getline(cin, title); nota << title	<< '\n';
    cout << "\n(Formato de fecha: dd-mm-aaaa)" << endl;
    cout << "Day: ";
      getline(cin, day);		nota << day	<< '\n';
    cout << "Month: ";
      getline(cin, month);	nota << month << '\n';
    cout << "Year: ";
      getline(cin, year);	nota << year << '\n';
    cout << "Descripcion: ";
      getline(cin, texto);	nota << texto << '\n';

    nota.close(); //cierra el archivo

    system("CLS");
 }
 // Guarda una nota nueva

 void notepad :: read(int c){
  fflush(stdin);
  system("CLS");
  stringstream s;
  s << c;
  string str =  s.str() + ".txt";
  ifstream nota;
  nota.open(str.c_str(), ios :: in);

  if(nota.fail()){
    cout << "no se pudo leer el archivo\n";
  }

  else{
    getline(nota, title); cout << title << endl;
    getline(nota, day); cout << day << "/";
    getline(nota , month); cout << month  << "/";
    getline(nota, year); cout << year << endl;
    while (getline(nota,linea)) {
      texto = texto + linea + '\n';
    }
    cout << texto << endl;
  }
  nota.close();

  cout << "Presiona ENTER para continuar" << '\n';
  getch ();
  system("CLS");
}
//lee e imprime una nota

 void notepad :: delit(int c){
   stringstream s;
   s << c;
   string str =  s.str() + ".txt";
   remove(str.c_str());
   save_setup(-1);
   system("CLS");
}
// Borra una nota

 void notepad :: popup(){

   for (int i = 0; i < size+1 ; i++) {
   string fecha;
   stringstream s;
   s << i;
   string str =  s.str() + ".txt";

   ifstream nota;
   nota.open(str.c_str(), ios :: in);
    getline(nota, aviso);
     getline(nota, day);
      fecha = day + "-";
     getline(nota , month);
      fecha = fecha + month  + "-";
     getline(nota, year);
      fecha = fecha + year;

   if( fecha == today()){
     // https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-messagebox
     int msgboxID = MessageBox(
            NULL,
            aviso.c_str(),
            "Nota pendiente: ",
            MB_ICONASTERISK
        );
      }
     nota.close();
    }
 }
 // Notificación en pantalla

 void notepad :: name(int temp){
  stringstream s;
  s << temp;
  ifstream nota;
  string str =  s.str() + ".txt";
  nota.open(str.c_str(), ios :: in);
  getline(nota,nombre);
  nota.close();
  cout << nombre;
}
// Función auxiliar para lectura de notas


int main(){
  system("color F0");

  aux(1);
  int n_obj = 0;
  int option = 1;
  int submenu = 0;
  cout << "\n\t\tWellcome!\n" << endl;
  cout << "\tToday is: "<< today() << endl;

do {
  heart user; //inicializa setup
  notepad *notas;
  notas = new notepad[1000];


    cout << "\n\tQue deseas hacer?\n\t\t1- Agregar nueva nota \n\t\t2- Ver notas guardadas\n\t\t3- Eliminar nota\n\t\t0- Salir\n\n\t\tTeclea el numero de la opcion y presiona ENTER: ";
    notas -> popup();
    cin >> option;

    switch (option){
      case 0:
            system("CLS");
            cout << "\n\n\n\tHasta pronto!!\n\n"; exit(-1);
            break;
      case 1:
            system("CLS");
            (notas+n_obj) -> save();
            n_obj++;
            fflush(stdin);
            cout << "\tNota guardada" << endl;
            break;
      case 2:
            system("CLS");
            cout<<"\n------------------------------------------------------"<<endl;
            cout<<" \tLISTA DE NOTAS "<<endl;
            cout<<"------------------------------------------------------"<<endl;
            n_obj = user.size;
            for (int i = 0; i < n_obj; i++)
            { cout << "\tNota " << i+1 << ":";
            (notas+i) -> name(i+1);
            cout << "\n";
            }
            cout << "\n\nIntroduce el numero de la nota que deseas leer y presiona ENTER: ";
            cin >> submenu;
            (notas)->read(submenu);
                  system("CLS");
            fflush(stdin);
            break;
      case 3:
          system("CLS");
          cout<<"\n------------------------------------------------------"<<endl;
          cout<<" LISTA DE NOTAS "<<endl;
          cout<<"------------------------------------------------------"<<endl;
          n_obj = user.size;
          for (int i = 0; i < n_obj; i++)
          { cout << "Nota " << i+1 << ":";
          (notas+i) -> name(i+1);
          cout << "\n";
          }
          cout << "\n\nIntroduce el numero de nota que deseas Eliminar: ";
          cin >> submenu;
          (notas)->delit(submenu);
          cout << "\tNota Eliminada\n";
          fflush(stdin);
            break;
      default: cout << "Opcion invalida, Intenta de nuevo: ";
      }
      delete [ ] notas;
    }
  while (option !=0);

}
