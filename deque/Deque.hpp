#ifndef _XICHEN_DEQUE_H_
#define _XICHEN_DEQUE_H_
#include <string.h>
#define Deque_DEFINE(t)\
\
struct Deque_##t;\
\
typedef struct Deque_##t##_Iterator{\
	t * headofarray;\
	t  * tailofarray;\
	t * locofarray;\
	t * current;\
\
	int soa;\
\
	void (*dec)(Deque_##t##_Iterator *);\
	void (*inc)(Deque_##t##_Iterator *);\
\
	t& (*deref)(Deque_##t##_Iterator *);\
\
\
}Deque_##t##_Iterator;\
\
typedef struct Deque_##t{\
\
	t* tmp;\
	t* data;\
	t* newdata;\
\
	int count;\
	int sz;\
\
	Deque_##t##_Iterator it;\
\
	int (*size) (Deque_##t*);\
	bool (*empty) (Deque_##t*);\
	void (*push_front)(Deque_##t*, t );\
	void (*push_back)(Deque_##t*, t );\
	void (*pop_front)(Deque_##t*);\
	void (*pop_back)(Deque_##t*);\
	t& (*front)(Deque_##t*);\
	t& (*back)(Deque_##t*);\
\
	char  type_name[sizeof(#t)+6];\
\
	Deque_##t##_Iterator (*begin)(Deque_##t*);\
	Deque_##t##_Iterator (*end)(Deque_##t*);\
	void (*clear)(Deque_##t*);\
	void (*dtor)(Deque_##t*);\
	t& (*at)(Deque_##t *, int);\
	bool (*compare) (const t &, const t &);\
	bool (*Deque_##t##_equal)(Deque_##t ,Deque_##t );\
\
\
\
\
}Deque_##t;\
\
\
void dec (Deque_##t##_Iterator* myit){\
\
	if( (myit->current)==myit->locofarray) myit->current=&(myit->locofarray[myit->soa-1]);\
\
	else myit->current--;\
\
\
\
}\
\
\
void inc (Deque_##t##_Iterator* myit){\
\
	if( (myit->current)==&myit->locofarray[myit->soa-1]) myit->current=myit->locofarray;\
\
	else myit->current++;\
\
\
}\
\
\
\
t& deref(Deque_##t##_Iterator *it){\
\
\
	return *(it->current);\
}\
\
\
\
int size( Deque_##t* data1){\
\
\
	return data1->count;\
\
}\
\
bool empty(Deque_##t* data1){\
\
	if(data1->count==0) return true;\
\
	else return false;\
}\
\
void push_back(Deque_##t* data1, t num){\
\
\
\
		if(data1->count==data1->sz){\
			data1->newdata=(t *)malloc(sizeof(t )*(data1->sz)*2);\
\
			data1->sz=(data1->sz)*2;\
			data1->it.soa=data1->sz;\
			data1->tmp=data1->newdata;\
\
			/*trasfer the first piece of data*/\
\
\
			*(data1->tmp)=*(data1->it.headofarray);\
			if(  ((data1->it.headofarray)-(data1->data)) == (data1->sz-1)  ){\
\
				data1->it.headofarray=data1->data;\
\
			}\
\
			else data1->it.headofarray++;\
\
\
			for(int i=1;i<(data1->count);i++){\
\
				data1->tmp++;\
				*(data1->tmp)=*(data1->it.headofarray);\
\
				if( ((data1->it.headofarray)-data1->data) == (data1->sz-1)  ){\
\
				data1->it.headofarray=data1->data;\
\
			}\
\
			else data1->it.headofarray++;\
\
		}\
\
		data1->tmp++;\
		*data1->tmp=num;\
		data1->count++;\
\
		/*update, free */\
		data1->it.headofarray=data1->newdata;\
		data1->it.locofarray=data1->newdata;\
		data1->it.tailofarray=data1->tmp;\
		data1->tmp=data1->data;\
		data1->data=data1->newdata;\
		free(data1->tmp);\
\
	}\
\
\
	else{\
\
		if(data1->count==0){\
\
			*data1->it.tailofarray=num;\
\
		}\
\
\
		else if(  ((data1->it.tailofarray)-data1->data)  == (data1->sz-1)  ){\
\
			data1->it.tailofarray=data1->data;\
		}\
		else data1->it.tailofarray++;\
		*data1->it.tailofarray=num;\
		data1->count++;\
	}\
\
	data1->it.current=data1->it.headofarray;\
\
}\
\
\
\
void push_front(Deque_##t* data1, t num){\
\
\
\
	if(data1->count==data1->sz){\
		data1->newdata=(t *)malloc(sizeof(t )*data1->sz*2);\
		data1->sz=data1->sz*2;\
		data1->it.soa=data1->sz;\
		data1->tmp=data1->newdata;\
\
		*data1->tmp=num;\
		data1->tmp++;\
\
\
\
		*(data1->tmp)=*(data1->it.headofarray);\
		if(  ((data1->it.headofarray)-data1->data)  == (data1->sz-1)  ){\
\
				data1->it.headofarray=data1->data;\
\
		}\
		else data1->it.headofarray++;\
\
		for(int i=1;i<(data1->count);i++){\
\
			data1->tmp++;\
			*(data1->tmp)=*(data1->it.headofarray);\
\
			if( ((data1->it.headofarray)-data1->data) == (data1->sz-1)  ){\
\
				data1->it.headofarray=data1->data;\
\
			}\
\
			else data1->it.headofarray++;\
\
		}\
\
		data1->count++;\
\
		/*update, free */\
		data1->it.headofarray=data1->newdata;\
		data1->it.locofarray=data1->newdata;\
		data1->it.tailofarray=data1->tmp;\
		data1->tmp=data1->data;\
		data1->data=data1->newdata;\
		free(data1->tmp);\
\
	}\
\
\
	else{\
\
\
		if(data1->count==0){\
\
			*data1->it.tailofarray=num;\
\
		}\
\
\
		else if(  (data1->it.headofarray)==data1->data ){\
\
			data1->it.headofarray=&(data1->data[data1->sz-1]);\
		}\
		else data1->it.headofarray--;\
\
		*data1->it.headofarray=num;\
		data1->count++;\
	}/*is not full, push back*/\
\
	data1->it.current=data1->it.headofarray;\
\
}\
\
\
\
t& front(Deque_##t* data1){\
\
	 return *(data1->it.headofarray);\
\
}\
\
t& back(Deque_##t* data1){\
\
	return  *(data1->it.tailofarray);\
\
}\
\
\
void pop_front(Deque_##t* data1){\
\
	if(  ((data1->it.headofarray)-data1->data) == (data1->sz-1)  ){\
\
		data1->it.headofarray=data1->data;\
	}\
	else data1->it.headofarray++;\
	data1->count--;\
\
	data1->it.current=data1->it.headofarray;\
\
}\
\
void pop_back(Deque_##t* data1){\
\
\
\
	if(  (data1->it.tailofarray)==data1->data){\
\
		data1->it.tailofarray=&(data1->data[data1->sz-1]);\
	}\
	else data1->it.tailofarray--;\
	data1->count--;\
\
}/*end of pop_back*/\
\
\
\
Deque_##t##_Iterator begin(Deque_##t *data1){\
\
\
	data1->it.current = data1->it.headofarray;\
	return data1->it;\
}\
\
\
Deque_##t##_Iterator end(Deque_##t *data1){\
\
\
	if(  ((data1->it.tailofarray)-data1->data)   == (data1->sz-1)  ){\
		data1->it.current = data1->data;\
	}\
	else {\
		data1->it.current=data1->it.tailofarray;\
		data1->it.current++;\
	}\
\
	return data1->it;\
}\
\
\
\
void clear(Deque_##t* data1){\
\
\
\
	data1->it.headofarray=0;\
	data1->count=0;\
	data1->it.headofarray=data1->data;\
	data1->it.tailofarray=data1->data;\
	data1->it.current=data1->it.headofarray;\
\
}\
\
\
void dtor(Deque_##t* data1){\
\
\
\
	data1->it.headofarray=0;\
\
	data1->count=0;\
\
\
	free(data1->data);\
\
\
}/*end of dtor*/\
\
\
\
t& at(Deque_##t *data1, int location){\
\
\
	int i;\
\
	Deque_##t##_Iterator it;\
	for(it = data1->begin(data1), i = 0; i < location ; it.inc(&it), i++){\
\
	}\
	return it.deref(&it);\
\
\
}\
\
\
\
bool Deque_##t##_equal(Deque_##t deq1,Deque_##t deq2){\
\
\
	Deque_##t##_Iterator it1;\
	Deque_##t##_Iterator it2;\
	it1=begin(&deq1);\
	it2=begin(&deq2);\
	int j;\
\
	if(deq1.count==deq2.count){\
\
		for(j=0;j<deq1.count;j++){\
\
			if(deq1.compare(it1.deref(&it1), it2.deref(&it2)) || deq2.compare(it2.deref(&it2), it1.deref(&it1)))\
\
			return false;\
\
			it1.inc(&it1);\
\
			it2.inc(&it2);\
\
		}\
\
	}\
\
\
	else 	return false;\
\
	return true;\
\
}\
\
\
\
\
void Deque_##t##_ctor(Deque_##t * data1, bool int_less (const t &o1, const t &o2)){\
\
\
		data1->data=(t *)malloc(sizeof(t )*20);\
\
		data1->size=size;\
		data1->empty=empty;\
		data1->push_back=push_back;\
		data1->push_front=push_front;\
		data1->front=front;\
		data1->back=back;\
		data1->pop_back=pop_back;\
		data1->pop_front=pop_front;\
		data1->begin=begin;\
		data1->end=end;\
		data1->at=at;\
		data1->clear=clear;\
		data1->dtor=dtor;\
		data1->Deque_##t##_equal=Deque_##t##_equal;\
\
		data1->it.headofarray=data1->data;\
		data1->it.tailofarray=data1->data;\
		data1->it.locofarray=data1->data;\
		data1->it.current=data1->data;\
		data1->it.soa=20;\
		data1->sz=20;\
		data1->count=0;\
\
		data1->it.dec=dec;\
		data1->it.inc=inc;\
		data1->it.deref=deref;\
\
 		data1->compare = int_less;\
\
		strcpy(data1->type_name,"Deque_");\
		strcat(data1->type_name,#t);\
\
}\
\
bool Deque_##t##_Iterator_equal(Deque_##t##_Iterator ita, Deque_##t##_Iterator itb){\
\
\
	if(ita.current==itb.current) return true;\
\
	else return false;\
\
\
\
}\
\

#endif