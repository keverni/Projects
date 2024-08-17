#pragma once

#include "Archive.h"

class Tar : public Archive
{
public:
	Tar();
	virtual ~Tar();

	virtual void Pack(const std::string& file_name);
};

