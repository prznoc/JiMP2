#include "bmp.h"

#include <cassert>
#include <fstream>
#include <cstring>
#include <cmath>


using namespace std;

namespace JiMP2 {

BMP::BMP(uint16_t width, uint16_t height) :
		bitmapCoreHeader(width, height) {

	assert(IS_LITTLE_ENDIAN);
	assert(width > 0);
	assert(height > 0);

	const unsigned int rowSize = ((bitmapCoreHeader.bitsPerPixel * width + 31)
			/ 32) * 4;
	const unsigned int imgSize = rowSize * height;

	bmpFileHeader.size = 14 + bitmapCoreHeader.size + imgSize;
	bmpFileHeader.dataOffset = 14 + bitmapCoreHeader.size;

	pixelData = new unsigned char[imgSize];
	std::memset(pixelData, 255, imgSize);
}

BMP::~BMP() {
	delete[] pixelData;
}

void BMP::setPixel(uint16_t x, uint16_t y, unsigned char r, unsigned char g,
		unsigned char b) {
	assert(bitmapCoreHeader.bitsPerPixel == 24);

	const size_t rowSize = ((bitmapCoreHeader.bitsPerPixel
			* bitmapCoreHeader.bmpWidth + 31) / 32) * 4;
	const size_t offset = rowSize * (bitmapCoreHeader.bmpHeight - y)
			+ x * (bitmapCoreHeader.bitsPerPixel / 8);

	pixelData[offset + 0] = b;
	pixelData[offset + 1] = g;
	pixelData[offset + 2] = r;
}

uint16_t BMP::getX(){
	return bitmapCoreHeader.bmpWidth;
}

uint16_t BMP::getY(){
	return bitmapCoreHeader.bmpHeight;
}

std::ostream& operator<<(std::ostream& os, const BMP& bmp) {
	os.write(bmp.bmpFileHeader.id, sizeof(bmp.bmpFileHeader.id));
	os.write((const char*) &bmp.bmpFileHeader.size,
			sizeof(bmp.bmpFileHeader.size));
	os.write(bmp.bmpFileHeader.reserved, sizeof(bmp.bmpFileHeader.reserved));
	os.write((const char*) &bmp.bmpFileHeader.dataOffset,
			sizeof(bmp.bmpFileHeader.dataOffset));

	os.write((const char*) &bmp.bitmapCoreHeader.size,
			sizeof(bmp.bitmapCoreHeader.size));
	os.write((const char*) &bmp.bitmapCoreHeader.bmpWidth,
			sizeof(bmp.bitmapCoreHeader.bmpWidth));
	os.write((const char*) &bmp.bitmapCoreHeader.bmpHeight,
			sizeof(bmp.bitmapCoreHeader.bmpHeight));
	os.write((const char*) &bmp.bitmapCoreHeader.colorPlanes,
			sizeof(bmp.bitmapCoreHeader.colorPlanes));
	os.write((const char*) &bmp.bitmapCoreHeader.bitsPerPixel,
			sizeof(bmp.bitmapCoreHeader.bitsPerPixel));

	const unsigned int rowSize = ((bmp.bitmapCoreHeader.bitsPerPixel
			* bmp.bitmapCoreHeader.bmpWidth + 31) / 32) * 4;
	const unsigned int imgSize = rowSize * bmp.bitmapCoreHeader.bmpHeight;

	os.write((const char*) bmp.pixelData, imgSize);

	return os;
}
}


//Point::Point(int x, int y): x(x), y(y){}




/*stack <Point> odci_wyci(JiMP2::BMP &bmp, int x1, int y1, int x2, int y2){
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
	stack <Point> stosp;
	if (szer>=wys){
		if (flag != 1){
			for (int i = ms; i < ws; ++i) {
				bmp.setPixel(i, mw+((i-ms)*float(wys))/szer, 255, 0, 0);
				Point p (i,mw+((i-ms)*float(wys))/szer);
				stosp.push(p);
				
			}
		}
		else{
			for (int i = ms; i < ws; ++i) {
				bmp.setPixel(i, ww-((i-ms)*float(wys))/szer, 255, 0, 0);
				Point p (i, ww-((i-ms)*float(wys))/szer);
				stosp.push(p);
			}
	}
	}
	else {
		if (flag != 1){
			for (int i = mw; i < ww; ++i) {
				bmp.setPixel(ms+((i-mw)*float(szer))/wys, i, 255, 0, 0);
				Point p(ms+((i-mw)*float(szer))/wys, i);
				stosp.push(p);
			}
		}
		else{
			for (int i = mw; i < ww; ++i) {
				bmp.setPixel(ws-((i-mw)*float(szer))/wys, i, 255, 0, 0);
				Point p(ws-((i-mw)*float(szer))/wys, i);
				stosp.push(p);
			}
		}
	}
	if (stosp.empty()==true){
		cout<<"pusty"<<endl;
	}
	return stosp;
}*/


































