#include <iostream>

using namespace std;

// lo curioso es que me toca como numero a cualquier numero que no sobrepase los 10 digitos
// si es igual o mayor ya lo desconoce como numero y dice que esta colocando texto

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
