#include "form.h"
#include "ui_form.h"
#include <QWindow>
#include <QProcess>
#ifdef Q_OS_WIN
#include <windows.h>
#endif


using namespace Everything;
//"D:\Everything\Everything.exe"

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
}

Form::~Form()
{

    if(M_WINDOW)
    {
        M_WINDOW->setTransientParent(nullptr);
        M_WINDOW->setFlags(M_WINDOW->flags() &~ Qt::CustomizeWindowHint &~ Qt::WindowTitleHint);
        M_WINDOW->setParent(nullptr);
        delete M_WINDOW;
        M_WINDOW = nullptr;
    }
    if(everythingChildWidget)
    {
        ui->horizontalLayout->removeWidget(everythingChildWidget);
    }
    delete ui;
}

void Form::showEvent(QShowEvent *event)
{
#ifdef Q_OS_WIN
    if(!M_WINDOW)
    {
        WId m_wid = (WId)FindWindow(L"EVERYTHING",L"EVERYTHING");//第一个参数xxx为调用的exe的类名；第二个xxx参数为调用的exe的标题名。
        M_WINDOW = QWindow::fromWinId(m_wid);
        if(M_WINDOW)
        {
            M_WINDOW->setFlags(M_WINDOW->flags() | Qt::CustomizeWindowHint | Qt::WindowTitleHint);
            everythingChildWidget =QWidget::createWindowContainer(M_WINDOW);//创建新的widget
            ui->horizontalLayout->addWidget(everythingChildWidget);//将widget窗口加入到主界面布局中
        }
    }
#endif
}

void Form::hideEvent(QHideEvent *event)
{

}


