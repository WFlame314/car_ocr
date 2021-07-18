/********************************************************************************
** Form generated from reading UI file 'process2.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROCESS2_H
#define UI_PROCESS2_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_process2
{
public:

    void setupUi(QWidget *process2)
    {
        if (process2->objectName().isEmpty())
            process2->setObjectName(QString::fromUtf8("process2"));
        process2->resize(400, 300);

        retranslateUi(process2);

        QMetaObject::connectSlotsByName(process2);
    } // setupUi

    void retranslateUi(QWidget *process2)
    {
        process2->setWindowTitle(QCoreApplication::translate("process2", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class process2: public Ui_process2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROCESS2_H
