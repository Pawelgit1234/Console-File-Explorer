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
		for (const auto& entry : std::filesystem::directory_iterator(path_))
		{
			if (pos_ == pos)
				std::cout << "\033[44;37m" << entry.path().filename().string() << "\033[0m" << std::endl;
			else
				std::cout << entry.path().filename().string() << std::endl;

			pos++;
		}

		std::cout << std::endl <<  "\033[42m" << path_ << "\033[0m" << std::endl;
		std::cout << "_______________________________________________" << std::endl;
	}
}