#include "Gen_pow_Qt_loading.h"

Gen_pow_Qt_loading::Gen_pow_Qt_loading(QWidget* parent)
	: QWidget(parent), ui(new Ui::Gen_pow_loading_screen)
{
	ui->setupUi(this);
	const int delay = 1000;
	QTimer* timer = new QTimer(this);
	connect(timer, &QTimer::timeout, this, QOverload<>::of(&Gen_pow_Qt_loading::update_pixelmap));
	timer->start(delay);
}

Gen_pow_Qt_loading::~Gen_pow_Qt_loading()
{
	delete ui;
}

void Gen_pow_Qt_loading::update_pixelmap()
{
	QPixmap pix;

	if (pix.load(QString::fromStdString(folder_path + anim_paths[current_anim]))) {
		pix = pix.scaled(ui->label_anim->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
		ui->label_anim->setPixmap(pix);
		if (current_anim == anim_num - 1) {
			current_anim = 0;
		}
		else {
			current_anim += 1;
		}
	}
}

void Gen_pow_Qt_loading::closeEvent(QCloseEvent* event)
{
	exit(0);
}