
#include <GL/glew.h>
#include <gl/freeglut.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


#include <iostream>
#include <cmath>
#include <vector>

#include <src/shader.cpp>
#include <GLBenchmark/FPS_history.h>
#include <GLBenchmark/cube.h>

glm::vec3 origin = glm::vec3(15.0, 10.0, -30.0);
Cube cube(1, origin);

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

	// for toggling wireframe
	bool toggleWireframe = false;

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

	    cube.init();
	}

	// RENDER INSTRUCTIONS
	void renderScene() {
		// clear the screen
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// get an angle
		float angle = glutGet(GLUT_ELAPSED_TIME) / 100.0;

		// draw the objects
		glm::mat4 model;
		model = glm::translate(model, origin);
		model = glm::rotate(model, glm::radians(angle), glm::vec3(0.0f, 0.0f, 1.0f));
		shader.setMat4("model", model);
        cube.draw();

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

			if(toggleWireframe) {
				glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );
				toggleWireframe = false;
			} else {
				glPolygonMode( GL_FRONT_AND_BACK, GL_FILL );
				toggleWireframe = true;
			}

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