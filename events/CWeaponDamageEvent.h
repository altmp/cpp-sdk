#pragma once

#include "../deps/alt-math/alt-math.h"

#include "CEvent.h"

namespace alt
{
	class IPlayer;
	class IEntity;

	class CWeaponDamageEvent : public CEvent
	{
	public:
		enum class BodyPart : int8_t
		{
			PELVIS,
			LEFT_HIP,
			LEFT_LEG,
			LEFT_FOOT,
			RIGHT_HIP,
			RIGHT_LEG,
			RIGHT_FOOT,
			LOWER_TORSO,
			UPPER_TORSO,
			CHEST,
			UNDER_NECK,
			LEFT_SHOULDER,
			LEFT_UPPER_ARM,
			LEFT_ELBROW,
			LEFT_WRIST,
			RIGHT_SHOULDER,
			RIGHT_UPPER_ARM,
			RIGHT_ELBROW,
			RIGHT_WRIST,
			NECK,
			HEAD,

			UNKNOWN = -1
		};

		CWeaponDamageEvent(const std::shared_ptr<IPlayer>& _source, const std::shared_ptr<IEntity>& _target, uint32_t _weaponHash, uint32_t _damageValue, Vector3f _shotOffset, BodyPart _bodyPart, const std::shared_ptr<IEntity>& _sourceEntity = nullptr) :
			CEvent(Type::WEAPON_DAMAGE_EVENT),
			source(_source),
			target(_target),
			weaponHash(_weaponHash),
			damageValue(_damageValue),
			shotOffset(_shotOffset),
			bodyPart(_bodyPart),
			sourceEntity(_sourceEntity)
		{

		}

		IPlayer* GetSource() const { return source.get(); }
		IEntity* GetTarget() const { return target.get(); }
		uint32_t GetWeaponHash() const { return weaponHash; }
		uint32_t GetDamageValue() const { return damageValue; }
		Vector3f GetShotOffset() const { return shotOffset; }
		BodyPart GetBodyPart() const { return bodyPart; }
		IEntity* GetSourceEntity() const { return sourceEntity.get(); }

		void SetDamageValue(uint32_t _damageValue)
		{
			damageValue = _damageValue;
		}

	private:
		std::shared_ptr<IPlayer> source;
		std::shared_ptr<IEntity> target;
		std::shared_ptr<IEntity> sourceEntity;
		uint32_t weaponHash;
		uint32_t damageValue;
		Vector3f shotOffset;
		BodyPart bodyPart;
	};
}
