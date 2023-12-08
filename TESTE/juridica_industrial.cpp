#include <iostream>
#include <bits/stdc++.h>
#include "pessoajuridica.h"
#include "contabilidade_juridica.h"
#include "juridica_industrial.h" 

void JuridicaIndustrial::_calculo_aliquotas_anexos(){
    // INDUSTRIA*

    // Metalurgia**

    // Todo tipo de Metal = Simples Nacional ANEXO II
    if ((JuridicaIndustrial::get_receita_bruta()/1000) < 180){
        _result_simples_nacional = (JuridicaIndustrial::get_receita_bruta()+_valor_estoque) * 0.045;
        // aliquota 4,5%
        // desconto = 0
    }
    if (180 < (JuridicaIndustrial::get_receita_bruta()/1000) < 360){
        _result_simples_nacional = (JuridicaIndustrial::get_receita_bruta() * 0.078) - 5940;
        // aliquota 7,8%
        // desconto = 5940
    }
    if (360 < (JuridicaIndustrial::get_receita_bruta()/1000) < 720){
        _result_simples_nacional = (JuridicaIndustrial::get_receita_bruta() * 0.1) - 13860;
        // aliquota 10%
        // desconto = 13860
    }
    if (720 < (JuridicaIndustrial::get_receita_bruta()/1000) < 1800){
        _result_simples_nacional = (JuridicaIndustrial::get_receita_bruta() * 0.112) - 22500;
        // aliquota 11,2%
        // desconto = 22500
    }
    if (1800 < (JuridicaIndustrial::get_receita_bruta()/1000) < 3600){
        _result_simples_nacional = (JuridicaIndustrial::get_receita_bruta() * 0.147) - 85500;
        // aliquota 14,7%
        // desconto = 85500
    }
    if (3600 < (JuridicaIndustrial::get_receita_bruta()/1000) < 4800){
        _result_simples_nacional = (JuridicaIndustrial::get_receita_bruta() * 0.3) - 720000;
        // aliquota 30%
        // desconto = 720000
    }
}

double JuridicaIndustrial::get_result_simples_nacional(){
    if(_result_simples_nacional < 0){
        std::cout << "A sua empresa não obteve faturamento." << std::endl;
        return _result_simples_nacional = 0;
    }
    else if(_result_simples_nacional > 0){
        std::cout << "Valor a restituir: " << std::endl;
        return _result_simples_nacional;
    }
    return 0;
}

void JuridicaIndustrial::set_estoque(){
    std::string fonte;
    int valor;
    bool opcao = false;
    int valida;
    while(!opcao){
        std::cout << std::endl;
        std::cout << "Você deseja adicionar informação ao estoque? " << std::endl;
        std::cout << "(1) - Sim" << std::endl;
        std::cout << "(2) - Não" << std::endl;
        while (true){
            try{
                std::cin >> valida;
                if (std::cin.fail())
                {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    throw std::invalid_argument("Devem ser digitados apenas números!");
                }
                break;
            }
            catch (std::invalid_argument &e)
            {
                std::cerr << e.what() << std::endl;
            }
        }   
        if(valida == 1){
            std::cin.ignore();
            std::cout << "Digite o nome do produto: ";  
            getline(std::cin, fonte);
            std::cout << "Digite o valor do produto: ";
            std::cin >> valor;
            _estoque.push_back({fonte, valor});
        }
        else if(valida == 2){
            opcao = true;
        }
        else{
            std::cout<<std::endl;
            std::cout << "Opção inválida!" << std::endl;
        }
    }
}

void JuridicaIndustrial::get_estoque(){ //valor do estoque
    for (int i = 0; i < _estoque.size(); i++){
        std::cout <<"Fonte: " <<  _estoque[i].first << std::endl << " Valor: " << _estoque[i].second << std::endl;
    }
}

double JuridicaIndustrial::get_valor_estoque(){
    for(auto i : _estoque){
        _valor_estoque += i.second;
    }
    return _valor_estoque;
}