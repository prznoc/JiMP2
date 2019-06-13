#include "translator.h"
#include <stdint.h>
#include <iostream>
#include <cstring>
#include <fstream>
#include <sstream>

int main(int argc, char* argv[]) {
	Object obj;
	Interpreter inter;
	std::string nazwa = "rysunki/cow.obj", rezultat = "rysunki/result.obj", rezultat2 = "rysunki/result2.obj";
	std::string rysunek = "rysunki/test.bmp", rysunek2 = "rysunki/test2.bmp", rysunek3 = "rysunki/test3.bmp",rysunek4 = "rysunki/test4.bmp", rysunek5 = "rysunki/test5.bmp", rysunek6 = "rysunki/test6.bmp";
	inter.getfile(nazwa, obj);
	obj.drawXY(rysunek);
	obj.drawXZ(rysunek2);
	obj.drawYZ(rysunek3);
//	obj.wypisz(rezultat);
	ObjT trans = obj;
	trans.translate(3,3,3);
	trans.rotateXC(30);
	obj = trans.get();
	obj.wypisz(rezultat);
	obj.drawXY(rysunek4);
	obj.drawXZ(rysunek5);
	obj.drawYZ(rysunek6);
/*	Point s(5,-2,3);
	Cube cube(s,3);
	cube.wypisz();
	CubeT transform = cube;
	transform.scaleC(3,2,4);
	transform.scaleK(3,2,2,2);
	cube = transform.get();
	cube.wypisz();
	transform = cube;
	transform.translate(2,2,2);
	cube = transform.get();
	cube.wypisz();*/
}
