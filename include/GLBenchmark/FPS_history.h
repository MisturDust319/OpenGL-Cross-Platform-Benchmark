/*
This file is part of OpenGL-Cross-Platform-Benchmark which is released under the MIT License.
Copyright Stan Slupecki 2018
Go to https://misturdust319.github.io/OpenGL-Cross-Platform-Benchmark/ for full license details.
*/

#ifndef FPS_HIST_H
#define FPS_HIST_H

#include <GLBenchmark/history.h>

#include <iostream>
#include <string>

class FPSHistory : public History {
public: 
	// constructor
	FPSHistory();
	// addItem overload that simplifies including
	// FPS, timestamp
	void addItem(const std::string&, const std::string&);
};

#endif //FPS_HIST_H


