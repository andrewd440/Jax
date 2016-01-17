#pragma once

#include "Vector3.h"
#include "ImportExports.h"

namespace JaxMat
{
	struct FMatrix4;

	struct JAXMAT_API FBox
	{
		Vector3f Min;
		Vector3f Max;

		/**
		* Constucts a box 2 unit cubic sized box centered at origin.
		*/
		FBox();

		Vector3f GetCenter() const { return (Min + Max) * 0.5f; }

		void TransformAABB(const FMatrix4& Transform);
		Vector3f GetDimensions() const;
	};

	inline Vector3f FBox::GetDimensions() const
	{
		return Max - Min;
	}
}