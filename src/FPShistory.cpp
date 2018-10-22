/*
This file is part of OpenGL-Cross-Platform-Benchmark which is released under the MIT License.
Copyright Stan Slupecki 2018
Go to https://misturdust319.github.io/OpenGL-Cross-Platform-Benchmark/ for full license details.
*/

#include <GLBenchmark/FPS_history.h>

#include <iostream>
#include <string>

// set the filename to "fps_record.csv"
FPSHistory::FPSHistory() {
	std::string name = "fps_record.csv";
	this->setFilename(name);

	// add in headers
	std::string data = "time (s), fps";
	History::addItem(data);
}

// adds a timestamp, fps record
void FPSHistory::addItem(std::string& timestamp, std::string& fps) {
	// concat the timestamp and data with a comma delimiter
	std::string data = timestamp + ", " + fps;
	History::addItem(data);
}