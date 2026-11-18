#pragma once
#include "sale/sale.hpp"
#include "ui_mainwindow.h"
#include <QMainWindow>
#include <QPointer>

class MainWindow final : public QMainWindow
{
  private:
    Q_OBJECT
    Ui::MainWindow* m_ui;
    QPointer<Sale> m_sale = nullptr;

  public:
    explicit MainWindow( QMainWindow* parent = nullptr );
    ~MainWindow();

  private:
    auto build_sale() -> void;
};
