#include <iostream>
#include <bits/stdc++.h>
#include "pessoajuridica.h"
#include "contabilidade_juridica.h"
#include "juridica_industrial.h" 

void JuridicaIndustrial::_calculo_aliquotas_anexos(){
    // INDUSTRIA*

    // Metalurgia**

    // Todo tipo de Metal = Simples Nacional ANEXO II
    if (JuridicaIndustrial::get_receita_bruta() < 180){
        _result_simples_nacional = JuridicaIndustrial::get_receita_bruta() * 0.045;
        // aliquota 4,5%
        // desconto = 0
    }
    if (180 < JuridicaIndustrial::get_receita_bruta() < 360){
        _result_simples_nacional = (JuridicaIndustrial::get_receita_bruta() * 0.078) - 5940;
        // aliquota 7,8%
        // desconto = 5940
    }
    if (360 < JuridicaIndustrial::get_receita_bruta() < 720){
        _result_simples_nacional = (JuridicaIndustrial::get_receita_bruta() * 0.1) - 13860;
        // aliquota 10%
        // desconto = 13860
    }
    if (720 < JuridicaIndustrial::get_receita_bruta() < 1800){
        _result_simples_nacional = (JuridicaIndustrial::get_receita_bruta() * 0.112) - 22500;
        // aliquota 11,2%
        // desconto = 22500
    }
    if (1800 < JuridicaIndustrial::get_receita_bruta() < 3600){
        _result_simples_nacional = (JuridicaIndustrial::get_receita_bruta() * 0.147) - 85500;
        // aliquota 14,7%
        // desconto = 85500
    }
    if (3600 < JuridicaIndustrial::get_receita_bruta() < 4800){
        _result_simples_nacional = (JuridicaIndustrial::get_receita_bruta() * 0.3) - 720000;
        // aliquota 30%
        // desconto = 720000
    }
}

double JuridicaIndustrial::get_result_simples_nacional(){
    if(_result_simples_nacional < 0){
       std::cout << "Valor a recolher: " << std::endl;
        return _result_simples_nacional*-1;
    }
    else if(_result_simples_nacional > 0){
        std::cout << "Valor a restituir: " << std::endl;
        return _result_simples_nacional;
    }
    return 0;
}

void JuridicaIndustrial::set_estoque(){
    std::string nome;
    double valor;
    std::cout << "Digite o nome do produto: ";
    std::cin >> nome;
    std::cout << "Digite o valor do produto: ";
    std::cin >> valor;
    _estoque.push_back({nome, valor});
}

void JuridicaIndustrial::get_estoque(){
    for (int i = 0; i < _estoque.size(); i++){
        std::cout << _estoque[i] << std::endl;
    }
}