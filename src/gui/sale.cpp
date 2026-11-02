#include "tab.hpp"

#include <QIcon>
#include <qnamespace.h>

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
    QPointer<QVBoxLayout> tool_bar_layout = new QVBoxLayout();
    // anonimous space to set layout without care for same var names
    {
        QPointer<QHBoxLayout> h_layout = new QHBoxLayout();
        QPointer<QHBoxLayout> h2_layout = new QHBoxLayout(); // second row
        QPointer<QVBoxLayout> v_layout = new QVBoxLayout();

        h_layout->setAlignment(Qt::AlignLeft);
        h2_layout->setAlignment(Qt::AlignLeft);

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

        v_layout->addLayout(h2_layout);
        tool_bar_layout->addLayout(h_layout);
        tool_bar_layout->addLayout(v_layout);

        tool_bar_frame->setLayout(tool_bar_layout);

    } // END TOOLBAR LAYOUT ---------------------------------------------------------------- */

    /* TOOLBAR ADD WIDGET -----------------------------------------------------------------*/
    tool_bar->addWidget(tool_bar_frame);

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
    tb_btn_list.storage_button(search_btn);

    // TOOLBAR SECOND ROW OF BUTTONS
    art_various_btn = new QPushButton("Art. Varios");
    art_various_btn->setFixedWidth(150);
    art_various_btn->setProperty("tb", true); // group of buttons for style
    tb_btn_list.storage_button(art_various_btn);

    art_common_btn = new QPushButton("Art. Comun");
    art_common_btn->setFixedWidth(150);
    art_common_btn->setProperty("tb", true);
    tb_btn_list.storage_button(art_common_btn);
}
auto Sale::set_binding() -> void {}
