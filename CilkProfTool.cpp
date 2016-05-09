/*
 * CilkProfTool.h
 
 *  Created on: May 9, 2016
 *      Author: knapp
 */

#include <vector>
#include "CilkProfTool.h"
#include <iostream>
#include <array>
#include <set>
#include <map>
#include <vector>
#include <memory>
#include "Interpreter.h"
#include "Event.h"
#include "ShadowThread.h"
#include "ShadowVar.h"
#include "ShadowLock.h"
#include "DataModel.h"
#include "DBDataModel.h"
#define THREADS 100


CilkProfTool::CilkProfTool() {

	this->cilkprof = new CilkProf;
	this->threadFunctionMap = new threadFunctionMap;
}	

CilkProfTool::~CilkProfTool() {

	delete this.cilkprof;
	delete this.threadFunctionMap;
}

void CilkProfTool::create(const Event* e) {

	// F spawns or calls G:

	// G.w = 0
	// G.p = 0
	// G.l = 0
	// G.c = 0

	CallInfo *_info = e->getCallInfo();
	this->cilkprof->addFunctionWorkSpan(_info->fnSignature, 0.0, 0.0, 0.0, 0.0);
}

void CilkProfTool::join(const Event* e) {

	// Spawned G returns to F
	// G.p += G.c
	// F.w += G.w
	// if F.c + G.p > F.l
	// 		F.l = G.p
	// 		F.p += G.c
	// 		F.c = 0

	JoinInfo *_info = e->getJoinInfo();
	ShadowThread* childThread = _info->childThread;

	const char* F_signature = this.threadFunctionMap[currentThread.threadId];
	const char* G_signature = this.threadFunctionMap[childThread.threadId];

void CilkProfTool::acquire(const Event* e) {

	// F syncs
	// if F.c > F.l
	// 		F.p += F.c
	// else
	// 		F.p += F.l
	// F.c = 0
	// F.l = 0

	AcquireInfo *_info = e->getAcquireInfo();
}


void CilkProfTool::call(const Event* e) {

	// F spawns or calls G:
	// G.w = 0
	// G.p = 0
	// G.l = 0
	// G.c = 0

	CallInfo *_info = e->getCallInfo();

}

void CilkProfTool::access(const Event* e) {


	AccessInfo *_info = e->getAccessInfo();

}

void CilkProfTool::release(const Event* e) {

	ReleaseInfo *_info = e->getReleaseInfo();
}


void CilkProfTool::returnOfCalled(const Event* e){

	// Called G returns to F:
	// G.p += G.c
	// F.w += G.w
	// F.c += G.p

}







