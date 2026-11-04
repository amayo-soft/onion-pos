#pragma once

#include <QFrame>
#include <QIcon>
#include <QMainWindow>
#include <QPointer>
#include <QTabWidget>
#include <QVBoxLayout>
#include <QWidget>

#include <array>

// some widget properties
namespace Props
{
    struct TabInfo
    {
        QString name;
        QIcon icon;
        QPointer<QFrame> tab = nullptr;
    };

} // namespace Props

using namespace Props;

class MainWindow : public QMainWindow
{
    Q_OBJECT
  public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

  private:
    auto build_window() -> void;
    auto build_tab_bar() -> void;

    /*
     * @brief GET TAB PROPERTIES.
     * @return ARRAY OF TABS PROPERTIES.
     */
    [[nodiscard]] auto tab_info() -> std::array<TabInfo, 6>;

    QPointer<QTabWidget> tab_bar;
};
