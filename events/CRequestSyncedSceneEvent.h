#pragma once

#include "../deps/alt-math/alt-math.h"

#include "CEvent.h"

namespace alt
{
	class IEntity;
	class IPlayer;

	class CRequestSyncedSceneEvent : public CEvent
	{
	public:
		CRequestSyncedSceneEvent(const std::shared_ptr<IPlayer> _source, int32_t _sceneID) :
			CEvent(Type::REQUEST_SYNCED_SCENE),
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
