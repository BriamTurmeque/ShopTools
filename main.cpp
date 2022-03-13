#include <iostream>
#include "vector"
#include "string"
#include "windows.h"

using namespace std;
int comprobarIntDia();



// creo que con el try catch tampoco se puede por que tengo el mismo problema
// catch: argumento invalido, no se que puede hacer

//  la forma mas eficiente que pienso para poder hacer esta verificacion es con un try catch
// usando al convertir el string a entero, y si me devuelve la excepcion decir que es un 
// argumento invalido, y volver a pedirle el dato
int comprobarIntDia(){
    int dia = 0;
    string dia2 = "";
    bool bandera = 0;
    cout << "Digite el dia: "; cin >> dia2;
    while (bandera == 0){
        if ((stoi(dia2)) <= 30 && (stoi(dia2)) > 0){
            bandera = 1;
            // aqui creo un if para ver si el dia es menor a 9, en ese caso agregue un cero antes de la fecha,
            // para que siga cumpliendo el estandar de mostrar la fecha, pero al convertirlo a un entero, este me suprime el cero
            if (stoi(dia2) <= 9 && stoi(dia2) > 0 ){
                dia2 = "0" + dia2;
                cout << "en este caso dia2 = " << dia2 << endl;
                dia = stoi(dia2);
            }
            else {
                dia = stoi(dia2);
            }
        }
        else { cout << "Digito una opcion invalida\nDigite el dia: ";cin >> dia2;}
    }

    return dia;
}

// creacion de la clase comprador sin la asociacion a la otra clase,
// sin la agregacion de herramientas
class Buyer{
    string name, date, addres, phoneNumber;
    float cost;  
    private:
    Buyer(){
        name = date = addres = phoneNumber = "";
        cost = 0.0;
    }
    Buyer(string name, string date, string addres, string phoneNumber, float cost){
        this->name = name;
        this->date = date;
        this->addres = addres;
        this->phoneNumber = phoneNumber;
        this->cost = cost;
    }

    string getName(){
        return name;
    }
    string getDate(){
        return date;
    }
    string getAddres(){
        return addres;
    }
    string getPhoneNumber(){
        return phoneNumber;
    }
    float getCost(){
        return cost;
    }
    void setName(string name){
        this->name = name;
    }
    void setDate(string date){
        this->date = date;
    }
    void setAddres(string addres){
        this->addres = addres;
    }
    void setPhoneNumber(string phoneNumber){
        this->phoneNumber = phoneNumber;
    }
    void setCost(float cost){
        this->cost = cost;
    }

};

class Person{
    string name, dateBorn, nit, cel, addres;
    private:
    Person(){
        name = dateBorn = nit = cel = addres = "";
    }
    Person(string name, string dateBorn, string nit, string cel, string addres){
        this->name = name;
        this->dateBorn = dateBorn;
        this->nit = nit;
        this->cel = cel;
        this->addres = addres;
    }
    string getName(){
        return name;
    }
    string getDateBorn(){
        return dateBorn;
    }
    string getNit(){
        return nit;
    }
    string getCel(){
        return cel;
    }
    string getAddres(){
        return addres;
    }
    void setName(string name){
        this->name = name;
    }
    void setDateBorn(string dateBorn){
        this->dateBorn = dateBorn;
    }
    void setNit(string nit){
        this->nit = nit;
    }
    void setCel(string cel){
        this->cel = cel;
    }
    void setAddres(string addres){
        this->addres = addres;
    }
};

class PersonBuyer: virtual public Buyer,virtual public Person{ 
    private:
};
class BusinessBuyer: virtual public Buyer,virtual public Person{
    private:
};

