#include "mainwindow.hpp"

#include "tab.hpp"

#include <QSize>
#include <QTabBar>

auto MainWindow::tab_info() -> std::array<TabInfo, 6>
{
    return {TabInfo{
                .name = QString("Venta"),
                .icon = QIcon(":res/sale.svg"),
                .tab = new Sale(nullptr),
            },
            TabInfo{

                .icon = QIcon(":res/client.svg"),
                .tab = new Client(nullptr),
            },
            TabInfo{
                .name = QString("Inventario"),
                .icon = QIcon(":res/inventory.svg"),
                .tab = new Inventory(nullptr),
            },
            TabInfo{
                .name = QString("Producto"),
                .icon = QIcon(":res/product.svg"),
                .tab = new Product(nullptr),
            },
            TabInfo{
                .name = QString("Reportes"),
                .icon = QIcon(":res/report.svg"),
                .tab = new Report(nullptr),
            },
            TabInfo{
                .name = QString("Configuraciones"),
                .icon = QIcon(":res/settings.svg"),
                .tab = new Configuration(nullptr),
            }};
}

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) { build_window(); }

MainWindow::~MainWindow() = default;

auto MainWindow::build_window() -> void
{
    this->setWindowTitle("onion");
    this->setFixedSize(QSize(1280, 720));
    build_tab_bar();
}

auto MainWindow::build_tab_bar() -> void
{
    tab_bar = new QTabWidget(this);

    auto info_list = tab_info();

    for (auto &info : info_list)
    {
        info.tab->setParent(tab_bar);
        tab_bar->addTab(info.tab, info.icon, info.name);
    }

    tab_bar->setDocumentMode(true);
    tab_bar->tabBar()->setExpanding(true);
    tab_bar->setIconSize(QSize(32, 32));
    tab_bar->setElideMode(Qt::ElideRight); // in case of small screen...
    this->setCentralWidget(tab_bar);
}
