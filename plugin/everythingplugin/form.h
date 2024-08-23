#ifndef FORM_H
#define FORM_H

#include <QWidget>


namespace Everything {
namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = nullptr);
    ~Form();

    // QWidget interface
protected:
    void showEvent(QShowEvent *event);
    void hideEvent(QHideEvent *event);

private:
    Ui::Form *ui;
    QWindow *M_WINDOW = nullptr;
    QWidget *everythingChildWidget = nullptr;


};
}

#endif // FORM_H
