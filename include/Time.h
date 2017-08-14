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
	Time(uint32_t sec, uint16_t msec, uint16_t usec);
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
	bool operator<(const Time& other) const;
	bool operator>(const Time& other) const;
	uint32_t toMsec() const;
private:
	uint32_t sec;
	uint16_t msec;
	uint16_t usec;

	void normalize();
};

#endif /* TIME_H_ */
