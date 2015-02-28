#ifndef SCRIPTS_H
#define SCRIPTS_H

#include <list>
using std::list;
#include "Timer.h"

#if BUILDING_DLL
#define DLLIMPORT __declspec(dllexport)
#else
#define DLLIMPORT __declspec(dllimport)
#endif

class Timer;

class DLLIMPORT Timers {
	private:
		list<Timer*> timerlist;
		static void StaticOnUpdateTime(void* sender,double data);
		friend class Scene; // Deze mag bij OnUpdateTime
	public:
		Timers();
		~Timers();
		void Add(Timer* timer);
		void Delete(Timer* timer);
		void Clear();
		void OnUpdateTime(float dt);
		void SaveToCSV();
};

#endif
