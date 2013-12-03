#ifndef TIMER_H_
#define TIMER_H_

#include <time.h>

class Timer {
private:
	double secondsPlayed;	//time played in seconds
	time_t timeIn;	//time player entered game
	time_t timeOut;	//time player left game
public:
	Timer(void);
	~Timer(void);
	time_t checkIn(void);
	time_t checkOut(void);
	double getSecondsPlayed(void);
};

#endif /*TIMER_H_*/
