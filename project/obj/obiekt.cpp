#include "obiekt.h"
#include "drawing.h"
#include <stdint.h>
#include <iostream>
#include <cstring>
#include <fstream>
#include <sstream>

void Object::addTriangle(unsigned int p1,unsigned int p2,unsigned int p3){
	int size = vertices_size();
	if (p1>size || p2> size || p3>size) return;
	faces.push_back(Triangle(vertices[p1-1],vertices[p2-1],vertices[p3-1]));
}

void Object::addTriangle(const Triangle& troj){
	faces.push_back(troj);
}

void Object::addPoint(const Point_I &p){
	Point_I add = p;
	add.index_change(vertices_size()+1); 
	vertices.push_back(add);
}

Object& Object::operator=(const Object &orginal){
	if(this != &orginal) {
		clear();
		vertices = orginal.vertices;
		faces = orginal.faces;
	}
	return *this;
}

	
void Interpreter::getfile(std::string &name, Object &obj){  
	string linia;
    fstream plik;
    plik.open(name, ios::in);
    int lin = 0;
	int flag;
    if(plik.good() == true){
    	while(!plik.eof()){
    		lin+=1;
    		getline(plik, linia);
    		flag = analyze(linia, obj , lin);
    		if (flag == 1) cerr<<"problem: linijka "<<lin<<endl;
    		else if (flag == 2) cerr<<"nieprawidlowa ilosc argumentow: linijka "<<lin<<endl;
    		else if( flag == 3) cerr<<"nieznana komenda: linijka "<<lin<<endl;
			if (flag != 0) break;
		}
	}
	if (flag != 0) obj.clear();
}

int Interpreter::analyze(string linia, Object &obj, int lin){
	int i = 0;
	std::istringstream iss(linia);
	string cmd;
	iss>>cmd;
	int flag = 0;
	if (cmd == "v") flag = vertex(linia, obj);
	else if (cmd == "f") flag = face(linia, obj);
	else if (cmd == "#"|| iss.eof() ) flag = 0;
	else {
		return 3;
	}
	return flag;
}

int Interpreter::vertex(std::string linia, Object &obj){
	double x,y,z;
	const int size = 4;
	int licznik = 0, i = 0;
	int count_flag = 0;
	while (i!=linia.size()){
		if (linia[i] == 32) {
		count_flag = 0;
		}
		if (linia[i] != 32&&count_flag == 0) {
		count_flag = 1;
		licznik +=1;
		}
		++i;
	}
	if (licznik!=size){
		return 2;
	}
	istringstream iss(linia);
	char cmd;
	iss>>cmd;
	iss>>x>>y>>z;
	Point_I p(x,y,z);
	obj.addPoint(p);
	return 0;
}

int Interpreter::face(std::string linia, Object &obj){
	int p1, p2, p3;
	const int size = 4;
	int licznik = 0, i = 0;
	int count_flag = 0;
	while (i!=linia.size()){
		if (linia[i] == 32) {
		count_flag = 0;
		}
		if (linia[i] != 32&&count_flag == 0) {
		count_flag = 1;
		licznik +=1;
		}
		++i;
	}
	if (licznik!=size){
		return 2;
	}
	istringstream iss(linia);
	char cmd;
	iss>>cmd;
	iss>>p1>>p2>>p3;
	int siz = obj.vertices_size();
	if (p1>siz || p2> siz || p3>siz ||p1<1||p2<1||p3<1) return 1;
	obj.addTriangle(p1,p2,p3);
	return 0;
}


