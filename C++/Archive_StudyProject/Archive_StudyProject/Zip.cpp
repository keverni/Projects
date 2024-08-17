#include "Zip.h"
#include <iostream>

Zip::Zip() :
	Archive(ArchiveType::Zip)
{
}

Zip::~Zip()
{
}

void Zip::Pack(const std::string& file_name)
{
	std::cout << "Pack file: " << file_name << " with " << GetTypeStr() << std::endl;
}
