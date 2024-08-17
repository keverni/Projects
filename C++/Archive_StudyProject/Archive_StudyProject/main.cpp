#include <iostream>
#include "ArchiveManager.h"

int main()
{
	ArchiveManager archive_manager;
	std::cout << "Hello! Its Archivator!" << std::endl;

	for (;;)
	{
		std::string file_name;
		std::cout << "Enter file name: ";
		std::cin >> file_name;

		std::string archive_type;
		std::cout << "Enter Archive Type(Supports Tar, Zip, Rar): ";
		std::cin >> archive_type;

		try
		{
			ArchiveType type = archive_manager.GetType(archive_type);
			archive_manager.Pack(file_name, type);
		}
		catch (const std::invalid_argument& ex)
		{
			std::cout << "Error: " << ex.what() << std::endl;
		}
	}

	return 0;
}