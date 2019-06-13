#include "drawing.h"

#include <iostream>
#include <fstream>
#include <cstring>
#define M_PI 3.14159265358979323846


using namespace std;

Rysownik::Rysownik(){}
Rysownik::~Rysownik(){}

void RysownikImplementacja::odcinek(JiMP2::BMP &bmp, int x1, int y1, int x2, int y2,int color_R, int color_G, int color_B){
	int ms = x1, ws = x2, mw = y1, ww = y2;
	int flag=0;	
	if (ms>ws) {
		swap(ms,ws);
		flag += 1;
	}
	if (mw>ww) {
		swap(mw,ww);
		flag += 1;
	}
	int wys = ww - mw;
	int szer = ws - ms;
	int borX = bmp.getX();
    int borY = bmp.getY();
	if (szer>=wys){
		if (flag != 1){
			for (int i = ms; i < ws; ++i) {
				if((i)<=borX&&(i)>=0&&(mw+((i-ms)*float(wys))/szer)<=borY&&(mw+((i-ms)*float(wys))/szer)>=0)bmp.setPixel(i, mw+((i-ms)*float(wys))/szer, color_R, color_G, color_B);
			}
		}
		else{
			for (int i = ms; i < ws; ++i) {
				if((i)<=borX&&(i)>=0&&(ww-((i-ms)*float(wys))/szer)<=borY&&(ww-((i-ms)*float(wys))/szer)>=0)bmp.setPixel(i, ww-((i-ms)*float(wys))/szer, color_R, color_G, color_B);
			}
	}
	}
	else {
		if (flag != 1){
			for (int i = mw; i < ww; ++i) {
				if((ms+((i-mw)*float(szer))/wys)<=borX&&(ms+((i-mw)*float(szer))/wys)>=0&&(i)<=borY&&(i)>=0)bmp.setPixel(ms+((i-mw)*float(szer))/wys, i, color_R, color_G, color_B);
			}
		}
		else{
			for (int i = mw; i < ww; ++i) {
				if((ws-((i-mw)*float(szer))/wys)<=borX&&(ws-((i-mw)*float(szer))/wys)>=0&&(i)<=borY&&(i)>=0)bmp.setPixel(ws-((i-mw)*float(szer))/wys, i, color_R, color_G, color_B);
			}
		}
	}
}

void RysownikImplementacja::okrag(JiMP2::BMP &bmp, int a, int b, int r, int color_R, int color_G, int color_B){
	int borX = bmp.getX();
    int borY = bmp.getY();
	int x = r-1;
    int y = 0;
    int dx = 1;
    int dy = 1;
    int err = dx - (r << 1);
	while(x>=y){
		if (a+x>=0&&a+x<=borX&&b+y>=0&&b+y<=borY)bmp.setPixel(a+x,b+y,color_R, color_G, color_B);
		if (a+y>=0&&a+y<=borX&&b+x>=0&&b+x<=borY)bmp.setPixel(a+y,b+x,color_R, color_G, color_B);
		if (a-y>=0&&a-y<=borX&&b+x>=0&&b+x<=borY)bmp.setPixel(a-y,b+x,color_R, color_G, color_B);
		if (a-x>=0&&a-x<=borX&&b+y>=0&&b+y<=borY)bmp.setPixel(a-x,b+y,color_R, color_G, color_B);
		if (a-x>=0&&a-x<=borX&&b-y>=0&&b-y<=borY)bmp.setPixel(a-x,b-y,color_R, color_G, color_B);
		if (a-y>=0&&a-y<=borX&&b-x>=0&&b-x<=borY)bmp.setPixel(a-y,b-x,color_R, color_G, color_B);
		if (a+y>=0&&a+y<=borX&&b-x>=0&&b-x<=borY)bmp.setPixel(a+y,b-x,color_R, color_G, color_B);
		if (a+x>=0&&a+x<=borX&&b-y>=0&&b-y<=borY)bmp.setPixel(a+x,b-y,color_R, color_G, color_B);
		if (err <= 0){
			++y;
			err += dy;
            dy += 2;
        } 
        if (err > 0){
            --x;
            dx += 2;
            err += dx - (r << 1);
        }
	}
}
	
double RysownikImplementacja::radian_convert(double angle){
	double pi = M_PI;
	angle = angle*(M_PI/180);
	return angle;
}
	
int RysownikImplementacja::finding_x(int r, double an, double angle){
	double xp = sin(radian_convert(an))*r;
	xp = round(xp);
	int x = (int) xp;
	if ((angle>270)||(angle>180&&angle<=270)) x = x*(-1);
	return x;
}
	
