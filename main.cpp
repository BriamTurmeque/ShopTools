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
int comprobarIntDia()
{
    int dia = 0;
    string dia2 = "";
    bool bandera = 0;
    cout << "Digite el dia: ";
    cin >> dia2;
    while (bandera == 0)
    {
        if ((stoi(dia2)) <= 30 && (stoi(dia2)) > 0)
        {
            bandera = 1;
            // aqui creo un if para ver si el dia es menor a 9, en ese caso agregue un cero antes de la fecha,
            // para que siga cumpliendo el estandar de mostrar la fecha, pero al convertirlo a un entero, este me suprime el cero
            if (stoi(dia2) <= 9 && stoi(dia2) > 0 )
            {
                dia2 = "0" + dia2;
                cout << "en este caso dia2 = " << dia2 << endl;
                dia = stoi(dia2);
            }
            else
            {
                dia = stoi(dia2);
            }
        }
        else
        {
            cout << "Digito una opcion invalida\nDigite el dia: ";
            cin >> dia2;
        }
    }

    return dia;
}

// creacion de la clase comprador sin la asociacion a la otra clase,
// sin la agregacion de herramientas
class Buyer
{
    string name, dateBorn, addres, phoneNumber;
    float cost;
    public:
    Buyer()
    {
        name = dateBorn = addres = phoneNumber = "";
        cost = 0.0;
    }
    Buyer(string name, string dateBorn, string addres, string phoneNumber, float cost)
    {
        this->name = name;
        this->dateBorn = dateBorn;
        this->addres = addres;
        this->phoneNumber = phoneNumber;
        this->cost = cost;
    }

    string getName()
    {
        return name;
    }
    string getDateBorn()
    {
        return dateBorn;
    }
    string getAddres()
    {
        return addres;
    }
    string getPhoneNumber()
    {
        return phoneNumber;
    }
    float getCost()
    {
        return cost;
    }
    void setName(string name)
    {
        this->name = name;
    }
    void setDateBorn(string dateBorn)
    {
        this->dateBorn = dateBorn;
    }
    void setAddres(string addres)
    {
        this->addres = addres;
    }
    void setPhoneNumber(string phoneNumber)
    {
        this->phoneNumber = phoneNumber;
    }
    void setCost(float cost)
    {
        this->cost = cost;
    }

};

class Person
{
    string name, dateBorn, nit, phoneNumber, addres;
    public:
    Person()
    {
        name = dateBorn = nit = phoneNumber = addres = "";
    }
    Person(string name, string dateBorn, string nit, string phoneNumber, string addres)
    {
        this->name = name;
        this->dateBorn = dateBorn;
        this->nit = nit;
        this->phoneNumber = phoneNumber;
        this->addres = addres;
    }
    string getName()
    {
        return name;
    }
    string getDateBorn()
    {
        return dateBorn;
    }
    string getNit()
    {
        return nit;
    }
    string getPhoneNumber()
    {
        return phoneNumber;
    }
    string getAddres()
    {
        return addres;
    }
    void setName(string name)
    {
        this->name = name;
    }
    void setDateBorn(string dateBorn)
    {
        this->dateBorn = dateBorn;
    }
    void setNit(string nit)
    {
        this->nit = nit;
    }
    void setPhoneNumber(string phoneNumber)
    {
        this->phoneNumber = phoneNumber;
    }
    void setAddres(string addres)
    {
        this->addres = addres;
    }
};

// datos heredados por persona: name, dateBorn, nit, phoneNumber, addres;
// datos heredados por comprador: name, dateBorn, phoneNumber, addres;

// esta clase solo va a contener los datos que hereda y datos mas especificos de las personas, diferentes al comprador que es una empresa
class PersonBuyer: virtual public Buyer,virtual public Person
{
    public:
    PersonBuyer(): Buyer() , Person(){}
    // PersonBuyer(string name, string dateBorn, string nit, string phoneNumber, string addres): Buyer(string name, string dateBorn, string phoneNumber, string addres) , Person(string nit){}
};
// esta clase va a contener los datos que hereda junto a otras mas especificos que son necesarios para el registro
//los datos que maneja este "van a ser los mismos", los que hereda los vamos a trabajar como los del rep leg y le vamos a pedir otros
//acerca de la empresa
class BusinessBuyer: virtual public Buyer,virtual public Person
{
    string businessName, businessAddres, businessPhoneNumber, businessNit, businessEmailAddres;
    public:

    // tengo una duda aqui, ya que ambos padres tienen los mismos datos, que datos le debo pasar en los constructores
    BusinessBuyer(): Buyer() , Person(){}
    // BusinessBuyer(string name, string dateBorn, string nit, string phoneNumber, string addres,
    //     string businessName, string businessAddres, string businessPhoneNumber, string businessNit,
    //     string businessEmailAdress): Buyer(name, dateBorn, addres, phoneNumber), Person(nit)
    //       {
    //         BusinessBuyer::businessName = businessName;
    //         BusinessBuyer::businessAddres = businessAddres;
    //         BusinessBuyer::businessPhoneNumber = businessPhoneNumber;
    //         BusinessBuyer::businessNit = businessNit;
    //         BusinessBuyer::businessEmailAddres = businessEmailAddres;    
    //       }

};

