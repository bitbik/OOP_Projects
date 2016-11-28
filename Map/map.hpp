#ifndef	__MAP_H__
#define	__MAP_H__

#include<stdexcept>
#include <stdlib.h>
#include <initializer_list>

//#include<iostream>
//#include<sstream>
//#include<string>


namespace  cs540{

template <typename Key, typename Value>
class Map{

		
		using value_type = std::pair<const Key, Value>;//_to avoid repetition

		class Node;//_Node
		public://_three kinds of iterators
			class Iterator;
			class ConstIterator;
			class ReverseIterator;	

	private:
	class Node{
		//define the struct of the Node, to 
			friend class Map<Key, Value>;
		
		private:
			Node* nparent;
			Node* nright;
			Node* nleft;			
			Node* next;
			Node* previous;
			value_type nv;
			int status;//-1 means it's the begin or the end of the tree
			
			Node(const value_type &val): nv(val){
				nparent = nullptr;
				nright = nullptr;
				nleft = nullptr;
				previous = nullptr;
				next = nullptr;
					
			};
			
			Node(value_type &&val): nv(std::move(val)){
				nparent = nullptr;
				nright = nullptr;
				nleft = nullptr;
				previous = nullptr;
				next = nullptr;
				
			};

		};//end of Node


			
	public:



			//Map<Key, Value>::Iterator

			//Iterator(const Iterator&);
			///////////////////////////////////////
			//Iterator& operator=(const Iterator&);
			//Iterator(Iterator&&);
			//Iterator& operator=(Iterator&&);
			//~Iterator();
			///////////////////////////////////////
			
			//Iterator& operator++();
			//Iterator operator++(int);
			//Iterator& operator--();
			//Iterator operator--(int);
			//std::pair<const Key, Value>& operator*() const;

	class Iterator{

				friend class Map<Key, Value>;

				public:

				//Iterator(Node* refIn) { ref = refIn; }
				//Iterator() { ref = NULL; }
			
				Iterator(){

					current  = nullptr;

				}//Iterator(const Iterator&), copy ctor

				//yiwen
				Iterator(Node* new_node) {
					current = new_node;
				}
	
				Iterator& operator++(){
					current = current ->next;
					return *this;
				}//Iterator& operator++();


				Iterator operator++(int){

					Iterator iter(*this);
					current = current ->next;
					return iter;

				}//Iterator operator++(int);

				Iterator& operator--(){
					current = current->previous;
					return *this;
				}//Iterator& operator--();

				Iterator operator--(int){
					Iterator iter(*this);
					current = current->previous;
					return iter;
				}//Iterator operator--(int);

				
				//Iterator comparisons

				bool operator==(const Iterator &iter){

					if (current == nullptr && iter.current  != nullptr){

						if (iter.current ->status == -1)	return true;
					
					}
						
					if (current != nullptr && iter.current  == nullptr){

						if (current -> status == -1)	return true;
					}
					
					if (current  == iter.current)

						return true;
					else
						return false ;

				}//bool operator==(const Iterator&, const Iterator&);



				bool operator!=(const Iterator &iter){

					if (current  == iter.current)
						return false;
					else 
						return true; 
					
				}//bool operator!=(const Iterator&, const Iterator&);


				bool operator==(const ConstIterator &const_iter){

					if (current  == nullptr && const_iter.current != nullptr){

						if (const_iter.current ->status == -1)	return true;
					}

						
					if ( current != nullptr && const_iter.current   == nullptr){
						if (current -> status == -1)	return true;

					}

					if (current   == const_iter.current)
						return true;
					else
						return false; 
				}//bool operator==(const Iterator&, const ConstIterator&)

				bool operator!=(const ConstIterator &const_iter){

					if (current  == const_iter.current)

						return false;
					else 
						return true; 

				}//bool operator!=(const Iterator&, const ConstIterator&)

				//std::pair<Key_T,Mapped_T> &operator*() const;
				value_type& operator*() const{

					return current->nv;

				};//std::pair<const Key, Value>& operator*() const, Returns a reference to the key-value pair the Iterator is pointing to
	

