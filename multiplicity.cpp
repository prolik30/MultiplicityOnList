#define _CRT_SECURE_NO_WARNINGS

#include <assert.h>
#include <iostream>
#include "multiplicity.hpp"

ListElem::ListElem():leBegin(NULL),leTmp(NULL)
{
}

void ListElem::AddElem(int iNewElem)
{
	ListEl **tmp=&leBegin,*leHelper;
	while(*tmp)
	{
		if((*tmp)->iElem > iNewElem)
			break;
		else if((*tmp)->iElem == iNewElem)
			return;
		tmp=&(*tmp)->leNext;
	}

	leHelper=(*tmp);
	(*tmp)=new ListEl;
	(*tmp)->iElem=iNewElem;
	(*tmp)->leNext=leHelper;
}

void ListElem::DelElem(int iRemovedElem)
{
	ListEl **tmp=&leBegin,*leHelper;
	while((*tmp)->iElem != iRemovedElem)
		tmp=&(*tmp)->leNext;
	
	leHelper=(*tmp)->leNext;
	delete (*tmp);
	(*tmp)=leHelper;
}

bool ListElem::FindElem(int iFoundElem)
{
	ListEl **tmp=&leBegin;
	while(*tmp)
	{
		if((*tmp)->iElem == iFoundElem)
			return true;
		tmp=&(*tmp)->leNext;
	}
	return false;
}

void ListElem::PrintListElem()
{
	ListEl **tmp=&leBegin;
	while(*tmp)
	{
		std::cout<<(*tmp)->iElem<<" ";
		tmp=&(*tmp)->leNext;
	}
	std::cout<<std::endl;
	return;
}

int ListElem::RetElem(ListEl *mBuf)
{
	return mBuf->iElem;
}

ListElem::~ListElem()
{
	ListEl *tmp=leBegin;

	while(tmp)
	{
		tmp=leBegin->leNext;
		delete leBegin;
		leBegin=tmp;
	}
}

Multiplicity::Multiplicity():leMultipl(NULL)
{
	leMultipl=new ListElem;
}

Multiplicity::~Multiplicity()
{
	(*leMultipl).~ListElem();
}

void Multiplicity::PrintMultipl()
{
	(*leMultipl).PrintListElem();
}

void Multiplicity::AddElemMultipl(int iNewElem)
{
	(*leMultipl).AddElem(iNewElem);
}

void Multiplicity::DelElemMultipl(int iRemovedElem)
{
	(*leMultipl).DelElem(iRemovedElem);
}

bool Multiplicity::FindElemMultipl(int iFoundElem)
{
	return (*leMultipl).FindElem(iFoundElem);
}

ListElem *ListElem::MergeList(ListElem *leA,ListElem *leB)
{
	ListElem *leNew=new ListElem;
	(*leA).leTmp=&(*leA).leBegin;
	(*leB).leTmp=&(*leB).leBegin;

	while(*(*leA).leTmp && *(*leB).leTmp)
	{
		if((*leA).RetElem(*(*leA).leTmp) < (*leB).RetElem(*(*leB).leTmp))
		{
			(*leNew).AddElem( (*leA).RetElem(*(*leA).leTmp) );
			(*leA).leTmp=&(*(*leA).leTmp)->leNext;
		}
		else if((*leA).RetElem(*(*leA).leTmp) > (*leB).RetElem(*(*leB).leTmp))
		{
			(*leNew).AddElem( (*leB).RetElem(*(*leB).leTmp) );
			(*leB).leTmp=&(*(*leB).leTmp)->leNext;
		}
		else
		{
			(*leNew).AddElem( (*leB).RetElem(*(*leB).leTmp) );
			(*leA).leTmp=&(*(*leA).leTmp)->leNext;
			(*leB).leTmp=&(*(*leB).leTmp)->leNext;
		}
	}

	if(*(*leA).leTmp == NULL && *(*leB).leTmp != NULL)
		while(*(*leB).leTmp)
		{
			(*leNew).AddElem( (*leB).RetElem(*(*leB).leTmp) );
			(*leB).leTmp=&(*(*leB).leTmp)->leNext;
		}
	else if(*(*leB).leTmp == NULL && *(*leA).leTmp != NULL)
		while(*(*leA).leTmp)
		{
			(*leNew).AddElem( (*leA).RetElem(*(*leA).leTmp) );
			(*leA).leTmp=&(*(*leA).leTmp)->leNext;
		}

//	(*leA).~ListElem();
//	(*leB).~ListElem();


	return leNew;
}

void Multiplicity::MergeMultiple(Multiplicity *mA,Multiplicity *mB)
{
	leMultipl = (*leMultipl).MergeList((*mA).leMultipl,(*mB).leMultipl);
}

ListElem *ListElem::IntersectionList(ListElem *leA,ListElem *leB)
{
	ListElem *leNew=new ListElem;
	(*leA).leTmp=&(*leA).leBegin;
	(*leB).leTmp=&(*leB).leBegin;

	while(*(*leA).leTmp && *(*leB).leTmp)
	{
		if((*leA).RetElem(*(*leA).leTmp) < (*leB).RetElem(*(*leB).leTmp))
			(*leA).leTmp=&(*(*leA).leTmp)->leNext;
		else if((*leA).RetElem(*(*leA).leTmp) > (*leB).RetElem(*(*leB).leTmp))
			(*leB).leTmp=&(*(*leB).leTmp)->leNext;
		else
		{
			(*leNew).AddElem( (*leA).RetElem(*(*leA).leTmp) );
			(*leA).leTmp=&(*(*leA).leTmp)->leNext;
			(*leB).leTmp=&(*(*leB).leTmp)->leNext;
		}
	}

//	(*leA).~ListElem();
//	(*leB).~ListElem();

	return leNew;
}

void Multiplicity::IntersectionMultiple(Multiplicity *mA,Multiplicity *mB)
{
	leMultipl = (*leMultipl).IntersectionList((*mA).leMultipl,(*mB).leMultipl);
}
