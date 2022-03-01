#include <iostream>
using namespace std;
int main (){
    system("cls");
    int a, b, c;
    cout << "Ingrese un numero para a: ";
    cin >> a;
    fflush(stdin);
    cout << "Ingrese un numero para b: ";
    cin >> b;
    fflush(stdin);
    cout << "Ingrese un numero para c: ";
    cin >> c;
    cout << "\na: " << a << "\nb: " << b << "\nc: " << c;

    // aqui podemos apreciar al escribir en la primer entrada que si escribimos dos enteros, el primero se
    // almacena en la variable que queremos y se borra del buffer, pero nos sigue quedando la otra parte en 
    // el buffer, ya que esta no se a asignado ni se a borrada, se va usar en la siguiente entrada, generando
    // ese error tan tipico que solemos utilizar
    
    // por eso cuando escribimos algo de esta manera, no nos pide el segundo dato, ya que como aun 
    // le queda algo en el buffer lo va a usar y despues si lo borra, para pedir la proxima entrada de datos

    // la manera de solucionar esto es mediante la funcion fflush(stdin); esto lo que va a hacer es que va a 
    // limpiar lo que tengamos en el buffer, de esta manera ya no nos generará ningun error ni ningun inconveniente
    // de esta manera solo coge lo primero y el resto lo borra, asi aunque en el resto nos haya puesto un string
    // no nos va a generar error puesto que esto lo borra y no lo almacena en ningun lado.

    return 0;
}