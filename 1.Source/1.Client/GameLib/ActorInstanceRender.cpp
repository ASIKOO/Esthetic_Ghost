//search 

void CActorInstance::BeginDiffuseRender()

//add above

#ifdef ENABLE_GHOST_MODE

BOOL CActorInstance::IsGhostWeapon()
{
	DWORD ghost = GetPartItemID(CRaceData::PART_WEAPON);
	switch (ghost)
	{
		case 299:
		case 19:
			return TRUE;
	}
	return FALSE;
}
#endif

//search 

void CActorInstance::BeginDiffuseRender()
{
	STATEMANAGER.SetTextureStageState(0, D3DTSS_COLORARG1,	D3DTA_TEXTURE);
	STATEMANAGER.SetTextureStageState(0, D3DTSS_COLORARG2,	D3DTA_DIFFUSE);
	STATEMANAGER.SetTextureStageState(0, D3DTSS_COLOROP,	D3DTOP_MODULATE);
	STATEMANAGER.SetTextureStageState(0, D3DTSS_ALPHAARG1,	D3DTA_TEXTURE);
	STATEMANAGER.SetTextureStageState(0, D3DTSS_ALPHAARG2,	D3DTA_DIFFUSE);
	STATEMANAGER.SetTextureStageState(0, D3DTSS_ALPHAOP,	D3DTOP_MODULATE);

	STATEMANAGER.SaveRenderState(D3DRS_ALPHABLENDENABLE, FALSE);
	
//modify last line with

#ifdef ENABLE_GHOST_MODE
	(STATEMANAGER.SaveRenderState(D3DRS_ALPHABLENDENABLE, IsGhostWeapon()));
#else
	STATEMANAGER.SaveRenderState(D3DRS_ALPHABLENDENABLE, FALSE);
#endif
}
