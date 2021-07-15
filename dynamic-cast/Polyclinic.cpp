#include "Polyclinic.h"

Polyclinic::Polyclinic(ifstream& file)
{
	getline(file, name);
	while (!file.eof())
	{
		char ch = file.get(); file.ignore();
		string FIO_; getline(file, FIO_);
		string gender_; getline(file, gender_);
		TPerson* new_person;
		if (ch == 'P')
		{
			short age_;
			string polic;
			file >> age_>>polic;
			file.ignore();
			new_person = new TPatient(FIO_, gender_, age_, polic);
		}
		else if (ch == 'W')
		{
			string skill_, rank_;
			short exp_;
			file >> skill_ >> exp_ >> rank_;
			file.ignore();
			new_person = new TWorker(FIO_, gender_, skill_, exp_, rank_);
		}
		getline(file, FIO_);
		list_person.push_front(new_person);
	}
}

Polyclinic::~Polyclinic()
{
	for (auto i : list_person)
		delete i;

}

TList Polyclinic::get_list_person()
{
	return list_person;
}

void Polyclinic::set_list_person(TList list_person)
{
	this->list_person = list_person;
}

void Polyclinic::print()
{
	for (auto i : list_person)
	{
		i->print();
	}
}

void Polyclinic::sort()
{
	list_person.sort([](TPerson* a, TPerson* b) -> bool{ return a->getFIO()<b->getFIO(); });
}
