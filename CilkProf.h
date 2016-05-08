/*
 * CilkProf.h
 *
 *  Created on: May 8, 2016
 *      Author: knapp
 */

#ifndef CILKPROF_H_
#define CILKPROF_H_

#include <vector>	

// maps function signatures to their FunctionInfo_ structure
typedef std::map<const char*, WorkSpan_> WorkSpanMap;

// stores the work-span variables of a function
typedef struct WorkSpan_ {

	// parent function signature
	const char* parentFunctionSignature;
	// function signature
	const char* functionSignature;
	// work 
	double work;
	// prefix
	double prefix;
	// longest-child
	double longest_child;
	// continuation
	double continuation;

} WorkSpan_;

// class to contain information used in CilkProf algorithm
class CilkProf {

	public:
					   
		const WorkSpanMap getWorkSpanMap() const;
		CilkProf();
		~CilkProf();
		// add function and it's corresponding WorkSpanInfo
		addFunctionWorkSpan();

	private:

		WorkSpanMap workSpanMap;
		// prevent generated functions
		CilkProf(const CilkProf&);
		CilkProf& operator=(const CilkProf&);
};

#endif /* CILKPROF_H_ */