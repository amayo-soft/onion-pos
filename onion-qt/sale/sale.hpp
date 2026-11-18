#pragma once
#include "ui_toolbar.h"
#include <QFrame>
#include <QHBoxLayout>
#include <QPointer>
#include <QToolBar>
#include <QVBoxLayout>
#include <QWidget>

class Sale final : public QWidget
{
  private:
    QPointer<QVBoxLayout> main_layout = nullptr;
    QPointer<QToolBar> m_toolbar = nullptr;
    QPointer<QFrame> m_frame = nullptr;
    Ui::m_widget* m_tb_layout = nullptr;

  public:
    Sale( QWidget* parent );
    ~Sale();

  private:
    auto build_toolbar() -> void;
};
