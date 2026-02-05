#include "header.h"
#include "window.h"
#include <QApplication>
#include <QPushButton>
#include <QTextEdit>
#include <vector>

Window::Window(QWidget *parent) :
    QWidget(parent)
{
    // Set size of the window
    setFixedSize(1000, 720);

    // Icon
    i_icon = new QIcon(QString::fromStdString(path) + "\\assets\\icons\\icon.ico");
    b_iconHolder = new QPushButton(this);
    b_iconHolder->setGeometry(885, 10, 110, 110);
    b_iconHolder->setIcon(*i_icon);
    b_iconHolder->setIconSize(QSize(100, 100));
    b_iconHolder->setToolTip("\"WHO DARES WINS\"");
    // Load Log Button
    b_LoadLog = new QPushButton("Load Log", this);
    b_LoadLog->setGeometry(885, 120, 110, 30);
    b_LoadLog->setToolTip("Loads the log into the application and colourises it.");
    connect(b_LoadLog, SIGNAL (clicked()), this, SLOT (loadLogButtonClicked()));
    // Clear Text Button
    b_ClearText = new QPushButton("Clear Text", this);
    b_ClearText->setGeometry(885, 150, 110, 30);
    b_ClearText->setToolTip("Clears the text.");
    connect(b_ClearText, SIGNAL (clicked()), this, SLOT (clearTextButtonClicked()));
    // AboutQT Button
    b_AboutQt = new QPushButton("About QT", this);
    b_AboutQt->setGeometry(885, 180, 110, 30);
    b_AboutQt->setToolTip("Information about Qt.");
    connect(b_AboutQt, SIGNAL (clicked()), this, SLOT (aboutQtButtonClicked()));
    // Exit Button
    b_Exit = new QPushButton("Exit", this);
    b_Exit->setGeometry(885, 210, 110, 30);
    b_Exit->setToolTip("Bail Out! Bail Out!");
    connect(b_Exit, SIGNAL (clicked()), QApplication::instance(), SLOT (quit()));

    // Text Box
    t_text = new QTextEdit(this);
    t_text->setReadOnly(true);
    t_text->setGeometry(10, 10, 870, 700);
    t_text->show();
}

// If the "About QT" button is clicked
void Window::aboutQtButtonClicked() { QApplication::aboutQt(); }
// If the "Load Log" button is clicked
void Window::loadLogButtonClicked()
{
    // Calls function to call SAS, open the parsed .txt, edit it and output it to vec1
    sas();

    // Header
    t_text->setText("<p style=\"color: #B59410\"><b>Ramble's SAS GUI - v0</b></p>");
    // Loads the text into the textbox
    for(int i = 0; i < text_lines.size(); i++){
        t_text->append(QString::fromStdString(text_lines[i]));
    }

    // Sets the spacing between each line
    qreal lineSpacing = 100;
    QTextCursor textCursor = t_text->textCursor();
    QTextBlockFormat *newFormat = new QTextBlockFormat();
    textCursor.clearSelection();
    textCursor.select(QTextCursor::Document);
    newFormat->setLineHeight(lineSpacing, QTextBlockFormat::ProportionalHeight);
    textCursor.setBlockFormat(*newFormat);

}

void Window::clearTextButtonClicked()
{
    t_text->clear();
}