class Date
{
    int dia, mes, anio;
    string date;
    public:
    Date()
    {
        dia = mes = anio = 0;
        date = "";
    }
    Date(int dia, int mes, int anio)
    {
        this->dia = dia;
        this->mes = mes;
        this->anio = anio;
        date = to_string(dia) + "/" + to_string(mes) + "/" + to_string(anio);
    }
    int getDia()
    {
        return dia;
    }
    int getMes()
    {
        return mes;
    }
    int getAnio()
    {
        return anio;
    }
    string getDate()
    {
        return date;
    }
    void setDia(int dia)
    {
        this->dia = dia;
    }
    void setMes(int mes)
    {
        this->mes = mes;
    }
    void setAnio(int anio)
    {
        this->anio = anio;
    }
    void setDate(int dia, int mes, int anio)
    {
        date = to_string(dia) + "/" + to_string(mes) + "/" + to_string(anio);
    }
    virtual string tipoFecha() = 0;
    friend ostream &operator << (ostream &salida, Date *d)
    {
        salida << d->tipoFecha() << " (DD/MM/AAAA): " <<  d->getDate();
        return salida;
    }
    friend istream &operator >> (istream &entrada, Date &d)
    {
        d.dia = comprobarIntDia();
        cout << "Digite el mes: ";
        entrada >> d.mes;
        cout << "Digite el anio: ";
        entrada >> d.anio;
        d.setDate(d.dia, d.mes, d.anio);
        return entrada;
    }


};
class BornDate: public Date{
    public:
    BornDate(): Date(){}
    BornDate(int dia, int mes, int anio):Date(dia,mes,anio){
        setDate(dia, mes, anio);
    }
    string tipoFecha() override{
        return "Fecha de Nacimiento";
    }


};
class AdquisitionDate: public Date{
    public:
    AdquisitionDate(): Date()
    {
    }
    AdquisitionDate(int dia, int mes, int anio):Date(dia,mes,anio)
    {
        setDate(dia,mes,anio);
    }
    string getTipo(){
    return "Adquisicion";
    }
    string tipoFecha() override{
        return "Fecha de Adquisicion";
    }
};



// esta es la clase abstracta tools -> herramientas
// esta va a ser la clase padre que va a heredar a todos los tipos de herramientas
// tenemos un metodo virtual llamado price, que lo vamos a tener que usar obligatoriamente
// en todas las clases hijas de esta
class Tools
{
    string name, funcion;
    float price;
    AdquisitionDate* fecha;
    public:
    Tools()
    {
        name="";
        funcion="";
        price=0.0;
        fecha = new AdquisitionDate();
    }
    Tools(string name,string funcion, float price, AdquisitionDate* fecha)
    {
        Tools::name=name;
        Tools::name=funcion;
        Tools::price = price;
        Tools::fecha = fecha;
    }
    float getPrice()
    {
        return price;
    }
    void setPrice(float price)
    {
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
    friend ostream &operator << (ostream &salida, Tools *t)
    {
        salida << t->getTipo() << "\nNombre: " << t->name << "\nFuncion: " << t->funcion << "\nPrecio: " << t->Price() << endl;
        // tengo problemas al tratar de mostrar la fecha, ya tengo sobrecargado el cout para
        // mostrar las fechas, pero no me lo esta tomando, se arreglara proximamente
        // salida << "\nFecha de adquisicion: "; salida << fecha << endl;
        salida << t->fecha;
        return salida;
    }
};

class ManualTools:public Tools
{
    float iva;
    public:
    ManualTools():Tools()
    {
        ManualTools::iva = 0.19;
    }
    ManualTools(string name,string funcion, float price, AdquisitionDate* fecha,float iva): Tools(name,funcion,price,fecha)
    {
        ManualTools::iva = iva;
    }
    string getTipo() override
    {
        return "Herramienta manual";
    }

    float Price() override
    {
        float precio = getPrice() * (1 + iva);
        return precio;
    }
};
class MechanicalTools:public Tools
{
    float iva;
    public:
    string getTipo() override
    {
        return "Herramienta Mecanica";
    }

    float Price() override
    {
        float precio = getPrice() * (1 + iva);
        return precio;
    }

    MechanicalTools():Tools()
    {
        iva = 0.19;
    }
    MechanicalTools(string name,string funcion, float price, AdquisitionDate* fecha,float iva): Tools(name,funcion,price,fecha)
    {
        MechanicalTools::iva = iva ;
    };
};
//a

class Purshaced
{
    vector <Tools*> purshacedTools;
public:
    Purshaced()
    {
        purshacedTools = {};
    }
    Purshaced(vector <Tools*> Tools)
    {
        purshacedTools = Tools;
    }
    void agregarHerramientas(Tools* h)
    {
        purshacedTools.push_back(h);
    }
    friend ostream &operator << (ostream &salida, Purshaced *p){
        salida << "Compra Realizada: " << endl;
        for (Tools* t: p->purshacedTools){
            salida << t << endl << endl;
        }

        // for (Estudiantes* e: a->estudiantes)
        // {
        //     out << e << endl;
        // }
        
        return salida;
    }

};

int main ()
{
    system("cls");
    system("color f5");
    vector <Tools*> herramientasCompradas = {};

    AdquisitionDate* fechaAdquision = new AdquisitionDate(01,12,2003);
    ManualTools*  mm = new ManualTools("martillo", "martillar", 10000, fechaAdquision, 0.19);
    MechanicalTools* mc = new MechanicalTools ("carretilla", "cargar con lo que se le de la gana", 50000, fechaAdquision, 0.19);
    cout << mm << endl << endl << mc;
    cout << endl << endl;
    cout << fechaAdquision;
    herramientasCompradas.push_back(mm);
    herramientasCompradas.push_back(mc);
    Purshaced* p = new Purshaced(herramientasCompradas);
    cout << p;

    return 0;
}
