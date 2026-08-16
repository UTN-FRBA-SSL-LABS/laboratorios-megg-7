#include <stdio.h>
#include "../src/carrito.h"
#include "minunit/minunit.h"

/*
 * Tests de integracion: verifican que las funciones trabajan bien
 * en combinacion, no de forma aislada.
 */

/* ═══════════════════════════════════════════════════════════════════════════
 *  PARTE D — Escribir el test guiado (ver README.md, Parte 8)
 * ═══════════════════════════════════════════════════════════════════════════ */

/* TODO: escribir test_compra_con_descuento() siguiendo la guia del .md */

void test_compra_con_descuento(void) {
    printf("\n[compra con descuento]\n");
    Carrito c;
    carrito_init(&c);
    Producto p1 = {"Leche", 350, 2};  /* 350 x 2 = 700 */
    Producto p2 = {"Pan", 150, 3};    /* 150 x 3 = 450 */
    carrito_agregar(&c, p1);
    carrito_agregar(&c, p2);
    int total = carrito_total(&c);     /* total = 700 + 450 = 1150 */
    int final = carrito_descuento(total, 10); /* descuento del 10% */
    ASSERT_IGUAL(1150, total);
    ASSERT_IGUAL(1035, final);          /* precio final = 1150 - (1150 * 10 / 100) = 1035 */
}

/* ═══════════════════════════════════════════════════════════════════════════
 *  PARTE E — Disenar un test propio (ver README.md, Parte 9)
 * ═══════════════════════════════════════════════════════════════════════════ */

/* TODO: escribir test_agregar_hasta_llenar() */

void test_agregar_hasta_llenar(void) {
    printf("\n[agregar hasta llenar]\n");
    Carrito c;
    carrito_init(&c);
    Producto p = {"Leche", 350, 1};
    for (int i = 0; i < MAX_ITEMS; i++) {
        ASSERT_IGUAL(1, carrito_agregar(&c, p));  /* deberia poder agregar hasta MAX_ITEMS */
    }
    ASSERT_IGUAL(0, carrito_agregar(&c, p));      /* ahora deberia fallar al agregar uno mas */
    ASSERT_IGUAL(MAX_ITEMS, carrito_contar(&c));  /* cantidad de productos en el carrito */
}

int main(void) {
    printf("=== Tests de integracion ===");
    /* Descomentar a medida que agregues las funciones: */
    test_compra_con_descuento();  
    test_agregar_hasta_llenar();  
    RESUMEN();
    return EXIT_CODE();
}
