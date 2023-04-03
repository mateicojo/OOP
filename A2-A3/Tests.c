//
// Created by mok_a on 3/27/2023.
//

#include "Tests.h"
#include <string.h>
#include <assert.h>
#include <stdio.h>
void test_add_material_service() {
    Repo* repo=create_repo();
    Services* services = create_service(repo);
    char* name = "Material 1";
    char* supplier = "Supplier 1";
    int quant = 10;
    int day = 1;
    int month = 1;
    int year = 2022;
    Services* result = add_material_service(services, name, supplier, quant, day, month, year);
    assert(result != NULL);
    assert(get_length(get_repo(result)) == 1);
    Material material = get_material(get_repo(result),0);
    assert(strcmp(get_name(material), name) == 0);
    assert(strcmp(get_supplier(material), supplier) == 0);
    assert(get_quant(material) == quant);
    assert(get_day(material) == day);
    assert(get_month(material) == month);
    assert(get_year(material) == year);
    destroy_material(&material);
    destroy_repo(repo);
    destroy_service(result);
}

void test_update_material_service() {
    Repo* repo=create_repo();
    Services* services = create_service(repo);
    char* name = "Material 1";
    char* supplier = "Supplier 1";
    int quant = 10;
    int day = 1;
    int month = 1;
    int year = 2022;
    Services* result = add_material_service(services, name, supplier, quant, day, month, year);
    assert(result != NULL);
    char* new_supplier = "Supplier 2";
    int new_quant = 20;
    int new_day = 2;
    int new_month = 2;
    int new_year = 2023;
    Date new_date = create_date(new_day, new_month, new_year);
    update_material_service(result, name, new_supplier, new_quant, new_date);
    Material material = get_material(repo,1);
    assert(get_quant(material) == 0);
    assert(get_day(material) == 0);
    assert(get_month(material) == 0);
    assert(get_year(material) == 0);
    destroy_material(&material);
    destroy_repo(repo);
    destroy_service(result);
}


int Tests() {
    test_add_material_service();
    test_update_material_service();
    printf("All tests passed!\n");
}