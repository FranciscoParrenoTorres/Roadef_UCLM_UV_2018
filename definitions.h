#ifndef DEFINITIONS_H
#define DEFINITIONS_H

//#include <stdint-gcc.h>
//lectura y escritura
#include <stdint.h>
#include <cstdlib>
#include <string>
#include <string.h>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <list>
#include <random>
#include <thread>
#include <sys/timeb.h>


#include "main.h"

#include "GlassDefect.h"
#include "GlassItem.h"
#include "GlassNode.h"
#include "GlassNodeB.h"
#include "GlassPlate.h"
#include "GlassStack.h"
#include "GlassRectangle.h"
#include "GlassStructures.h"
#include "GlassCorte.h"



                  

using namespace std;

#define get_aleatorio(min, max) ((rand() % (int)(((max)+1) - (min))) + (min))





//This function give back the new rectangle that we have to pack
/*GlassRectangle * AsignarRectangulo(GlassRectangle &rectangulo)
{

};*/
#endif
