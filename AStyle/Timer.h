#ifndef TIMER_H
#define TIMER_H

#include <list>
using std::list;
#include "TimeEvent.h" // OnTimer
#include "Parser.h" // ???
#include "Scene.h" // ???
#include "Console.h" // ???

#if BUILDING_DLL
#define DLLIMPORT __declspec(dllexport)
#else
#define DLLIMPORT __declspec(dllimport)
#endif

class DLLIMPORT Timer {
		friend class Timers; // this has access to everything
		std::list<Timer*>::iterator bufferlocation;
		bool running; // opposite of paused
		int miliseconds;
	public:
		Timer();
		~Timer();
		bool IsRunning();
		bool IsFinished();
		void AddEvent(void (*function)(void* sender,double data),void* sender);
		void SetTime(int miliseconds, bool set);
		void OnUpdateTime(double dt);

		// Events
		TimeEvent* OnTimer;
};

#endif
