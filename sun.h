#ifndef SUN_H
#define SUN_H

#include <QWidget>

namespace Ui {
class Sun;
}

class Sun : public QWidget
{
    Q_OBJECT

public:
    explicit Sun(QWidget *parent = nullptr);
    ~Sun();

private:
    Ui::Sun *ui;
};

#endif // SUN_H
