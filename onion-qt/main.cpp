#include "mainwindow.hpp"
#include <QApplication>
#include <QDebug>
#include <QFile>

int main( int argc, char* argv[] )
{
    const auto& app = QApplication( argc, argv );
    auto window = MainWindow();
    window.show();

    if ( QFile::exists( ":/icon.png" ) )
    {
        window.setWindowIcon( QIcon( ":/icon.png" ) );
        qDebug() << "Icon File Found";
    }
    else qDebug() << "Icon Resource Not Found";

    return app.exec();
}
