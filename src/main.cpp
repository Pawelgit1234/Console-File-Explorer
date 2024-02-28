#include "Explorer.hpp"

#include <locale>


int main(int argc, char* argv[])
{
	SetConsoleOutputCP(CP_UTF8);
	std::setlocale(LC_ALL, "Russian");
	cfe::Explorer explorer;

	while (true)
	{
		switch (_getch())
		{
		case 72:
			explorer.up();
			break;
		case 80:
			explorer.down();
			break;
		case 75:
			explorer.upPath();
			break;
		case 77:
			explorer.downPath();
			break;
		case 'p':
			{
				system("cls");
				std::wstring path;
				std::cout << "Your path: ";
				std::wcin >> path;
				explorer.setPath(path);
				break;
			}
		case 'f':
			{
				system("cls");
				std::wstring name;
				std::cout << "Your File name: ";
				std::wcin >> name;
				explorer.createFile(name);
				break;
			}
		case 'd':
		{
			system("cls");
			std::wstring name;
			std::cout << "Your Folder name: ";
			std::wcin >> name;
			explorer.createFolder(name);
			break;
		}
		case 'r':
			system("cls");
			explorer.deleteObject();
			break;
		case 'n':
			{
				system("cls");
				std::wstring name;
				std::cout << "New name: ";
				std::wcin >> name;
				explorer.changeName(name);
				break;
			}
		case 'h':
			system("cls");
			std::cout << "Available commands:\n";
			std::cout << "-------------------\n";
			std::cout << "up   : Move cursor up\n";
			std::cout << "down : Move cursor down\n";
			std::cout << "<    : Move to parent directory\n";
			std::cout << ">    : Enter directory or open file\n";
			std::cout << "p    : Set path\n";
			std::cout << "f    : Create file\n";
			std::cout << "d    : Create folder\n";
			std::cout << "r    : Delete object\n";
			std::cout << "n    : Change name of file or folder\n";
			std::cout << "h    : Display this help message\n";
			break;
		}
	}

	return 0;
}