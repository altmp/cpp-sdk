#pragma once
#include <string>

namespace alt
{
	class IPackage
	{
	public:
		struct PathInfo
		{
			alt::IPackage *pkg = nullptr;
			std::string fileName;
			std::string prefix;
		};

		enum class Mode
		{
			READ,
			WRITE
		};

		enum class SeekOrigin
		{
			SET = 0,
			CUR = 1,
			END = 2
		};

		class File
		{
		public:
			virtual ~File() = default;
		};

		virtual ~IPackage() = default;

		virtual Mode GetMode() const = 0;

		virtual bool FileExists(const std::string& path) = 0;

		virtual File *OpenFile(const std::string& path) = 0;
		virtual void CloseFile(File *file) = 0;

		virtual uint64_t GetFileSize(File *file) = 0;
		virtual void SeekFile(File *file, uint64_t offset, SeekOrigin origin) = 0;
		virtual uint64_t TellFile(File *file) = 0;

		virtual uint64_t ReadFile(File *file, void *buffer, uint64_t size) = 0;
		virtual uint64_t WriteFile(File *file, void *buffer, uint64_t size) = 0;

	protected:
		IPackage() = default;

	private:
		IPackage(const IPackage &that) = delete;
		IPackage &operator=(const IPackage &that) = delete;
	};
} // namespace alt
