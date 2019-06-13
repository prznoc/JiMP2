#include<iostream>
#include<string>
#include <cmath>

class bigint{
private:
	bool sign;  //True = ujemna;
	
public:
	

	std::string num;
	bigint() {}
	
	bigint (const std::string &s){
		create(s);
	}
	
	bigint (const long int liczba){
		convert(liczba);
	}
	
	bigint operator=(const std::string &s) {
		create(s);
		return *this;
	}
	
	bigint operator=(const long int &liczba) {
		convert(liczba);
		return *this;
	}
	
	bool getsign(){return sign;}

	void inverse(){                   //cyfry jednoœci na pocz¹tku zamiast na koñcu
		int a = num.size();
		for(int i = 1; i<=a/2; ++i){
			std::swap(num[i-1],num[a-i]);
		}
	}
	
	int bezwzg(const bigint &b2)const{                 //porównywanie wartoœci bezwzglêdnych
		if (num.size()>b2.num.size()) return 0;      // 0 -> lewa wiêksza
		if (b2.num.size()>num.size()) return 2;      // 2 -> prawa wiêksza
		if (b2.num.size()==num.size()) {
			for (int i=num.size()-1; i>=0; --i){
				if (num[i]>b2.num[i]) return 0;
				if (num[i]<b2.num[i]) return 2;
			}
			return 1;                      // 1-> s¹ równe
		}
	}
	
	bigint convert(const long int &dana){      //convert z long int to bigint
		long int liczba = dana;
		sign = false;
		num = "";
		if (liczba==0){
			num = "0";
			return *this;
		}
		if (liczba < 0) {
			liczba = liczba*(-1);
			sign = true;
		}
		int reszta;
		int i = 0;
		while (liczba > 0){
			reszta = liczba%10;
			num = num + char(reszta+48);
			liczba = liczba/10;
			++i;
		}
		return *this;
	}
	
	long int convert()const{                 //convert z bigint to long int
	long int wynik = 0;
	for (int k = 0; k<num.size(); ++k ){
		wynik = wynik + (num[k]-48)*pow(10,k);
	}
	if(sign == true) wynik*=-1;
	return wynik;
}
	
	void wypisz(){ 
		if (sign == true) std::cout<<"-";
		for(int i=num.size()-1; i>=0; --i){
			std::cout << num[i];
		} 
		std::cout <<std::endl;
	}

	bool if_zero()const{                    //sprawdza czy jest zerem
		if (num.size() == 1 && num[0] == 48) return true;
		else return false;
	}
	
	void create(const std::string &org){          //tworzy ze stringa
		std::string org2 = org;
		num = "";
		if (org2[0] == 45){
			sign = true;
			for (int i = 0; i<org2.size()-1; ++i){
				org2[i] = org2[i+1];
			}
			org2.erase(org2.size()-1,1);
		}			
		else sign = false;
		for (int j = 0; j<org2.size(); ++j){
			if(org2[j]<48||org2[j]>57) {
				org2.erase(j,1);
				--j;
			}
		}
		num = org2;
		inverse();
	}

	bigint& operator=(const bigint& b2){
		num = b2.num;
		sign = b2.sign;
		return *this;
	}
	
	void reverse(){                        //zmiana znaku
		if (if_zero()==false ) sign = !sign;
	}
	
	bool operator>(const bigint &b2)const{
		if (sign == false && b2.sign == true) return true;
		if (sign == true && b2.sign == false) return false;
		int bez = bezwzg(b2);
		if (bez == 1) return false;
		if (sign == false && bez == 0) return true;
		else if (sign == true && bez == 2) return true;
		else return false;
	}
	
	bool operator<(const bigint &b2)const{
		if (sign == false && b2.sign == true) return false;
		if (sign == true && b2.sign == false) return true;
		int bez = bezwzg(b2);
		if (bez == 1) return false;
		if (sign == false && bez == 2) return true;
		if (sign == true && bez == 0) return true;
		else return false;
	}
	
	bool operator>=(const bigint &b2)const{
		if (sign == false && b2.sign == true) return true;
		if (sign == true && b2.sign == false) return false;
		int bez = bezwzg(b2);
		if (bez == 1) return true;
		if (sign == false && bez == 0) return true;
		if (sign == true && bez == 2) return true;
		else return false;
	}
	
