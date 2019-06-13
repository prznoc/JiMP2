#include "translator.h"


Cube::Cube(const Point &p, double dl){
	if (dl == 0) throw;
	s = p;
	dl/=2;
	wierzcholki[0] = Point(p.x-dl,p.y-dl,p.z-dl);
	wierzcholki[1] = Point(p.x-dl,p.y-dl,p.z+dl);
	wierzcholki[2] = Point(p.x-dl,p.y+dl,p.z-dl);
	wierzcholki[3] = Point(p.x-dl,p.y+dl,p.z+dl);
	wierzcholki[4] = Point(p.x+dl,p.y-dl,p.z-dl);
	wierzcholki[5] = Point(p.x+dl,p.y-dl,p.z+dl);
	wierzcholki[6] = Point(p.x+dl,p.y+dl,p.z-dl);
	wierzcholki[7] = Point(p.x+dl,p.y+dl,p.z+dl);
}

Cube CubeT::get()const{
	if (macierze.size() == 0) return cube;
	Cube kuba;
	Macierz mnoznik = macierze[0];
	for (int i = 1; i<size;++i) mnoznik = macierze[i]*mnoznik;
	Macierz result(4,1);
	double table[] = {cube.s.x,cube.s.y,cube.s.z,1};
	result.wczytaj(table);
	result = mnoznik*result;
	Point poi(result.element(1,1),result.element(2,1), result.element(3,1));
	kuba.s = poi;
	for (int i = 0; i<8; ++i){
		Macierz result(4,1);
		double table[] = {cube.wierzcholki[i].x,cube.wierzcholki[i].y,cube.wierzcholki[i].z,1};
		result.wczytaj(table);
		result = mnoznik*result;
		Point poi(result.element(1,1),result.element(2,1), result.element(3,1));
		kuba.wierzcholki[i] = poi;
	}
	return kuba;
}

void CubeT::scaleC(double xs, double ys, double zs){
	Macierz result = scaleS(xs,ys,zs);
	++size;
	macierze.push_back(result);
}

void CubeT::scaleC_edit(int place, double xs, double ys, double zs){
	Macierz result = scaleS(xs,ys,zs);
	if (place >= size){
		macierze.push_back(result);
		++size;
	}
	else macierze[place] = result;
}

void CubeT::scaleC_insert(int place, double xs, double ys, double zs){
	Macierz result = scaleS(xs,ys,zs);
	if (place >= size){
		macierze.push_back(result);
		++size;
	}
	else macierze.insert(macierze.begin()+place, result);
}

void CubeT::scaleK(int number,double xs, double ys, double zs){
	if(number<0||number>7)return;
	Point &p = cube.wierzcholki[number];
	Macierz result = Transformator::scale_P(xs,ys,zs,p.x,p.y,p.z);
	++size;
	macierze.push_back(result);
}

void CubeT::scaleK_edit(int place,int number, double xs, double ys, double zs){
	if(number<0||number>7)return;
	Point &p = cube.wierzcholki[number];
	Macierz result = Transformator::scale_P(xs,ys,zs,p.x,p.y,p.z);
	if (place >= size){
		macierze.push_back(result);
		++size;
	}
	else macierze[place] = result;
}

void CubeT::scaleK_insert(int place,int number, double xs, double ys, double zs){
	if(number<0||number>7)return;
	Point &p = cube.wierzcholki[number];
	Macierz result = Transformator::scale_P(xs,ys,zs,p.x,p.y,p.z);
	if (place >= size){
		macierze.push_back(result);
		++size;
	}
	else macierze.insert(macierze.begin()+place, result);
}

Macierz CubeT::scaleS(double xp, double yp, double zp ){
	Cube kuba = get();
	Point &poi = kuba.s;
	Macierz m(4,4);
	m = Transformator::scale_P(xp,yp,zp,poi.x,poi.y,poi.z);
	return m;
}

void CubeT::rotateA(int p1, int p2, double ancle){
	if(p1<0||p1>7||p2<0||p2>7)return;
	Point &pa = cube.wierzcholki[p1];
	Point &pb = cube.wierzcholki[p2];
	Macierz result = Transformator::rotateA(ancle,pa.x,pa.y,pa.z,pb.x,pb.y,pb.z);
	++size;
	macierze.push_back(result);
}

void CubeT::rotateA_edit(int place, int p1, int p2, double ancle){
	if(p1<0||p1>7||p2<0||p2>7)return;
	Point &pa = cube.wierzcholki[p1];
	Point &pb = cube.wierzcholki[p2];
	Macierz result = Transformator::rotateA(ancle,pa.x,pa.y,pa.z,pb.x,pb.y,pb.z);
	if (place >= size){
		macierze.push_back(result);
		++size;
	}
	else macierze[place] = result;
}

void CubeT::rotateA_insert(int place, int p1, int p2, double ancle){
	if(p1<0||p1>7||p2<0||p2>7)return;
	Point &pa = cube.wierzcholki[p1];
	Point &pb = cube.wierzcholki[p2];
	Macierz result = Transformator::rotateA(ancle,pa.x,pa.y,pa.z,pb.x,pb.y,pb.z);
	if (place >= size){
		macierze.push_back(result);
		++size;
	}
	else macierze.insert(macierze.begin()+place, result);
}
