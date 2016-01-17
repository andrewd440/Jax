#pragma once
#include <iostream>
#include <cstdint>


#ifndef JAX_ASSERT
#ifndef NDEBUG
 
#define debugBreak() __asm { int 3 };

#define JAX_ASSERT(expr) \
	if (expr) { } \
	else \
	{ \
		Jax::ReportAssertionFailure(#expr, \
						__FILE__, __LINE__); \
		debugBreak(); \
	}

namespace Jax
{
	inline void ReportAssertionFailure(const char* Expr, const char* File, const uint32_t Line)
	{
		std::cerr << "Jax Assertion Failed: " << Expr << " File: " << File << " Line: " << Line << std::endl;
	}
}

#else

#define JAX_ASSERT(expr) // does nothing

#endif
#endif