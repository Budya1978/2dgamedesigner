#ifndef RedoUndoManager_h
#define RedoUndoManager_h

#include "LevelSet.h"

class RedoUndoManager {

public:

    ~RedoUndoManager();
    RedoUndoManager();

    static const int MAX_UNDO_STEPS = 32;

    // ������� ����� � ����������� �� � ����� �����,
    // ���� ���� ������������� - ������� ������
    // ���� �� ����� ��������� undo - �� ������� ��� ����� ������� ������
    void PushCopy(LevelSet *lset, const QVector<BeautyBase *> &currentBeauty);

    // ��������� ������� ������, ������ ������ �� ������ �������
    LevelSet * Undo(QVector<int> &beauty);

    // �������� Undo - ���� ����� - ����������� ������� ������, ������ ������ �� ������ �������
    LevelSet * Redo(QVector<int> &beauty);

    // ������� ����������
    void Clear();

    // ������� ��� ��� ��������
    void ClearRedo();

private:

    struct OneState {
        LevelSet *levelSet;
        QVector<int> selectedBeauty;
    };

    QVector<OneState> _history;

    int _currentVersion;

    int SearchBeautyOrder(LevelSet *levelSet, BeautyBase *beauty);

};

#endif//RedoUndoManager_h
