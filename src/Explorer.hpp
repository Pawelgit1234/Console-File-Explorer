#pragma once

#include <string>
#include <filesystem>
#include <iostream>
#include <iomanip>
#include <windows.h>

namespace cfe
{
	class Explorer
	{
	public:
		Explorer() noexcept;
		~Explorer() = default;

		void upFolder();
		void downFolder();
		void up();
		void down();

		void openFile();
		void changeFileContent();
		void closeFile();

		void createFile();
		void createFolder();
		void deleteFile();
		void deleteFolder();

		void changeFileName();
		void changeFolderName();

		void setPath(const std::string& path) { path_ = path; draw(); }

	private:
		void draw();

		unsigned short pos_;
		std::string path_;
	};
}

