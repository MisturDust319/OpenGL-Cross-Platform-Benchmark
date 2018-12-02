
#include <GL/glew.h>
#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GL/freeglut.h>
#else
#include <GL/freeglut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#endif
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


#include <iostream>
#include <cmath>
#include <vector>

#include <src/shader.cpp>
#include <GLBenchmark/FPS_history.h>
#include <GLBenchmark/cube.h>

// glm::vec3 origin = glm::vec3(15.0, 10.0, -30.0);
// Cube cube(1, origin);

// settings
class Manager {
private:
	// shader object
	Shader shader;

	// matrices
	// mModel is determined by the shape's origin 
	glm::mat4 view; // view matrix
	glm::mat4 mProjection; // projection matrix

    const unsigned int SCR_WIDTH = 800;
	const unsigned int SCR_HEIGHT = 600;

	// time and frame tracking info
	int frame = 0, fps = 0, time, timebase=0;

	// fps tracking object
	FPSHistory hist;

	// this var sets the stop time in ms
	int stopTime = 60000;

	// list of origins to generate cubes
	std::vector<glm::vec3> origins;
	// list of cubes
	std::vector<Cube> cubes;

public:
	// CONSTRUCTOR
	Manager(int argc, char** argv) {

		// init GLUT and create Window
		glutInit(&argc, argv);
		glutInitContextVersion(3,3); // init to OpenGL v 3.3 
		glutInitContextProfile(GLUT_CORE_PROFILE); // Set up to core profile
		glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
		glutInitWindowPosition(100,100);
		glutInitWindowSize(SCR_WIDTH, SCR_HEIGHT);
		glutCreateWindow("OpenGL Benchmark");

		// init GLEW
		glewInit();

		// enable GL depth test
		glEnable(GL_DEPTH_TEST);
		// select clear color
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);

        // initialize matrices
        view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
        mProjection =
        glm::perspective(glm::radians(45.0f), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
		
		// init shader
		shader.init("src/shader.vert","src/shader.frag");
		// use the shader object
		shader.use();
		// pass view and projection matrices to shader
		shader.setMat4("projection", mProjection);
		shader.setMat4("view",view);

	    // cube.init();
	    // create the cube objects, but don't init them
		// create list of origins to generate cubes with
		glm::vec3 org[60] = {
			glm::vec3(-15.0, 10.0, -30.0),
			glm::vec3(-12.0, 10.0, -30.0),
			glm::vec3(-9.0, 10.0, -30.0),
			glm::vec3(-6.0, 10.0, -30.0),
			glm::vec3(-3.0, 10.0, -30.0),
			glm::vec3(0.0, 10.0, -30.0),
			glm::vec3(3.0, 10.0, -30.0),
			glm::vec3(6.0, 10.0, -30.0),
			glm::vec3(9.0, 10.0, -30.0),
			glm::vec3(12.0, 10.0, -30.0),
			glm::vec3(15.0, 10.0, -30.0),
			glm::vec3(-15.0, 6.2, -30.0),
			glm::vec3(-12.0, 6.2, -30.0),
			glm::vec3(-9.0, 6.2, -30.0),
			glm::vec3(-6.0, 6.2, -30.0),
			glm::vec3(-3.0, 6.2, -30.0),
			glm::vec3(0.0, 6.2, -30.0),
			glm::vec3(3.0, 6.2, -30.0),
			glm::vec3(6.0, 6.2, -30.0),
			glm::vec3(9.0, 6.2, -30.0),
			glm::vec3(12.0, 6.2, -30.0),
			glm::vec3(15.0, 6.2, -30.0),
			glm::vec3(-15.0, 2.4, -30.0),
			glm::vec3(-12.0, 2.4, -30.0),
			glm::vec3(-9.0, 2.4, -30.0),
			glm::vec3(-6.0, 2.4, -30.0),
			glm::vec3(-3.0, 2.4, -30.0),
			glm::vec3(0.0, 2.4, -30.0),
			glm::vec3(3.0, 2.4, -30.0),
			glm::vec3(6.0, 2.4, -30.0),
			glm::vec3(9.0, 2.4, -30.0),
			glm::vec3(12.0, 2.4, -30.0),
			glm::vec3(15.0, 2.4, -30.0),
			glm::vec3(-15.0, -1.4, -30.0),
			glm::vec3(-12.0, -1.4, -30.0),
			glm::vec3(-9.0, -1.4, -30.0),
			glm::vec3(-6.0, -1.4, -30.0),
			glm::vec3(-3.0, -1.4, -30.0),
			glm::vec3(0.0, -1.4, -30.0),
			glm::vec3(3.0, -1.4, -30.0),
			glm::vec3(6.0, -1.4, -30.0),
			glm::vec3(9.0, -1.4, -30.0),
			glm::vec3(12.0, -1.4, -30.0),
			glm::vec3(15.0, -1.4, -30.0),
			glm::vec3(-15.0, -4.2, -30.0),
			glm::vec3(-12.0, -4.2, -30.0),
			glm::vec3(-9.0, -4.2, -30.0),
			glm::vec3(-6.0, -4.2, -30.0),
			glm::vec3(-3.0, -4.2, -30.0),
			glm::vec3(0.0, -4.2, -30.0),
			glm::vec3(3.0, -4.2, -30.0),
			glm::vec3(6.0, -4.2, -30.0),
			glm::vec3(9.0, -4.2, -30.0),
			glm::vec3(12.0, -4.2, -30.0),
			glm::vec3(15.0, -4.2, -30.0),
			glm::vec3(-15.0, -8.0, -30.0),
			glm::vec3(-12.0, -8.0, -30.0),
			glm::vec3(-9.0, -8.0, -30.0),
			glm::vec3(-6.0, -8.0, -30.0),
			glm::vec3(-3.0, -8.0, -30.0)
		};
		for(int i = 0; i < 60; i++) {
			origins.push_back(org[i]);
		}

		// pop an origin from origins, 
		// use it to init a starting cube
		cubes.push_back(origins.back());
		origins.pop_back(); // remove last origin
	    // init first cube
	    cubes.back().init();
	}

