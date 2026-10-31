#include "mainwindow.hpp"
#include <QApplication>
#include <QFile>

int main(int argc, char *argv[])
{
    auto app = QApplication(argc, argv);

    QFile file(":/res/style.qss");
    if (file.open(QFile::ReadOnly | QFile::Text))
    {
        QTextStream stream(&file);
        app.setStyleSheet(stream.readAll());
        file.close();
    }

    auto window = MainWindow();
    window.show();
    return app.exec();
}
