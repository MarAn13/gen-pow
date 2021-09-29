#pragma once
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMessageBox>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <Windows.h>
#include <iostream>
#include <cmath>
#include <thread>
#include <chrono>

class Gen_pow_SFML
{
public:
	Gen_pow_SFML(int num, int power, QWidget* parent = nullptr);
	~Gen_pow_SFML();
private:
	QWidget* parent;
	sf::RenderWindow window;
	const std::string path_to_sound = "media/sound/";
	const int num_of_sound_files = 2;
	const std::string file_location[2] = { "step_sound.wav", "success.wav" };
	sf::SoundBuffer* file_buffers;
	sf::Sound* sound;
	sf::Font font;
	std::string path_to_font = "media/font/";
	std::string font_file = "Roboto-Regular.ttf";
	sf::Text text;
	std::chrono::time_point<std::chrono::system_clock> global_start;
	std::chrono::time_point<std::chrono::system_clock> global_end = std::chrono::time_point<std::chrono::system_clock>();
	const int delay = 1000;
	struct Rect {
		long long int height;
		long long int width;
	};
	Rect rect = { 1, 1 };
	const int num;
	const int power;
	void draw_driver();
	void draw(int x_center, int y_center, long long int& pixel_scale, int temp_power);
};
