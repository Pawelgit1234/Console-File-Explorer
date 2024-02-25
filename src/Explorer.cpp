#include "Explorer.hpp"

namespace cfe
{
	Explorer::Explorer() noexcept : pos_(0)
	{
		char path[MAX_PATH] = { 0 };
		GetModuleFileNameA(NULL, path, MAX_PATH);
		path_ = std::filesystem::path(path).parent_path().wstring();
		draw();
	}

	void Explorer::upFolder()
	{
		std::filesystem::path parent_path = std::filesystem::path(path_).parent_path();
		if (!parent_path.empty())
		{
			path_ = parent_path.wstring();
			pos_ = 0;
			draw();
		}
	}

	void Explorer::downFolder()
	{
		int selected_pos = 0;
		for (const auto& entry : std::filesystem::directory_iterator(path_))
		{
			if (selected_pos == pos_)
			{
				if (std::filesystem::is_directory(entry.path()))
				{
					path_ = entry.path().wstring();
					pos_ = 0;
					draw();
				}
				break;
			}
			selected_pos++;
		}
	}

	void Explorer::up()
	{
		if (pos_ > 0)
		{
			pos_--;
			draw();
		}
	}

	void Explorer::down()
	{
		int file_count = 0;
		for (const auto& entry : std::filesystem::directory_iterator(path_))
			file_count++;

		if (pos_ < file_count - 1)
		{
			pos_++;
			draw();
		}
	}

	void Explorer::openFile()
	{
	}

	void Explorer::changeFileContent()
	{
	}

	void Explorer::closeFile()
	{
	}

	void Explorer::createFile()
	{
	}

	void Explorer::createFolder()
	{
	}

	void Explorer::deleteFile()
	{
	}

	void Explorer::deleteFolder()
	{
	}

	void Explorer::changeFileName()
	{
	}

	void Explorer::changeFolderName()
	{
	}

	void Explorer::draw()
	{
		system("cls");

		cfe::printRepeatedCharacter('_', 65);
		std::cout << std::endl << "Name";
		cfe::printRepeatedCharacter(' ', 28);
		std::cout << "|Size";
		cfe::printRepeatedCharacter(' ', 8);
		std::cout << "|Modify Time";
		cfe::printRepeatedCharacter(' ', 8);
		std::cout << '|';
		std::cout << std::endl;

		int pos = 0;
		int max_filename_length = 30;
		int max_filesize_length = 12;

		for (const auto& entry : std::filesystem::directory_iterator(path_))
		{
			std::wstring filename = entry.path().filename().wstring();
			if (filename.length() > max_filename_length)
				filename = filename.substr(0, max_filename_length - 3) + L"...";

			std::wcout << std::left << std::setw(max_filename_length) << std::setfill(L' ');

			if (pos_ == pos)
			{
				HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | BACKGROUND_BLUE);
				std::wcout << filename;
			}
			else
				std::wcout << filename;

			if (entry.is_regular_file())
				std::cout << " \033[42;30mF\033[0m"; 
			else if (entry.is_directory())
				std::cout << " \033[44;37mD\033[0m"; 
			else if (entry.is_symlink())
				std::cout << " \033[45;37mS\033[0m"; 
			else if (entry.is_block_file())
				std::cout << " \033[46;37mB\033[0m"; 
			else if (entry.is_character_file())
				std::cout << " \033[43;30mC\033[0m"; 
			else if (entry.is_fifo())
				std::cout << " \033[41;37mF\033[0m"; 
			else if (entry.is_socket())
				std::cout << " \033[47;30mS\033[0m"; 
			else
				std::cout << " \033[40;31m?\033[0m";

			std::cout << "|";
			std::cout << std::left << std::setw(max_filesize_length) << std::setfill(' ');
			std::cout << std::filesystem::file_size(entry.path()) << '|';

			std::filesystem::file_time_type ftime = entry.last_write_time();
			std::string strtime = std::format("{}", ftime).substr(0, 19);
			std::cout << strtime << '|' << std::endl;

			pos++;
		}

		std::wcout << L"\033[42m" << path_ << L"\033[0m" << std::endl;
		cfe::printRepeatedCharacter('_', 65);
	}

	void printRepeatedCharacter(char symbol, int count)
	{
		for (int i = 0; i < count; ++i)
			std::cout << symbol;
	}
}