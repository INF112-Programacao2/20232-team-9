#include <iostream>
#include <bits/stdc++.h>

#include "cadastro.h"
#include "contabilidade_juridica.h"

void ContabilJuridica::set_caixa(int quant_elementos){
    const char* fonte;
    double valor;
    for(int i = 0; i < quant_elementos; i++){
        std::cout << "Digite a fonte: ";
        std::cin >> fonte;
        std::cout << "Digite o valor: ";
        std::cin >> valor;
        _caixa.push_back({fonte,valor});
    }
    
}

void ContabilJuridica::set_contasPagar(int quant_elementos){
    const char* fonte;
    double valor;
    for(int i = 0; i < quant_elementos; i++){
        std::cout << "Digite a fonte: ";
        std::cin >> fonte;
        std::cout << "Digite o valor: ";
        std::cin >> valor;
        _contasPagar.push_back({fonte,valor});
    }
}

void ContabilJuridica::set_contasReceber(int quant_elementos){
    const char* fonte;
    double valor;
    for(int i = 0; i < quant_elementos; i++){
        std::cout << "Digite a fonte: ";
        std::cin >> fonte;
        std::cout << "Digite o valor: ";
        std::cin >> valor;
        _contasReceber.push_back({fonte,valor});
    }
}

void ContabilJuridica::set_realizavelCurtoPrazo(int quant_elementos){
    const char* fonte;
    int valor;
    for(int i = 0; i < quant_elementos; i++){
        std::cout << "Digite a fonte: ";
        std::cin >> fonte;
        std::cout << "Digite o valor: ";
        std::cin >> valor;
        _realizavelCurtoPrazo.push_back({fonte,valor});
    }
}

void ContabilJuridica::set_realizavelLongoPrazo(int quant_elementos){
    const char* fonte;
    int valor;
    for(int i = 0; i < quant_elementos; i++){
        std::cout << "Digite a fonte: ";
        std::cin >> fonte;
        std::cout << "Digite o valor: ";
        std::cin >> valor;
        _realizavelLongoPrazo.push_back({fonte,valor});
    }
}

void ContabilJuridica::set_emprestimos(int quant_elementos){
    const char* fonte;
    double valor;
    for(int i = 0; i < quant_elementos; i++){
        std::cout << "Digite a fonte: ";
        std::cin >> fonte;
        std::cout << "Digite o valor: ";
        std::cin >> valor;
        _emprestimos.push_back({fonte,valor});
    }
}
