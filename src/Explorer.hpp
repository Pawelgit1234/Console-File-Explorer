#pragma once

#include <string>
#include <filesystem>
#include <iostream>
#include <iomanip>
#include <ctime>
#include <format>
#include <windows.h>

namespace cfe
{
	void printRepeatedCharacter(char symbol, int count);

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

		void setPath(const std::wstring& path) { path_ = path; draw(); }

	private:
		void draw();

		unsigned short pos_;
		std::wstring path_;
	};
}

