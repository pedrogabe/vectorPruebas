#ifndef ENCABEZADOS_H_INCLUDED
#define ENCABEZADOS_H_INCLUDED

#include <vector>
#include "Persona.h"

void VectoresConInts();
void VectoresSimplesConInts();
void MasIdeasConInts();

void MostrarVectorDeInts(std::vector<int> vec);
std::vector<int> llenarConPrimos(int n);
int siguientePrimo(unsigned int n);



void VectoresConObjetosPersona();
std::vector<Persona> CargaNormalDePersonas();
void MostrarPersonas(std::vector<Persona> vec);
Persona CargarPersona();

#endif // ENCABEZADOS_H_INCLUDED
