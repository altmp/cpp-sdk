#pragma once

#include "../objects/IBaseObject.h"

namespace alt
{
	class IAudioFilter : public virtual IBaseObject
	{
	public:
		virtual ~IAudioFilter() = default;
		
		virtual uint32_t GetHash() const = 0;

		virtual uint32_t AddRotateEffect(float fRate, int priority) const = 0;
		virtual uint32_t AddVolumeEffect(float fVolume, int priority) const = 0;
		virtual uint32_t AddPeakeqEffect(int lBand, float fBandwidth, float fQ, float fCenter, float fGain, int priority) const = 0;
		virtual uint32_t AddDampEffect(float fTarget, float fQuiet, float fRate, float fGain, float fDelay, int priority) const = 0;
		virtual uint32_t AddAutowahEffect(float fDryMix, float fWetMix, float fFeedback, float fRate, float fRange, float fFreq, int priority) const = 0;
		virtual uint32_t AddPhaserEffect(float fDryMix, float fWetMix, float fFeedback, float fRate, float fRange, float fFreq, int priority) const = 0;
		virtual uint32_t AddChorusEffect(float fDryMix, float fWetMix, float fFeedback, float fMinSweep, float fMaxSweep, float fRate, int priority) const = 0;
		virtual uint32_t AddDistortionEffect(float fDrive, float fDryMix, float fWetMix, float fFeedback, float fVolume, int priority) const = 0;
		virtual uint32_t AddCompressor2Effect(float fGain, float fThreshold, float fRatio, float fAttack, float fRelease, int priority) const = 0;
		virtual uint32_t AddBqfEffect(int lFilter, float fCenter, float fGain, float fBandwidth, float fQ, float fS, int priority) const = 0;
		virtual uint32_t AddEcho4Effect(float fDryMix, float fWetMix, float fFeedback, float fDelay, int priority) const = 0;
		virtual uint32_t AddPitchshiftEffect(float fPitchShift, float fSemitones, long lFFTsize, long lOsamp, int priority) const = 0;
		virtual uint32_t AddFreeverbEffect(float fDryMix, float fWetMix, float fRoomSize, float fDamp, float fWidth, uint32_t lMode, int priority) const = 0;

		virtual bool RemoveEffect(uint32_t hfxHandler) const = 0;
	};
}