			private:
				Node* current;


		};//end of class Iterator


			//Map<Key, Value>::ReverseIterator

			///////////////////////////////////////

			//ReverseIterator(const ReverseIterator&);
			//ReverseIterator& operator=(const ReverseIterator&);
			//ReverseIterator(ReverseIterator&&);
			//ReverseIterator& operator=(ReverseIterator&&);
			//~ReverseIterator();
			/////////////////////////////////////////

			
			//ReverseIterator& operator++();
			//ReverseIterator operator++(int);
			//ReverseIterator& operator--();
			//ReverseIterator operator--(int);
			//std::pair<const Key, Value>& operator*() const;


	class ReverseIterator{
			
				friend class Map<Key, Value>;
				
			public:
	
				ReverseIterator(){
					current  = nullptr;	
				}
				//yiwen
				ReverseIterator(Node* new_node) {
					current = new_node; 
				}
				
				ReverseIterator& operator++(){

					current = current ->previous;
					return *this;
				
				}
				
				ReverseIterator operator++(int){

					ReverseIterator reverse_iter(*this);
					current = current ->previous;
					return reverse_iter;
				}
				
				ReverseIterator& operator--(){

					current = current->next;
					return *this;
				}
				
				ReverseIterator operator--(int){

					ReverseIterator reverse_iter(*this);
					current = current->next;
					return reverse_iter;

					
				}
				
				bool operator==(const ReverseIterator &reverse_iter){

					if (current == nullptr && reverse_iter.current  != nullptr){

						if (reverse_iter.current ->status == -1)	return true;
					
					}
						
					if (current != nullptr && reverse_iter.current  == nullptr){

						if (current -> status == -1)	return true;
					}
					
					if (current  == reverse_iter.current)

						return true;
					else
						return false ;

				
				}
				bool operator!=(const ReverseIterator &reverse_iter){

					if (current  == reverse_iter.current)
						return false;
					else 
						return true; 		

				}
			
				value_type& operator*() const{

					return current->nv;
				
				};
				
		
				
			private:
				Node* current;
		};//end of class ReverseIterator

			//Map<Key, Value>::ConstIterator
			
			///////////////////////////////////////////////////
			//ConstIterator(const ConstIterator&);
			//ConstIterator& operator=(const ConstIterator&);
			//ConstIterator(ConstIterator&&);
			//ConstIterator& operator=(ConstIterator&&);
			//~ConstIterator();
			//////////////////////////////////////////
			
			//ConstIterator(const Iterator&);

			
			//ConstIterator& operator++();
			//ConstIterator operator++(int);
			//ConstIterator& operator--();
			//ConstIterator operator--(int);
			//const std::pair<const Key, Value>& operator*() const;



	class ConstIterator{
		
				friend class Map<Key, Value>;
			
			public:

				ConstIterator(){
					current  = nullptr;
				}
				//ConstIterator(const ConstIterator &); 
				//yiwen
				ConstIterator(const Iterator& iter){
					current = iter.current;
					
				}
				
				ConstIterator(Node* new_node){
					current = new_node;
				}
					
				ConstIterator& operator++(){
					current = current ->next;
					return *this;
				
				}
				ConstIterator operator++(int){
					ConstIterator const_iter(*this);
					current = current ->next;
					return const_iter;
				}
				ConstIterator& operator--(){
					current = current->previous;
					return *this;
				}
				ConstIterator operator--(int){
					ConstIterator const_iter(*this);
					current = current->previous;
					return const_iter;
					
				}

				bool operator==(const ConstIterator &const_iter){

					if (current == nullptr && const_iter.current  != nullptr){

						if (const_iter.current ->status == -1)	return true;
					
					}
						
					if (current != nullptr && const_iter.current  == nullptr){

						if (current -> status == -1)	return true;
					}
					
					if (current  == const_iter.current)

						return true;
					else
						return false ;

				}//bool operator==(const Iterator&, const Iterator&);
		
				bool operator!=(const ConstIterator &const_iter){
						if (current  == const_iter.current)
							return false;
						else 
							return true; 
				}

