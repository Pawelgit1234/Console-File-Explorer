#include "Explorer.hpp"

namespace cfe
{
	Explorer::Explorer() noexcept
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

		draw();
	}

	void Explorer::down()
	{

		draw();
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
		std::cout << "\033[44;37m";
		std::cout << "_______________________________________________" << std::endl;

		for (const auto& entry : std::filesystem::directory_iterator(path_))
		{
			if (std::filesystem::is_regular_file(entry.path()))
			{
				std::cout << entry.path().filename().string() << std::endl;
			}
		}

		std::cout << path_ << std::endl;
		std::cout << "_______________________________________________" << std::endl;
		std::cout << "\033[0m";
	}
}