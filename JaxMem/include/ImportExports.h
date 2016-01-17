#pragma once

#ifdef JAXMEM_EXPORTS
#define JAXMEM_API __declspec(dllexport)
#else
#define JAXMEM_API __declspec(dllimport)
#endif