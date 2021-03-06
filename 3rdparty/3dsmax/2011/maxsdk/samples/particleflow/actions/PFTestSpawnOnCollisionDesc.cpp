/**********************************************************************
 *<
	FILE:			PFTestSpawnOnCollisionDesc.cpp

	DESCRIPTION:	Duration Test Class Descriptor (definition)
											 
	CREATED BY:		Oleg Bayborodin

	HISTORY:		created 12-03-01

 *>	Copyright (c) 2001, All Rights Reserved.
 **********************************************************************/

#include "resource.h"

#include "PFTestSpawnOnCollisionDesc.h"

#include "PFActions_GlobalVariables.h"
#include "PFActions_GlobalFunctions.h"
#include "PFActions_SysUtil.h"
#include "PFTestSpawnOnCollision.h"
#include "PFClassIDs.h"
#include "IPFAction.h"

namespace PFActions {


HBITMAP PFTestSpawnOnCollisionDesc::m_depotIcon = NULL;
HBITMAP PFTestSpawnOnCollisionDesc::m_depotMask = NULL;

PFTestSpawnOnCollisionDesc::~PFTestSpawnOnCollisionDesc()
{
	if (m_depotIcon != NULL) {
		DeleteObject(m_depotIcon);
		m_depotIcon = NULL;
	}
	if (m_depotMask != NULL) {
		DeleteObject(m_depotMask);
		m_depotMask = NULL;
	}
}

int PFTestSpawnOnCollisionDesc::IsPublic()
{
	return 0;
}

void* PFTestSpawnOnCollisionDesc::Create(BOOL loading) 
{
	return new PFTestSpawnOnCollision();
}

const TCHAR* PFTestSpawnOnCollisionDesc::ClassName() 
{
	return GetString(IDS_TEST_SPAWNONCOLLISION_CLASS_NAME);
}

SClass_ID PFTestSpawnOnCollisionDesc::SuperClassID() 
{
	return HELPER_CLASS_ID;
}

Class_ID PFTestSpawnOnCollisionDesc::ClassID()
{
	return PFTestSpawnCollisionSW_Class_ID;
}

Class_ID PFTestSpawnOnCollisionDesc::SubClassID()
{
	return PFTestSubClassID;
}

const TCHAR* PFTestSpawnOnCollisionDesc::Category() 
{
	return GetString(IDS_PARTICLEFLOW_CATEGORY);
}

const TCHAR* PFTestSpawnOnCollisionDesc::InternalName()
{
	return _T("Collision_Spawn");
}

HINSTANCE PFTestSpawnOnCollisionDesc::HInstance()
{
	return hInstance;
}

INT_PTR PFTestSpawnOnCollisionDesc::Execute(int cmd, ULONG_PTR arg1, ULONG_PTR arg2, ULONG_PTR arg3)
{
	TCHAR** res = NULL;
	HBITMAP* depotIcon;
	HBITMAP* depotMask;
	switch( cmd )
	{
	case kPF_GetActionDescription:
		if (arg1 == NULL) return 0;
		res = (TCHAR**)arg1;
		*res = GetString(IDS_TESTSPAWNONCOLLISION_DESCRIPTION);
		break;
	case kPF_PViewCategory:
		if (arg1 == NULL) return 0;
		res = (TCHAR**)arg1;
		*res = GetString(IDS_PF_TEST_CATEGORY);
		break;
	case kPF_PViewDepotIcon:
		if (arg1 == NULL) return 0;
		depotIcon = (HBITMAP*)arg1;
		if (arg2 == NULL) return 0;
		depotMask = (HBITMAP*)arg2;
		if (m_depotIcon == NULL)
			m_depotIcon = LoadBitmap(hInstance, MAKEINTRESOURCE(IDB_SPAWNONCOLLISION_DEPOTICON));
		if (m_depotMask == NULL)
			m_depotMask = LoadBitmap(hInstance, MAKEINTRESOURCE(IDB_DEPOTICONMASK_TEST));
		*depotIcon = m_depotIcon;
		*depotMask = m_depotMask;
		break;
	default:
		return 0;
	}
	return 1;
}


} // end of namespace PFActions