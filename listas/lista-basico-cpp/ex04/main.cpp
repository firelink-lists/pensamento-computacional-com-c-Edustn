/**
 * @exercise Lista Básico C++ - Exercício 4
 * @title Template e Shared Pointer
 * @description Crie uma template de função `trocar` que receba dois parâmetros por referência e troque seus valores. No `main`, crie dois `shared_ptr` para diferentes tipos (ex: `int` e `double`), use a função template para trocar os valores apontados pelos shared_ptr, exiba os valores antes e depois da troca, e mostre a contagem de referências.
 * @input stdin
 * @output stdout
 * @timeout 1000
 * @test name="Troca int" input="5 10" expected="Antes: 5 10\nDepois: 10 5\nRefs: 1 1"
 * @test name="Troca double" input="3.14 2.71" expected="Antes: 3.14 2.71\nDepois: 2.71 3.14\nRefs: 1 1"
 */

#include <iostream>
#include <memory>

using namespace std;

// TODO: Crie o template de função trocar

template<typename T>
void trocar(T& a, T& b) {
    // Implementa a troca
    T temp = a;
    a = b;
    b = temp;
}

int main() {
    // Crie shared_ptr para int
    shared_ptr<int> p1 = make_shared<int>(5);
    shared_ptr<int> p2 = make_shared<int>(10);

    // Crie shared_ptr para double
    shared_ptr<double> p3 = make_shared<double>(3.14);
    shared_ptr<double> p4 = make_shared<double>(2.71);

    // Exiba valores antes da troca
    cout << "Antes: " << *p1 << " " << *p2 << endl;
    cout << "Antes: " << *p3 << " " << *p4 << endl;

    // Troque os valores
    trocar(*p1, *p2);
    trocar(*p3, *p4);

    // Exiba valores depois da troca
    cout << "Depois: " << *p1 << " " << *p2 << endl;
    cout << "Depois: " << *p3 << " " << *p4 << endl;

    // Mostre contagem de referências
    cout << "Refs: " << p1.use_count() << " " << p2.use_count() << endl;
    cout << "Refs: " << p3.use_count() << " " << p4.use_count() << endl;

    return 0;
}
