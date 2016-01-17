
#include "JaxMem\MemoryUtil.h"
#include "JaxMat\Frustum.h"

int main()
{
	using namespace JaxMem;
	using namespace JaxMat;

	static_assert(alignof(FFrustum) == 16, "4 component vector not aligned.");
	static_assert(alignof(Vector4ui) == 16, "4 component vector not aligned.");
	static_assert(alignof(Vector4i) == 16, "4 component vector not aligned.");

	FMemory::IsAligned(0, 0);

	return 0;
}