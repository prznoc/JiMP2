#ifndef OBIEKT_H_
#define OBIEKT_H_
#include <vector>
#include <stdint.h>
#include <iostream>
#include <string>
#include <string>

class Point_I{
	private:
		double x = 0.0, y=0.0, z=0.0;
		unsigned int index = 0;
	public:
		Point_I(){}
		Point_I(double xx, double yy, double zz) : x(xx), y(yy), z(zz) {}
		Point_I(double xx, double yy, double zz, int ii) : x(xx), y(yy), z(zz), index(ii) {}
		Point_I (const Point_I &p){*this = p;}
		~Point_I(){x = y = z = index = 0;}
		double getX() const { return x; }
		double getY() const { return y; }
		double getZ() const { return z; }
		void edit_X(double li) {x = li;}
		void edit_Y(double li) {y = li;}
		void edit_Z(double li) {z = li;}
		void index_change(int a){index = a;}
		int getIndex() const {return index;}
};


class Triangle{
	private:
		int points[3];  
	public:
		Triangle() = default;
		Triangle(Point_I a, Point_I b, Point_I c) { points[0] = a.getIndex(); points[1] = b.getIndex(); points[2] = c.getIndex();}
		Triangle(const Triangle &tr){*this = tr;}
		double getPoint(unsigned int i) {
			if(i>= 0 && i <= 2)	return points[i];
		}
};

class Object{
	private:
		std::vector <Point_I> vertices;
		std::vector <Triangle> faces;
		void draw(std::string nazwa, int flag)const;
	public:
		Object() = default;
		Object(const Object &o){*this = o;}
		Object& operator=(const Object&);
		void Vedit(const Point_I &poi, int i) {vertices[i] = poi;}
		void addPoint(const Point_I &p);
		void addTriangle(unsigned int p1,unsigned int p2,unsigned int p3);
		void addTriangle(const Triangle&);
		Point_I getVertex(int i) const {return vertices[i];}
		Triangle getFace(int i) const{return faces[i];}
		void clear(){
			vertices.clear();
			faces.clear();
		}
		int vertices_size() const {return vertices.size();}
		int faces_size() const {return faces.size();}
		void drawXY(std::string nazwa)const{draw(nazwa, 0);}
		void drawXZ(std::string nazwa)const{draw(nazwa, 1);}
		void drawYZ(std::string nazwa)const{draw(nazwa, 2);}
		std::vector <Triangle> get_triangles()const{return faces;}
		void wypisz(std::string&)const;
		Point_I getS()const;
};

class Interpreter{
	private:
		int analyze(std::string linia, Object &obj, int lin);
		int vertex (std::string linia, Object &obj);
		int face (std::string linia, Object &obj);
	public:
		void getfile(std::string &name, Object &obj);
		
};



#endif /* OBIEKT_H_ */
