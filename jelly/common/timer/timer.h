#ifndef _TIMER_H_
#define _TIMER_H_

#include "utils/double_link.h"

class Timer : public DoubleLinkNode
{
public:
    Timer():timeout(0){}
    virtual ~Timer() {}

    virtual void OnTimeOut() = 0;

    void SetTimeOut(uint32_t timeout) {this->timeout = timeout;}

    uint32_t GetTimeOut() {return timeout;}

private:
    uint32_t timeout;
};

class TimerMgr
{
    struct Wheel
    {
        Wheel(uint32_t wheel_no);
        ~Wheel();

        uint32_t wheel_no;
        DoubleLink *tlist;
        uint32_t cur_slot;
    };

public:

    TimerMgr();

    ~TimerMgr();

    int32_t RegisterTimer(Timer *pTimer, uint32_t timeout);

    static int32_t UnRegisterTimer(Timer *pTimer);

    void Tick();

private:
    void Step();

private:
    static const uint32_t WHEEL_CNT = 5;
    uint32_t last_tick;
    Wheel    *wheels[WHEEL_CNT];
};

#endif
