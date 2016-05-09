/*
 * CilkProf.cpp
 *
 *  Created on: Dec 12, 2015
 *      Author: knapp
 */

#include <vector>
#include "CilkProf.h"

CilkProf::CilkProf() {
	
	workSpanMap = new WorkSpanMap();
}	

CilkProf::~CilkProf() {

	workSpanMap.clear();
}

CilkProf::CilkProf::addFunctionWorkSpan(const char* functionSignature, double work, double prefix, double longest-child, double continuation)  {

	WorkSpan_ newWorkSpan = {functionSignature, work, prefix, longest-child, continuation};
	workSpanMap.insert(std::pair<char*, WorkSpan> (functionSignature, &newWorkSpan));
}

CilkProf::changeFunctionWorkSpan(const char* functionSignature, double work, double prefix, double longest-child, double continuation)  {

	workSpanMap.erase(functionSignature);
	WorkSpan_ newWorkSpan = {functionSignature, work, prefix, longest-child, continuation};
	workSpanMap.insert(std::pair<char*, WorkSpan> (functionSignature, &newWorkSpan));
}

CilkProf::incrementFunctionWorkSpan(const char* functionSignature, double work_diff, double prefix_diff, double longest-child_diff, 
	 								double continuation_diff)  {

	workSpanMap.erase(functionSignature);
	WorkSpan_ newWorkSpan = {functionSignature, work + work_diff, prefix + prefix_diff, longest-child + longest-child_diff, 
		                     continuation + continuation_diff};
	workSpanMap.insert(std::pair<char*, WorkSpan> (functionSignature, &newWorkSpan));
}

CilkProf::setWork(const char* functionSignature, double wrk){

	WorkSpan_* ws = workSpanMap[functionSignature];
	ws->work = wrk;
}

CilkProf::setPrefix(const char* functionSignature, double prfix){

	WorkSpan_* ws = workSpanMap[functionSignature];
	ws->prefix = prfix;
}

CilkProf::setLongestChild(const char* functionSignature, double lngest_child){

	WorkSpan_* ws = workSpanMap[functionSignature];
	ws->longest_child = lngest_child;
}

CilkProf::setContinuation(const char* functionSignature, double cntinuation){


	WorkSpan_* ws = workSpanMap[functionSignature];
	ws->continuation = cntinuation;
}


CilkProf::addToWork(const char* functionSignature, double work_diff){


	WorkSpan_* ws = workSpanMap[functionSignature];
	ws->work += work_diff;

}

CilkProf::addToPrefix(const char* functionSignature, double prefix_diff){

	WorkSpan_* ws = workSpanMap[functionSignature];
	ws->prefix += prefix_diff;
}

CilkProf::addToLongestChild(const char* functionSignature, double longest_child_diff){

	WorkSpan_* ws = workSpanMap[functionSignature];
	ws->longest_child += longest_child_diff;
}

CilkProf::addToContinuation(const char* functionSignature, double continuation_diff){

	WorkSpan_* ws = workSpanMap[functionSignature];
	ws->continuation += continuation_diff;
}








