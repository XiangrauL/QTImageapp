/********************************************************************************
** Form generated from reading UI file 'QtWidgetsApplication1.ui'
**
** Created by: Qt User Interface Compiler version 5.14.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTWIDGETSAPPLICATION1_H
#define UI_QTWIDGETSAPPLICATION1_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtWidgetsApplication1Class
{
public:
    QWidget *centralWidget;
    QPushButton *ReadImg;
    QPushButton *HistAna;
    QPushButton *Multiline;
    QPushButton *Threshold;
    QLCDNumber *multilinetime;
    QSlider *ThresholdValue;
    QLabel *label1;
    QLabel *label2;
    QLabel *label3;
    QProgressBar *multilineprogess;
    QLineEdit *thresholdvalue;
    QLabel *lableImg;
    QLabel *labeltime;

    void setupUi(QMainWindow *QtWidgetsApplication1Class)
    {
        if (QtWidgetsApplication1Class->objectName().isEmpty())
            QtWidgetsApplication1Class->setObjectName(QString::fromUtf8("QtWidgetsApplication1Class"));
        QtWidgetsApplication1Class->resize(601, 481);
        QFont font;
        font.setPointSize(9);
        font.setBold(true);
        font.setWeight(75);
        QtWidgetsApplication1Class->setFont(font);
        centralWidget = new QWidget(QtWidgetsApplication1Class);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        ReadImg = new QPushButton(centralWidget);
        ReadImg->setObjectName(QString::fromUtf8("ReadImg"));
        ReadImg->setGeometry(QRect(440, 10, 111, 51));
        HistAna = new QPushButton(centralWidget);
        HistAna->setObjectName(QString::fromUtf8("HistAna"));
        HistAna->setGeometry(QRect(440, 80, 111, 51));
        Multiline = new QPushButton(centralWidget);
        Multiline->setObjectName(QString::fromUtf8("Multiline"));
        Multiline->setGeometry(QRect(440, 250, 111, 51));
        Threshold = new QPushButton(centralWidget);
        Threshold->setObjectName(QString::fromUtf8("Threshold"));
        Threshold->setGeometry(QRect(440, 150, 111, 51));
        multilinetime = new QLCDNumber(centralWidget);
        multilinetime->setObjectName(QString::fromUtf8("multilinetime"));
        multilinetime->setGeometry(QRect(500, 310, 61, 23));
        QFont font1;
        font1.setPointSize(12);
        multilinetime->setFont(font1);
        multilinetime->setAutoFillBackground(true);
        multilinetime->setSmallDecimalPoint(false);
        multilinetime->setDigitCount(4);
        multilinetime->setSegmentStyle(QLCDNumber::Flat);
        ThresholdValue = new QSlider(centralWidget);
        ThresholdValue->setObjectName(QString::fromUtf8("ThresholdValue"));
        ThresholdValue->setGeometry(QRect(410, 230, 160, 16));
        ThresholdValue->setOrientation(Qt::Horizontal);
        label1 = new QLabel(centralWidget);
        label1->setObjectName(QString::fromUtf8("label1"));
        label1->setGeometry(QRect(430, 210, 71, 16));
        label2 = new QLabel(centralWidget);
        label2->setObjectName(QString::fromUtf8("label2"));
        label2->setGeometry(QRect(400, 310, 101, 20));
        label3 = new QLabel(centralWidget);
        label3->setObjectName(QString::fromUtf8("label3"));
        label3->setGeometry(QRect(400, 350, 71, 20));
        multilineprogess = new QProgressBar(centralWidget);
        multilineprogess->setObjectName(QString::fromUtf8("multilineprogess"));
        multilineprogess->setGeometry(QRect(480, 350, 118, 23));
        multilineprogess->setValue(0);
        thresholdvalue = new QLineEdit(centralWidget);
        thresholdvalue->setObjectName(QString::fromUtf8("thresholdvalue"));
        thresholdvalue->setGeometry(QRect(510, 210, 41, 20));
        thresholdvalue->setReadOnly(true);
        lableImg = new QLabel(centralWidget);
        lableImg->setObjectName(QString::fromUtf8("lableImg"));
        lableImg->setGeometry(QRect(10, 20, 381, 441));
        labeltime = new QLabel(centralWidget);
        labeltime->setObjectName(QString::fromUtf8("labeltime"));
        labeltime->setGeometry(QRect(570, 310, 21, 21));
        labeltime->setMaximumSize(QSize(16777215, 16777215));
        labeltime->setBaseSize(QSize(0, 0));
        QFont font2;
        font2.setPointSize(13);
        font2.setBold(true);
        font2.setItalic(false);
        font2.setWeight(75);
        labeltime->setFont(font2);
        QtWidgetsApplication1Class->setCentralWidget(centralWidget);

        retranslateUi(QtWidgetsApplication1Class);

        QMetaObject::connectSlotsByName(QtWidgetsApplication1Class);
    } // setupUi

    void retranslateUi(QMainWindow *QtWidgetsApplication1Class)
    {
        QtWidgetsApplication1Class->setWindowTitle(QCoreApplication::translate("QtWidgetsApplication1Class", "QtWidgetsApplication1", nullptr));
        ReadImg->setText(QCoreApplication::translate("QtWidgetsApplication1Class", "\350\257\273\345\217\226\345\233\276\347\211\207", nullptr));
        HistAna->setText(QCoreApplication::translate("QtWidgetsApplication1Class", "\347\233\264\346\226\271\345\233\276\345\210\206\346\236\220", nullptr));
        Multiline->setText(QCoreApplication::translate("QtWidgetsApplication1Class", "\345\244\232\347\272\277\347\250\213\345\244\204\347\220\206", nullptr));
        Threshold->setText(QCoreApplication::translate("QtWidgetsApplication1Class", "\344\272\214\345\200\274\345\214\226\351\230\210\345\200\274", nullptr));
        label1->setText(QCoreApplication::translate("QtWidgetsApplication1Class", "\344\272\214\345\200\274\345\214\226\351\230\210\345\200\274", nullptr));
        label2->setText(QCoreApplication::translate("QtWidgetsApplication1Class", "\345\244\232\347\272\277\347\250\213\345\244\204\347\220\206\346\227\266\351\225\277", nullptr));
        label3->setText(QCoreApplication::translate("QtWidgetsApplication1Class", "\345\244\232\347\272\277\347\250\213\350\277\233\345\272\246", nullptr));
        lableImg->setText(QString());
        labeltime->setText(QCoreApplication::translate("QtWidgetsApplication1Class", "ms", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QtWidgetsApplication1Class: public Ui_QtWidgetsApplication1Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTWIDGETSAPPLICATION1_H
