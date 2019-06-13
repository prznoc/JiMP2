#include "translator.h"


Macierz Transformator::translate(double xx, double yy, double zz)const{
	Macierz transformacja(4,4);
	double tablica2[] = {1,0,0,xx,0,1,0,yy,0,0,1,zz,0,0,0,1};
	transformacja.wczytaj(tablica2);
	return transformacja;
}


Macierz Transformator::scale(double xx, double yy, double zz)const{
	if(xx == 0||yy==0||zz==0)throw;
	Macierz transformacja(4,4);
	double tablica2[] = {xx,0,0,0,0,yy,0,0,0,0,zz,0,0,0,0,1};
	transformacja.wczytaj(tablica2);
	return transformacja;
}

Macierz Transformator::scale_P(double x, double y, double z,double xx, double yy, double zz)const{
	if(xx == 0||yy==0||zz==0)throw;
	Macierz transformacja(4,4), pomoc1(4,4),pomoc2(4,4), result(4,4);
	double tablica2[] = {x,0,0,0,0,y,0,0,0,0,z,0,0,0,0,1};
	transformacja.wczytaj(tablica2);
	pomoc1 = translate(-xx,-yy,-zz);
	pomoc2 = translate(xx,yy,zz);
	result = pomoc2*transformacja*pomoc1;
	return result;
}

Macierz Transformator::rotateX(double kat)const{
	double ancle = kat*M_PI/180;
	Macierz transformacja(4,4);
	double tablica2[] = {1,0,0,0,0,cos(ancle),-sin(ancle),0,0,sin(ancle),cos(ancle),0,0,0,0,1};
	transformacja.wczytaj(tablica2);
	return transformacja;
}


Macierz Transformator::rotateXP(double kat, double yy, double zz)const{
	double ancle = kat*M_PI/180;
	Macierz transformacja(4,4), pomoc1(4,4),pomoc2(4,4), result(4,4);
	double tablica2[] = {1,0,0,0,0,cos(ancle),-sin(ancle),0,0,sin(ancle),cos(ancle),0,0,0,0,1};
	transformacja.wczytaj(tablica2);
	pomoc1 = translate(0,-yy,-zz);
	pomoc2 = translate(0,yy,zz);
	result = pomoc2*transformacja*pomoc1;
	return result;
}


Macierz Transformator::rotateY(double kat)const{
	double ancle = kat*M_PI/180;
	Macierz transformacja(4,4);
	double tablica2[] = {cos(ancle),0,sin(ancle),0,0,1,0,0,-sin(ancle),0,cos(ancle),0,0,0,0,1};
	transformacja.wczytaj(tablica2);
	return transformacja;
	
}

Macierz Transformator::rotateYP(double kat, double xx, double zz)const{
	double ancle = kat*M_PI/180;
	Macierz transformacja(4,4), pomoc1(4,4),pomoc2(4,4), result(4,4);
	double tablica2[] = {cos(ancle),0,sin(ancle),0,0,1,0,0,-sin(ancle),0,cos(ancle),0,0,0,0,1};
	transformacja.wczytaj(tablica2);
	pomoc1 = translate(0,-xx,-zz);
	pomoc2 = translate(0,xx,zz);
	result = pomoc2*transformacja*pomoc1;
	return result;
}

Macierz Transformator::rotateZ(double kat)const{
	double ancle = kat*M_PI/180;
	Macierz transformacja(4,4);
	double tablica2[] = {cos(ancle),-sin(ancle),0,0,sin(ancle),cos(ancle),0,0,0,0,1,0,0,0,0,1};
	transformacja.wczytaj(tablica2);
	return transformacja;
}

Macierz Transformator::rotateZP(double kat, double xx, double yy)const{
	double ancle = kat*M_PI/180;
	Macierz transformacja(4,4), pomoc1(4,4),pomoc2(4,4), result(4,4);
	double tablica2[] = {cos(ancle),-sin(ancle),0,0,sin(ancle),cos(ancle),0,0,0,0,1,0,0,0,0,1};;
	transformacja.wczytaj(tablica2);
	pomoc1 = translate(0,-xx,-yy);
	pomoc2 = translate(0,xx,yy);
	result = pomoc2*transformacja*pomoc1;
	return result;
}


Macierz Transformator::rotateA(double kat, double x1, double y1, double z1, double x2, double y2, double z2)const{
	double ancle = kat*M_PI/180;
	Macierz transformacja(4,4), pomoc1(4,4),pomoc2(4,4), result(4,4);
	double ux,uy,uz,dl;
	ux = x2-x1;
	uy = y2-y1;
	uz = z2-z1;
	dl = sqrt((ux*ux)+uy*uy+uz*uz);
	if (dl == 0){
		double tablica[] = {1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1};
		result.wczytaj(tablica);
		return result;
	}
	ux /=dl;
	uy /=dl;
	uz /=dl;
	double a,b,c,d,e,f,g,h,i;
	a = cos(ancle) + ux*ux*(1-cos(ancle));
	b = ux*uy*(1-cos(ancle)) - uz*sin(ancle);
	c = ux*uz*(1-cos(ancle)) + uy*sin(ancle);
	d = ux*uy*(1-cos(ancle)) + uz*sin(ancle);
	e = cos(ancle) + uy*uy*(1-cos(ancle));
	f = uy*uz*(1-cos(ancle)) - ux*sin(ancle);
	g = uz*ux*(1-cos(ancle)) - uy*sin(ancle);
	h = uz*uy*(1-cos(ancle)) + ux*sin(ancle);
	i = cos(ancle) + uz*uz*(1-cos(ancle));
	double tablica2[] = {a,b,c,0,d,e,f,0,g,h,i,0,0,0,0,1};
	transformacja.wczytaj(tablica2);
	pomoc1 = translate(-x1,-y1,-z1);
	pomoc2 = translate(x1,y1,z1);
	result = pomoc2*transformacja*pomoc1;
	return result;
}

	
