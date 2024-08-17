#include "Archive.h"

Archive::Archive(ArchiveType type) :
	m_Type(type)
{
}

Archive::~Archive()
{
}

ArchiveType Archive::GetType() const
{
	return m_Type;
}

std::string Archive::GetTypeStr() const
{
	if (m_Type == ArchiveType::Rar)
	{
		return "rar";
	}
	if (m_Type == ArchiveType::Zip)
	{
		return "zip";
	}
	if (m_Type == ArchiveType::Tar)
	{
		return "tar";
	}

	return "";
}
