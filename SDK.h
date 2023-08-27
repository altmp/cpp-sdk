#pragma once

#ifdef __cplusplus
#define EXTERN extern "C"
#else
#define EXTERN
#endif // __cplusplus

#ifdef _WIN32

#define EXPORT EXTERN __declspec(dllexport)
#define IMPORT EXTERN __declspec(dllimport)

#else

#define EXPORT EXTERN __attribute__((visibility("default")))
#define IMPORT

#endif // _WIN32

#include "deps/alt-math/alt-math.h"
#include "deps/alt-config/alt-config.h"

#include "types/Types.h"
#include "types/RGBA.h"
#include "types/MValue.h"
#include "types/VehicleModelInfo.h"
#include "types/WeaponModelInfo.h"

#include "objects/IBaseObject.h"
#include "objects/IWorldObject.h"
#include "objects/IEntity.h"
#include "objects/IPlayer.h"
#include "objects/IVehicle.h"

#include "script-objects/ICheckpoint.h"
#include "script-objects/IBlip.h"
#include "script-objects/IVoiceChannel.h"
#include "script-objects/IHttpClient.h"
#include "script-objects/ILocalVehicle.h"
#include "script-objects/ILocalPed.h"
#include "script-objects/ICustomTexture.h"

#include "events/CEvent.h"
#include "events/CServerScriptEvent.h"
#include "events/CClientScriptEvent.h"
#include "events/CPlayerConnectEvent.h"
#include "events/CPlayerDisconnectEvent.h"
#include "events/CPlayerDamageEvent.h"
#include "events/CPlayerDeathEvent.h"
#include "events/CColShapeEvent.h"
#include "events/CPlayerEnterVehicleEvent.h"
#include "events/CPlayerLeaveVehicleEvent.h"
#include "events/CPlayerChangeVehicleSeatEvent.h"
#include "events/CDataNodeReceivedEvent.h"
#include "events/CConsoleCommandEvent.h"
#include "events/CWeaponDamageEvent.h"
#include "events/CExplosionEvent.h"
#include "events/CResourceStartEvent.h"
#include "events/CResourceStopEvent.h"
#include "events/CResourceErrorEvent.h"
#include "events/CMetaDataChangeEvent.h"
#include "events/CSyncedMetaDataChangeEvent.h"
#include "events/CStreamSyncedMetaDataChangeEvent.h"
#include "events/CGlobalMetaDataChangeEvent.h"
#include "events/CGlobalSyncedMetaDataChangeEvent.h"
#include "events/CLocalMetaDataChangeEvent.h"
#include "events/CVehicleDestroyEvent.h"
#include "events/CCreateBaseObjectEvent.h"
#include "events/CRemoveBaseObjectEvent.h"
#include "events/CFireEvent.h"
#include "events/CStartProjectileEvent.h"
#include "events/CPlayerWeaponChangeEvent.h"
#include "events/CVehicleAttachEvent.h"
#include "events/CVehicleDetachEvent.h" 
#include "events/CNetOwnerChangeEvent.h" 
#include "events/CPlayerEnteringVehicleEvent.h"
#include "events/CVehicleDamageEvent.h"
#include "events/CConnectionQueueAddEvent.h"
#include "events/CConnectionQueueRemoveEvent.h"
#include "events/CPlayerRequestControlEvent.h"
#include "events/CPlayerChangeAnimationEvent.h"
#include "events/CPlayerChangeInteriorEvent.h"
#include "events/CPlayerConnectDeniedEvent.h"
#include "events/CPlayerDimensionChangeEvent.h"
#include "events/CVehicleHornEvent.h"
#include "events/CVehicleSirenEvent.h"
#include "events/CPlayerSpawnEvent.h"
#include "events/CWorldObjectPositonChangeEvent.h"
#include "events/CWorldObjectStreamInEvent.h"
#include "events/CWorldObjectStreamOutEvent.h"
#include "events/CPlayerWeaponShootEvent.h"
#include "events/CEntityHitEntityEvent.h"
#include "events/CPlayerStartEnterVehicleEvent.h"
#include "events/CPlayerStartLeaveVehicleEvent.h"
#include "events/CPlayerBulletHitEvent.h"
#include "events/CVoiceConnectionEvent.h"
#include "events/CRequestSyncedSceneEvent.h"
#include "events/CStartSyncedSceneEvent.h"
#include "events/CStopSyncedSceneEvent.h"
#include "events/CUpdateSyncedSceneEvent.h"

#ifdef ALT_SERVER_API
#include "events/CClientRequestObjectEvent.h"
#include "events/CClientDeleteObjectEvent.h"
#endif

#ifdef ALT_CLIENT_API

#include "events/CConnectionComplete.h"
#include "events/CDisconnectEvent.h"
#include "events/CWebViewEvent.h"
#include "events/CKeyboardEvent.h"
#include "events/CGameEntityCreateEvent.h"
#include "events/CGameEntityDestroyEvent.h"
#include "events/CWebSocketClientEvent.h"
#include "events/CTaskChangeEvent.h"
#include "events/CSpawnedEvent.h"
#include "events/CRmlEvent.h"
#include "events/CWindowFocusChangeEvent.h"
#include "events/CWindowResolutionChangeEvent.h"

#endif

#include "IPackage.h"
#include "IResource.h"
#include "IScriptRuntime.h"

#include "ICore.h"
