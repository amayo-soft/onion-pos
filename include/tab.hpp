#pragma once

#include <QFrame>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QList>
#include <QPointer>
#include <QPushButton>
#include <QTabWidget>
#include <QToolBar>
#include <QVBoxLayout>

/* Tabs class */
class Tab; // Base Class
class Sale;
class Inventory;
class Client;
class Product;
class Configuration;
class Report;

namespace Widget
{
    struct Button
    {
        QList<QPointer<QPushButton>> button;
        auto storage_button(QPushButton *btn) -> void { button.append(btn); }
        [[nodiscard]] auto get_button() -> QList<QPointer<QPushButton>> { return button; }
    };
} // namespace Widget

class Tab
{
  public:
    virtual ~Tab() = default;

  protected:
    virtual auto build_tab() -> void = 0;
    virtual auto set_layout() -> void = 0;  // Set the layout
    virtual auto set_binding() -> void = 0; // bind widget with their custom action
    virtual auto set_button() -> void = 0;  // no need explaination

#ifndef DISABLED
    virtual auto set_tooltip() -> void {}
#endif
};

class Sale : protected Tab, public QFrame
{

  public:
    explicit Sale(QFrame *tab_parent);
    ~Sale() override;

  protected:
    auto build_tab() -> void override;
    auto set_layout() -> void override;
    auto set_binding() -> void override;
    auto set_button() -> void override;

  private:
    auto build_search_bar() -> void;
    auto build_tool_bar(QVBoxLayout *parent) -> void;
    auto build_ticket(QVBoxLayout *parent) -> void;
    auto add_ticket() -> void;
    auto delete_ticket(int index) -> void;

#ifndef DISABLED
    auto set_tooltip() -> void override;
#else
    auto set_tooltip() -> void;
#endif

    QPointer<QVBoxLayout> main_layout = nullptr;
    QPointer<QTabWidget> tickets = nullptr;
    QPointer<QToolBar> tool_bar = nullptr;

    Widget::Button tb_btn_list; // toolbar btn list

    /* Controls */
    QPointer<QLineEdit> search = nullptr;

    // search by code, stay at the right of the search bar
    QPointer<QPushButton> search_btn = nullptr;
    QPointer<QPushButton> art_various_btn = nullptr;
    QPointer<QPushButton> art_common_btn = nullptr;     // common article button
    QPointer<QPushButton> search_product_btn = nullptr; // open a new window with inventory
    QPointer<QPushButton> wholesale_btn = nullptr;
    QPointer<QPushButton> entry_btn = nullptr;      // money entry
    QPointer<QPushButton> departures_btn = nullptr; // money departures
    QPointer<QPushButton> delete_art_btn = nullptr; // delete article from the table
    QPointer<QPushButton> new_ticket = nullptr;
};

class Client : protected Tab, public QFrame
{
  public:
    explicit Client(QFrame *tab_parent);
    ~Client() override;

  protected:
    auto build_tab() -> void override;
    auto set_layout() -> void override;
    auto set_binding() -> void override;
    auto set_button() -> void override;
};

class Inventory : protected Tab, public QFrame
{
  public:
    explicit Inventory(QFrame *tab_parent);
    ~Inventory() override;

  protected:
    auto build_tab() -> void override;
    auto set_layout() -> void override;
    auto set_binding() -> void override;
    auto set_button() -> void override;
};

class Product : protected Tab, public QFrame
{
  public:
    explicit Product(QFrame *tab_parent);
    ~Product() override;

  protected:
    auto build_tab() -> void override;
    auto set_layout() -> void override;
    auto set_binding() -> void override;
    auto set_button() -> void override;
};

class Report : protected Tab, public QFrame
{
  public:
    explicit Report(QFrame *tab_parent);
    ~Report() override;

  protected:
    auto build_tab() -> void override;
    auto set_layout() -> void override;
    auto set_binding() -> void override;
    auto set_button() -> void override;
};

class Configuration : protected Tab, public QFrame
{
  public:
    explicit Configuration(QFrame *tab_parent);
    ~Configuration() override;

  protected:
    auto build_tab() -> void override;
    auto set_layout() -> void override;
    auto set_binding() -> void override;
    auto set_button() -> void override;
};
