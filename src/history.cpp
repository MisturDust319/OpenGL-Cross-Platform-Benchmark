/*
This file is part of OpenGL-Cross-Platform-Benchmark which is released under the MIT License.
Copyright Stan Slupecki 2018
Go to https://misturdust319.github.io/OpenGL-Cross-Platform-Benchmark/ for full license details.
*/

#include <GLBenchmark/history.h>

#include <iostream>
#include <fstream>
#include <string>
#include <deque>

// init to save to "history.txt" file
History::History() {
	fileName = "history";
	fileExtension = "csv";
}
// init to filename
History::History(std::string& fileName) {
	this->fileName = fileName;
}

// set file name
void History::setFilename(const std::string& fileName) {
	this->fileName = fileName;
}
//set file extension
void History::setFileExtension(const std::string& fileExtension) {
	this->fileExtension = "." + fileExtension;
}

// places data into history
void History::addItem(const std::string& data) {
	history.push_back(data);
}

// saves history to disk
bool History::saveHistory() {
	// try to open file
	file.open(fileName + fileExtension);

	// check if file already exists
	// if yes, add a number to filename

	// if history has no values,
	// return false
	if (history.size() == 0) {
		return false;
	}
	// if file opened, write
	else if (file) {
		// iterate over history and store each line
		std::deque<std::string>::iterator it =
			history.begin();
		
		while (it != history.end()) {
			// get current item in history
			std::string datum = *it;
			// increment iterator
			it++;

			file << datum << std::endl;
			// store item in history,
			// plus a newline
		}

		//close the file
		file.close();

		return true;
	}
	else {
		// otherwise return false
		return false;
	}
}