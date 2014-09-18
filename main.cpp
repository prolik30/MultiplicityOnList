#include <iostream>
#include "multiplicity.hpp"

using namespace std;

int main()
{
	Multiplicity *M1=new Multiplicity;
	Multiplicity *M2=new Multiplicity;
	Multiplicity *M3=new Multiplicity;
	Multiplicity *MergeM1M3=new Multiplicity;
	Multiplicity *IntersectionM1M2=new Multiplicity;
	
	(*M1).AddElemMultipl(5);
	(*M1).AddElemMultipl(4);
	(*M1).AddElemMultipl(1);
	(*M1).AddElemMultipl(7);

	(*M2).AddElemMultipl(7);
	(*M2).AddElemMultipl(4);
	(*M2).AddElemMultipl(3);
	(*M2).AddElemMultipl(5);
	(*M2).AddElemMultipl(2);

	(*M3).AddElemMultipl(8);
	(*M3).AddElemMultipl(1);
	(*M3).AddElemMultipl(4);

	cout << "M1:"; 
	(*M1).PrintMultipl();
	cout << "M2:";
	(*M2).PrintMultipl();
	cout << "M3:";
	(*M3).PrintMultipl();

	
	int buf=0;
	cout << "Input elem to find in M1:";
	cin >> buf;
	if((*M1).FindElemMultipl(buf))
		cout << buf << " founded in M1" << endl;
	else
		cout << buf << " not founded in M1" << endl;

	cout << "Input elem to delete in M1:";
	cin >> buf;
	(*M1).DelElemMultipl(buf);
	
	cout << "Input elem to find in M1:";
	cin >> buf;
	if((*M1).FindElemMultipl(buf))
		cout << buf << " founded in M1" << endl;
	else
		cout << buf << " not founded in M1" << endl;

	cout << "M1:"; 
	(*M1).PrintMultipl();
	cout << "M2:";
	(*M2).PrintMultipl();
	cout << "M3:";
	(*M3).PrintMultipl();

	(*MergeM1M3).MergeMultiple(M1,M3);
	cout << "Merge M1 and M3:" << endl;
	(*MergeM1M3).PrintMultipl();
	
	(*IntersectionM1M2).IntersectionMultiple(M1,M2);
	cout << "Intersection M1 and M2:" << endl;
	(*IntersectionM1M2).PrintMultipl();

	delete M1;
	delete M2;
	delete M3;

	return 0;
}
