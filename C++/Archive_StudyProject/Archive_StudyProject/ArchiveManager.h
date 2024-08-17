#pragma once

#include "Archive.h"
#include <vector>
#include <memory>

class ArchiveManager
{
public:
	ArchiveManager();

	void Pack(const std::string& file_name, ArchiveType type);

	ArchiveType GetType(const std::string& type);

private:
	std::vector<std::unique_ptr<Archive>> m_Archives;
};
