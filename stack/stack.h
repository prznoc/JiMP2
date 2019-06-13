template<typename T>
struct Node{
	T elem;
	Node *prev;
	Node():elem(NULL), prev(NULL){}
	Node(T &value):elem(value),prev(NULL){}
	};

template<typename T>
class Stos {
	private:
		Node<T> *top = NULL;
		int size = 0;
 	public:
    	void push(T cos);
    	T pop();
    	bool is_empty()const;
    	void clear();
    	int rozmiar()const;
    	
    	
    class iterator {
			Node <T> *itr;
			Stos<T> &stack;
		public:
			iterator(Stos<T> &p): itr(p.top()), stack(p){}
   			iterator(const iterator& other): itr(other.itr), stack(other.stack) {}
   			iterator& operator=(const iterator& other){
   				if(*this!=other)itr = other.itr;
				return *this;
			   }
			iterator& operator--(){
   					if(itr->prev) itr = itr->prev;
					return *this;
			   }
   			iterator& operator--(int){
   					if(itr->prev) itr = itr->prev;
					return *this;
			   } 
   			bool operator==(const iterator& left) { return itr == left.itr; }
   			bool operator!=(const iterator& left) { return itr != left.itr; }
   			T& operator*() {return itr->elem;}
   			T& operator->() {return itr->elem;}
  	 		iterator operator-(int i){
   			for(i;i>0;--i){
  				--*this;
  				}
  			}
		};
}; 

