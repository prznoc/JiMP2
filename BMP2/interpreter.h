#ifndef _INTERPRETER_H
#define _INTERPRETER_H

#include <iostream>
#include <string>
#include "bmp.h"

using namespace std;

class Interpreter{
	private:
		int analyze(string linia, JiMP2::BMP &bmp, int lin);
		int line(string linia, JiMP2::BMP &bmp);
		int circle(string linia, JiMP2::BMP &bmp);
		int disc(string linia, JiMP2::BMP &bmp);
		int arc(string linia, JiMP2::BMP &bmp);
		int part(string linia, JiMP2::BMP &bmp);
	public:
		void getfile();
};


#endif

