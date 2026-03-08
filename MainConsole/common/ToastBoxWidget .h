#ifndef TOASTBOXWIDGET_H
#define TOASTBOXWIDGET_H

#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QPropertyAnimation>
#include <QSequentialAnimationGroup>
#include <QHBoxLayout>
#include <QTimer>

class Toast : public QWidget {
public:
	Toast(QWidget *parent = nullptr) : QWidget(parent) {
		setupUI();
		setWindowOpacity(0); // Start fully transparent to avoid visual jump
	}

	void showToast(const QString &message, int duration = 3000) {
		messageLabel->setText(message);
		messageLabel->adjustSize();
		adjustSize(); // Adjust the size of the toast to fit the content

		if (!parentWidget()) {
			return;  // Ensure there is a parent widget
		}

		// Calculate start and end positions based on parent's position
		int startX = parentWidget()->mapToGlobal(parentWidget()->rect().center()).x() - width() / 2;
		int startY = parentWidget()->mapToGlobal(parentWidget()->rect().topLeft()).y() + 30; // Start 30 pixels below the top of the parent
		int endY = startY + 20; // End 20 pixels below the start position

		setGeometry(startX, startY, width(), height()); // Set initial geometry before showing

		// Prepare animations
		QPropertyAnimation *moveAnimation = new QPropertyAnimation(this, "pos");
		moveAnimation->setDuration(500);
		moveAnimation->setStartValue(QPoint(startX, startY));
		moveAnimation->setEndValue(QPoint(startX, endY));

		QPropertyAnimation *fadeInAnimation = new QPropertyAnimation(this, "windowOpacity");
		fadeInAnimation->setDuration(500);
		fadeInAnimation->setStartValue(0.0);
		fadeInAnimation->setEndValue(1.0);

		// Stay visible for the duration specified
		QTimer::singleShot(duration, this, [this]() {
			QPropertyAnimation *fadeOutAnimation = new QPropertyAnimation(this, "windowOpacity");
			fadeOutAnimation->setDuration(500);
			fadeOutAnimation->setStartValue(1.0);
			fadeOutAnimation->setEndValue(0.0);
			fadeOutAnimation->start();

			connect(fadeOutAnimation, &QPropertyAnimation::finished, this, &QWidget::hide);
		});

		QSequentialAnimationGroup *group = new QSequentialAnimationGroup(this);
		group->addAnimation(moveAnimation);
		group->addAnimation(fadeInAnimation);

		connect(group, &QSequentialAnimationGroup::finished, this, [this]() {
			setWindowOpacity(1.0); // Ensure that window opacity is reset if the toast is shown again
		});

		connect(closeButton, &QPushButton::clicked, this, &QWidget::hide);

		show();
		group->start();
	}

private:
	QLabel *messageLabel;
	QPushButton *closeButton;

	void setupUI() {
		messageLabel = new QLabel(this);
		closeButton = new QPushButton("×", this);
		closeButton->setStyleSheet("border: none; background-color: transparent; color: white; font-weight: bold; font-size: 14px;");
		closeButton->setFixedSize(20, 20);

		QHBoxLayout *layout = new QHBoxLayout(this);
		layout->addWidget(messageLabel);
		layout->addWidget(closeButton, 0, Qt::AlignTop | Qt::AlignRight);

		setLayout(layout);
		setStyleSheet("background-color: rgba(0, 0, 0, 180); padding: 10px;");
		setWindowFlags(Qt::FramelessWindowHint | Qt::Tool | Qt::WindowStaysOnTopHint);
		setAttribute(Qt::WA_TranslucentBackground);
	}
};

//int main(int argc, char *argv[]) {
//	QApplication app(argc, argv);
//
//	QWidget mainWindow;
//	mainWindow.resize(400, 400);
//	mainWindow.show();
//
//	Toast *toast = new Toast(&mainWindow);
//	toast->showToast("Hello, this is a toast message!", 3000);
//
//	return app.exec();
//}

#endif // TOASTBOXWIDGET_H
