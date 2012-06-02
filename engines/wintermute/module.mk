MODULE := engines/wintermute
 
MODULE_OBJS := \
	Base/scriptables/ScEngine.o \
	Base/scriptables/ScScript.o \
	Base/scriptables/ScStack.o \
	Base/scriptables/ScValue.o \
	Base/scriptables/SXArray.o \
	Base/scriptables/SXDate.o \
	Base/scriptables/SXFile.o \
	Base/scriptables/SXMath.o \
	Base/scriptables/SxObject.o \
	Base/scriptables/SXMemBuffer.o \
	Base/scriptables/SXStore.o \
	Base/scriptables/SXString.o \
	Ad/AdActor.o \
	Ad/AdActorDir.o \
	Ad/AdEntity.o \
	Ad/AdGame.o \
	Ad/AdInventory.o \
	Ad/AdInventoryBox.o \
	Ad/AdItem.o \
	Ad/AdLayer.o \
	Ad/AdNodeState.o \
	Ad/AdObject.o \
	Ad/AdPath.o \
	Ad/AdPathPoint.o \
	Ad/AdRegion.o \
	Ad/AdResponse.o \
	Ad/AdResponseBox.o \
	Ad/AdResponseContext.o \
	Ad/AdRotLevel.o \
	Ad/AdScaleLevel.o \
	Ad/AdScene.o \
	Ad/AdSceneNode.o \
	Ad/AdSceneState.o \
	Ad/AdSentence.o \
	Ad/AdSpriteSet.o \
	Ad/AdTalkDef.o \
	Ad/AdTalkHolder.o \
	Ad/AdTalkNode.o \
	Ad/AdWaypointGroup.o \
	Base/BActiveRect.o \
	Base/BBase.o \
	Base/BDebugger.o \
	Base/BDiskFile.o \
	Base/BDynBuffer.o \
	Base/BFader.o \
	Base/BFile.o \
	Base/BFileEntry.o \
	Base/BFileManager.o \
	Base/BGame.o \
	Base/BFont.o \
	Base/BFontBitmap.o \
	Base/BFontStorage.o \
	Base/BFontTT.o \
	Base/BFrame.o \
	Base/BImage.o \
	Base/BKeyboardState.o \
	Base/BNamedObject.o \
	Base/BObject.o \
	Base/BPackage.o \
	Base/BParser.o \
	Base/BPersistMgr.o \
	Base/BPkgFile.o \
	Base/BPoint.o \
	Base/BQuickMsg.o \
	Base/BRegion.o \
	Base/BRegistry.o \
	Base/BRenderer.o \
	Base/BRenderSDL.o \
	Base/BResources.o \
	Base/BResourceFile.o \
	Base/BSaveThumbFile.o \
	Base/BSaveThumbHelper.o \
	Base/BScriptable.o \
	Base/BScriptHolder.o \
	Base/BSound.o \
	Base/BSoundBuffer.o \
	Base/BSoundMgr.o \
	Base/BSprite.o \
	Base/BStringTable.o \
	Base/BSubFrame.o \
	Base/BSurface.o \
	Base/BSurfaceSDL.o \
	Base/BSurfaceStorage.o \
	Base/BTransitionMgr.o \
	Base/BViewport.o \
	ConvertUTF.o \
	crc.o \
	detection.o \
	FontGlyphCache.o \
	graphics/transparentSurface.o \
	graphics/tga.o \
	math/MathUtil.o \
	math/Matrix4.o \
	math/Vector2.o \
	PathUtil.o \
	Base/PartParticle.o \
	Base/PartEmitter.o \
	Base/PartForce.o \
	PlatformSDL.o \
	StringUtil.o \
	Sys/SysClass.o \
	Sys/SysClassRegistry.o \
	Sys/SysInstance.o \
	tinyxml/tinyxml.o \
	tinyxml/tinystr.o \
	tinyxml/tinyxmlparser.o \
	tinyxml/tinyxmlerror.o \
	UI/UIButton.o \
	UI/UIEdit.o \
	UI/UIEntity.o \
	UI/UIObject.o \
	UI/UIText.o \
	UI/UITiledImage.o \
	UI/UIWindow.o \
	utils.o \
	VidPlayer.o \
	VidTheoraPlayer.o \
	wintermute.o
 
MODULE_DIRS += \
	engines/wintermute
 
# This module can be built as a plugin
ifeq ($(ENABLE_WINTERMUTE), DYNAMIC_PLUGIN)
PLUGIN := 1
endif
 
# Include common rules 
include $(srcdir)/rules.mk
