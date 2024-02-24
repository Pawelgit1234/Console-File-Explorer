#pragma once

#include <string>
#include <filesystem>

namespace cfe
{
	class Explorer
	{
	public:
		Explorer(const std::string& start_path) noexcept;
		~Explorer() = default;

	private:
		std::string path_;
	};
}

