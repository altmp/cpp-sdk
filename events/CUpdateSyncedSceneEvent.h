#pragma once

#include "../deps/alt-math/alt-math.h"

#include "CEvent.h"

namespace alt
{
	class IEntity;
	class IPlayer;

	class CUpdateSyncedSceneEvent : public CEvent
	{
	public:
		CUpdateSyncedSceneEvent(const std::shared_ptr<IPlayer> _source, int32_t _sceneID, float _startRate) :
			CEvent(Type::STOP_SYNCED_SCENE),
			source(_source),
			sceneID(_sceneID),
			startRate(_startRate)
		{

		}

		IPlayer* GetSource() const { return source.get(); }
		float GetStartRate() const { return startRate; }
		int32_t GetSceneID() const { return sceneID; }

	private:
		std::shared_ptr<IPlayer> source;
		int32_t sceneID;
		float startRate;
	};
}
