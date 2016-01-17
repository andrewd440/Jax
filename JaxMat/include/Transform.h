#pragma once

#pragma warning ( disable : 4251 )

#include "Vector3.h"
#include "Quaternion.h"
#include "ImportExports.h"

namespace JaxMat
{
	/**
	* Class for representing 3D spatial information for an object.
	*/
	class JAXMAT_API FTransform
	{
	public:

		/**
		* Ctor
		* Constructs a transform with an optional origin position and scale.
		*/
		FTransform(const Vector3f& Position = Vector3f{ 0, 0, 0 }, const float Scale = 1.0f);

		/**
		* Copy Ctor
		* Copies tranform spatial data and inherits parent information.
		*/
		FTransform(const FTransform& Other);

		/**
		* Dtor
		*/
		~FTransform() = default;

		/**
		* Copies tranform spatial data and inherits parent information.
		*/
		FTransform& operator=(const FTransform& Other);

		/**
		* Constructs a matrix that will transform local coordinates
		* to world coordinates.
		*/
		FMatrix4 LocalToWorldMatrix() const;

		/**
		* Constructs a matrix that will transform world coordinates
		* to local coordinates of this transform.
		*/
		FMatrix4 WorldToLocalMatrix() const;

		/**
		* Set the position of this tranform.
		*/
		void SetLocalPosition(const Vector3f& NewPosition);

		/**
		* Get the position of this transform.
		*/
		Vector3f GetLocalPosition() const;

		/**
		* Transforms a 3D position.
		* @param Vector - The vector to transform.
		* @return The transformed vector.
		*/
		Vector3f TransformPosition(const Vector3f& Position) const;

		/**
		* Transforms a 3D direction.
		* @param Vector - The vector to transform.
		* @return The transformed vector.
		*/
		Vector3f TransformDirection(const Vector3f& Direction) const;

		/**
		* Transforms a 3D position using the inverse of this transform.
		* @param Vector - The vector to transform.
		* @return The transformed vector.
		*/
		Vector3f InvTransformPosition(const Vector3f& Position) const;

		/**
		* Transforms a 3D direction using the inverse of this transform.
		* @param Vector - The vector to transform.
		* @return The transformed vector.
		*/
		Vector3f InvTransformDirection(const Vector3f& Direction) const;

		/**
		* Get the world position of this transform.
		*/
		Vector3f GetWorldPosition() const;

		/**
		* Translates this tranform.
		*/
		void Translate(const Vector3f& Translation);

		/**
		* Set the rotation.
		*/
		void SetRotation(const FQuaternion& NewRotation);

		/**
		* Get the rotation.
		*/
		FQuaternion GetRotation() const;

		/**
		* Rotates this tranform by a given amount.
		*/
		void Rotate(const FQuaternion& Rotation);

		/**
		* Set the scale.
		*/
		void SetScale(const Vector3f NewScale);

		/**
		* Get the scale.
		*/
		Vector3f GetScale() const;

		/**
		* Set the parent of this object. All transform data will be
		* relative to the parent if set.
		*/
		void SetParent(FTransform* NewParent);

		/**
		* Get the parent of this object. All transform data will be
		* relative to the parent if set.
		*/
		FTransform* GetParent() const;

	private:
		FQuaternion mRotation;
		Vector3f mTranslation;
		Vector3f mScale;
		FTransform* mParent;
	};
}
#include "Transform.inl"