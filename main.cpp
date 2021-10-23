#include <iostream>
#include <vector>
#include "Persona.h"
#include "encabezados.h"
#include <cmath>

using namespace std;

int main()
{
    VectoresConInts();

    cout << endl << endl;

    VectoresConObjetosPersona();

    return 0;
}

void VectoresConInts()
{
    VectoresSimplesConInts();
    MasIdeasConInts();
}

void MostrarVectorDeInts(vector<int> vec)
{
    if(!vec.empty()) // Validar que el vector no esté vacío
        for(int i=0; i<vec.size(); i++) cout << vec[i] << " "; //size() devuelve la cantidad de elementos asignados que tiene el vector
    cout << endl;
}


void VectoresSimplesConInts()
{
    vector<int> vectorDeIntsVacio; //Vector vacío
    MostrarVectorDeInts(vectorDeIntsVacio); //No muestra nada porque no tiene elementos

    vector<int> vectorDeIntsConNumerosIguales(150,100); //Vector de 150 elementos con valor 100 cada uno
    MostrarVectorDeInts(vectorDeIntsConNumerosIguales); //Mustra 100, 150 veces

    vector<int> vectorConNumerosPorAsignacion = {1,2,3}; //Creo un vector con tres elementos específicados
    MostrarVectorDeInts(vectorConNumerosPorAsignacion); //Muestra 1 2 3

    vectorConNumerosPorAsignacion = {4,5,6,7}; //Modifico los elementos que existían y agrego uno mediante una asignación
    MostrarVectorDeInts(vectorConNumerosPorAsignacion); //Muestra 4 5 6 7

    vectorConNumerosPorAsignacion = {8,9}; //Reemplaza los 4 elementos que había en el vector por estos dos
    MostrarVectorDeInts(vectorConNumerosPorAsignacion); //Muestra 8 y 9

    vector<int> vectorCopiaDeOtroVector(vectorConNumerosPorAsignacion);//Se crea un vector copiando los valores del vector que se pasa por parámetro
    MostrarVectorDeInts(vectorCopiaDeOtroVector);//Muestra 8 y 9

    vectorCopiaDeOtroVector.pop_back(); //Elimina el elemnto del final
    MostrarVectorDeInts(vectorCopiaDeOtroVector);//Muestra 8

    vectorCopiaDeOtroVector.push_back(7); //Agrega un elemnto al final
    MostrarVectorDeInts(vectorCopiaDeOtroVector);//Muestra 8 y 7

    vectorCopiaDeOtroVector.emplace(vectorCopiaDeOtroVector.begin()+1,0); //Inserto un elemento con valor 0, 1 posición después del comienzo
    MostrarVectorDeInts(vectorCopiaDeOtroVector);//Muestra 8 0 7

}

void MasIdeasConInts()
{
    vector<int> vectorDePrimos = llenarConPrimos(9);
    MostrarVectorDeInts(vectorDePrimos);

}

vector<int> llenarConPrimos(int n)
{
    vector<int> vectorDePrimos;
    vectorDePrimos.push_back(2); //Le agregamos un primer valor ya que lo usaremos luego
    for(int i=0;i<n;i++)
    {
        vectorDePrimos.push_back( //Llamamos a push_back para agregar un elemento al final
                                 siguientePrimo( //LLamamos a siguientePrimo para obtener el próximo valor que vamos a agregar
                                                vectorDePrimos.back() //Mandamos por parámetro el último valor que agregamos al vector para que no se repitan los números
                                                ));
    }
    return vectorDePrimos;
}

int siguientePrimo(unsigned int n)
{
    bool primo=false;
    while(!primo)
    {
        primo=true; //Se considera primo hasta demostrar lo contrario
        n++;
        int mitad=n/2;
        for(int i=2;i<=mitad;i++)
        {
            if(n%i==0)
                primo=false; //Si tiene un divisor es porque no es primo
        }
    }
    return n;
}


//********  Vectores con objetos persona ************
void VectoresConObjetosPersona()
{
    vector<Persona> listaDesordenadaDePersonas = CargaNormalDePersonas();
    MostrarPersonas(listaDesordenadaDePersonas);
}

Persona CargarPersona()
{
    string nombre, apellido;
    cout << "Ingrese el nombre de la persona" << endl;
    cin >> nombre;
    cout << "Ingrese el apellido de la persona" << endl;
    cin >> apellido;
    return Persona(nombre,apellido);
}

void MostrarPersonas(vector<Persona> vec)
{
    if(!vec.empty())
        for(int i=0; i<vec.size(); i++)
            cout << vec[i].getNombre() << " " << vec[i].getApellido() << endl;
    cout << endl;
}


vector<Persona> CargaNormalDePersonas()
{
    vector<Persona> listaDePersonas; //Inicializamos un vector vacío
    int aux=1;

    while(aux==1)
    {
        listaDePersonas.push_back(CargarPersona()); //Construyo y cargo al vector el objeto persona que acabo de crear

        cout << "Si desea ingresar más personas ingrese 1" << endl;
        cin >> aux;
    }
    cout << endl;
    return listaDePersonas;
}

