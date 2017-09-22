#ifndef _DATE_TIME_H_
#define _DATE_TIME_H_

#include <stdint.h>
#include <time.h>
#include <assert.h>

class DateTime
{
    public:
        static uint64_t GetTickMS()
        {
            struct timespec ts;
            int ret = clock_gettime(CLOCK_MONOTONIC, &ts);
            assert(ret == 0);
            return (uint64_t) ts.tv_sec * 1000 + (uint64_t) ts.tv_nsec/1000000;
        }

        static uint32_t GetNowSec()
        {
            return time(NULL);
        }
};

#endif
