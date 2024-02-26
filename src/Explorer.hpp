#pragma once

#include <string>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <ctime>
#include <format>
#include <windows.h>
#include <conio.h>

namespace cfe
{
	void printRepeatedCharacter(char symbol, int count);

	class Explorer
	{
	public:
		Explorer() noexcept;
		~Explorer() = default;

		void upPath();
		void downPath();
		void up();
		void down();

		void openFile();
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

		bool is_at_file_;
	};
}

