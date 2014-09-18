#ifndef __MULTIPLICITY_HPP__
#define __MULTIPLICITY_HPP__

class ListElem
{
	private:
		struct ListEl
		{
			int iElem;
			ListEl *leNext;
		};
		
	public:
		ListEl *leBegin,**leTmp;

		ListElem();
		~ListElem();

		int RetElem(ListEl *leBuf);
		void AddElem(int iNewElem);
		void DelElem(int iRemovedElem);
		bool FindElem(int iFoundElem);
		void PrintListElem();
		ListElem *MergeList(ListElem *leA,ListElem*leB);
		ListElem *IntersectionList(ListElem *leA,ListElem*leB);
};

class Multiplicity:ListElem
{
	private:
		ListElem *leMultipl;
	public:
		Multiplicity();
		~Multiplicity();

		void PrintMultipl();
		int RetElemMultiple();
		void AddElemMultipl(int iNewElem);
		void DelElemMultipl(int iRemovedElem);
		bool FindElemMultipl(int iFoundElem);
		void MergeMultiple(Multiplicity *leA,Multiplicity *leB);
		void IntersectionMultiple(Multiplicity *leA,Multiplicity *leB);
		
};


#endif