	bool operator<=(const bigint &b2)const{
		if (sign == false && b2.sign == true) return false;
		if (sign == true && b2.sign == false) return true;
		int bez = bezwzg(b2);
		if (bez == 1) return true;
		if (sign == false && bez == 2) return true;
		if (sign == true && bez == 0) return true;
		else return false;
	}
	
	bool operator==(const bigint &b2)const{
		if (sign == b2.sign && bezwzg(b2) == 1) return true;
		else return false;
	}
	
	bool operator!=(const bigint &b2)const{
		if (sign != b2.sign || bezwzg(b2) != 1) return true;
		else return false;
	}
	
	bigint operator+(const bigint &b2)const{
		if (sign != b2.sign){
			bigint pomoc = b2;
			pomoc.reverse();
			return *this-pomoc;
		}
		if (b2.num.size()>num.size()) return b2+*this;
		std::string number1 = num;
		std::string number2 = b2.num;
		std::string result = (number1.size() > number2.size()) ?  number1 : number2;
		int difference = abs( number1.size() - number2.size() );
		int i = 0, c = 0;
		if(number1.size() > number2.size()) number2.insert(number2.size(), difference, '0');
		else number1.insert(number1.size(), difference, '0');
		char d = '0';
		while (i<number2.size() ){
			result[i] = (d-'0')+(number1[i]-'0')+(number2[i]-'0') + '0';
			if(result[i] > '9'){
				result[i] -= 10;
				d = '1';
			}
			else d = '0';
			++i;
		}
		if( d != '0'){
			result.insert(i,1,'1');
		}
		bigint b3(result);
		b3.inverse();
		if (b2.sign == true) b3.sign = true;
		if (b2.sign == false) b3.sign = false;
		return b3;
	}
	
	bigint operator-(const bigint &b2)const{
		bigint b3("");
		if (sign != b2.sign){
			bigint pomoc = b2;
			pomoc.reverse();
			b3 = *this+pomoc;
			return b3;
		}
		int war = bezwzg(b2);
		if (war==1){
			b3.num = "0";
			b3.sign = false;
			return b3;
		}
		if (war == 2){
			b3 = b2 - *this;
			b3.reverse();
			return b3;
		}
		int i = 0, c = 0, d=0;
		int a,b;
		while (i<b2.num.size() || d!=0){
			if (i<num.size()) a = num[i] - 48;
			else a = 0;
			if (i<b2.num.size()) b  = b2.num[i] - 48;
			else b = 0;
			c = a-b-d;
			d = 0;
			while (c<0){
				c += 10;
				d += 1;
			}
			b3.num = b3.num + char(c+48);
			++i;
		}
		while(i<num.size()) {
			b3.num += num[i];
			++i;
		}
		b3.sign = sign;
		return b3;
	}

	bigint operator*(const bigint &b2)const{
		bigint result (0);
		result.sign = false;
		for (int i = 0; i<num.size(); ++i){
			bigint pom = b2.num;
			pom.sign = false;
			int current = num[i]-'0';
			char d = '0';
			int j = 0;
			while(j<b2.num.size()){
				pom.num[j] = ((pom.num[j]-'0') * current) + d;
				d = '0';
				while(pom.num[j] > '9'){
					d += 1;
					pom.num[j] -= 10;
				}
				++j;
			}
			if( d != '0'){
				pom.num.insert(i,1,d);
			}
			pom.num.insert(0,i,'0');
//			std::cout<<pom.num<<std::endl;
			result += pom;
		}
		if (sign != b2.sign) result.sign = true;
		return result;
/*		bigint b3 = *this;
		b3.sign = false;
		if (if_zero() || b2.if_zero()) return b3 = 0;
		for (bigint p("1"); p.bezwzg(b2) == 2; ++p) b3 += *this;
		if (sign != b2.sign) b3.sign = true;
		return b3;*/
	}

	bigint operator/(const bigint &b2)const{
		return dzielenie(b2,0);
	}
	
	bigint operator%(const bigint &b2)const{
		return dzielenie(b2,1);
	}

