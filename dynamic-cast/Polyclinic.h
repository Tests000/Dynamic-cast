#pragma once
#include "Person.h"

#include <list>
#include <fstream>

using namespace std;

using TList = list<TPerson*>;
using TIterator = list<TPerson*>::iterator;

class Polyclinic
{
private:
	string name;
	TList list_person;
public:
	Polyclinic(ifstream& file);
	~Polyclinic();
	TList get_list_person();
	void set_list_person(TList list_person);
	void print();
	void sort();
};