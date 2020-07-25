#include <QWidget>


class MainWidget : public QWidget
{
    Q_OBJECT
    void (MainWidget::*FUNC)(int);

public:
    explicit MainWidget(QWidget *parent,QString serverIP,int httpPort,int tcpPort,int udpPort);
    ~MainWidget();
private:
    void test_fuc(int);
    void select_main_card(int){};
    void select_next_card(int){};
public:
    //注册钩子
    void register_key_hook();
    //释放钩子
    void unregister_key_hook();
    void excute_function(FUNC fun,int param)
    {
        (this->*fun)(param);
    }
}

struct  ITEM_FUNC
{
    int  code;
    FUNC pFun;
    int  param;
};
