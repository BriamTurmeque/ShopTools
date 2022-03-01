#include <iostream>

using namespace std;

int main (){
    system("cls");
    int numero;
    cout << "-------------\nIngrese un numero\n-------------\n- ";
    // mediante el siguiente while se hace la comprobacion de datos, al verificar que tipo de dato es erroneo,
    // procede a limpiar la memoria y ignora el error, ademas notificamos acerca del error y volvemos a pedir
    // la entrada de datos por parte del usuarion
    while (!(cin >> numero)){
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Debes ingresar un valor numerico, intenta de nuevo." << endl << "- ";
    }
    cout << "\tLos datos ingresados por el usuario cumplen \n\tcon los requerimientos establecidos. :)\n\n";
    return 0;
}
