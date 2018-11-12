
#define GLFW_DLL

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <cmath>

#include <src/shader.cpp>
#include <GLBenchmark/FPS_history.h>

// settings
class Manager {
private:
	// shader object
	Shader shader;
	// create object to track fps
	FPSHistory hist;

	//glfw window
	GLFWwindow* window;

	// buffers
	GLuint VBO, VAO;

	// temp vert obj
	float vertices[9] = {
         0.5f, -0.5f, 0.0f,  // bottom right
        -0.5f, -0.5f, 0.0f,  // bottom left
         0.0f,  0.5f, 0.0f   // top 
    };

    const unsigned int SCR_WIDTH = 800;
	const unsigned int SCR_HEIGHT = 600;

	// values for tracking fps
	double currentTime, previousTime;
	int frameCount;

public:
	// CONSTRUCTOR
	Manager(int argc, char** argv) {

		// init assorted variables
		currentTime = previousTime = 0.0;
		frameCount = 0;

		// glfw: initialize and configure
	    // ------------------------------
	    glfwInit();
	    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);  
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	#ifdef __APPLE__
	    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // uncomment this statement to fix compilation on OS X
	#endif

	    // glfw window creation
	    // --------------------
	    window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
	    if (window == NULL)
	    {
	        std::cout << "Failed to create GLFW window" << std::endl;
	        glfwTerminate();	        
	    }
	    glfwMakeContextCurrent(window);

		// init GLEW
		GLenum err = glewInit();
		if (err != GLEW_OK) {
			// const GLubyte* vendor = glGetString​(GL_VENDOR); 
		  	std::cout << "GLEW ERROR: \n" << glewGetErrorString(err) << std::endl << "vendor: " << glGetString(GL_VENDOR);
		  	exit(1); // or handle the error in a nicer way
		}
		if (!GLEW_VERSION_3_3)  // check that the machine supports the 2.1 API.
		  exit(1); // or handle the error in a nicer way

		// init shader
		shader.init("src/shader.vert","src/shader.frag");
		// use the shader object
		shader.use();

	    // INIT BUFFERS
	    glGenVertexArrays(1, &VAO);
	    glGenBuffers(1, &VBO);
	    // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
	    glBindVertexArray(VAO);

	    glBindBuffer(GL_ARRAY_BUFFER, VBO);
	    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	    glEnableVertexAttribArray(0);

	    glBindVertexArray(VAO);
	}

	// DESTRUCTOR
	~Manager() {
		// optional: de-allocate all resources once they've outlived their purpose:
	    // ------------------------------------------------------------------------
	    glDeleteVertexArrays(1, &VAO);
	    glDeleteBuffers(1, &VBO);

	    // save FPS history
	    hist.saveHistory();
	}

	// RENDER INSTRUCTIONS
	void renderScene(void) {

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		// calculate FPS
		calculateFPS();

		// update shader uniform
		double timeValue = glfwGetTime();

		float blueValue = sin(timeValue) / 2.0f + 0.5f;
		shader.setFloat("ourColor", blueValue);

		// render the triangle
        glDrawArrays(GL_TRIANGLES, 0, 3);
 		
 		glfwSwapBuffers(window);
        glfwPollEvents();
	}

	// CALCULATE FPS
	void calculateFPS(void) {
		currentTime = glfwGetTime();
	    frameCount++;
	    // If a second has passed.
	    if ( currentTime - previousTime >= 1.0 )
	    {
	        // save the frame count
	        hist.addItem(std::to_string(currentTime), std::to_string(frameCount));

	        frameCount = 0;
	        previousTime = currentTime;
	    }
	}
};


int main(int argc, char **argv) {

	Manager manager(argc, argv);	


	// enter GLUT event processing cycle
	// glutMainLoop();

	
	return 0;
}