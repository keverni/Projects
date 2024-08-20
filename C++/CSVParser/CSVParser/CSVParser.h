#pragma once

#include "Person.h"
#include <vector>

class CSVParser
{
public:
	CSVParser(const std::string& FilePath);

	const Person& Find(const std::string& LastName) const;
	const std::vector<Person>& GetData() const;
	
private:
	int CountLines(const std::string& FilePath) const;
	Person ParseLine(const std::string& Line);

private:
	std::vector<Person> m_Persons;

};

