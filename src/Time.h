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
	~Time() {}

	static Time now();
	static Time preciseNow();
	void addMsec(uint16_t msec);

	inline uint32_t getSec() const {
		return sec;
	}
	inline uint16_t getMsec() const {
		return msec;
	}
	inline uint16_t getUsec() const {
		return usec;
	}
private:
	uint32_t sec;
	uint16_t msec;
	uint16_t usec;

	void normalize();
};

#endif /* TIME_H_ */