int RysownikImplementacja::finding_y(int r, double an, double angle){
	double yp = cos(radian_convert(an))*r;
	yp = round(yp);
	int y = (int) yp;
	if ((angle>90&&angle<=180)||(angle>180&&angle<=270)) y = y*(-1);
	return y;
}

double RysownikImplementacja::proper_angle(double angle){
	while (angle > 360) angle = angle - 360;
	while (angle < 0) angle = angle + 360; 
	return angle;
}

double RysownikImplementacja::proper_angle2(double angle){
	if (angle>90 && angle<=180) angle = 180-angle;
	if (angle>180 && angle<=270) angle = angle - 180;
	if (angle>270) angle = 360 - angle; 
	return angle;
}

void RysownikImplementacja::luk_a(JiMP2::BMP &bmp, double anglea, double angleb,int r, int x1, int y1, int x2, int y2, int a, int b, int flag, int color_R, int color_G, int color_B, int flag_W){
	int xp = x1, yp = y1, xk = x2, yk = y2;
	int beta_flag = 0;
	int gamma_flag = 0;
	if(anglea>90){
		xp = a;
		yp = b-r;
		beta_flag +=1;
	}
	if(angleb>90){
		xk = a+r;
		yk = b;
		beta_flag +=1;
	}
	if (beta_flag == 0 && flag == 0 && anglea>angleb){
		xk = a+r;
		yk = b;
		gamma_flag+=1;
	}
	if (beta_flag == 0 && flag == 4 && anglea>angleb){
		xp = a;
		yp = b-r;
	}
	int x = r-1;
    int y = 0;
    int dx = 1;
    int dy = 1;
    int err = dx - (r << 1);
    int borX = bmp.getX();
    int borY = bmp.getY();
	while(x>=y){
		if ((a+y)>=xp&&(b-x)>=yp&&(a+y)<=xk&&(b-x)<=yk){
			if((a+y)<=borX&&(a+y)>=0&&(b-x)<=borY&&(b-x)>=0)bmp.setPixel(a+y,b-x,color_R, color_G, color_B);
			if(flag_W == 1){
				odcinek(bmp, a,b,a+y,b-x,color_R, color_G, color_B);
			}
		}
		if ((a+x)>=xp&&(b-y)>=yp&&(a+x)<=xk&&(b-y)<=yk){
			if ((a+x)<=borX&&(a+x)>=0&&(b-y)<=borY&&(b-y)>=0)bmp.setPixel(a+x,b-y,color_R, color_G, color_B);
			if(flag_W == 1){
				odcinek(bmp, a,b,a+x,b-y,color_R, color_G, color_B);
			}
		}
		if (err <= 0){
			++y;
			err += dy;
            dy += 2;
        } 
        if (err > 0){
            --x;
            dx += 2;
            err += dx - (r << 1);
        }
	}
	flag +=1;
	if (angleb>90||gamma_flag==1) luk_b(bmp,anglea, angleb,r, x1,y1,x2,y2,a,b,flag, color_R, color_G, color_B,flag_W);
}

void RysownikImplementacja::luk_b(JiMP2::BMP &bmp, double anglea, double angleb,int r, int x1, int y1, int x2, int y2, int a, int b, int flag, int color_R, int color_G, int color_B, int flag_W){
	int xp = x1, yp = y1, xk = x2, yk = y2;
	int beta_flag = 0;
	int gamma_flag = 0;
	if(anglea<=90||anglea>180){
		xp = a+r;
		yp = b;
		beta_flag +=1;
	}
	if(angleb<=90||angleb>180){
		xk = a;
		yk = b+r;
		beta_flag +=1;
	}
	if (beta_flag == 0 && flag == 0 && anglea>angleb){
		xk = a;
		yk = b+r;
		gamma_flag+=1;
	}
	if (beta_flag == 0 && flag == 4 && anglea>angleb){
		xp = a+r;
		yp = b;
	}
	int x = r-1;
    int y = 0;
    int dx = 1;
    int dy = 1;
    int err = dx - (r << 1);
    int borX = bmp.getX();
    int borY = bmp.getY();
	while(x>=y){
		if ((a+x)<=xp&&(b+y)>=yp&&(a+x)>=xk&&(b+y)<=yk) {
			if ((a+x)<=borX&&(a+x)>=0&&(b+y)<=borY&&(b+y)>=0)bmp.setPixel(a+x,b+y,color_R, color_G, color_B);
			if(flag_W == 1){
				odcinek(bmp, a,b,a+x,b+y,color_R, color_G, color_B);
			}
		}	
		if ((a+y)<=xp&&(b+x)>=yp&&(a+y)>=xk&&(b+x)<=yk) {
			if((a+y)<=borX&&(a+y)>=0&&(b+x)<=borY&&(b+x)>=0)bmp.setPixel(a+y,b+x,color_R, color_G, color_B);
			if(flag_W == 1){
				odcinek(bmp, a,b,a+y,b+x,color_R, color_G, color_B);
			}
		}
		if (err <= 0){
			++y;
			err += dy;
            dy += 2;
        } 
        if (err > 0){
            --x;
            dx += 2;
            err += dx - (r << 1);
        }
	}
	flag +=1;
	if (angleb<=90||angleb>180||gamma_flag==1) luk_c(bmp,anglea, angleb,r, x1,y1,x2,y2,a,b, flag, color_R, color_G, color_B, flag_W);
}

