#include "Explorer.hpp"

namespace cfe
{
	Explorer::Explorer() noexcept : pos_(0)
	{
		char path[MAX_PATH] = { 0 };
		GetModuleFileNameA(NULL, path, MAX_PATH);
		path_ = std::filesystem::path(path).parent_path().string();
		draw();
	}

	void Explorer::upFolder()
	{
		std::filesystem::path parent_path = std::filesystem::path(path_).parent_path();
		if (!parent_path.empty())
		{
			path_ = parent_path.string();
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
					path_ = entry.path().string();
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

		std::cout << "_______________________________________________" << std::endl;

		int pos = 0;
		int max_filename_length = 30;

		for (const auto& entry : std::filesystem::directory_iterator(path_))
		{
			std::string filename = entry.path().filename().string();
			if (filename.length() > max_filename_length)
				filename = filename.substr(0, max_filename_length - 3) + "...";

			std::cout << std::left << std::setw(max_filename_length) << std::setfill(' ');

			if (pos_ == pos)
			{
				HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | BACKGROUND_BLUE);
				std::cout << filename;
			}
			else
				std::cout << filename;

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

			std::cout << "|" << std::endl;
			pos++;
		}

		std::cout << std::endl << "\033[42m" << path_ << "\033[0m" << std::endl;
		std::cout << "_______________________________________________" << std::endl;
	}
}