#pragma once
/*!	\file	gats/stopwatch.hpp
	\author	Garth Santor
	\date	2018/09/06
	\brief	High-performance timer class.
*/


#include <Windows.h>	// Win32: QueryPerformanceCounter(), LARGE_INTEGER

namespace gats {

	/*!	High-performance timer class.

		Use .start() to start the timer.
		Use .stop() to stop the timer.
		Use .ticks() to read the timer (only valid after .start()/.stop() both called.

		\note	Light-weight class - no error checking.
	*/
	class StopWatch {
		LARGE_INTEGER startTime;	// holds ticks since CPU powered on
		LARGE_INTEGER stopTime;		// holds ticks since CPU powered on
	public:
		void start() { QueryPerformanceCounter(&startTime); }
		void stop() { QueryPerformanceCounter(&stopTime); }
		decltype(startTime.QuadPart) ticks() const { return stopTime.QuadPart - startTime.QuadPart; }
	};
} // End-of-namespace: gats