				bool operator==(const Iterator &iter){
					
					if (current  == nullptr && iter.current != nullptr){

						if (iter.current ->status == -1)	return true;
					}

						
					if ( current != nullptr && iter.current   == nullptr){
						if (current -> status == -1)	return true;

					}

					if (current   == iter.current)
						return true;
					else
						return false; 

				}//bool operator==(const ConstIterator&, const Iterator& )
				
				bool operator!=(const Iterator &iter){

					if (current  == iter.current)

						return false;
					else 
						return true; 
				}

			
				value_type& operator*() const{

					return current->nv;
				};//std::pair<const Key, Value>& operator*() const, Returns a reference to the key-value pair the Iterator is pointing to
			

			
			private:
				Node* current;
				
	};//end of class ConstIterator
			



		public:

			
			//Constructors
			//Map();
			//Map(const Map&);	
			//Map& operator=(const Map&);	
			//Map(Map&&);
			//Map& operator=(Map&&)
			//Map(std::initializer_list<std::pair<const Key, Value>>);
			//~Map();

			//creates an empty map
			Map() 
				: nroot(nullptr) 
				, nbegin(nullptr) 
				, nend(nullptr) {};

	

			//copy constructor
			
			/*Map(const Map&copy){
				Node *temp=new Node();
				nroot=copy.nroot;
				nbegin=copy.nbegin;
				nend=copy.nend;			
			}
			*/

			
			Map(const Map&);

			Map& operator=(const Map&);

			Map(Map&&);

			Map& operator=(Map&&);

			Map(std::initializer_list<std::pair<const Key, Value>>);

			Iterator insert(value_type&);
			Iterator insert(value_type&&);

			Iterator find(const Key &key){
				if (nroot != nullptr){
					Iterator iter = find_helper(nroot, key);
						if (iter.current == nullptr)
							iter = end();
						return iter;
				}//end of if
				else{
				Iterator iter;
					iter.current = nullptr;
					return iter;
				}//end of else
			};
			ConstIterator find(const Key &key) const{
				if (nroot != nullptr){
					ConstIterator const_iter = find_helper(nroot, key);
					if (const_iter.current == nullptr)
						const_iter = end();
					return const_iter;
				}
				else{
					ConstIterator const_iter;
					const_iter.current = nullptr;
					return const_iter;
				}//end of else
			};
			
			Value& at(const Key &key){
				Iterator iter(find_helper(nroot, key));
				if (iter.current == nullptr){
					throw std::out_of_range("std::out_of_range");
				}
				return iter.current->nv.second;
			};
			
			const Value& at(const Key &key) const{
				ConstIterator const_iter(find_helper(nroot, key));
				if (const_iter.current == nullptr){
					throw std::out_of_range("std::out_of_range");
				}
				return const_iter.current->nv.second;
			};
// key is in the Map, return a reference to the corresponding value.
//If it does not, default constructs a value for that key and returns a reference to it
			Value& operator[](const Key &key){
				Iterator iter;
				if (nroot != nullptr)
					iter = find_helper(nroot, key);
				if (iter.current != nullptr)
					return iter.current->nv.second;
				else{//can not find key
					value_type vt(key, Value());
					if (nroot != nullptr){
						iter = insertnode(nroot, vt);
					}//end of if
					else{//empty tree, this become the root
						Node* temp = new Node(vt);
						nroot = temp;
						nend = new Node(vt);
						nend->next = nullptr;
						nend->nleft = nullptr;
						nend->nright = nullptr;
						nend->nparent = nullptr;
						nbegin = new Node(vt);
						nbegin->previous = nullptr;
						nbegin->nleft = nullptr;
						nbegin->nright = nullptr;
						nbegin->nparent = nullptr;

						nroot->previous = nbegin;
						nroot->next = nend;
						nend->previous = nroot;
						nbegin->next = nroot;
						nend->status = -1;
						nbegin->status = -1;
						iter.current = nroot;
					}//end of else
					return iter.current->nv.second;
				}//end of else
			};//end of operator[]


			
			~Map(){ 
				if (nroot != nullptr)
					clear();
				if (nend != nullptr){	
					delete(nend);
					nend = nullptr;
				}
				if (nbegin != nullptr){
					delete(nbegin);
					nbegin = nullptr;
				}
			};

