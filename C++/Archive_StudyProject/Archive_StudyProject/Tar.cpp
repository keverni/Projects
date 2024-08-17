#include "Tar.h"
#include <iostream>

Tar::Tar() :
	Archive(ArchiveType::Tar)
{
}

Tar::~Tar()
{
}

void Tar::Pack(const std::string& file_name)
{
	std::cout << "Pack file: " << file_name << " with " << GetTypeStr() << std::endl;
}
