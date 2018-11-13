/*
This file is part of OpenGL-Cross-Platform-Benchmark which is released under the MIT License.
Copyright Stan Slupecki 2018
Go to https://misturdust319.github.io/OpenGL-Cross-Platform-Benchmark/ for full license details.
*/

#ifndef HISTORY_H
#define HISTORY_H

#include <iostream>
#include <fstream>
#include <string>
#include <deque>

class History {
private:
	// this holds the data to save to disk
	std::deque<std::string> history;
	// file name
	std::string fileName;
	// file extension
	std::string fileExtension;
	// file object
	std::ofstream file;

public:	
	//constructors
	History();
	History(std::string&);

	// set file name
	void setFilename(const std::string&);
	// set extension
	void setFileExtension(const std::string&);
	// insert item into history
	void addItem(const std::string&);

	// save history to disk
	// return true if succesful
	// false otherwises
	bool saveHistory();
};

#endif // !HISTORY_H
