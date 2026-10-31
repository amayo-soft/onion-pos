#include "tab.hpp"

Report::Report(QFrame *tab_parent) : QFrame(tab_parent) { build_tab(); }

Report::~Report() = default;

auto Report::build_tab() -> void {}
auto Report::set_layout() -> void {}
auto Report::set_binding() -> void {}
auto Report::set_button() -> void {}
