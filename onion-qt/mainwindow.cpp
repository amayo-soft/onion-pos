#include "mainwindow.hpp"

#include <QTabBar>
#include <utility>

// use to easy know what tab position is, names of tab are defined in .ui file
/*
 * static constexpr std::array<std::string_view, 6> tabs = {
    "Ventas", "Inventario", "Clientes", "Productos", "Cote", "Configuracion" };
*/

MainWindow::~MainWindow()
{
    if ( m_ui )
    {
        delete m_ui;
        m_ui = nullptr;
    }
}

MainWindow::MainWindow( QMainWindow* parent ) : QMainWindow( parent ), m_ui( new Ui::MainWindow() )
{
    m_ui->setupUi( this );
    m_ui->m_tab->tabBar()->setExpanding( true ); // need document mode
    m_ui->m_tab->setTabEnabled( 2, false );
    build_sale();
}

auto MainWindow::build_sale() -> void
{
    const auto sale_tab = std::move( m_ui->m_tab->widget( 0 ) );
    m_sale = new Sale( sale_tab );
}
