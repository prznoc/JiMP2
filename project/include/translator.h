#ifndef __TRANSLATOR_H
#define __TRANSLATOR_H

#include "macierz4.h"
#include "obiekt.h"
#include <cmath>
#include <vector>
#include <array>


class Transformator{
	protected:
		virtual ~Transformator(){}
		virtual Macierz translate( double, double, double)const;
		virtual Macierz scale(double, double, double)const;
		virtual Macierz rotateX(double)const;
		virtual Macierz rotateY(double)const;
		virtual Macierz rotateZ(double)const;
		virtual Macierz scale_P(double,double,double,double,double,double)const;
        virtual Macierz rotateXP(double,double,double)const;
		virtual Macierz rotateYP(double,double,double)const;
		virtual Macierz rotateZP(double,double,double)const;
		virtual Macierz rotateA(double, double, double,double,double,double,double)const;
};

struct Point{
	double x=0,y=0,z=0;
	Point(){}
	Point(double xx, double yy, double zz): x(xx),y(yy),z(zz){}
};


class PointT: public Transformator{
	private:
		Point p;
	protected:
		std::vector<Macierz> macierze;
		int size = 0;
	public:
		void translate(double, double, double);
		void scale(double, double, double);
		void rotateX(double);
		void rotateY(double);
		void rotateZ(double);
		void scale_P(double, double, double, double, double, double);
        void rotateXP(double,double,double);
		void rotateYP(double,double,double);
		void rotateZP(double,double,double);
		void rotateA(double, double, double,double,double,double,double);
		//-------------------------------------------------------------//
		void translate_edit(int, double, double, double);       //przy edytowaniu zakładam liczenie od 0
		void scale_edit(int, double, double, double);
		void rotateX_edit(int, double);
		void rotateY_edit(int, double);
		void rotateZ_edit(int, double);
		void scale_P_edit(int, double, double, double, double, double, double);
        void rotateXP_edit(int,double,double,double);
		void rotateYP_edit(int,double,double,double);
		void rotateZP_edit(int,double,double,double);
		void rotateA_edit(int,double, double, double,double,double,double,double);
		//-------------------------------------------------------------//
		void translate_insert(int, double, double,double);      // a przy wkladaniu też od 0
		void scale_insert(int, double, double, double);
		void rotateX_insert(int, double);
		void rotateY_insert(int, double);
		void rotateZ_insert(int, double);
		void scale_P_insert(int, double, double, double, double, double, double);
        void rotateXP_insert(int,double,double,double);
		void rotateYP_insert(int,double,double,double);
		void rotateZP_insert(int,double,double,double);
		void rotateA_insert(int,double, double, double,double,double,double,double);
		//------------------------------------------------------------//
		PointT(){Point p;}
		PointT(const Point& pp): p(pp), macierze(){}
		void remove(int);
		void undo(){remove (size-1);}
		Point get();
};

class ObjT: public PointT{
	private:
		Object obiekt;
		Macierz rotateXS(double)const;
		Macierz rotateYS(double)const;
		Macierz rotateZS(double)const;
		Macierz scaleS(double, double, double);
	public:
		ObjT(const Object& obj):obiekt(obj) {}
		void rotateXC(double);
		void rotateXC_edit(int, double);
		void rotateXC_insert(int, double);
		void rotateYC(double);
		void rotateYC_edit(int, double);
		void rotateYC_insert(int, double);
		void rotateZC(double);
		void rotateZC_edit(int, double);
		void rotateZC_insert(int, double);
		void scaleC(double, double, double);
		void scaleC_edit(int,double, double, double);
		void scaleC_insert(int,double, double, double);
		Object get()const;
};

struct Cube{
	Point s;
	Point wierzcholki[8];
	Cube(){}
	Cube(const Point&, double);
	void wypisz()const{
		std::cout<<s.x<<" "<<s.y<<" "<<s.z<<std::endl;
		std::cout<<wierzcholki[0].x<<" "<<wierzcholki[0].y<<" "<<wierzcholki[0].z<<std::endl;
		std::cout<<wierzcholki[1].x<<" "<<wierzcholki[1].y<<" "<<wierzcholki[1].z<<std::endl;
		std::cout<<wierzcholki[2].x<<" "<<wierzcholki[2].y<<" "<<wierzcholki[2].z<<std::endl;
		std::cout<<wierzcholki[3].x<<" "<<wierzcholki[3].y<<" "<<wierzcholki[3].z<<std::endl;
		std::cout<<wierzcholki[4].x<<" "<<wierzcholki[4].y<<" "<<wierzcholki[4].z<<std::endl;
		std::cout<<wierzcholki[5].x<<" "<<wierzcholki[5].y<<" "<<wierzcholki[5].z<<std::endl;
		std::cout<<wierzcholki[6].x<<" "<<wierzcholki[6].y<<" "<<wierzcholki[6].z<<std::endl;
		std::cout<<wierzcholki[7].x<<" "<<wierzcholki[7].y<<" "<<wierzcholki[7].z<<std::endl;
		std::cout<<std::endl;
	}
};

class CubeT:public PointT{
	private:
		Cube cube;
		Macierz scaleS(double, double, double);
	public:
		CubeT(const Cube& cu):cube(cu) {}
		Cube get()const;
		void scaleC(double, double, double);
		void scaleC_edit(int,double, double, double);
		void scaleC_insert(int,double, double, double);
		void scaleK(int, double, double, double);
		void scaleK_edit(int,int, double, double, double);
		void scaleK_insert(int,int, double, double, double);
		void rotateA(int, int, double);
		void rotateA_edit(int, int, int, double);
		void rotateA_insert(int, int, int, double);
};


#endif
