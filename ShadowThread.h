/*
 * ShadowThread.h
 *
 *  Created on: Sep 1, 2014
 *      Author: wilhelma
 */

#ifndef SHADOWTHREAD_H_
#define SHADOWTHREAD_H_

#include "Event.h"

/******************************************************************************
 * ShadowThread
 *****************************************************************************/
class ShadowThread {
public:
	typedef unsigned int ThreadId;

	ShadowThread(ThreadId threadId);
	const ThreadId threadId;

	bool operator < (const ShadowThread& other) const;

	//template<typename Key, typename Value> static Decoration<Key, Value> makeDec(const Value& init) {
	//	return Decoration<Key, Value>(init);	
	// }

private:

	// prevent generated functions
	ShadowThread(const ShadowThread&);
	ShadowThread& operator=(const ShadowThread&);
};

#endif /* SHADOWTHREAD_H_ */
