/*
 * Time.h
 *
 *  Created on: 2017. aug. 6.
 *      Author: peti
 */

#ifndef TIME_H_
#define TIME_H_

#include <stdint.h>

class Time {
public:
    Time();
    Time(uint32_t sec, uint16_t msec);
    ~Time() {}

    static Time now();
    static void setNow(const Time& value);

    void addSec(int32_t sec);
    void addMsec(uint16_t msec);

    inline uint32_t getSec() const {
        return sec;
    }
    inline uint16_t getMsec() const {
        return msec;
    }
    bool operator>(const Time& other) const;
    bool operator<(const Time& other) const;
    inline uint32_t toMsec() const {
        return sec * 1000 + msec;
    }

    static inline void tick();
    static uint32_t getTicksSinceStart();
private:
    uint32_t sec;
    uint16_t msec;

    void normalize();
};

#endif /* TIME_H_ */
