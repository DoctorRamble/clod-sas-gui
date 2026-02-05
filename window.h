#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QTextEdit>

class QPushButton;
class Window : public QWidget
{
    Q_OBJECT
public:
    explicit Window(QWidget *parent = 0);
signals:
private slots:
    void aboutQtButtonClicked();
    void loadLogButtonClicked();
    void clearTextButtonClicked();
private:
    // Icon
    QIcon *i_icon;
    QPushButton *b_iconHolder;
    // Buttons
    QPushButton *b_AboutQt;
    QPushButton *b_LoadLog;
    QPushButton *b_ClearText;
    QPushButton *b_Exit;
    // Text Box
    QTextEdit *t_text;
};

#endif // WINDOW_H

