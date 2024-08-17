#pragma once

#include "Archive.h"

class Rar : public Archive
{
public:
	Rar();
	virtual ~Rar();
	
	virtual void Pack(const std::string& file_name);
};

