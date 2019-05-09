#pragma once

#include "types/StringView.h"
#include "types/String.h"
#include "types/MValue.h"
#include "types/MValueList.h"
#include "types/MValueDict.h"

namespace alt
{
	class IPackage;
	class CEvent;

	class IResource
	{
	public:
		enum class State
		{
			STOPPED,
			INSTANTIATING,
			STARTED
		};

		struct CreationInfo
		{
			String type;
			String name;
			String path;
			String main;
			Array<String> deps;
			IPackage* pkg;
		};

		virtual ~IResource() = default;

		State GetState() const { return state; }
		bool IsStarted() const { return state == State::STARTED; }

		StringView GetType() const { return type; }
		StringView GetName() const { return name; }
		StringView GetPath() const { return path; }
		StringView GetMain() const { return main; }
		IPackage* GetPackage() const { return pkg; }
		MValueDict GetExports() { return exports; }

#ifdef ALT_SERVER_API
		virtual void MakeClient(CreationInfo* info, Array<String> files) { };
#endif
		virtual bool Instantiate() { state = State::INSTANTIATING; return true; }
		virtual bool Start() { state = State::STARTED; return true; };
		virtual bool Stop() { state = State::STOPPED; return true; };

		virtual bool OnEvent(const CEvent* ev) { return true; };
		virtual void OnTick() { };

		virtual void OnCreateBaseObject(IBaseObject* object) { };
		virtual void OnRemoveBaseObject(IBaseObject* object) { };

	protected:
		String type;
		String name;
		String path;
		String main;
		IPackage* pkg;

		State state;
		MValueDict exports;

		IResource(CreationInfo* info) :
			type(info->type),
			name(info->name),
			path(info->path),
			main(info->main),
			pkg(info->pkg),
			state(State::STOPPED)
		{

		}
	};
}
