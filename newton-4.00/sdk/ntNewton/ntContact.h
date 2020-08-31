/* Copyright (c) <2003-2019> <Julio Jerez, Newton Game Dynamics>
* 
* This software is provided 'as-is', without any express or implied
* warranty. In no event will the authors be held liable for any damages
* arising from the use of this software.
* 
* Permission is granted to anyone to use this software for any purpose,
* including commercial applications, and to alter it and redistribute it
* freely, subject to the following restrictions:
* 
* 1. The origin of this software must not be misrepresented; you must not
* claim that you wrote the original software. If you use this software
* in a product, an acknowledgment in the product documentation would be
* appreciated but is not required.
* 
* 2. Altered source versions must be plainly marked as such, and must not be
* misrepresented as being the original software.
* 
* 3. This notice may not be removed or altered from any source distribution.
*/

#ifndef __DGCONTACT_H__
#define __DGCONTACT_H__

#include "ntStdafx.h"
#include "ntConstraint.h"

class ntBody;
class ntShapeInstance;

D_MSC_VECTOR_ALIGNMENT
class ntContactPoint
{
	public:
	dVector m_point;
	dVector m_normal;
	const ntBody* m_body0;
	const ntBody* m_body1;
	const ntShapeInstance* m_collision0;
	const ntShapeInstance* m_collision1;
	//dInt64 m_shapeId0;
	//dInt64 m_shapeId1;
	//dFloat32 m_penetration;
} D_GCC_VECTOR_ALIGNMENT;


D_MSC_VECTOR_ALIGNMENT 
//class ntContact: public ntConstraint, public dgList<dgContactMaterial>
class ntContact: public ntConstraint
{
	public:
	D_NEWTON_API ntContact(ntBody* const body0, ntBody* const body1);
	D_NEWTON_API virtual ~ntContact();

	D_NEWTON_API void AttachToBodies();
	D_NEWTON_API void DetachFromBodies();

	ntContact* GetAsContact() { return this; }
	
	dVector m_positAcc;
	dQuaternion m_rotationAcc;
	dList<ntContact, dContainersFreeListAlloc<ntContact>>::dListNode* m_linkNode;
	dFloat32 m_timeOfImpact;
	dFloat32 m_separationDistance;
	dUnsigned32 m_maxDOF;
	dUnsigned32 m_broadphaseLru;
	bool m_active;
	bool m_isAttached;
	bool m_killContact;
} D_GCC_VECTOR_ALIGNMENT;

#if 0
DG_INLINE void dgContactMaterial::SetCollisionCallback (OnAABBOverlap aabbOverlap, OnContactCallback contact) 
{
	m_aabbOverlap = aabbOverlap;
	m_processContactPoint = contact;
}

DG_INLINE void dgContactMaterial::SetCollisionGenerationCallback (OnContactGeneration contactGeneration)
{
	m_contactGeneration = contactGeneration;
}

DG_INLINE void dgContactMaterial::SetCompoundCollisionCallback (OnCompoundCollisionPrefilter aabbOverlap)
{
	m_compoundAABBOverlap = aabbOverlap;
}

DG_INLINE void* dgContactMaterial::GetUserData () const
{
	return m_userData;
}

DG_INLINE void dgContactMaterial::SetUserData (void* const userData)
{
	m_userData = userData;
}

DG_INLINE void dgContactMaterial::SetAsSoftContact(dFloat32 regularizer)
{
	dgAssert(regularizer >= dFloat32 (0.0f));
	dgAssert(regularizer <= dFloat32 (1.0f));
	// re purpose some of the variable to store parameter for soft contact
	m_flags |= m_isSoftContact;
	m_skinThickness = regularizer;
}

DG_INLINE const dgContactMaterial* ntContact::GetMaterial() const
{
	return m_material;
}

DG_INLINE bool ntContact::IsDeformable() const 
{
	return false;
}

DG_INLINE void ntContact::SetDestructorCallback (OnConstraintDestroy destructor)
{
}

DG_INLINE void ntContact::SetTimeOfImpact(dFloat32 timetoImpact)
{
	m_timeOfImpact = timetoImpact;
}

DG_INLINE dFloat32 ntContact::GetTimeOfImpact() const
{
	return m_timeOfImpact;
}

DG_INLINE dFloat32 ntContact::GetClosestDistance() const
{
    return m_closestDistance;
}

DG_INLINE void ntContact::ResetMaxDOF()
{
	m_maxDOF = 0;
}

DG_INLINE dFloat32 ntContact::GetPruningTolerance() const
{
	return m_contactPruningTolereance;
}

DG_INLINE void ntContact::SetPruningTolerance(dFloat32 tolerance)
{
	m_contactPruningTolereance = dgAbs (tolerance);
}

DG_INLINE void ntContact::ResetSkeletonIntraCollision()
{
	m_skeletonIntraCollision = 0;
}

DG_INLINE bool ntContact::IsSkeletonIntraCollision() const
{
	return m_skeletonIntraCollision;
}

DG_INLINE void ntContact::ResetSkeletonSelftCollision()
{
	m_skeletonSelftCollision = 0;
}

DG_INLINE bool ntContact::IsSkeletonSelftCollision() const
{
	return m_skeletonSelftCollision;
}

DG_INLINE dFloat32 ntContact::GetImpulseContactSpeed() const
{
	return m_impulseSpeed;
}

DG_INLINE void ntContact::SetImpulseContactSpeed(dFloat32 speed)
{
	m_impulseSpeed = speed;
}
#endif



#endif 

