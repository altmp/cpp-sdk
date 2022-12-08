#pragma once

#include "../deps/alt-math/alt-math.h"

#include "CEvent.h"

namespace alt
{
	class IEntity;
	class IPlayer;

	class CStartProjectileEvent : public CEvent
	{
	public:
		CStartProjectileEvent(const std::shared_ptr<IPlayer> _source, Position _startPosition, Vector3f _direction, uint32_t _ammoHash, uint32_t _weaponHash) :
			CEvent(Type::START_PROJECTILE_EVENT),
			source(_source),
			startPosition(_startPosition),
			direction(_direction),
			ammoHash(_ammoHash),
			weaponHash(_weaponHash)
		{

		}

		IPlayer* GetSource() const { return source.get(); }
		Position GetStartPosition() const { return startPosition; }
		Vector3f GetDirection() const { return direction; }
		uint32_t GetAmmoHash() const { return ammoHash; }
		uint32_t GetWeaponHash() const { return weaponHash; }

	private:
		std::shared_ptr<IPlayer> source;
		Position startPosition;
		Vector3f direction;
		uint32_t ammoHash;
		uint32_t weaponHash;
	};
}
