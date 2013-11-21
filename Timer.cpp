#include "Timer.h"

Timer::Timer(void) {
	secondsPlayed = 0;
	timeIn = 0;
	timeOut = 0;
}

Timer::~Timer(void) {};

time_t Timer::checkIn(void) {
	timeIn = time(NULL);
	return timeIn;
};

time_t Timer::checkOut(void) {
	timeOut = time(NULL);
	secondsPlayed = secondsPlayed + difftime(timeOut, timeIn);
	return timeOut;
};

double Timer::getSecondsPlayed(void) {return secondsPlayed;};