class Date{
    int dia, mes, anio;
    string date;
    public:
    Date(){
        dia = mes = anio = 0;
        date = "";
    }
    Date(int dia, int mes, int anio){
        this->dia = dia;
        this->mes = mes;
        this->anio = anio;
        date = to_string(dia) + "/" + to_string(mes) + "/" + to_string(anio);
    }
    int getDia(){
        return dia;
    }
    int getMes(){
        return mes;
    }
    int getAnio(){
        return anio;
    }
    string getDate(){
        return date;
    }
    void setDia(int dia){
        this->dia = dia;
    }
    void setMes(int mes){
        this->mes = mes;
    }
    void setAnio(int anio){
        this->anio = anio;
    }
    void setDate(int dia, int mes, int anio){
        date = to_string(dia) + "/" + to_string(mes) + "/" + to_string(anio);
    }
    friend ostream &operator << (ostream &salida, Date &d){
        salida << "la fecha es (dd/mm/aaaa): " <<  d.getDate();
        return salida;
    }
    friend istream &operator >> (istream &entrada, Date &d){
        d.dia = comprobarIntDia();
        cout << "Digite el mes: "; entrada >> d.mes;
        cout << "Digite el anio: "; entrada >> d.anio;
        d.setDate(d.dia, d.mes, d.anio);
        return entrada;
    }


};

// esta es la clase abstracta tools -> herramientas
// esta va a ser la clase padre que va a heredar a todos los tipos de herramientas 
// tenemos un metodo virtual llamado price, que lo vamos a tener que usar obligatoriamente
// en todas las clases hijas de esta
class Tools     
{

// ---------------------
// falta añadir la asociacion de la fecha de compra, cuando se cree esa clase se va a crear la asociacion;
// --------------------
    string name, funcion;
    float price;
    Date* fecha;
public:
    Tools()
    {
        name="";
        funcion="";
        price=0.0;
        fecha = new Date();
        }
    Tools(string name,string funcion, float price, Date* fecha)
    {
        Tools::name=name;
        Tools::name=funcion;
        Tools::price = price;
        Tools::fecha = fecha;
    }
    float getPrice(){
        return price;
    }
    void setPrice(float price){
        Tools::price = price;
    }
    string getName()
    {
        return name;
    }
    string getFuncion()
    {
        return funcion;
    }
    void setName(string name)
    {
        Tools::name=name;
    }
    void setFuncion(string funcion)
    {
        Tools::funcion=funcion;
    }

    virtual string getTipo() = 0;
    virtual float Price()=0;
    friend ostream &operator << (ostream &salida, Tools &t)
    {
        salida << t.getTipo() << "\nNombre: " << t.name << "\nFuncion: " << t.funcion << "\nPrecio: " << t.getPrice();
        // tengo problemas al tratar de mostrar la fecha, ya tengo sobrecargado el cout para 
        // mostrar las fechas, pero no me lo esta tomando, se arreglara proximamente 
        // salida << "\nFecha de adquisicion: "; salida << fecha << endl;
        salida << "\nFecha adquision(DD/MM/AAAA): " << t.fecha->getDia() << "/" << t.fecha->getMes() << "/" << t.fecha->getAnio() << endl;   
        return salida;
    }
};

class ManualTools:public Tools
{
    float iva;
public:
ManualTools():Tools(){
    ManualTools::iva = 0.19;
}
ManualTools(string name,string funcion, float price, Date* fecha,float iva): Tools(name,funcion,price,fecha){
    ManualTools::iva = iva;
}
string getTipo() override {
    return "Herramienta manual";}

float Price() override {
    float precio = getPrice() * (1 + iva);
    return precio;
}
};
class MechanicalTools:public Tools
{
string getTIpo(){return "Herramienta Mecanica";}

};



int main (){
    system("cls");
    Date* d = new Date(01,12,2003);
    // estamos teniendo problemas con la creacion del objeto de ManualTools, proximamente lo arreglaremos
    // ManualTools m = ManualTools("martillo" , "martillar" , 20500 , d, 0.19);
    
    ManualTools* mm = new ManualTools("martillo" , "martillar" , 20500 , d , 0.19); 
    cout << mm;
    return 0;
}