	private:
		
		Node* nroot;
		Node* nbegin;
		Node* nend;
		Iterator insertnode(Node*, value_type&);
		Iterator insertnode(Node*, value_type&&);
		void print_helper(Node*);
		void print_helper2(Node*);
		Iterator find_helper(Node*, Key) const;
		void remove_helper(Node*, Key);
		void copy(Node*);
		void copymap(Node*);
		void move(Node*);
		
		//void move2(Node*);
		//Modifiers
		//	Iterator insert(const std::pair<const Key, Value>&);
		//	Iterator insert(std::pair<const Key, Value>&&);
		//	void erase(Iterator);
		//	void remove(const Key&);
		//	void clear();


			//Inserts the given key-value pair. Returns an iterator to the newly inserted element. 
			//If the key already exists, returns an iterator to the already existing key and does not modify the existing Map


public:

		
			
			void erase(Iterator erase_iter);
			/*{
				if(erase_iter.current != NULL){
					remove(*(erase_iter.current->key));
				};
				
			
			}//end  of erase
			*/
			void remove(const Key &key){
				if (nroot != nullptr)
				remove_helper(nroot, key);
			};
	
			void clear();
			void clearhelper(Node* );

		
			std::size_t size() const{
				std::size_t size = 0;
				ConstIterator const_iter;
				for(const_iter = begin(); const_iter != end(); ++const_iter){
					size=size+1;
				}

				return size;
			};

			bool empty() const{ return nroot == nullptr;};
			
			bool operator==(const Map&) const;
			bool operator!=(const Map&) const;

