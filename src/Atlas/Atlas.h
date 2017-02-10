#ifndef ATLAS_H
#define ATLAS_H

#include <vector>
#include "assert.h"

class Atlas {

public:	

	//! �������������
	struct Rect
	{
		int x; 
		int y;
		int w;
		int h;

		Rect(int x, int y, int w, int h);
		void Set(int x, int y, int w, int h);
		Rect();
	};

	//! ������ ��������
	typedef std::vector<Rect *> List;


	Atlas(int SurfaceMaxWidth, int SurfaceMaxHeight);
	~Atlas();

	//! �������� �������
	// ���������� ��������� �� ���������� �������
	Rect * Alloc(int w,int h);

private:

	//! �������� ������� � ����������, ������ �������
	void Split(Rect *parent, int w, int h);

	//! ������ �������� �������� ������s
	List m_AreaRoots;
	List m_Busy;

};


#endif