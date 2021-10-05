#pragma once

#include <QtWidgets/QWidget>
#include <QTimer>
#include "ui_Gen_pow_loading_screen.h"

class Gen_pow_Qt_loading : public QWidget
{
	Q_OBJECT

public:
	Gen_pow_Qt_loading(QWidget* parent = Q_NULLPTR);
	~Gen_pow_Qt_loading();

private:
	Ui::Gen_pow_loading_screen* ui;
	const int anim_num = 7;
	const std::string qrc_prefix = ":/gen_pow/";
	const std::string folder_path = "media/doubles_anim/";
	const std::string anim_paths[7] = { "doubles_state_1.png", "doubles_state_2.png", "doubles_state_3.png", "doubles_state_4.png", "doubles_state_5.png",
		"doubles_state_6.png", "doubles_state_7.png" };
	int current_anim = 0;
	void update_pixelmap();
	void Gen_pow_Qt_loading::closeEvent(QCloseEvent* event);
};
