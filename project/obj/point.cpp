#include "translator.h"

void PointT::translate(double x, double y, double z){
	++size;
	Macierz result = Transformator::translate(x,y,z);
	macierze.push_back(result);
}

void PointT::translate_edit(int place, double x, double y, double z){
	Macierz result = Transformator::translate(x,y,z);
	if (place >= size){
		macierze.push_back(result);
		++size;
	}
	else macierze[place] = result;
}

void PointT::translate_insert(int place, double x, double y, double z){
	Macierz result = Transformator::translate(x,y,z);
	if (place >= size){
		macierze.push_back(result);
		++size;
	}
	else macierze.insert(macierze.begin()+place, result);
}

void PointT::scale(double x, double y, double z){
	Macierz result = Transformator::scale(x,y,z);
	++size;
	macierze.push_back(result); 
}

void PointT::scale_edit(int place, double x, double y, double z){
	Macierz result = Transformator::scale(x,y,z);
	if (place >= size){
		macierze.push_back(result);
		++size;
	}
	else macierze[place] = result;
}

void PointT::scale_insert(int place, double x, double y, double z){
	Macierz result = Transformator::scale(x,y,z);
	if (place >= size){
		macierze.push_back(result);
		++size;
	}
	else macierze.insert(macierze.begin()+place, result);
}

void PointT::rotateX(double ancle){
	Macierz result = Transformator::rotateX(ancle);
	++size;
	macierze.push_back(result);
}

void PointT::rotateX_edit(int place, double ancle){
	Macierz result = Transformator::rotateX(ancle);
	if (place >= size){
		macierze.push_back(result);
		++size;
	}
	else macierze[place] = result;
}

void PointT::rotateX_insert(int place, double ancle){
	Macierz result = Transformator::rotateX(ancle);
	if (place >= size){
		macierze.push_back(result);
		++size;
	}
	else macierze.insert(macierze.begin()+place, result);
}

void PointT::rotateXP(double ancle, double yy, double zz){
	Macierz result = Transformator::rotateXP(ancle,yy,zz);
	++size;
	macierze.push_back(result);
}

void PointT::rotateXP_edit(int place, double ancle, double yy, double zz){
	Macierz result = Transformator::rotateXP(ancle,yy,zz);
	if (place >= size){
		macierze.push_back(result);
		++size;
	}
	else macierze[place] = result;
}

void PointT::rotateXP_insert(int place, double ancle, double yy, double zz){
	Macierz result = Transformator::rotateXP(ancle,yy,zz);
	if (place >= size){
		macierze.push_back(result);
		++size;
	}
	else macierze.insert(macierze.begin()+place, result);
}

void PointT::rotateY(double ancle){
	Macierz result = Transformator::rotateY(ancle);
	++size;
	macierze.push_back(result);
}

void PointT::rotateY_edit(int place, double ancle){
	Macierz result = Transformator::rotateY(ancle);
	if (place >= size){
		macierze.push_back(result);
		++size;
	}
	else macierze[place] = result;
}

void PointT::rotateY_insert(int place, double ancle){
	Macierz result = Transformator::rotateY(ancle);
	if (place >= size){
		macierze.push_back(result);
		++size;
	}
	else macierze.insert(macierze.begin()+place, result);
}

void PointT::rotateYP(double ancle, double xx, double zz){
	Macierz result = Transformator::rotateYP(ancle,xx,zz);
	++size;
	macierze.push_back(result);
}

void PointT::rotateYP_edit(int place, double ancle, double xx, double zz){
	Macierz result = Transformator::rotateYP(ancle,xx,zz);
	if (place >= size){
		macierze.push_back(result);
		++size;
	}
	else macierze[place] = result;
}

void PointT::rotateYP_insert(int place, double ancle, double xx, double zz){
	Macierz result = Transformator::rotateYP(ancle,xx,zz);
	if (place >= size){
		macierze.push_back(result);
		++size;
	}
	else macierze.insert(macierze.begin()+place, result);
}

void PointT::rotateZ(double ancle){
	Macierz result = Transformator::rotateZ(ancle);
	++size;
	macierze.push_back(result);
}

void PointT::rotateZ_edit(int place, double ancle){
	Macierz result = Transformator::rotateZ(ancle);
	if (place >= size){
		macierze.push_back(result);
		++size;
	}
	else macierze[place] = result;
}

void PointT::rotateZ_insert(int place, double ancle){
	Macierz result = Transformator::rotateZ(ancle);
	if (place >= size){
		macierze.push_back(result);
		++size;
	}
	else macierze.insert(macierze.begin()+place, result);
}

void PointT::rotateZP(double ancle, double yy, double zz){
	Macierz result = Transformator::rotateZP(ancle,yy,zz);
	++size;
	macierze.push_back(result);
}

void PointT::rotateZP_edit(int place, double ancle, double xx, double yy){
	Macierz result = Transformator::rotateZP(ancle,xx,yy);
	if (place >= size){
		macierze.push_back(result);
		++size;
	}
	else macierze[place] = result;
}

void PointT::rotateZP_insert(int place, double ancle, double xx, double yy){
	Macierz result = Transformator::rotateZP(ancle,xx,yy);
	if (place >= size){
		macierze.push_back(result);
		++size;
	}
	else macierze.insert(macierze.begin()+place, result);
}


void PointT::scale_P(double x, double y, double z, double xp, double yp, double zp){
	Macierz result = Transformator::scale_P(x,y,z,xp,yp,zp);
	++size;
	macierze.push_back(result);
}

void PointT::scale_P_edit(int place, double x, double y, double z, double xp, double yp, double zp){
	Macierz result = Transformator::scale_P(x,y,z,xp,yp,zp);
	if (place >= size){
		macierze.push_back(result);
		++size;
	}
	else macierze[place] = result;
}

void PointT::scale_P_insert(int place, double x, double y, double z, double xp, double yp, double zp){
	Macierz result = Transformator::scale_P(x,y,z,xp,yp,zp);
	if (place >= size){
		macierze.push_back(result);
		++size;
	}
	else macierze.insert(macierze.begin()+place, result);
}

void PointT::rotateA(double ancle, double x1, double y1, double z1, double x2, double y2, double z2){
	Macierz result = Transformator::rotateA(ancle,x1,y1,z1,x2,y2,z2);
	++size;
	macierze.push_back(result); 
}

void PointT::rotateA_edit(int place, double ancle, double x1, double y1, double z1, double x2, double y2, double z2){
	Macierz result = Transformator::rotateA(ancle,x1,y1,z1,x2,y2,z2);
	if (place >= size){
		macierze.push_back(result);
		++size;
	}
	else macierze[place] = result;
}

void PointT::rotateA_insert(int place, double ancle, double x1, double y1, double z1, double x2, double y2, double z2){
	Macierz result = Transformator::rotateA(ancle,x1,y1,z1,x2,y2,z2);
	if (place >= size){
		macierze.push_back(result);
		++size;
	}
	else macierze.insert(macierze.begin()+place, result);
}

void PointT::remove(int place){
	if (place >= size) return;
	else {
		macierze.erase (macierze.begin()+place);
		--size;
	}
}

Point PointT::get(){
	if (macierze.size() == 0) return p;
	Macierz result(4,1);
	double table[] = {p.x,p.y,p.z,1};
	result.wczytaj(table);
	Macierz mnoznik = macierze[0];
	for (int i = 1; i<size;++i) mnoznik = macierze[i]*mnoznik;
	result = mnoznik*result;
	Point point(result.element(1,1),result.element(2,1), result.element(3,1));
	return point;
}
