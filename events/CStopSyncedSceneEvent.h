#pragma once

#include "../deps/alt-math/alt-math.h"

#include "CEvent.h"

namespace alt
{
	class IEntity;
	class IPlayer;

	class CStopSyncedSceneEvent : public CEvent
	{
	public:
		CStopSyncedSceneEvent(const std::shared_ptr<IPlayer> _source, int32_t _sceneID) :
			CEvent(Type::STOP_SYNCED_SCENE),
			source(_source),
			sceneID(_sceneID)
		{

		}

		IPlayer* GetSource() const { return source.get(); }
		int32_t GetSceneID() const { return sceneID; }

	private:
		std::shared_ptr<IPlayer> source;
		int32_t sceneID;
	};
}
