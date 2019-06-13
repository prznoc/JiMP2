IDIR =include
CXX=g++
CXXFLAGS=-I$(IDIR) -std=c++11

ODIR=obj
LDIR =lib

LIBS=-lm

_DEPS = macierz4.h translator.h obiekt.h drawing.h bmp.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ= main.o macierz4.o translator.o obiekt.o drawing.o bmp.o point.o obj.o cube.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.c++ $(DEPS)
	$(CXX) -c++ -o $@ $< $(CXXFLAGS)

projekt: $(OBJ)
	$(CXX) -o $@ $^ $(CXXFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 
