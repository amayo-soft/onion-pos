#include "sale.hpp"
#include "ui_toolbar.h"

Sale::~Sale()
{
    if ( m_tb_layout )
    {
        delete m_tb_layout;
        m_tb_layout = nullptr;
    }
}

Sale::Sale( QWidget* parent )
    : QWidget( parent ), main_layout( new QVBoxLayout ), m_toolbar( new QToolBar ),
      m_tb_layout( new Ui::m_widget ), m_frame( new QFrame )
{
    build_toolbar();
    main_layout->addWidget( m_frame );
    this->setLayout( main_layout );
}

auto Sale::build_toolbar() -> void { m_tb_layout->setupUi( m_frame ); }