	// RENDER INSTRUCTIONS
	void renderScene() {
		// clear the screen
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// get an angle
		float angle = glutGet(GLUT_ELAPSED_TIME) / 100.0;

		// iterate over cubes vector
		for(std::vector<Cube>::iterator it = cubes.begin();
			it != cubes.end();
			++it) {
			// get the current cube object
			Cube cube = *it;
			glm::vec3 origin = cube.getOrigin();

			// draw the objects
			// create model matrix
			glm::mat4 model;
			// note: transformations should be done in this order:
			// scale -> rotate -> transform
			// but the calculations must be done in reverse
			// translate model
			model = glm::translate(model, origin);
			// rotate model
			model = glm::rotate(model, glm::radians(angle), glm::vec3(0.0f, 0.0f, 1.0f));
			// give this model matrix to the shader
			shader.setMat4("model", model);
	        cube.draw();	
		}

		glutSwapBuffers();
	}

	// check time
	// from: http://www.lighthouse3d.com/tutorials/glut-tutorial/frames-per-second/
	void checkTime() {
		frame++;
		time = glutGet(GLUT_ELAPSED_TIME);

		if( time - timebase > 1000 ) {
			// get FPS
			fps = frame*1000.0/(time - timebase);
			timebase = time;
			// save the timestamp and FPS
			hist.addItem(std::to_string(time), std::to_string(fps));

			frame = 0;

			// create and init a new cube
			cubes.push_back(origins.back());
			origins.pop_back(); // remove last origin
		    cubes.back().init();

			// also, if time is greater than the stop time
			// save the fps data and stop the program
			if(time >= stopTime) {
				// save fps data
				hist.saveHistory();
				// end program
				exit(0);
			}
		}
	}
};



int main(int argc, char **argv) {

	Manager manager(argc, argv);	

	while(1==1) {
		glutMainLoopEvent();
		manager.renderScene();
		manager.checkTime();
	}
	
	return 0;
}