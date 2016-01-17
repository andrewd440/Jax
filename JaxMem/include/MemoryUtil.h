#pragma once

#include <cstdint>
#include "JaxCommon\Assertions.h"

#define JAXMEM_API __declspec(dllexport)

#define ALIGNED_ALLOC(Alignment) \
	void* operator new(size_t Size) { return JaxMem::FMemory::AllocateAligned(Size, (Alignment)); }  \
	void operator delete(void* Data) { JaxMem::FMemory::FreeAligned(Data); } \
	void* operator new[](size_t Size) { return JaxMem::FMemory::AllocateAligned(Size, (Alignment)); }  \
	void operator delete[](void* Data) { JaxMem::FMemory::FreeAligned(Data); } \

namespace JaxMem
{
	/**
	* Namespace for utility memory-based operations.
	*/
	namespace FMemory
	{
		/**
		* Allocates an unaligned chunk of memory on the heap. Memory allocated 
		* by this function must be freed with FMemory::FreeUnaligned. For aligned 
		* dynamic allocations, use FMemory::AllocateAligned
		*/
		JAXMEM_API void* AllocateUnaligned(const uint32_t Bytes);

		/**
		* Allocates an aligned chunk of memory on the heap. Memory allocated by 
		* this function must be freed with FMemory::FreeAligned.
		* @param Bytes Size of requested memory block.
		* @param Alignment Requested alignment of the memory block.
		*/
		JAXMEM_API void* AllocateAligned(const uint32_t Bytes, const uint32_t Alignment);

		/**
		* Frees a block of memory allocated by FMemory::AllocateUnaligned.
		* @param Data to be freed.
		*/
		JAXMEM_API void FreeUnaligned(void* Data);

		/**
		* Frees a block of memory allocated by FMemory::AllocateAligned.
		* @param Data to be freed.
		*/
		JAXMEM_API void FreeAligned(void* Data);

		/**
		* Check the alignment of a memory address.
		* @param Address - A pointer to the address to check.
		* @param Alignment - The address alignment to test against.
		* @return True if the address is aligned with the given alignment.
		**/
		inline JAXMEM_API bool IsAligned(const void* const Address, const uint32_t Alignment)
		{
			JAX_ASSERT(Alignment != 0);
			return (reinterpret_cast<uintptr_t>(Address) & (Alignment - 1)) == 0;
		}
	}
}