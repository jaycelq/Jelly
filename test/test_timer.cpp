#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include "timer/timer.h"
#include "detail/socket_type.h"

class TestTimer : public Timer
{
public:
    TestTimer()
    {
    }

    void OnTimeOut()
    {
        uint32_t now = time(NULL);
        printf("now: %u, timer_now: %u\n", now, timer_now);
        timer_now++;
    }
private:
    static uint32_t timer_now;
};

uint32_t TestTimer::timer_now = time(NULL);

TimerMgr timerMgr;

int main()
{
    uint32_t sleep_seconds = 0;

    TestTimer t[1024];

    printf("Test 1: Tick 50\n");
    while(true)
    {
        timerMgr.Tick();
        timerMgr.RegisterTimer(&t[0], 1);
        usleep(50000);
        sleep_seconds++;
        if (sleep_seconds > 200)
            break;
    }
    
    printf("Test 2: Tick:1023\n");
    for (int32_t i = 1; i < 1024; i++)
    {
        timerMgr.RegisterTimer(&t[i], i);
    }

    bool remove = false;
    while(true)
    {
        timerMgr.Tick();

        if (remove == false)
        {
            TimerMgr::UnRegisterTimer(&t[3]);
            TimerMgr::UnRegisterTimer(&t[4]);
        }
        usleep(50000);
    }

    return 0;
}
