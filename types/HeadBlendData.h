#pragma once

#include <iostream>
#include <cstdint>

namespace alt
{
	struct HeadBlendData
	{
		uint32_t shapeFirstID = 0;
		uint32_t shapeSecondID = 0;
		uint32_t shapeThirdID = 0;
		uint32_t skinFirstID = 0;
		uint32_t skinSecondID = 0;
		uint32_t skinThirdID = 0;
		float shapeMix = 0.f;
		float skinMix = 0.f;
		float thirdMix = 0.f;

		HeadBlendData() = default;

		HeadBlendData(uint32_t _shapeFirstID, uint32_t _shapeSecondID, uint32_t _shapeThirdID,
			uint32_t _skinFirstID, uint32_t _skinSecondID, uint32_t _skinThirdID,
			float _shapeMix, float _skinMix, float _thirdMix) :
			shapeFirstID(_shapeFirstID), shapeSecondID(_shapeSecondID), shapeThirdID(_shapeThirdID), 
			skinFirstID(_skinFirstID), skinSecondID(_skinSecondID), skinThirdID(_skinThirdID),
			shapeMix(_shapeMix) , skinMix(_skinMix) , thirdMix(_thirdMix) { }

		friend std::ostream &operator<<(std::ostream &stream, const HeadBlendData &headBlendData)
		{
			stream << "HeadBlendData{ "<< headBlendData.shapeFirstID << headBlendData.shapeSecondID << ", " << headBlendData.shapeThirdID << ", "
				   << headBlendData.skinFirstID << ", " << headBlendData.skinSecondID << ", " << headBlendData.skinThirdID
				<< ", " << headBlendData.shapeMix << ", " << headBlendData.skinMix << ", " << headBlendData.thirdMix << " }";
			return stream;
		}
	};
}
