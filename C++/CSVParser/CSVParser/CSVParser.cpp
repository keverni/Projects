#include "CSVParser.h"

#include <stdexcept>
#include <algorithm>
#include <fstream>
#include <sstream>

CSVParser::CSVParser(const std::string& FilePath)
{
	int Count_Lines = CountLines(FilePath);
	m_Persons.reserve(Count_Lines);
	
	std::ifstream in_file(FilePath);
	if (!in_file.is_open())
	{
		throw std::runtime_error("Cannot open file!");
	}

	std::string line;
	while (std::getline(in_file, line))
	{
		m_Persons.emplace_back(ParseLine(line));
	}

	in_file.close();
}

const Person& CSVParser::Find(const std::string& LastName) const
{
	if (LastName.empty())
	{
		throw std::invalid_argument("Invalid LastName!");
	}

	auto Result = std::find_if(std::begin(m_Persons), std::end(m_Persons), [&LastName](const Person& person) 
	{
		return person.LastName == LastName;
	});

	if (Result == std::end(m_Persons))
	{
		throw std::runtime_error("Cannot find person!");
	}

	return *Result;
}

const std::vector<Person>& CSVParser::GetData() const
{
	return m_Persons;
}

int CSVParser::CountLines(const std::string& FilePath) const
{
	if (FilePath.empty())
	{
		throw std::invalid_argument("Invalid LastPath!");
	}

	int lines_count = 0;

	std::ifstream in_file(FilePath);
	if (in_file.is_open())
	{
		std::string line;
		while (std::getline(in_file, line))
		{
			++lines_count;
		}

		in_file.close();
	}

	if (lines_count == 0)
	{
		throw std::runtime_error("File is empty!");
	}

	return lines_count;
}

Person CSVParser::ParseLine(const std::string& Line)
{
	if (Line.empty())
	{
		throw std::invalid_argument("Line is empty!");
	}

	auto parse_next_value = [&](size_t pos)
	{
		std::string value;

		while (pos < Line.size())
		{
			if (Line[pos] != ';')
			{
				value.push_back(Line[pos]);
			}
			else
			{
				++pos;
				break;
			}

			++pos;
		}

		if (value.empty())
		{
			throw std::runtime_error{ "Value is empty" };
		}

		return std::pair{ pos, value };
	};

	Person person;
	
	auto value = parse_next_value(0);
	person.LastName = value.second;

	value = parse_next_value(value.first);
	person.FirstName = value.second;

	value = parse_next_value(value.first);
	person.Date = value.second;

	value = parse_next_value(value.first);
	person.City = value.second;

	value = parse_next_value(value.first);
	person.Balance = std::stod(value.second);
	
	if (!person.IsValid())
	{
		throw std::invalid_argument("Invalid person!");
	}
	
	return person;
}

