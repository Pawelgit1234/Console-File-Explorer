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

		draw();
	}

	void Explorer::downFolder()
	{

		draw();
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
			if (std::filesystem::is_regular_file(entry.path()))
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
			if (std::filesystem::is_regular_file(entry.path()))
			{
				if (pos_ == pos)
					std::cout << "\033[44;37m" << entry.path().filename().string() << "\033[0m" << std::endl;
				else
					std::cout << entry.path().filename().string() << std::endl;

				pos++;
			}
		}

		std::cout << pos_ << std::endl;
		std::cout << path_ << std::endl;
		std::cout << "_______________________________________________" << std::endl;
	}
}