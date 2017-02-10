// InputSystem.h: interface for the InputSystem class.
//
//////////////////////////////////////////////////////////////////////

#ifndef MYENGINE_INPUTSYSTEM_H
#define MYENGINE_INPUTSYSTEM_H

#include "types.h"
#include "Object.h"
#include <set>

//
// ���������� ��� �������� �����,
// ���� ����� ������������ ������� ���� - ����������� �� ����� ������
// ���� ��� - �� Object.h
//

class InputSystem 
	: public Object  
{
private:
	static float DOUBLE_CLICK_TIME; // ������������ ����� �� ������ ���� - ���� ����� ������ - ������� "������������"
	static float LONG_TAP_EPS; // ����������� �� ��������� �������� ���� �� ����� �������, ���� �������� ����� ������� - ������� "������������"
	static float LONG_TAP_TIME; // ����������� ����� �� ����� ������� - ���� ����� ������ - ������� "������������"
	static float _timeCounter; // ������� �������(����������� ����� ���� � ���������� ������� ������� ��� ���������� ������ ����
	static bool _longTap; // true - ���� ����� ������� "������� ���"
	static bool _doubleClick; // true - ���� ����� ��� ������� "������� ����"
	static FPoint _longTapPos;
	static InputSystem *_locked;// ���� ���� ��� ������ ������������ ����(�������/����������) - ��������� �� ����� MouseMove
	static std::set<int> _pressedKeys;
public:
	InputSystem();
	virtual ~InputSystem();
	// ��� ������ ������ �������������� 
	// ���� ����� ������������ �������������� �������

	// ���� �� ��������(������� ����� ������ ����)
	virtual void OnMouseDown(const FPoint &mousePos);
	// ��������� ������ ����(������� ���)
	virtual void OnMouseUp();
	// �������� ����
	virtual void OnMouseMove(const FPoint &mousePos);
	// �������� ����
	virtual bool OnMouseWheel(int direction);
	
	virtual bool OnKey(int key, bool bDown);

	// ���������� ������� � ���������
	virtual void OnLongTap(const FPoint &mousePos);
	// ������� ����
	virtual void OnDoubleClick(const FPoint &mousePos);

	// ���������� ����� ���������� ��� ���������� ������ OnMouseDown() � ������ �������
	virtual bool IsMouseOver(const FPoint &mousePos) = 0;
	
protected:
	// ��� �������(���������) ��������� ����� - ����� ������������, ���������� ����� ������
	void RemoveFromList(InputSystem *listener); 

private:
	typedef std::list<InputSystem *> Listeners;
	static Listeners _listeners;

	static void MouseWheel(int direction);
	static void LongTap();
	static void DoubleClick(const FPoint &mousePos);

public:
	static void MouseDown(const FPoint &mousePos);
	static void MouseUp();
	static void MouseMove(const FPoint &mousePos);

	static void Reset();
	static void Init();
	static bool CheckForEvent(float dt);

	static void OnKeyDown(int key);
	static void OnKeyUp(int key);
	static bool IsPressed(int key);

};

#endif//MYENGINE_INPUTSYSTEM_H