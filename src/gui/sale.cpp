#include "tab.hpp"

#include <QIcon>

Sale::Sale(QFrame *tab_parent) : QFrame(tab_parent) { build_tab(); }

Sale::~Sale() = default;

auto Sale::build_tab() -> void
{
    QPointer<QVBoxLayout> main_layout = new QVBoxLayout(this);

    header = new QVBoxLayout();
    center = new QVBoxLayout();
    footer = new QVBoxLayout();

    main_layout->addLayout(header);
    main_layout->addLayout(center);
    main_layout->addLayout(footer);

    set_layout();
    this->setLayout(main_layout);
}

auto Sale::set_layout() -> void
{
    if (!(header || center || footer))
        return;

    QPointer<QFrame> header_container = new QFrame();
    QPointer<QFrame> footer_container = new QFrame();

    build_tool_bar(header_container);
    build_search_bar();
    set_button();

    /* TOOLBAR LAYOUTS -------------------------------------------------------------------------*/
    QPointer<QFrame> tool_bar_frame = new QFrame();
    QPointer<QHBoxLayout> h_layout = new QHBoxLayout();

    QPointer<QLabel> lbl = new QLabel("Codigo del Producto:");
    lbl->setObjectName("lbl_code");

    h_layout->addWidget(lbl, 0, Qt::AlignLeft);
    h_layout->addWidget(search);

    tool_bar_frame->setLayout(h_layout);
    /* END TOOLBAR LAYOUT ------------------------------------------------------------------*/

    /* TOOLBAR ADD WIDGET -----------------------------------------------------------------*/
    tool_bar->addWidget(tool_bar_frame);
    tool_bar->addWidget(search_btn);

    /* END */
    header->addWidget(header_container);
    footer->addWidget(footer_container);
}

auto Sale::build_tool_bar(QFrame *parent) -> void
{
    if (!parent)
        return;

    tool_bar = new QToolBar(parent);
    tool_bar->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
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
    if (!tool_bar || !header || !center || !footer)
        return;

    search_btn = new QPushButton(QIcon(":res/search.svg"), "Buscar");
    search_btn->setFixedWidth(150);
    search_btn->setObjectName("search_btn"); // Identifier for style
}
auto Sale::set_binding() -> void {}
