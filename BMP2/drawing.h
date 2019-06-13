#ifndef  DRAWING_H_
#define _DRAWING_H_

#include "bmp.cpp"

using namespace std;

class Rysownik{
	protected:
		virtual void luk_a(JiMP2::BMP &bmp, double anglea, double angleb,int r, int x1, int y1, int x2, int y2, int a, int b, int flag, int color_R, int color_G, int color_B, int flag_W)=0;
		virtual void luk_b(JiMP2::BMP &bmp, double anglea, double angleb,int r, int x1, int y1, int x2, int y2, int a, int b, int flag, int color_R, int color_G, int color_B, int flag_W)=0;
		virtual void luk_c(JiMP2::BMP &bmp, double anglea, double angleb,int r, int x1, int y1, int x2, int y2, int a, int b, int flag, int color_R, int color_G, int color_B, int flag_W)=0;
		virtual void luk_d(JiMP2::BMP &bmp, double anglea, double angleb,int r, int x1, int y1, int x2, int y2, int a, int b, int flag, int color_R, int color_G, int color_B, int flag_W)=0;
		virtual double radian_convert(double angle)=0;
		virtual int finding_x(int r, double an, double angle)=0;
		virtual int finding_y(int r, double an, double angle)=0;
		virtual double proper_angle(double angle)=0;
		virtual double proper_angle2(double angle)=0;
	public:
		Rysownik();
		virtual ~Rysownik();
		virtual void odcinek(JiMP2::BMP &bmp, int x1, int y1, int x2, int y2, int color_R, int color_G, int color_B)=0;
		virtual void okrag(JiMP2::BMP &bmp, int a, int b, int r, int color_R, int color_G, int color_B)=0;
		virtual void luk(JiMP2::BMP &bmp, int x, int y, double anglea, double angleb, int r, int color_R, int color_G, int color_B)=0;
		virtual void kolo(JiMP2::BMP &bmp,int a, int b, int r, int color_R, int color_G, int color_B)=0;
		virtual void wycinek(JiMP2::BMP &bmp, int x, int y, double anglea, double angleb, int r, int color_R, int color_G, int color_B)=0;
};

class RysownikImplementacja: public Rysownik{
	private:
		 virtual void luk_a(JiMP2::BMP &bmp, double anglea, double angleb,int r, int x1, int y1, int x2, int y2, int a, int b, int flag, int color_R, int color_G, int color_B, int flag_W);
		 virtual void luk_b(JiMP2::BMP &bmp, double anglea, double angleb,int r, int x1, int y1, int x2, int y2, int a, int b, int flag, int color_R, int color_G, int color_B, int flag_W);
		 virtual void luk_c(JiMP2::BMP &bmp, double anglea, double angleb,int r, int x1, int y1, int x2, int y2, int a, int b, int flag, int color_R, int color_G, int color_B, int flag_W);
		 virtual void luk_d(JiMP2::BMP &bmp, double anglea, double angleb,int r, int x1, int y1, int x2, int y2, int a, int b, int flag, int color_R, int color_G, int color_B, int flag_W);
		 virtual double radian_convert(double angle);
		 virtual int finding_x(int r, double an, double angle);
		 virtual int finding_y(int r, double an, double angle);
		 virtual double proper_angle(double angle);
		 virtual double proper_angle2(double angle);
	public:
		 RysownikImplementacja() : Rysownik() {}
		 virtual void odcinek(JiMP2::BMP &bmp, int x1, int y1, int x2, int y2, int color_R, int color_G, int color_B);
		 virtual void okrag(JiMP2::BMP &bmp, int a, int b, int r, int color_R, int color_G, int color_B);
		 virtual void luk(JiMP2::BMP &bmp, int x, int y, double anglea, double angleb, int r, int color_R, int color_G, int color_B);
		 virtual void kolo(JiMP2::BMP &bmp,int a, int b, int r, int color_R, int color_G, int color_B);
		 virtual void wycinek(JiMP2::BMP &bmp, int x, int y, double anglea, double angleb, int r, int color_R, int color_G, int color_B);
		
};

#endif
