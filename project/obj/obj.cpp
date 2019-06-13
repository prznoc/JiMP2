#include "translator.h"


Object ObjT::get()const{
	if (macierze.size() == 0) return obiekt;
	Object obj;
	Macierz mnoznik = macierze[0];
	for (int i = 1; i<size;++i) mnoznik = macierze[i]*mnoznik;
	for (int i = 0; i<obiekt.vertices_size(); ++i){
		Macierz result(4,1);
		double table[] = {obiekt.getVertex(i).getX(),obiekt.getVertex(i).getY(),obiekt.getVertex(i).getZ(),1};
		result.wczytaj(table);
		result = mnoznik*result;
		Point_I poi(result.element(1,1),result.element(2,1), result.element(3,1));
		obj.addPoint(poi);
	}
	for (int i = 0; i<obiekt.faces_size(); ++i) obj.addTriangle(obiekt.getFace(i));
	return obj;
}

void ObjT::rotateXC(double ancle){
	Macierz result = rotateXS(ancle);
	++size;
	macierze.push_back(result);
}

void ObjT::rotateXC_edit(int place, double ancle){
	Macierz result = rotateXS(ancle);
	if (place >= size){
		macierze.push_back(result);
		++size;
	}
	else macierze[place] = result;
}

void ObjT::rotateXC_insert(int place, double ancle){
	Macierz result = rotateYS(ancle);
	if (place >= size){
		macierze.push_back(result);
		++size;
	}
	else macierze.insert(macierze.begin()+place, result);
}

void ObjT::rotateYC(double ancle){
	Macierz result = rotateYS(ancle);
	++size;
	macierze.push_back(result);
}

void ObjT::rotateYC_edit(int place, double ancle){
	Macierz result = rotateYS(ancle);
	if (place >= size){
		macierze.push_back(result);
		++size;
	}
	else macierze[place] = result;
}

void ObjT::rotateYC_insert(int place, double ancle){
	Macierz result = rotateXS(ancle);
	if (place >= size){
		macierze.push_back(result);
		++size;
	}
	else macierze.insert(macierze.begin()+place, result);
}

void ObjT::rotateZC(double ancle){
	Macierz result = rotateZS(ancle);
	++size;
	macierze.push_back(result);
}

void ObjT::rotateZC_edit(int place, double ancle){
	Macierz result = rotateZS(ancle);
	if (place >= size){
		macierze.push_back(result);
		++size;
	}
	else macierze[place] = result;
}

void ObjT::rotateZC_insert(int place, double ancle){
	Macierz result = rotateZS(ancle);
	if (place >= size){
		macierze.push_back(result);
		++size;
	}
	else macierze.insert(macierze.begin()+place, result);
}

void ObjT::scaleC(double xs, double ys, double zs){
	Macierz result = scaleS(xs,ys,zs);
	++size;
	macierze.push_back(result);
}

void ObjT::scaleC_edit(int place, double xs, double ys, double zs){
	Macierz result = scaleS(xs,ys,zs);
	if (place >= size){
		macierze.push_back(result);
		++size;
	}
	else macierze[place] = result;
}

void ObjT::scaleC_insert(int place, double xs, double ys, double zs){
	Macierz result = scaleS(xs,ys,zs);
	if (place >= size){
		macierze.push_back(result);
		++size;
	}
	else macierze.insert(macierze.begin()+place, result);
}

Macierz ObjT::rotateXS(double ancle)const{
	Object obi = get();
	Point_I poi = obi.getS();
	Macierz m(4,4);
	m = Transformator::rotateA(ancle,poi.getX(),poi.getY(),poi.getZ(),poi.getX()+2,poi.getY(),poi.getZ());
	return m;
}

Macierz ObjT::rotateYS(double ancle)const{
	Object obi = get();
	Point_I poi = obi.getS();
	Macierz m(4,4);
	m = Transformator::rotateA(ancle,poi.getX(),poi.getY(),poi.getZ(),poi.getX(),poi.getY()+2,poi.getZ());
	return m;
}

Macierz ObjT::rotateZS(double ancle)const{
	Object obi = get();
	Point_I poi = obi.getS();
	Macierz m(4,4);
	m = Transformator::rotateA(ancle,poi.getX(),poi.getY(),poi.getZ(),poi.getX(),poi.getY(),poi.getZ()+2);
	return m;
}

Macierz ObjT::scaleS(double xp, double yp, double zp ){
	Object obi = get();
	Point_I poi = obi.getS();
	Macierz m(4,4);
	m = Transformator::scale_P(xp,yp,zp,poi.getX(),poi.getY(),poi.getZ());
	return m;
}
