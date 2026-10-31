#pragma once

#include <QFrame>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPointer>
#include <QPushButton>
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

class Tab
{
  public:
    virtual ~Tab() = default;

  protected:
    virtual auto build_tab() -> void = 0;
    virtual auto set_layout() -> void = 0;  // Set the layout
    virtual auto set_binding() -> void = 0; // bind widget with their custom action
    virtual auto set_button() -> void = 0;  // no need explaination
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
    auto build_tool_bar(QFrame *parent) -> void;

    QPointer<QVBoxLayout> header = nullptr;
    QPointer<QVBoxLayout> center = nullptr;
    QPointer<QVBoxLayout> footer = nullptr;
    QPointer<QToolBar> tool_bar = nullptr;

    /* Controls */
    QPointer<QLineEdit> search = nullptr;

    QPointer<QPushButton> search_btn = nullptr;
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