			Iterator begin();
			ConstIterator begin() const;
			ReverseIterator rbegin();
			Iterator end();
			ConstIterator end() const;
			ReverseIterator rend();
			

	};//end of map


//Map(const Map&)
	template<typename Key, typename Value>
	Map<Key, Value>::Map(const Map<Key, Value>& map)
	: nroot(nullptr){
	copy(map.nroot);
}



//Map& operator=(const Map&)
//Copy assignment. Must follow Value Semantics and handle self assignment
template<typename Key, typename Value>
Map<Key, Value>& Map<Key, Value>::operator=(const Map<Key, Value>& map){

	if (this != &map){
		if (nroot != nullptr)
			clear();
		if (nend != nullptr){	
			delete(nend);
			nend = nullptr;
		}
		if (nbegin != nullptr){
			delete(nbegin);
			nbegin = nullptr;
		}
		copy(map.nroot);
	}
	return *this;


    //std::cout<<"map:operator=& map"<<'\n';
    /*if(this!=&map){
		
        this->clearhelper(this->nroot);
        copymap(map.nroot);
    }//end of if
    return *this;

*/
}//end of map op=


template<typename Key, typename Value>
void Map<Key, Value>::copy(Node* node){

	if(nroot!=nullptr){
		insertnode(nroot,std::move(node->nv));
	}
	else{
		Node* temp=new Node(node->nv);
		nroot=std::move(temp);

		nend=new Node(node->nv);
		nend->next=nullptr;
		nend->nleft=nullptr;
		nend->nright=nullptr;
		nend->nparent=nullptr;

		nbegin=new Node(node->nv);
		nbegin->previous=nullptr;
		nbegin->nleft=nullptr;
		nbegin->nright=nullptr;
		nbegin->nparent=nullptr;

		nroot->previous=nbegin;
		nroot->next=nend;
		nend->previous=nroot;
		nend->status=-1;
		nbegin->next=nroot;
		nbegin->status=-1;
		temp=nullptr;

	}
		
	if(node->nleft!=nullptr)
		
		copy(node->nleft);
	if(node->nright!=nullptr)
		
		copy(node->nright);


}

template<typename Key, typename Value>
void Map<Key, Value>::copymap(Node* node){//copy the entire tree

    if(node == nullptr)return;
    this->insert(node->nv); //nv is value type, not *
    copy(node->nleft);
    copy(node->nright);

}

template<typename Key, typename Value>
Map<Key, Value>::Map(Map<Key, Value>&& map): nroot(nullptr){
	if (!map.empty()){
		move(map.nroot);
	}
	else{
		if (nroot != nullptr)
			clear();
		if (nend != nullptr){	
			delete(nend);
			nend = nullptr;
		}
		if (nbegin != nullptr){
			delete(nbegin);
			nbegin = nullptr;
		}
	}

}


//Move assignment operator

template<typename Key, typename Value>
Map<Key, Value>& Map<Key, Value>::operator=(Map<Key, Value>&& map){
	if(this!=&map){
		this->clearhelper(this->nroot);
		this->nroot = map.nroot;
		this->nbegin->next = map.nbegin->next;
		this->nend->previous = map.nend->previous;
		map.nroot=nullptr; 
		map.nbegin->next = nullptr;
		map.nend->previous = nullptr;
	}
	return *this;

}//end of map op=&&

/////////////////////////////////////////////////////////////

template<typename Key, typename Value>
void Map<Key, Value>::move(Node *node){

	if(nroot!=nullptr){
		insertnode(nroot,std::move(node->nv));
	}
	else{
		Node* temp=new Node(std::move(node->nv));
		nroot=temp;
		nend=new Node(std::move(node->nv));
		nend->next=nullptr;
		nend->nleft=nullptr;
		nend->nright=nullptr;
		nend->nparent=nullptr;
		nbegin=new Node(std::move(node->nv));
		nbegin->previous=nullptr;
		nbegin->nleft=nullptr;
		nbegin->nright=nullptr;
		nbegin->nparent=nullptr;

		nroot->previous=nbegin;
		nroot->next=nend;
		nend->previous=nroot;
		nend->status=-1;
		nbegin->next=nroot;
		nbegin->status=-1;

	}
		
	if(node->nleft!=nullptr)
		
		move(std::move(node->nleft));
	if(node->nright!=nullptr)
		
		move(std::move(node->nright));


}




/*
			Map(std::initializer_list<std::pair<const Key, Value>> i_list){
				Node *temp=new Node();
				nroot=nullptr;
				nbegin=nullptr;
				nend=nullptr;	
				int i_size = i_list.size();
				int lenth = 0;
				const std::pair<const Key, Value>* i_list;
				while(lenth<i_size) {
					insert(value_type &i_list);
					++iter;
					++len;
				}
			}
*/


template<typename Key, typename Value>
Map<Key, Value>::Map(std::initializer_list<std::pair<const Key, Value>> l)
	: nroot(nullptr)
	, nbegin(nullptr)
	, nend(nullptr){
		for (auto iter = l.begin(); iter != l.end(); ++iter){
			value_type vt(std::move(*iter));
			insert(std::move(vt));
		}

}


///////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////

template<typename Key, typename Value>
typename Map<Key, Value>::Iterator Map<Key, Value>::insert(value_type &vt){

	Iterator iter;
	if(nroot!=nullptr){

		iter=insertnode(nroot,vt);
	}
	else{

		Node*temp=new Node(vt);
		nroot=temp;
		if(nend==nullptr)
			nend=new Node(vt);
		nend->nleft=nullptr;
		nend->nright=nullptr;
		nend->next=nullptr;
		nend->nparent=nullptr;
		if(nbegin==nullptr)
			nbegin=new Node(vt);
		nend->nleft=nullptr;
		nend->nright=nullptr;
		nend->previous=nullptr;
		nend->nparent=nullptr;
		nroot->previous=nbegin;
		nroot->next=nend;
		nend->previous=nroot;
		nend->status=-1;
		nbegin->next=nroot;
		nbegin->status=-1;
		iter.current=nroot;
		
	}//end of else

	return iter;

}


	

template<typename Key, typename Value>
typename Map<Key, Value>::Iterator Map<Key, Value>::insertnode(Node* node, value_type &ins_nd){

	Iterator iter;
	 if(node->nv.first<ins_nd.first){

		if(node->nright !=nullptr){
				iter=insertnode(node->nright,ins_nd);
		}//end of if 2

		else{
			Node* ins_right=new Node(ins_nd);
			ins_right->nparent=node;
			if(node->next  !=nullptr){

				node->next->previous=ins_right;
				ins_right->next=node->next;
			}//end of if2

			node->next=ins_right;
			ins_right->previous=node;
			iter.current=ins_right;
			node->nright=ins_right;

		}//end of else
		
	}//end of if 1

	else if(ins_nd.first<node->nv.first){

		if(node->nleft !=nullptr){
			iter=insertnode(node->nleft,ins_nd);
		}//end of if2

		else{

			Node* ins_left=new Node(ins_nd);
			ins_left->nparent=node;
			if(node->previous != nullptr){

				node->previous->next=ins_left;
				ins_left->previous=node->previous;
			}//end of if2
			ins_left->next=node;
			node->previous=ins_left;
			iter.current=ins_left;
			node->nleft=ins_left;
		}//end of else


	}
	else{

		iter.current=node;
	}


	return iter;
}
			



//////////////////////////
template<typename Key, typename Value>
typename Map<Key, Value>::Iterator Map<Key, Value>::insert(value_type &&vt){




	Iterator iter;
	
	if (nroot != nullptr){

		iter = insertnode(nroot, std::move(vt));
	}
	else{

		Node* temp = new Node(std::move(vt));
		nroot = temp;
		if (nend == nullptr) 
		
		nend = new Node(std::move(vt));
		nend ->next = nullptr;
		nend ->nleft = nullptr;
		nend ->nright = nullptr;
		nend ->nparent = nullptr;
		if (nbegin == nullptr)
		nbegin = new Node(std::move(vt));
		nbegin-> previous = nullptr;
		nbegin-> nleft = nullptr;
		nbegin-> nright = nullptr;
		nbegin-> nparent = nullptr;

		nroot->previous = nbegin;
		nroot->next = nend;
		nend->previous = nroot;
		nbegin->next = nroot;
		nend->status= -1;
		nbegin->status= -1;
		iter.current = nroot;
	}
	return iter;



}

template<typename Key, typename Value>
typename Map<Key, Value>::Iterator Map<Key, Value>::insertnode(Node* node, value_type &&vt){


	Iterator iter;
	if (vt.first < node->nv.first){
		if (node->nleft != nullptr){
			iter = insertnode(node->nleft, std::move(vt));
		}
		else{
			Node* ins_left = new Node(std::move(vt));
			ins_left->nparent = node;
			if (node->previous!= nullptr){
				node->previous->next = ins_left;
				ins_left->previous= node->previous;
			}
			ins_left->next = node;
			node->previous= ins_left;
			iter.current= ins_left;
			node->nleft = ins_left;
		}

	}//end of else

	else if (node->nv.first < vt.first){
		if (node->nright != nullptr){
			iter = insertnode(node->nright, std::move(vt));
		}//end of if
		else{
			Node* ins_right = new Node(std::move(vt));
			ins_right->nparent = node;
			if (node->next != nullptr){
				node->next->previous= ins_right;
				ins_right->next = node->next;
			}
			node->next = ins_right;
			ins_right->previous= node;
			iter.current = ins_right;
			node->nright = ins_right;
		}


	}//end of else if

	else{
		iter.current = node;
	}//end of else
	return iter;


}

template<typename Key, typename Value>
typename Map<Key, Value>::Iterator Map<Key, Value>::find_helper(Node* node, Key key) const{
	Iterator iter;
	if(node->nv.first==key) {iter.current=node;}
	else if(key<node->nv.first){
		if(node->nleft!=nullptr){iter=find_helper(node->nleft,key);}
		else{
			iter.current=nullptr;
		}
	}
	else{
		if(node->nright !=nullptr){iter=find_helper(node->nright,key);}
		else{
			iter.current=nullptr;
		}
	}
	return iter;

	
}

template<typename Key, typename Value>
void Map<Key, Value>::erase(Map<Key, Value>::Iterator iter){


	if(iter.current!=nullptr){


	remove_helper(iter.current,iter.current->nv.first);
	iter.current=nullptr;

	}

}



template<typename Key, typename Value>
void Map<Key, Value>::remove_helper(Node* node, Key key){

	Map<Key, Value>::Iterator iter=find_helper(node, key);
	if(iter.current==nullptr){
		throw std::out_of_range("std::out_of_range");
	}
	else{

		Map<Key, Value>::Node* temp=iter.current;
		if(temp->previous!=nullptr && temp->next != nullptr){

			temp->previous->next=temp->next;
			temp->next->previous=temp->previous;
		}
		else if(temp->previous!=nullptr && temp->next == nullptr){
			temp->previous->next=nullptr;
		}
		else if(temp->previous ==nullptr && temp->next != nullptr){
			temp->next->previous=nullptr;
		}
		temp->next=nullptr;
		temp->previous=nullptr;

		if(temp->nleft==nullptr && temp->nright==nullptr ){
		// is leaf
			if(temp==nroot){
				//delete(nroot);
				nroot=nullptr;

			}
			else{
				//if(temp->nparent->nleft->nv.first== temp->nv.first)
				//	temp->nparent->nleft=nullptr;
				//if(temp->nparent->nright->nv.first== temp->nv.first)
				//	temp->nparent->nright=nullptr;	
				if (key < temp->nparent->nv.first){
					temp->nparent->nleft = nullptr;
				}else{
					temp->nparent->nright = nullptr;
				}		
				
			}

			delete(temp);
			temp=nullptr;
		}


		else if(temp->nleft!=nullptr &&temp->nright==nullptr ){
		// only has left cihld
			if(temp==nroot){
				nroot=temp->nleft;
				temp->nleft->nparent=nullptr;
				delete(temp);
				temp=nullptr;
			}
			else{
				if (key < temp->nparent->nv.first){
					temp->nparent->nleft = temp->nleft;
					temp->nleft->nparent = temp->nparent;
					delete(temp);
					temp = nullptr;
				//temp->nparent->nleft=temp->nleft;
				//temp->nleft->nparent=temp->nparent;
				//temp->nparent=nullptr;
				//temp->nleft=nullptr;
				//delete(temp);
				//temp=nullptr;
				}
				else{
					temp->nparent->nright = temp->nleft;
					temp->nleft->nparent = temp->nparent;
					delete(temp);
					temp = nullptr;
				}
		
			}
		}//end of else if

		else if(temp->nleft ==nullptr &&temp->nright !=nullptr){
		//only has right child
			if(temp==nroot){
				nroot=temp->nright;
				temp->nright->nparent=nullptr;			
				delete(temp);
				temp=nullptr;
			}
			else{
				if (key < temp->nparent->nv.first){
					temp->nparent->nleft = temp->nright;
					temp->nright->nparent= temp->nparent;
					delete(temp);
					temp = nullptr;
				}else{
					temp->nparent->nright = temp->nright;
					temp->nright->nparent = temp->nparent;
					delete(temp);
					temp = nullptr;
				}
				//temp->nparent->nright=temp->nright;
				//temp->nright->nparent=temp->nparent;
				//temp->nparent=nullptr;
				//temp->nright=nullptr;
				//delete(temp);
				//temp=nullptr;
		
			}

		}//end of else if


		else{//temp->nleft !=nullptr &&temp->nright !=nullptr

			//if(temp==nroot){

			//	temp->nright->nleft=temp->nleft;
			//	temp->nleft->nparent=temp->nright;
			//	temp->nleft=nullptr;
			//	temp->nright=nullptr;
			//	temp->nright->nparent=nullptr;	
			//	delete(temp);
			//	temp=nullptr;			
				
			//}
			
			Map<Key, Value>::Node* right_most = temp->nleft;
			while (right_most->nright != nullptr){
				right_most = right_most->nright;
			}
			if (right_most->nv.first < right_most->nparent->nv.first){
				right_most->nparent = temp->nparent;
				right_most->nright = temp->nright;
				temp->nright->nparent = right_most;
				if (temp == nroot)
					nroot = right_most;
				else{
					if (temp->nv.first < temp->nparent->nv.first)
						temp->nparent->nleft = right_most;
					else
						temp->nparent->nright = right_most;
				}
					delete(temp);
					temp = nullptr;
			}//end of if
				
			else{
					if (right_most->nleft != nullptr){
						right_most->nparent->nright = right_most->nleft;
							right_most->nleft->nparent = right_most->nparent;
					}
					else{
						right_most->nparent->nright = nullptr;
					}
					temp->nleft->nparent = right_most;
					temp->nright->nparent = right_most;
					right_most->nleft = temp->nleft;
					right_most->nright = temp->nright;
					right_most->nparent = temp->nparent;
					if (temp == nroot)
						nroot = right_most;
					else{
						if (temp->nv.first < temp->nparent->nv.first)
							temp->nparent->nleft = right_most;
						else
							temp->nparent->nright = right_most;
					}
					delete(temp);
					temp = nullptr;
				}//end of else
			}//enf of else
/**/
	}//end  of else not null 



}

//////////////////////////////////////////////////////////

template<typename Key, typename Value>
void Map<Key, Value>::clear(){
	//clearhelper(nroot);
	clearhelper(this->nroot->nleft);
    	clearhelper(this->nroot->nright);
    this->nbegin->next=this->nend;
    this->nend->previous=this->nbegin;
    this->nroot = nullptr;

}


template < typename Key, typename Value>
void Map<Key, Value>::clearhelper(Node* root){
	if(root == NULL) return;
	if(root->nleft != NULL){clearhelper(root->nleft);}
	if(root->nright != NULL){clearhelper(root->nright);}
	delete root;
	return;
}

////////////////////////////////////////////////////////////////////

template<typename Key, typename Value>
bool Map<Key, Value>::operator==(const Map<Key, Value> &map) const{
	if(this->size()!=map.size()){
		return false;
	}
	else if(this->nroot == NULL && map.nroot == NULL){
		return true;
	}
	else{
		Map::ConstIterator i =map.begin();
    		Map::ConstIterator j = this->begin();
    		size_t cnt = this->size();
		while(cnt!=0){
			if((i.current->nv.first==j.current->nv.first) == false || (i.current->nv.second==i.current->nv.second)==false){
           
            			return false; 
       		 	}
       		i++;
		j++;
        		cnt=cnt-1;

		}//end of while

		return true;
	}//end of else
}//end of op==


template<typename Key, typename Value>
bool Map<Key, Value>::operator!=(const Map<Key, Value> &map) const{
	if(*this == map){
		return false;
	}
	else
		return true;
}


///////////////////////////////////////////////////////////////////
template<typename Key, typename Value>
typename Map<Key, Value>::Iterator Map<Key, Value>::begin(){

	if(this->nroot == NULL){
		
		return this->end();
	}
	else{
		return Iterator(this->nbegin->next);
	}
}


template<typename Key, typename Value>
typename Map<Key, Value>::Iterator Map<Key, Value>::end(){
	return Iterator(this->nend);
}


//////////////////////////////////////////////////////////////////////
template<typename Key, typename Value>
typename Map<Key, Value>::ConstIterator Map<Key, Value>::begin() const{
	if(this->nroot == NULL) {
		return this->end();
	}
	else{
		return ConstIterator(this->nbegin->next);
	}
}

template<typename Key, typename Value>
typename Map<Key, Value>::ConstIterator Map<Key, Value>::end() const{

	return ConstIterator(this->nend);

}


///////////////////////////////////////////////////////////////////
template<typename Key, typename Value>
typename Map<Key, Value>::ReverseIterator Map<Key, Value>::rbegin(){

	if(this->nroot == NULL) {
		return this->rend();
	}
	else{
		return ReverseIterator(this->nend->previous);
	}
	
}


template<typename Key, typename Value>
typename Map<Key, Value>::ReverseIterator Map<Key, Value>::rend(){
		return ReverseIterator(this->nbegin);
}


		

}//end of calss 540

#endif