void RysownikImplementacja::luk_c(JiMP2::BMP &bmp, double anglea, double angleb,int r, int x1, int y1, int x2, int y2, int a, int b, int flag, int color_R, int color_G, int color_B, int flag_W){
	int xp = x1, yp = y1, xk = x2, yk = y2;
	int beta_flag = 0;
	int gamma_flag = 0;
	if(anglea<=180||anglea>270){
		xp = a;
		yp = b+r;
		beta_flag +=1;
	}
	if(angleb<=180||angleb>270){
		xk = a-r;
		yk = b;
		beta_flag +=1;
	}
	if (beta_flag == 0 && flag == 0 && anglea>angleb){
		xk = a-r;
		yk = b;
		gamma_flag+=1;
	}
	if (beta_flag == 0 && flag == 4 && anglea>angleb){
		xp = a;
		yp = b+r;
	}
	int x = r-1;
    int y = 0;
    int dx = 1;
    int dy = 1;
    int err = dx - (r << 1);
    int borX = bmp.getX();
    int borY = bmp.getY();
	while(x>=y){
		if ((a-y)<=xp&&(b+x)<=yp&&(a-y)>=xk&&(b+x)>=yk){
			if((a-y)<=borX&&(a-y)>=0&&(b+x)<=borY&&(b+x)>=0)bmp.setPixel(a-y,b+x,color_R, color_G, color_B);
			if(flag_W == 1){
				odcinek(bmp, a,b,a-y,b+x,color_R, color_G, color_B);
			}
		}
		if ((a-x)<=xp&&(b+y)<=yp&&(a-x)>=xk&&(b+y)>=yk){
			if((a-x)<=borX&&(a-x)>=0&&(b+y)<=borY&&(b+y)>=0)bmp.setPixel(a-x,b+y,color_R, color_G, color_B);
			if(flag_W == 1){
				odcinek(bmp, a,b,a-x,b+y,color_R, color_G, color_B);
			}
		}
		if (err <= 0){
			++y;
			err += dy;
            dy += 2;
        } 
        if (err > 0){
            --x;
            dx += 2;
            err += dx - (r << 1);
        }
	}
	flag += 1;
	if (angleb<=180||angleb>270||gamma_flag==1) luk_d(bmp,anglea, angleb,r, x1,y1,x2,y2,a,b, flag, color_R, color_G, color_B, flag_W);
}

void RysownikImplementacja::luk_d(JiMP2::BMP &bmp, double anglea, double angleb,int r, int x1, int y1, int x2, int y2, int a, int b, int flag, int color_R, int color_G, int color_B, int flag_W){
	int xp = x1, yp = y1, xk = x2, yk = y2;
	int beta_flag = 0;
	int gamma_flag = 0;
	if(anglea<270){
		xp = a-r;
		yp = b;
		beta_flag +=1;
	}
	if(angleb<270){
		xk = a;
		yk = b-r;
		beta_flag +=1;
	}
	if (beta_flag == 0 && flag == 0 && anglea>angleb){
		xk = a;
		yk = b-r;
		gamma_flag+=1;
	}
	if (beta_flag == 0 && flag == 4 && anglea>angleb){
		xp = a-r;
		yp = b;
	}
	int x = r-1;
    int y = 0;
    int dx = 1;
    int dy = 1;
    int err = dx - (r << 1);
    int borX = bmp.getX();
    int borY = bmp.getY();
	while(x>=y){
		if ((a-x)>=xp&&(b-y)<=yp&&(a-x)<=xk&&(b-y)>=yk){
			if((a-x)<=borX&&(a-x)>=0&&(b-y)<=borY&&(b-y)>=0)bmp.setPixel(a-x,b-y,color_R, color_G, color_B);
			if(flag_W == 1){
				odcinek(bmp, a,b,a-x,b-y,color_R, color_G, color_B);
			}
		}
		if ((a-y)>=xp&&(b-x)<=yp&&(a-y)<=xk&&(b-x)>=yk){
		if((a-y)<=borX&&(a-y)>=0&&(b-x)<=borY&&(b-x)>=0)bmp.setPixel(a-y,b-x,color_R, color_G, color_B);
		if(flag_W == 1){
				odcinek(bmp, a,b,a-y,b-x,color_R, color_G, color_B);
			}
		}
		if (err <= 0){
			++y;
			err += dy;
            dy += 2;
        } 
        if (err > 0){
            --x;
            dx += 2;
            err += dx - (r << 1);
        }
	}
	flag += 1;
	if (angleb<270||gamma_flag==1) luk_a(bmp,anglea, angleb,r, x1,y1,x2,y2,a,b, flag, color_R, color_G, color_B, flag_W);

}

