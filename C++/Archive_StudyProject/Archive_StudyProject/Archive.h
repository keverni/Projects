#pragma once

#include <string>

enum class ArchiveType
{
	Tar = 0,
	Zip,
	Rar,
};

class Archive
{
public:
	explicit Archive(ArchiveType type);
	virtual ~Archive();

	ArchiveType GetType() const;
	std::string GetTypeStr() const;

	virtual void Pack(const std::string& file_name) = 0;

private:
	ArchiveType m_Type;
};
