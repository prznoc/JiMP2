template <typename T>
class Array{
	private:
		int size = 0;
		T *tablica;
		int max;
		void copy(T *left, T *right);
	public:
		Array(int liczba = 10){
			max  = liczba;
			tablica = new T[max];
		}
		void push_back(const T &dane);
		T pop_back();
		T& operator[](int pos);
		void add(const T dane, int pos);
		int rozmiar()const;
		void clear();
		
		class iterator {
			int number = 1;
			Array<T> &tablica;
		public:
			iterator(Array<T> &p): tablica(p){}
   			iterator(const iterator& other): number(other.number), tablica(other.tablica) {}
   			iterator& operator=(const iterator& other){
   				if(*this!=other)number = other.number;
				return *this;
			   }
   			iterator& operator++(){
   				if(number<tablica.rozmiar()) number++;
				return *this;
			   }
   			iterator& operator++(int){
   				if(number<tablica.rozmiar()) number++;
				return *this;
			   } 
			iterator& operator--(){
   				if(number>1) number--;
				return *this;
			   }
   			iterator& operator--(int){
   				if(number>1) number--;
				return *this;
			   } 
   			bool operator==(const iterator& left) { return number == left.number; }
   			bool operator!=(const iterator& left) { return number != left.number; }
   			T &operator*() {return tablica[number-1];}
   			T operator->() {return tablica[number-1];}
   			iterator operator+(int i){
   			for(int j=0;j<i;++j){
  				*this++;
				}
  	  		}	
  	  		iterator operator-(int i){
   			for(i;i>0;--i){
  				*this--;
  				}
  			}
		};
};

