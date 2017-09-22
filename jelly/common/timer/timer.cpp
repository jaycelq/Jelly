#include <time.h>
#include <vector>
#include "timer.h"

// 每个时间轮的槽位数
const uint32_t ELEMENT_CNT_PER_WHEEL[] = { 4, 4, 4, 4, 4 };
// 访问每个时间轮需要右移的位数
const uint32_t RIGHT_SHIFT_PER_WHEEL[] = { 2, 2, 2, 2, 2 };
// 每个时间轮相当于有多少个基本Tick槽位
const uint32_t BASE_TICK_PER_WHEEL[] = { 1, 4, 4 * 4, 4 * 4 * 4, 4 * 4 * 4 * 4 };

TimerMgr::Wheel::Wheel(uint32_t wheel_no):wheel_no(wheel_no), tlist(NULL), cur_slot(0)
{
    tlist = new DoubleLink[ELEMENT_CNT_PER_WHEEL[wheel_no]];
}

TimerMgr::Wheel::~Wheel()
{
    delete [] tlist;
}

TimerMgr::TimerMgr():last_tick(0)
{
    for (uint32_t wheel_no = 0; wheel_no < WHEEL_CNT; wheel_no++)
    {
        wheels[wheel_no] = new Wheel(wheel_no);
    }
}

TimerMgr::~TimerMgr()
{
    for (uint32_t wheel_no = 0; wheel_no < WHEEL_CNT; wheel_no++)
    {
        delete wheels[wheel_no];
    }
}

int32_t TimerMgr::RegisterTimer(Timer* pTimer, uint32_t timeout)
{
    uint32_t wheel_no = 0;
    uint32_t offset = timeout;
    uint32_t left = timeout;

    while (offset >= ELEMENT_CNT_PER_WHEEL[wheel_no])
    {
        Wheel *wheel = wheels[wheel_no];
        offset >>= RIGHT_SHIFT_PER_WHEEL[wheel_no];
        left -= BASE_TICK_PER_WHEEL[wheel_no] * (ELEMENT_CNT_PER_WHEEL[wheel_no] - wheel->cur_slot - (wheel_no == 0 ? 0 : 1));
        wheel_no++;
    }

    left -= BASE_TICK_PER_WHEEL[wheel_no] * (offset - 1);
    uint32_t slot = (offset + wheels[wheel_no]->cur_slot) % ELEMENT_CNT_PER_WHEEL[wheel_no];
    pTimer->SetTimeOut(left);
    wheels[wheel_no]->tlist[slot].Push(pTimer);

    return 0;
}

int32_t TimerMgr::UnRegisterTimer(Timer *pTimer)
{
    if (pTimer == NULL || pTimer->pOwner == NULL)
    {
        return -1;
    }

    DoubleLink::Remove(pTimer);
    return 0;
}

void TimerMgr::Tick()
{
    uint32_t cur_tick = time(NULL);
    if (cur_tick > last_tick)
    {
        Step();
        last_tick = cur_tick;
    }
}

void TimerMgr::Step()
{
    std::vector<Timer*> timers;

    for (uint32_t wheel_no = 0; wheel_no < WHEEL_CNT; wheel_no++)
    {
        Wheel *wheel = wheels[wheel_no]; 
        wheel->cur_slot = (wheel->cur_slot + 1) % ELEMENT_CNT_PER_WHEEL[wheel_no];
        DoubleLink& cur_tlist = wheel->tlist[wheel->cur_slot];
        while (!cur_tlist.Empty())
        {
            if(wheel_no == 0 || ((Timer *)cur_tlist.GetFirst())->GetTimeOut() == 0)
            {
                Timer *pTimer = (Timer *)cur_tlist.Pop();
                timers.push_back(pTimer);
            }
            else
            {
                Timer *pTimer = (Timer *)cur_tlist.Pop();
                RegisterTimer(pTimer, pTimer->GetTimeOut());
            }
        }

        if (wheel->cur_slot != 0)
        {
            break;
        }
    }

    for (uint32_t i = 0; i < timers.size(); i++)
    {
        Timer *pTimer = timers[i];
        pTimer->OnTimeOut();
    }
}

