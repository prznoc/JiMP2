#include "interpreter.h"
#include <fstream>
#include <sstream>
#include "drawing.cpp"

using namespace std;

void Interpreter::getfile(){
	string linia;
    fstream plik;
    plik.open("plik.txt", ios::in);
    const uint16_t imgWidth = 800;
	const uint16_t imgHeight = 600;
	JiMP2::BMP bmp(imgWidth, imgHeight);
	int lin = 0;
	int flag;
    if(plik.good() == true){
    	while(!plik.eof()){
    		lin+=1;
    		getline(plik, linia);
    		flag = analyze(linia, bmp, lin);
    		if (flag == 1) break;
		}
	}
	if (flag == 0){
		std::ofstream outfile("test4.bmp", std::ofstream::binary);
		outfile<<bmp;
	}
}

int Interpreter::analyze(string linia, JiMP2::BMP &bmp, int lin){
	istringstream iss(linia);
	string cmd;
	iss>>cmd;
	int flag = 0;
	if (cmd == "L") flag = line(linia,bmp);
	else if (cmd == "C") flag = circle(linia, bmp);
	else if (cmd == "D") flag = disc(linia, bmp);
	else if (cmd == "A") flag = arc(linia, bmp);
	else if (cmd == "S") flag = part(linia, bmp);
	else if (cmd == "#") flag = 0;
	else {
		cout<<"nieznana komenda: linijka "<<lin<<endl;
		return 1;
	}
	if (flag == 1) cout<<"problem: linijka "<<lin<<endl;
	return flag;
	
}

int Interpreter::line(string linia, JiMP2::BMP &bmp){
	double xx1,yy1,xx2,yy2;
	int r,g,b;
	const int size = 8;
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
		return 1;
	}
	istringstream iss(linia);
	char cmd;
	iss>>cmd;
	iss>>xx1>>yy1>>xx2>>yy2>>r>>g>>b;
	if (r>255||r<0, b>255||b<0, g>255||r<g) return 1;
	int x1 = (int) xx1;
	int y1 = (int) yy1;
	int x2 = (int) xx2;
	int y2 = (int) yy2;
	RysownikImplementacja obraz;
	obraz.odcinek(bmp,x1,y1,x2,y2,r,g,b);
	return 0;
}

int Interpreter::circle(string linia, JiMP2::BMP &bmp){
	double aa,cc,pp;
	int r,g,b;
	const int size = 7;
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
		return 1;
	}
	istringstream iss(linia);
	char cmd;
	iss>>cmd;
	iss>>aa>>cc>>pp>>r>>g>>b;
	if (r>255||r<0, b>255||b<0, g>255||r<g) return 1;
	int a = (int) aa;
	int c = (int) cc;
	int p = (int) pp;
	RysownikImplementacja obraz;
	obraz.okrag(bmp,a,c,p,r,g,b);
	return 0;
}

int Interpreter::disc(string linia, JiMP2::BMP &bmp){
	double aa,cc,pp;
	int r,g,b;
	const int size = 7;
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
	istringstream iss(linia);
	char cmd;
	iss>>cmd;
	iss>>aa>>cc>>pp>>r>>g>>b;
	if (r>255||r<0, b>255||b<0, g>255||r<g) return 1;
	int a = (int) aa;
	int c = (int) cc;
	int p = (int) pp;
	RysownikImplementacja obraz;
	obraz.kolo(bmp,a,c,p,r,g,b);
	return 0;
}

int Interpreter::arc(string linia, JiMP2::BMP &bmp){
	double aa,cc,pp, anglea, angleb;
	int r,g,b;
    int size = 9;
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
		return 1;
	}
	istringstream iss(linia);
	char cmd;
	iss>>cmd;
	iss>>aa>>cc>>anglea>>angleb>>pp>>r>>g>>b;
	if (r>255||r<0, b>255||b<0, g>255||r<g) return 1;
	int a = (int) aa;
	int c = (int) cc;
	int p = (int) pp;
	RysownikImplementacja obraz;
	obraz.luk(bmp,a,c,anglea, angleb,p,r,g,b);
	return 0;	
}

int Interpreter::part(string linia, JiMP2::BMP &bmp){
	double aa,cc,pp, anglea, angleb;
	int r,g,b;
	const int size = 9;
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
	istringstream iss(linia);
	char cmd;
	iss>>cmd;
	iss>>aa>>cc>>anglea>>angleb>>pp>>r>>g>>b;
	if (r>255||r<0, b>255||b<0, g>255||r<g) return 1;
	int a = (int) aa;
	int c = (int) cc;
	int p = (int) pp;
	RysownikImplementacja obraz;
	obraz.wycinek(bmp,a,c,anglea, angleb,p,r,g,b);
	return 0;	
}

int main () {
	Interpreter inter;
	inter.getfile();
}