void Object::draw(std::string nazwa, int flag)const{
	if (vertices_size() == 0) return;
	const uint16_t imgWidth = 800;
	const uint16_t imgHeight = 600;
	JiMP2::BMP bmp(imgWidth, imgHeight);
	Point_I p;
	p = getVertex(0);
	double x_min , x_max, y_min, y_max;
	if (flag==0||flag == 1)x_min = x_max = p.getX(); 
	if (flag == 2)x_min = x_max = p.getZ();
	if (flag == 0)y_min = y_max = p.getY();
	if(flag == 1) y_min = y_max = p.getZ();
	if(flag == 2) y_min = y_max = p.getY();
	double xx,yy;
	Triangle t;
	for (int i = 1; i<vertices_size(); ++i){
		p = getVertex(i);
		if (flag==0||flag == 1)xx = p.getX();
		if (flag == 2)xx = p.getZ();
		if (flag == 0)yy = p.getY();
		if (flag == 1) yy = p.getZ();
		if (flag == 2) yy = p.getY();
		if(xx>x_max) x_max = xx;
		if(xx<x_min) x_min = xx;
		if(yy>y_max) y_max = yy;
		if(yy<y_min) y_min = yy;
	}
	x_max = x_max - x_min;
	y_max = y_max - y_min;
	double width = bmp.getX();
	double height = bmp.getY();
	width = width/x_max;
	height = height/y_max;
	double mnoznik = min(width,height);
	int x1,y1,x2,y2,x3,y3;
	Point_I p1,p2,p3;
	RysownikImplementacja obraz;
	for (int i = 0; i<faces_size(); ++i){
		t = getFace(i);
		p1 = getVertex(t.getPoint(0)-1);
		p2 = getVertex(t.getPoint(1)-1);
		p3 = getVertex(t.getPoint(2)-1);
		if (flag == 0){
			x1 =  (p1.getX()-x_min)*mnoznik;
			y1 =  (p1.getY()-y_min)*mnoznik;
			x2 =  (p2.getX()-x_min)*mnoznik;
			y2 =  (p2.getY()-y_min)*mnoznik;
			x3 =  (p3.getX()-x_min)*mnoznik;
			y3 =  (p3.getY()-y_min)*mnoznik;
		}
		if (flag == 1){
			x1 =  (p1.getX()-x_min)*mnoznik;
			y1 =  (p1.getZ()-y_min)*mnoznik;
			x2 =  (p2.getX()-x_min)*mnoznik;
			y2 =  (p2.getZ()-y_min)*mnoznik;
			x3 =  (p3.getX()-x_min)*mnoznik;
			y3 =  (p3.getZ()-y_min)*mnoznik;
		}
		if (flag == 2){
			x1 =  (p1.getZ()-x_min)*mnoznik;
			y1 =  (p1.getY()-y_min)*mnoznik;
			x2 =  (p2.getZ()-x_min)*mnoznik;
			y2 =  (p2.getY()-y_min)*mnoznik;
			x3 =  (p3.getZ()-x_min)*mnoznik;
			y3 =  (p3.getY()-y_min)*mnoznik;
		}
		if (flag == 0|| flag == 2){
			y1 = imgHeight - y1;
			y2 = imgHeight - y2;
			y3 = imgHeight - y3;
		}
		obraz.odcinek(bmp, x1,y1,x2,y2,255,0,0);
		obraz.odcinek(bmp, x1,y1,x3,y3,255,0,0);
		obraz.odcinek(bmp, x3,y3,x2,y2,255,0,0);
	}
	
	std::ofstream outfile(nazwa, std::ofstream::binary);
	outfile<<bmp;
}

void Object::wypisz(std::string &name)const{
	if (vertices_size() == 0) return;
	std::ofstream output(name, std::ofstream::binary);
	output << "# Wavefront OBJ file\n";
	for(int i = 0; i < vertices_size(); ++i){
		const Point_I &p = getVertex(i);
		output << "v " << p.getX() << ' '<< p.getY() << ' '<< p.getZ()<<'\n';
		
 	}
 	for (int i = 0; i<faces_size(); ++i){
 		Triangle t = getFace(i);
 		output<< "f"<<" "<< t.getPoint(0)<<" "<<t.getPoint(1)<<" "<<t.getPoint(2)<<'\n';
	}
}

Point_I Object::getS()const{
	Point_I p;
	p = getVertex(0);
	double x_min , x_max, y_min, y_max, z_min, z_max,xx,yy,zz;
	x_min = x_max = p.getX(); 
	y_min = y_max = p.getY(); 
	z_min = z_max = p.getZ(); 
	for (int i = 1; i<vertices_size(); ++i){
		p = getVertex(i);
		xx = p.getX();
		yy = p.getY();
		zz = p.getZ();
		if(xx>x_max) x_max = xx;
		if(xx<x_min) x_min = xx;
		if(yy>y_max) y_max = yy;
		if(yy<y_min) y_min = yy;
		if(zz>x_max) z_max = zz;
		if(zz<x_min) z_min = zz;
	}
	double xm,ym,zm;
	xm = (x_max+x_min)/2;
	ym = (y_max+y_min)/2;
	zm = (z_max+z_min)/2;
	Point_I poi(xm,ym,zm);
	return poi;
}
