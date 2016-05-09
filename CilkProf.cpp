/*
 * CilkProf.cpp
 *
 *  Created on: Dec 12, 2015
 *      Author: knapp
 */

#include <vector>
#include "CilkProf.h"

CilkProf::CilkProf() {
	
	workSpanMap = WorkSpanMap();
}	

CilkProf::~CilkProf() {

	workSpanMap.clear();
}

CilkProf::addFunctionWorkSpan(const char* functionSignature, double work, double prefix, double longest-child, double continuation)  {

	WorkSpan_ newWorkSpan = {functionSignature, work, prefix, longest-child, continuation};
	workSpanMap.insert(std::pair<char*, WorkSpan> (functionSignature, newWorkSpan));
}

CilkProf::changeFunctionWorkSpan(const char* functionSignature, double work, double prefix, double longest-child, double continuation)  {

	workSpanMap.erase(functionSignature);
	WorkSpan_ newWorkSpan = {functionSignature, work, prefix, longest-child, continuation};
	workSpanMap.insert(std::pair<char*, WorkSpan> (functionSignature, newWorkSpan));
}


