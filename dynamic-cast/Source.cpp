#include"Polyclinic.h"

void Task(Polyclinic &polic);

int main()
{
	ifstream ifile("Task.txt");
	if (ifile)
	{
		Polyclinic polic(ifile);
		polic.sort();
		Task(polic);
		polic.print();
	}
	ifile.close();
	return 0;
}

void Task(Polyclinic &polic)
{
	TList list = polic.get_list_person();
	for (auto i = list.begin(); i != list.end();)
	{
		TPatient* pat = dynamic_cast<TPatient*>(*i);
		if (pat)
		{
			if (pat->get_policy_number()[0] == '0')
				i=list.erase(i);
			else
				i++;
		}
		else
			i++;
	}
	polic.set_list_person(list);
}

