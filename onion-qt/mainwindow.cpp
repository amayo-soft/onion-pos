#include "mainwindow.hpp"
#include <QTabBar>

// use to easy know what tab position is, names of tab are defined in .ui file
/*
 * static constexpr std::array<std::string_view, 6> tabs = {
    "Ventas", "Inventario", "Clientes", "Productos", "Cote", "Configuracion" };
*/

MainWindow::MainWindow( QMainWindow* parent ) : QMainWindow( parent ), m_ui( new Ui::MainWindow() )
{
    m_ui->setupUi( this );
    m_ui->m_tab->tabBar()->setExpanding( true ); // need document mode
    m_ui->m_tab->setTabEnabled( 2, false );
}

MainWindow::~MainWindow()
{
    if ( m_ui )
    {
        delete m_ui;
        m_ui = nullptr;
    }
}
