#pragma once

#ifdef JAXMAT_EXPORTS
	#define JAXMAT_API __declspec(dllexport)
#else
	#define JAXMAT_API __declspec(dllimport)
#endif