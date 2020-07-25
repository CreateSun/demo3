#ifndef DIALOG_H
#define DIALOG_H

#include <QWidget>

namespace Ui {
class Contact;
}

class Contact : public QWidget
{
    Q_OBJECT

public:
    explicit Contact(QWidget *parent = nullptr);
    ~Contact();

private:
    Ui::Contact *ui;
};

#endif // DIALOG_H
