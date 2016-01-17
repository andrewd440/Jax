#pragma once

//////////////////////////////////////////////////////////////////////////////////////
////////////////////// Inlined FTransform ////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////
namespace JaxMat
{
	inline FTransform::FTransform(const Vector3f& Position, const float Scale)
		: mTranslation(Position)
		, mRotation()
		, mScale(Scale, Scale, Scale)
		, mParent(nullptr)
	{
	}

	inline FTransform::FTransform(const FTransform& Other)
		: mTranslation(Other.mTranslation)
		, mRotation(Other.mRotation)
		, mScale(Other.mScale)
		, mParent(Other.mParent)
	{
	}

	inline FTransform& FTransform::operator=(const FTransform& Other)
	{
		mTranslation = Other.mTranslation;
		mRotation = Other.mRotation;
		mScale = Other.mScale;
		mParent = Other.mParent;

		return *this;
	}

	inline void FTransform::SetLocalPosition(const Vector3f& NewPosition)
	{
		mTranslation = NewPosition;
	}

	inline Vector3f FTransform::GetLocalPosition() const
	{
		return mTranslation;
	}

	inline void FTransform::Translate(const Vector3f& Translation)
	{
		mTranslation += (mRotation * Translation);
	}

	inline Vector3f FTransform::TransformPosition(const Vector3f& Position) const
	{
		return (mRotation * (Position * mScale)) + mTranslation;
	}

	inline Vector3f FTransform::TransformDirection(const Vector3f& Direction) const
	{
		return (mRotation * (Direction * mScale));
	}

	inline Vector3f FTransform::InvTransformPosition(const Vector3f& Position) const
	{
		return (mRotation.Inverse() * (Position - mTranslation)) * (1.0f / mScale);
	}

	inline Vector3f FTransform::InvTransformDirection(const Vector3f& Direction) const
	{
		return (mRotation.Inverse() * Direction) * (1.0f / mScale);
	}

	inline void FTransform::SetRotation(const FQuaternion& NewRotation)
	{
		mRotation = NewRotation;
	}

	inline FQuaternion FTransform::GetRotation() const
	{
		return mRotation;
	}

	inline void FTransform::Rotate(const FQuaternion& Rotation)
	{
		mRotation *= Rotation;
	}

	inline void FTransform::SetScale(const Vector3f NewScale)
	{
		mScale = NewScale;
	}

	inline Vector3f FTransform::GetScale() const
	{
		return mScale;
	}

	inline void FTransform::SetParent(FTransform* NewParent)
	{
		mParent = NewParent;
	}

	inline FTransform* FTransform::GetParent() const
	{
		return mParent;
	}


	//////////////////////////////////////////////////////////////////////////////////////
	////////////////////// Non-Member Functions //////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////

	inline bool operator==(const FTransform& Lhs, const FTransform& Rhs)
	{
		return Lhs.GetParent() == Rhs.GetParent() &&
			Lhs.GetLocalPosition() == Rhs.GetLocalPosition() &&
			Lhs.GetRotation() == Rhs.GetRotation() &&
			Lhs.GetScale() == Rhs.GetScale();
	}

	inline bool operator!=(const FTransform& Lhs, const FTransform& Rhs)
	{
		return Lhs.GetParent() != Rhs.GetParent() ||
			Lhs.GetLocalPosition() != Rhs.GetLocalPosition() ||
			Lhs.GetRotation() != Rhs.GetRotation() ||
			Lhs.GetScale() != Rhs.GetScale();
	}
}