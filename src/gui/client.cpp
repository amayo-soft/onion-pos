#include "tab.hpp"

Client::Client(QFrame *tab_parent) : QFrame(tab_parent) { build_tab(); }

Client::~Client() = default;

auto Client::build_tab() -> void {}
auto Client::set_layout() -> void {}
auto Client::set_binding() -> void {}
auto Client::set_button() -> void {}
