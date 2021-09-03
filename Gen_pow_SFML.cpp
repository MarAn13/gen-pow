#include "Gen_pow_SFML.h"

Gen_pow_SFML::Gen_pow_SFML(int num, int power, QWidget* parent)
	:num(num), power(power), parent(parent)
{
	try {
		HWND hd = GetDesktopWindow();
		HMONITOR monitor = MonitorFromWindow(hd, MONITOR_DEFAULTTONEAREST);
		MONITORINFO info;
		info.cbSize = sizeof(MONITORINFO);
		GetMonitorInfo(monitor, &info);
		int monitor_width = info.rcMonitor.right - info.rcMonitor.left;
		int monitor_height = info.rcMonitor.bottom - info.rcMonitor.top;
		float scale = 0.5;
		window.create(sf::VideoMode(monitor_width * scale, monitor_height * scale), "Gen pow", sf::Style::Titlebar | sf::Style::Close);
		if (!font.loadFromFile(font_file)) {
			throw std::exception("Font file was not found");
		}
		text.setFont(font);
		int character_size = 30;
		text.setCharacterSize(character_size);
		global_start = std::chrono::system_clock::now();
		draw_driver();
	}
	catch (std::exception& e) {
		if (parent) {
			QMessageBox::critical(parent, "Error", e.what());
		}
		else {
			std::cout << e.what() << std::endl;
		}
	}
}

Gen_pow_SFML::~Gen_pow_SFML()
{
}

void Gen_pow_SFML::draw_driver()
{
	const int x_center = window.getSize().x / 2;
	const int y_center = window.getSize().y / 2;
	long long int pixel_scale = 1;
	int height_offset = 1;
	int width_offset = 1;
	int temp_power = 0;
	sf::Event event;
	while (temp_power != power + 1) {
		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed) {
				window.close();
				return;
			}
		}
		draw(x_center, y_center, pixel_scale, temp_power);
		if (rect.height < rect.width) {
			rect.height = rect.height * num;
		}
		else {
			rect.width = rect.width * num;
		}
		++temp_power;
	}
	while (window.isOpen()) {
		if (window.waitEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
				return;
			}
		}
	}
}

void Gen_pow_SFML::draw(int x_center, int y_center, long long int& pixel_scale, int temp_power)
{
	window.clear(sf::Color::Black);
	std::chrono::duration<double> temp_elapsed_time = std::chrono::system_clock::now() - global_start;
	if (global_end != std::chrono::time_point<std::chrono::system_clock>()) {
		temp_elapsed_time = global_end - global_start;
	}
	std::string duration = std::to_string(temp_elapsed_time.count());
	duration = duration.substr(0, duration.find('.') + 3);
	text.setString("Current num: " + std::to_string(num) + '^' + std::to_string(temp_power) + '\n' +
		"Duration: " + duration + " seconds" + '\n' +
		"Delay: " + std::to_string(delay) + " milliseconds" + '\n' +
		"Pixel size: " + std::to_string(pixel_scale));
	text.setFillColor(sf::Color::White);
	window.draw(text);
	if (window.getSize().x <= rect.width / pixel_scale || window.getSize().y <= rect.height / pixel_scale) {
		pixel_scale = rect.width;
	}
	sf::RectangleShape temp(sf::Vector2f(rect.width / pixel_scale, rect.height / pixel_scale));
	temp.setPosition(x_center - temp.getSize().x / 2, y_center - temp.getSize().y / 2);
	if (temp_power == power) {
		temp.setFillColor(sf::Color::Green);
	}
	window.draw(temp);
	window.display();
	std::this_thread::sleep_for(std::chrono::milliseconds(delay));
}