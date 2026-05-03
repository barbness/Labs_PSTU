#pragma once
#include "Vector.h"
#include "Event.h"

class Dialog : public Vector {
private:
    int endState;

public:
    Dialog();
    Dialog(int n);
    ~Dialog();

    void GetEvent(TEvent& event);
    void HandleEvent(TEvent& event);
    void ClearEvent(TEvent& event);
    void Execute();

    int Valid() const;
    void EndExec();
    void EventError(const TEvent& event) const;
};