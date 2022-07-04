/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QSlider>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QToolButton *addmusic;
    QToolButton *playButton;
    QLabel *showName;
    QSlider *progress;
    QLabel *showProgress;
    QToolButton *previousButton;
    QToolButton *nextButton;
    QListWidget *showlrcWidget;
    QListWidget *playlistWidget;
    QToolButton *playbackMode;
    QToolButton *clearButton;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(800, 600);
        addmusic = new QToolButton(Widget);
        addmusic->setObjectName(QString::fromUtf8("addmusic"));
        addmusic->setGeometry(QRect(560, 50, 71, 31));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        addmusic->setIcon(icon);
        playButton = new QToolButton(Widget);
        playButton->setObjectName(QString::fromUtf8("playButton"));
        playButton->setGeometry(QRect(280, 470, 91, 31));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/pause.png"), QSize(), QIcon::Normal, QIcon::Off);
        playButton->setIcon(icon1);
        showName = new QLabel(Widget);
        showName->setObjectName(QString::fromUtf8("showName"));
        showName->setGeometry(QRect(20, 520, 431, 21));
        progress = new QSlider(Widget);
        progress->setObjectName(QString::fromUtf8("progress"));
        progress->setGeometry(QRect(50, 560, 611, 21));
        progress->setOrientation(Qt::Horizontal);
        showProgress = new QLabel(Widget);
        showProgress->setObjectName(QString::fromUtf8("showProgress"));
        showProgress->setGeometry(QRect(690, 560, 91, 21));
        previousButton = new QToolButton(Widget);
        previousButton->setObjectName(QString::fromUtf8("previousButton"));
        previousButton->setGeometry(QRect(200, 470, 61, 31));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/previous.png"), QSize(), QIcon::Normal, QIcon::Off);
        previousButton->setIcon(icon2);
        nextButton = new QToolButton(Widget);
        nextButton->setObjectName(QString::fromUtf8("nextButton"));
        nextButton->setGeometry(QRect(400, 470, 61, 31));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/next.png"), QSize(), QIcon::Normal, QIcon::Off);
        nextButton->setIcon(icon3);
        showlrcWidget = new QListWidget(Widget);
        showlrcWidget->setObjectName(QString::fromUtf8("showlrcWidget"));
        showlrcWidget->setGeometry(QRect(115, 90, 351, 271));
        playlistWidget = new QListWidget(Widget);
        playlistWidget->setObjectName(QString::fromUtf8("playlistWidget"));
        playlistWidget->setGeometry(QRect(575, 90, 191, 271));
        playbackMode = new QToolButton(Widget);
        playbackMode->setObjectName(QString::fromUtf8("playbackMode"));
        playbackMode->setGeometry(QRect(560, 470, 81, 31));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/sequential.png"), QSize(), QIcon::Normal, QIcon::Off);
        playbackMode->setIcon(icon4);
        clearButton = new QToolButton(Widget);
        clearButton->setObjectName(QString::fromUtf8("clearButton"));
        clearButton->setGeometry(QRect(690, 50, 71, 31));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/clear.png"), QSize(), QIcon::Normal, QIcon::Off);
        clearButton->setIcon(icon5);

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        addmusic->setText(QCoreApplication::translate("Widget", "\346\267\273\345\212\240", nullptr));
        playButton->setText(QCoreApplication::translate("Widget", "\346\222\255\346\224\276", nullptr));
        showName->setText(QCoreApplication::translate("Widget", "\346\255\214\346\233\262\345\220\215", nullptr));
        showProgress->setText(QCoreApplication::translate("Widget", "\346\222\255\346\224\276\350\277\233\345\272\246", nullptr));
        previousButton->setText(QCoreApplication::translate("Widget", "\344\270\212\344\270\200\351\246\226", nullptr));
        nextButton->setText(QCoreApplication::translate("Widget", "\344\270\213\344\270\200\351\246\226", nullptr));
        playbackMode->setText(QCoreApplication::translate("Widget", "\345\276\252\347\216\257\346\250\241\345\274\217", nullptr));
        clearButton->setText(QCoreApplication::translate("Widget", "\346\267\273\345\212\240", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
