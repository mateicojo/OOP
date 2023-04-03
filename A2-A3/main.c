//
// Created by mok_a on 3/13/2023.
//

#include "UI.h"
#include "Tests.h"

int main() {
    Tests();
    UI *ui = create_ui();
    start(ui);
    return 0;
}