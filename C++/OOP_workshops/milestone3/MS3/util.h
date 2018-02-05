#pragma once

#include <string>
#include <vector>

void trim(std::string& s);

void csvRead(std::string& fileName, char separator, std::vector< std::vector<std::string> > &csvData);

void csvPrint(std::vector< std::vector<std::string> > &csvData);

bool validTaskName(std::string &s);

bool validItem(std::string &s);

bool validTask(std::string &s);

bool validSequence(std::string &s);

bool validSlots(std::string &s);