#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

using namespace std;

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);

int main() {


	setlocale(LC_ALL, "rus");
	cout << "Hello" << endl;

	// glm test
	glm::vec4 vec(1.0f, 1.0f, 1.0f, 1.0f);
	glm::mat4 trans = glm::mat4(1.0f); // Матрица идентичности
	//trans = glm::translate(trans, glm::vec3(1.0f, 1.0f, 0.0f)); // translation
	// Вектор будет переведен в 2,1,0
	//trans = glm::rotate(trans, glm::radians(90.0f), glm::vec3(0.0, 0.0, 1.0)); // Поворот
	//trans = glm::scale(trans, glm::vec3(0.5, 0.5, 0.5)); // Масштабирование
	vec = trans * vec;
	cout << vec.x << ' ' << vec.y << ' ' << vec.z << endl;

	
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

# ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

	GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL Rudzeris", NULL, NULL);
	if (window == NULL) { // Окно не создалось
		cout << "Не получилось созать окно.\n";
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		cout << "Не получилось инициализировать GLAD\n";
		return -2;
	}

	glViewport(0, 0, 800, 600); // Создание окна (положение и ширина и высота)

	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	while (!glfwWindowShouldClose(window)) {
		// Проверка на выход
		processInput(window);

		// Рендеринг
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		// Выслать новый кадр в окно
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, true);
	}
}
