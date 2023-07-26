#pragma once

#include "../deps/alt-math/alt-math.h"

#include "CEvent.h"

namespace alt
{
	class IEntity;
	class IPlayer;

	class CStartSyncedSceneEvent : public CEvent
	{
	public:
		CStartSyncedSceneEvent(const std::shared_ptr<IPlayer> _source, int32_t _sceneID, Position _startPosition, Rotation _startRotation, uint32_t _animDictHash, std::unordered_map<std::shared_ptr<IEntity>, uint32_t>& _entityAndAnimHashPairs) :
			CEvent(Type::START_SYNCED_SCENE),
			source(_source),
			sceneID(_sceneID),
			startPosition(_startPosition),
			startRotation(_startRotation),
			animDictHash(_animDictHash),
			entityAndAnimHashPairs(_entityAndAnimHashPairs)
		{

		}

		IPlayer* GetSource() const { return source.get(); }
		int32_t GetSceneID() const { return sceneID; }

		Position GetStartPosition() const { return startPosition; }
		Rotation GetStartRotation() const { return startRotation; }
		
		uint32_t GetAnimDictHash() const { return animDictHash; }

	private:
		std::shared_ptr<IPlayer> source;
		int32_t sceneID;

		Position startPosition;
		Rotation startRotation;
		
		uint32_t animDictHash;
		
		std::unordered_map<std::shared_ptr<IEntity>, uint32_t> entityAndAnimHashPairs;
	};
}
