#include "tab.hpp"

#include <QIcon>
#include <QTabBar>

Sale::Sale(QFrame *tab_parent) : QFrame(tab_parent) { build_tab(); }

Sale::~Sale() = default;

auto Sale::build_tab() -> void
{
    main_layout = new QVBoxLayout(this);

    set_layout();
    set_tooltip();
    this->setLayout(main_layout);
}

auto Sale::set_layout() -> void
{
    QPointer<QFrame> main = new QFrame();
    QPointer<QVBoxLayout> m_layout = new QVBoxLayout();

    build_tool_bar(m_layout);
    build_search_bar();
    set_button();
    build_ticket(m_layout);

    /* TOOLBAR LAYOUTS -------------------------------------------------------------------------*/
    QPointer<QFrame> tool_bar_frame = new QFrame();
    QPointer<QVBoxLayout> tool_bar_layout = new QVBoxLayout();
    // anonimous space to set layout without care for same var names
    {
        QPointer<QHBoxLayout> h_layout = new QHBoxLayout();  // first row
        QPointer<QHBoxLayout> h2_layout = new QHBoxLayout(); // second row
        QPointer<QVBoxLayout> v_layout = new QVBoxLayout();

        h_layout->setAlignment(Qt::AlignLeft);
        h_layout->setSpacing(10);
        h2_layout->setAlignment(Qt::AlignLeft);
        h2_layout->setSpacing(10);

        QPointer<QLabel> lbl = new QLabel("Codigo del Producto:");
        lbl->setObjectName("lbl_code");

        h_layout->addWidget(lbl);
        h_layout->addWidget(search);

        for (const auto &btn : tb_btn_list.get_button())
        {
            if (btn->objectName() == "search_btn")
            {
                h_layout->addWidget(btn);
                continue;
            }
            h2_layout->addWidget(btn);
        }

        h_layout->addStretch();
        h2_layout->addStretch();

        v_layout->addLayout(h2_layout);
        tool_bar_layout->addLayout(h_layout);
        tool_bar_layout->addLayout(v_layout);

        tool_bar_frame->setLayout(tool_bar_layout);

    } // END TOOLBAR LAYOUT ---------------------------------------------------------------- */

    /* TOOLBAR ADD WIDGET -----------------------------------------------------------------*/
    tool_bar->addWidget(tool_bar_frame);

    /* END */

    main->setLayout(m_layout);
    main_layout->addWidget(main);
}

auto Sale::build_tool_bar(QVBoxLayout *parent) -> void
{
    if (!parent)
        return;

    tool_bar = new QToolBar();
    tool_bar->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    parent->addWidget(tool_bar);
}

auto Sale::build_ticket(QVBoxLayout *parent) -> void
{
    if (!parent)
        return;

    tickets = new QTabWidget();
    tickets->addTab(new QFrame, "ticket 1");
    tickets->setElideMode(Qt::ElideRight);
    tickets->tabBar()->setExpanding(true);
    tickets->setTabsClosable(true);
    parent->addWidget(tickets);
}

auto Sale::build_search_bar() -> void
{
    if (!tool_bar)
        return;

    search = new QLineEdit();
    search->addAction(QIcon(":res/search.svg"), QLineEdit::LeadingPosition);
    search->setPlaceholderText("Buscar...");
    search->setFixedSize(600, 35);
}

auto Sale::set_button() -> void
{
    if (!tool_bar)
        return;

    search_btn = new QPushButton(QIcon(":res/search.svg"), "Buscar");
    search_btn->setFixedWidth(100);
    search_btn->setObjectName("search_btn"); // Identifier for style
    tb_btn_list.storage_button(search_btn);

    // TOOLBAR SECOND ROW OF BUTTONS
    art_various_btn = new QPushButton(QIcon(":res/boxes.svg"), "Art. Varios");
    tb_btn_list.storage_button(art_various_btn);

    art_common_btn = new QPushButton(QIcon(":res/list-plus.svg"), "Art. Comun");
    tb_btn_list.storage_button(art_common_btn);

    search_product_btn = new QPushButton(QIcon(":res/search.svg"), "[F3] / Buscar Producto");
    tb_btn_list.storage_button(search_product_btn);

    wholesale_btn = new QPushButton(QIcon(":res/wholesale.svg"), "Mayoreo");
    tb_btn_list.storage_button(wholesale_btn);

    entry_btn = new QPushButton(QIcon(":res/entry-arrow.svg"), "Entrada");
    tb_btn_list.storage_button(entry_btn);

    departures_btn = new QPushButton(QIcon(":res/departure-arrow.svg"), "Salida");
    tb_btn_list.storage_button(departures_btn);

    delete_art_btn = new QPushButton(QIcon(":res/trash.svg"), "[Del] / Borrar");
    tb_btn_list.storage_button(delete_art_btn);

    for (const auto &btn : tb_btn_list.get_button())
    {
        if (btn->objectName() != "search_btn")
        {
            btn->setProperty("tb", true);
        }
    }
}
auto Sale::set_tooltip() -> void
{
    search_btn->setToolTip("Buscar un Producto");
    art_various_btn->setToolTip("agregar por cantidad");
    art_common_btn->setToolTip("agregar producto fuera de inventario");
    search_product_btn->setToolTip("Buscar Producto en inventario");
    wholesale_btn->setToolTip("Establecer Articulo al por mayor");
}
auto Sale::set_binding() -> void {}
