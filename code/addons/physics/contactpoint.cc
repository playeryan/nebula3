//------------------------------------------------------------------------------
//  physics/contactpoint.cc
//  (C) 2005 Radon Labs GmbH
//------------------------------------------------------------------------------
#include "stdneb.h"
#include "physics/contactpoint.h"
#include "physics/physicsentity.h"
#include "physics/composite.h"

namespace Physics
{

//------------------------------------------------------------------------------
/**
    Returns pointer to entity of the contact point. This resolves an
    entity id into a pointer, so it may be slow.
*/
PhysicsEntity*
ContactPoint::GetEntity() const
{
    return PhysicsServer::Instance()->FindEntityByUniqueId(this->entityId);
}

//------------------------------------------------------------------------------
/**
    Returns pointer to rigid body of contact point. This resolves id's into
    pointer, so it may be slow.
*/
RigidBody*
ContactPoint::GetRigidBody() const
{
    // find entity
    PhysicsEntity* entity = this->GetEntity();
    if (entity)
    {
        return entity->GetComposite()->FindBodyByUniqueId(this->rigidBodyId);
    }
    else
    {
        return 0;
    }
}

}