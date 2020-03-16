#include<glad/glad.h>
#include<GLFW/glfw3.h>

#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height); \
void processInput(GLFWwindow* window);

const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

const char* vertexShaderSource = "#version 330 core\n"
     "layout (location = 0) in vec3 aPos;\n"
     "void main ()\n"
     "{\n"
     "gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0); \n"
     "}\n\0";

const char* fragmentShaderSource = "#version 330 core\n"
     "out vec4 Fragcolor; \n"
     "void main ()\n"
     "{\n"
     "     Fragcolor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
     "}\n\0";

const char* fragmentShaderSource2 = "#version 330 core\n"
"out vec4 Fragcolor; \n"
"void main ()\n"
"{\n"
"     Fragcolor = vec4(1.0f, 1.0f, 0.0f, 1.0f);\n"
"}\n\0";





int main()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


	GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT , "Learnopengl", NULL, NULL);
	if (window == NULL)
	{
		std::cout << " Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
	std::cout << "Failed to initialize GLAD" << std::endl;
	return -1;
    }

	int vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource (vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader (vertexShader);

	int success;
	char infoLog[512];
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(vertexShader, 512, NULL,  infoLog);
		std::cout << "ERROR :: SHADER :: VERTEX :: COMPILATION FAILED\n" << infoLog << std::endl;
	}


	int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);

	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
		std::cout << "ERROR :: SHADER :: FRAGMENT :: COMPILATION FAILED\n" << infoLog << std::endl;
	}



	int fragmentShader2 = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader2, 1, &fragmentShaderSource2, NULL);
	glCompileShader(fragmentShader2);

	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
		std::cout << "ERROR :: SHADER :: FRAGMENT :: COMPILATION FAILED\n" << infoLog << std::endl;
	}



	int shaderProgram = glCreateProgram( );
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);

	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
		std::cout << "ERROR :: SHADER :: PROGRAM :: COMPILATION FAILED\n" << infoLog << std::endl;
	}


	int shaderProgram2 = glCreateProgram();
	glAttachShader(shaderProgram2, vertexShader);
	glAttachShader(shaderProgram2, fragmentShader2);
	glLinkProgram(shaderProgram2);

	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
		std::cout << "ERROR :: SHADER :: PROGRAM :: COMPILATION FAILED\n" << infoLog << std::endl;
	}

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
	glDeleteShader(fragmentShader2);

	float vertices [ ] = {
		        
		0.0f,  0.2f, 0.0f,  // top right
		  0.0f, -0.2f, 0.0f,  // bottom right
		   -0.4f, -0.2f, 0.0f,  // bottom left
		-0.4f,  0.2f, 0.0f,  // top left

	  
	  

	   

	};


	unsigned int indices [ ] = {

	0, 1, 3,   // first triangle
	1, 2, 3    // second triangle

	};



	float vertices2[] = {



	0.4f,  0.2f, 0.0f,  // top right
		0.4f, -0.2f, 0.0f,  // bottom right
		   0.0f, -0.2f, 0.0f,  // bottom left
	0.0f,  0.2f, 0.0f,  // top left




	};



	/*unsigned int indices [ ] = {

	0, 1, 3,   // first triangle
	1, 2, 3    // second triangle

	};*/

    unsigned int  VBOs [2];
	unsigned int VAOs[2];
    unsigned int EBO [2];


	glGenVertexArrays(2,VAOs);
	glGenBuffers(2, VBOs);
	glGenBuffers(2, EBO);

	glBindVertexArray(VAOs[0]);

	glBindBuffer(GL_ARRAY_BUFFER, VBOs[0]);

	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	
	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	//glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices , GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3* sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO[0]);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);


	glBindVertexArray(VAOs[1]);

	glBindBuffer(GL_ARRAY_BUFFER, VBOs[1]);

	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices2, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO[1]);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glBindVertexArray(0);

	while (!glfwWindowShouldClose(window))
	{
		processInput(window);


		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glUseProgram(shaderProgram);
		glBindVertexArray(VAOs[0]);
		//glDrawArrays(GL_TRIANGLES, 0, 6);
		glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_INT, 0);

		glUseProgram(shaderProgram2);
		glBindVertexArray(VAOs[1]);
		glDrawElements(GL_TRIANGLES, 9,GL_UNSIGNED_INT, 0);
		//glDrawArrays(GL_TRIANGLES, 0, 6);




		glfwSwapBuffers(window);
		glfwPollEvents();

	}

	glDeleteVertexArrays(2, VAOs);
	glDeleteBuffers(2, VBOs);
	//glDeleteBuffers(1, &EBO);


	glfwTerminate();
	return 0;
}



void processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}