	bigint dzielenie(const bigint &b2, int flag)const{
		if (b2.if_zero()==true) throw;
		bigint pom("");
		pom.sign = false;
		bigint wynik("");
		wynik.sign = false;
		long int reszta;
		long int a,b = b2.convert(),c;
		for (int i = num.size()-1; i>=0; --i){ 
			pom.num = pom.num + num[i];
			pom.inverse();
			if (pom>=b2){
				a = pom.convert();
				c = a/b;
				wynik.num = wynik.num + char(c+48);
				if (c>9) std::cout<<"blad"<<std::endl;
				reszta = a%b;
				pom.convert(reszta);
			}
			else{
				wynik.num = wynik.num + char(48);
			}
			pom.inverse();	
		}
		while (wynik.num[0] == 48 && wynik.num.size()>1){
			wynik.num.erase(0,1);
		}
		if (sign != b2.sign) wynik.sign = true;
		wynik.inverse();
		if (flag == 1) {
			pom.inverse();
			wynik = pom;
		}
		return wynik;
	}
	
	bigint operator+(long int liczba)const{
	bigint pomoc(liczba), wynik("");
	wynik = *this+pomoc;
	return wynik;
	}
	
	bigint operator-(long int liczba)const{
	bigint pomoc(liczba), wynik("");
	wynik = *this-pomoc;
	return wynik;
	}
	
	bigint operator*(long int liczba)const{
	bigint pomoc(liczba), wynik("");
	wynik = *this*pomoc;
	return wynik;
	}
	
	bigint operator/(long int liczba)const{
	bigint pomoc(liczba), wynik("");
	wynik = *this/pomoc;
	return wynik;
	}
	
	bigint& operator+=(const bigint &b2){
		*this = *this+b2;
		return *this;
	}
	
	bigint& operator-=(const bigint &b2){
		*this = *this-b2;
		return *this;
	}
	
	bigint& operator*=(const bigint &b2){
		*this = *this*b2;
		return *this;
	}
	
	bigint& operator/=(const bigint &b2){
		*this = *this/b2;
		return *this;
	}
	
	bigint& operator+=(const std::string &s){
		bigint b2(s);
		*this = *this+b2;
		return *this;
	}
	
	bigint& operator-=(const std::string &s){
		bigint b2(s);
		*this = *this*b2;
		return *this;
	}
	
	bigint& operator*=(const std::string &s){
		bigint b2(s);
		*this = *this*b2;
		return *this;
	}
	
	bigint& operator/=(const std::string &s){
		bigint b2(s);
		*this = *this/b2;
		return *this;
	}
	
	bigint& operator+=(long int n){
		bigint b2(n);
		*this = *this+b2;
		return *this;
	}
	
	bigint& operator-=(long int n){
		bigint b2(n);
		*this = *this-b2;
		return *this;
	}
	
	bigint& operator*=(long int n){
		bigint b2(n);
		*this = *this*b2;
		return *this;
	}
	
	bigint& operator/=(long int n){
		bigint b2(n);
		*this = *this/b2;
		return *this;
	}
	
	char operator[](const int &liczba){
		return num[liczba - 1];
	}
	
	bigint operator++(){
		return *this+=1;
	}
	
	bigint operator++(int a){
		return *this+=1;
	}
	
	bigint operator--(){
		return *this-=1;
	}
	
	bigint operator--(int a){
		return *this-=1;
	}
	
};


std::ostream& operator<<(std::ostream& os, bigint& b1){
	if (b1.getsign() == true) os<<"-";
		for(int i=b1.num.size()-1; i>=0; --i){
			os << b1.num[i];
		} 
	os<<std::endl;
	return os;
}

bigint operator>>(std::istream& os, bigint& b1){
	std::string a;
	std::cin>>a;
	b1.create(a);
	return b1;
}

int main(){
	bigint b1("1"),por(10),silnia(1);
	for (b1; b1<=por; ++b1){
		silnia = silnia*b1;
		std::cout<<silnia;
}
//std::cout<<silnia;	
/*	bigint b1("457684"), b2(743125);
	bigint b3 = b1+b2;
	std::cout<<b3;*/
}
