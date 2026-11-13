#pragma once
#include "ui_mainwindow.h"
#include <QMainWindow>
#include <QPointer>

class MainWindow final : public QMainWindow
{
  private:
    Q_OBJECT
    Ui::MainWindow* m_ui;

  public:
    explicit MainWindow( QMainWindow* parent = nullptr );
    ~MainWindow();
};
