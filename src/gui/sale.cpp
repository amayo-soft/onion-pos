#include "tab.hpp"

#include <QIcon>
#include <QTabBar>

Sale::Sale(QFrame *tab_parent) : QFrame(tab_parent) { build_tab(); }

Sale::~Sale() = default;

auto Sale::build_tab() -> void
{
    main_layout = new QVBoxLayout(this);

    build_tool_bar(main_layout);
    build_ticket(main_layout);
    set_tooltip();
    set_binding();

    this->setLayout(main_layout);
}

auto Sale::build_tool_bar(QVBoxLayout *parent) -> void
{
    if (!parent)
        return;

    tool_bar = new QToolBar();
    tool_bar->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    build_search_bar();
    set_tb_button();

    QPointer<QFrame> tool_bar_frame = new QFrame();
    QPointer<QVBoxLayout> tool_bar_layout = new QVBoxLayout();
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

    tool_bar->addWidget(tool_bar_frame);
    parent->addWidget(tool_bar);
}

auto Sale::build_ticket(QVBoxLayout *parent) -> void
{
    if (!parent)
        return;

    tickets = new QTabWidget();
    tickets->setElideMode(Qt::ElideRight);
    tickets->tabBar()->setExpanding(false);
    tickets->setTabsClosable(true);
    tickets->addTab(new QFrame, "Ticket 1");

    new_ticket = new QPushButton("+");
    new_ticket->setObjectName("add_ticket_btn");
    new_ticket->setFixedSize(25, 25);

    auto corner_widget = new QWidget();
    auto corner_layout = new QHBoxLayout(corner_widget);
    corner_layout->addWidget(new_ticket);
    corner_layout->setContentsMargins(0, 0, 0, 0);
    corner_layout->setSpacing(0);

    tickets->setCornerWidget(corner_widget, Qt::TopRightCorner);

    parent->addWidget(tickets);
}

auto Sale::add_ticket() -> void
{
#ifndef DISABLED
    if (tickets->count() >= 10)
#else
    if (tickets->count() >= 5)
#endif
        return;

    QPointer<QFrame> ticket = new QFrame();

    auto ticket_count = tickets->count() + 1;
    auto title = QString("Ticket %1").arg(ticket_count);

    tickets->addTab(ticket, title);
    tickets->setCurrentWidget(ticket);
}
auto Sale::delete_ticket(int index) -> void
{
    if (tickets->count() <= 1)
        return;

    auto ticket = tickets->widget(index);
    tickets->removeTab(index);
    if (ticket)
        ticket->deleteLater();
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

auto Sale::set_tb_button() -> void
{

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
auto Sale::set_binding() -> void
{
    QObject::connect(new_ticket, &QPushButton::clicked, this, &Sale::add_ticket);
    QObject::connect(tickets, &QTabWidget::tabCloseRequested, this, &Sale::delete_ticket);
}
