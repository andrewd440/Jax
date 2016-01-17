#pragma once

#include "Vector3.h"
#include "ImportExports.h"

namespace JaxMat
{
	/**
	* Class for representing a ray in 3D space.
	*/
	struct FRay
	{
		/**
		* Constructs a ray from an origin point that points in a
		* given direction.
		* @param OriginiPoint - The origin of the ray
		* @param DirectionVector - A direction for the ray (not normalized on construction)
		*/
		FRay(Vector3f OriginPoint = Vector3f(), Vector3f DirectionVector = Vector3f());

		/**
		* Calculates the point on the ray from the 't' parameter in the
		* ray equation.
		* @param t - Value for t in the ray equation
		* @return Point on the ray at t
		*/
		Vector3f GetPointAtParameter(float t) const;

		Vector3f Origin;		/* Origin or ray */
		Vector3f Direction;		/* Direction of ray */
	};

	inline FRay::FRay(Vector3f OriginPoint, Vector3f DirectionVector)
		: Origin(OriginPoint)
		, Direction(DirectionVector)
	{
	}

	inline Vector3f FRay::GetPointAtParameter(float t) const
	{
		return Origin + Direction * t;
	}
}