void RysownikImplementacja::luk(JiMP2::BMP &bmp, int x, int y, double anglea, double angleb, int r, int color_R, int color_G, int color_B){ 
	if(anglea > 360||anglea<0) anglea = proper_angle(anglea);
	if(angleb > 360||angleb<0) angleb = proper_angle(angleb);
	double anaa = anglea;
	double anbb = angleb;
	anaa = proper_angle2(anaa);
	anbb = proper_angle2(anbb);
	int x1, y1, x2, y2;
	x1 = x + finding_x(r, anaa, anglea);
	y1 = y - finding_y(r, anaa, anglea);
	x2 = x + finding_x(r, anbb, angleb);
	y2 = y - finding_y(r, anbb, angleb);
	if (anglea < 90) luk_a(bmp,anglea, angleb,r, x1,y1,x2,y2,x,y,0, color_R, color_G, color_B, 0);
	if (anglea > 90&&anglea<=180) luk_b(bmp,anglea, angleb,r, x1,y1,x2,y2,x,y,0, color_R, color_G, color_B, 0);
	if (anglea > 180&&anglea<=270) luk_c(bmp,anglea, angleb,r, x1,y1,x2,y2,x,y,0, color_R, color_G, color_B, 0);
	if (anglea > 270) luk_d(bmp,anglea, angleb,r, x1,y1,x2,y2,x,y,0, color_R, color_G, color_B, 0);

}

void RysownikImplementacja::kolo(JiMP2::BMP &bmp,int a, int b, int r, int color_R, int color_G, int color_B){
	int borX = bmp.getX();
    int borY = bmp.getY();
	for (int x=a-r; x<=a+r; ++x){
		for(int y=b-r; y<=b+r;++y){
			if (((x-a)*(x-a)+(y-b)*(y-b))<=(r*r)&&(x)<=borX&&(x)>=0&&(y)<=borY&&(y)>=0){
				bmp.setPixel(x,y, color_R, color_G, color_B);
			}
		}
	}
}

void RysownikImplementacja::wycinek(JiMP2::BMP &bmp, int x, int y, double anglea, double angleb, int r, int color_R, int color_G, int color_B){
	if(anglea > 360||anglea<0) anglea = proper_angle(anglea);
	if(angleb > 360||angleb<0) angleb = proper_angle(angleb);
	double anaa = anglea;
	double anbb = angleb;
	anaa = proper_angle2(anaa);
	anbb = proper_angle2(anbb);
	int x1, y1, x2, y2;
	x1 = x + finding_x(r, anaa, anglea);
	y1 = y - finding_y(r, anaa, anglea);
	x2 = x + finding_x(r, anbb, angleb);
	y2 = y - finding_y(r, anbb, angleb);

	if (anglea < 90) luk_a(bmp,anglea, angleb,r, x1,y1,x2,y2,x,y,0, color_R, color_G, color_B, 1);
	if (anglea > 90&&anglea<=180) luk_b(bmp,anglea, angleb,r, x1,y1,x2,y2,x,y,0, color_R, color_G, color_B, 1);
	if (anglea > 180&&anglea<=270) luk_c(bmp,anglea, angleb,r, x1,y1,x2,y2,x,y,0, color_R, color_G, color_B, 1);
	if (anglea > 270) luk_d(bmp,anglea, angleb,r, x1,y1,x2,y2,x,y,0, color_R, color_G, color_B, 1);
}
	

