#ifndef _GFX_H
#define _GFX_H

#include "stdtypes.h"

typedef struct BasicTexture BasicTexture;
typedef struct ViewportInfo ViewportInfo;

typedef struct GfxState
{
	// Special effects flags
	U32 waterThisFrame:1;
	U32 postprocessing:1;
	U32 renderscale:1;
	U32	renderToPBuffer:1;
	U32 stencilAvailable:1;
	U32 doStencilShadows:1;
	U32 doCubemaps:1;
	U32 doPlanarReflections:1;	// for buildings, not water

	U32 screenshot:1; // Updating the screen for a screenshot

	U32	mainViewport:1;	// set if we are rendering the main viewport
	U32 prevFrameReflectionValid:1;
	S32 renderPass;
	U32 writeDepthOnly:1;

	U32 viewCacheCaching:1;
	U32 viewCacheInUse:1;

	// lod_model_override is used to force rendering of a specific environment model (GroupDef) LOD 
	U32 lod_model_override;		// 0 for no override, MAX_LODS to force to lowest LOD (any other values will cause incorrect results)

	Mat44 projection_matrix;
	
	// Used for clipping underwater alpha objects
	float waterReflectionScore;
	F32 waterPlane[4];

	float reflectionCandidateScore;
	F32 nextFrameReflectionPlane[4];

	F32 prevFrameReflectionPlane[4];

	// For debugging
	Vec3 reflectionQuadVerts[4];

	// Sometimes other viewports need to reference the main viewports settings
	// (e.g., shadowmap rendering culls to the main camera view frustum even though
	// it renders from the shadow light view)
	ViewportInfo*	main_viewport_info;	

	ViewportInfo*	current_viewport_info;	

	// Used to determine cubemap reflection attenuation
	Vec3 cubemap_origin;
	Vec3 cubemap_origin_vs;

	float	vis_limit_entity_dist_from_player;	// used by viewports to cull entities at a certain distance from player

	Vec3	shadowmap_light_direction_ws;	// world space light direction used for shadow map generation (sun direction but may be clamped)
	Vec3	shadowmap_light_direction_vs;	// view space light direction used for shadow map generation (sun direction but may be clamped)

	F32		shadowmap_extrusion_scale;		// 1.0f / shadowmap_light_direction_ws[1]
	F32		lowest_visible_point_last_frame;	// used by shadow maps to determine extrusion length
	F32		lowest_visible_point_this_frame;	// lowest point found so far this frame
} GfxState;

extern GfxState gfx_state;

// Generated by mkproto
void waitFps(int fps);
void showFrameRate(void);
void fixCamMat(Mat4 mat);
void gfxSetViewMat(Mat4 cammat,Mat4 viewmat,Mat4 inv_viewmat);
void gfxReload(int unloadAllModels);
void gfxUpdateFrame(int force_render_world, int headShot, int no_drawing);
void gfxDoNothingFrame(void);
void gfxLoadRelevantTextures(void);
void gfxResetTextures(void);
void gfxTextureDump(int texid, char *fn);
void gfxRenderDump(char *fn, ...);
void setVisScale(F32 vis_scale, int setGameState);

void gfxRenderViewport(ViewportInfo *viewport_info);

// Individual bits of drawing a frame for headshots, etc
void gfxDrawSetupDrawing(ViewportInfo *viewport);

void gfxSetupLetterBoxViewport(void);
void gfxPrepareforLoadingScreen(void);

// End mkproto
#endif