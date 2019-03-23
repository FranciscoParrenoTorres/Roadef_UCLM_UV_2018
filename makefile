CC          = g++
CC          = gcc -fopenmp
CFLAGS      = -std=c++11 -O4 -DDEBUG 


LIBS        = -fopenmp -lstdc++ -lm 

OBJSC = GlassCorte.o Glass.o GlassDefect.o GlassItem.o GlassNodeB.o GlassNode.o GlassOriginals.o GlassPlate.o GlassRectangle.o GlassRsol.o GlassStack.o GlassStructures.o
OBJSF  = 
OBJS= $(OBJSC) $(OBJSF)

default: roadef

all: $(CPROGS)

clean:	
	rm -f core  
	rm -f salida* 
	rm -f sal* 
	rm -f *.o  
	rm -f *.exe  

roadef :   main.o $(OBJS)
	$(CC) $(CFLAGS) -o Roadef-UCLMUV.exe main.o $(OBJS) $(LIBS)

.f.o:
	$(F77) $(FFLAGS) -c $<

.cpp.o:
	$(CC) -c $(CFLAGS) -c  $<

