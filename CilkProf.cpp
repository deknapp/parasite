/*
 * CilkProf.cpp
 *
 *  Created on: Dec 12, 2015
 *      Author: knapp
 */

#include <vector>
#include "CilkProf.h"

CilkProf::CilkProf() {
	
	WorkSpanMap = WorkSpanMap();
}	

CilkProf::~CilkProf() {

	workSpanMap.clear();
}

CilkProf::addFunctionWorkSpan(const char* functionSignature, double work, double prefix, double longest-child, double continuation)  {

	WorkSpan_ newWorkSpan = {functionSignature, work, prefix, longest-child, continuation};
	WorkSpanMap.insert(std::pair<char*, WorkSpan> (functionSignature, newWorkSpan));
}


