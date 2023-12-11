#include <iostream>
#include <bits/stdc++.h>
#include "pessoajuridica.h"
#include "contabilidade_juridica.h"
#include "juridica_industrial.h" 

void JuridicaIndustrial::_calculo_aliquotas_anexos(){
    // INDUSTRIA*

    // Metalurgia**

    // Todo tipo de Metal = Simples Nacional ANEXO II
    if ((JuridicaIndustrial::get_receita_bruta()/1000) < 180){ //verifica se a receita bruta é menor que 180 mil
        _result_simples_nacional = (JuridicaIndustrial::get_receita_bruta()+_valor_estoque) * 0.045; //calcula o valor a ser pago
        // aliquota 4,5%
        // desconto = 0
    }
    if (180 < (JuridicaIndustrial::get_receita_bruta()/1000) < 360){ //verifica se a receita bruta é menor que 360 mil
        _result_simples_nacional = (JuridicaIndustrial::get_receita_bruta() * 0.078) - 5940; //calcula o valor a ser pago
        // aliquota 7,8%
        // desconto = 5940
    }
    if (360 < (JuridicaIndustrial::get_receita_bruta()/1000) < 720){ //verifica se a receita bruta é menor que 720 mil
        _result_simples_nacional = (JuridicaIndustrial::get_receita_bruta() * 0.1) - 13860; //calcula o valor a ser pago
        // aliquota 10%
        // desconto = 13860
    }
    if (720 < (JuridicaIndustrial::get_receita_bruta()/1000) < 1800){ //verifica se a receita bruta é menor que 1.8 milhões
        _result_simples_nacional = (JuridicaIndustrial::get_receita_bruta() * 0.112) - 22500; //calcula o valor a ser pago
        // aliquota 11,2%
        // desconto = 22500
    }
    if (1800 < (JuridicaIndustrial::get_receita_bruta()/1000) < 3600){ //verifica se a receita bruta é menor que 3.6 milhões
        _result_simples_nacional = (JuridicaIndustrial::get_receita_bruta() * 0.147) - 85500; //calcula o valor a ser pago
        // aliquota 14,7%
        // desconto = 85500
    }
    if (3600 < (JuridicaIndustrial::get_receita_bruta()/1000) < 4800){ //verifica se a receita bruta é menor que 4.8 milhões
        _result_simples_nacional = (JuridicaIndustrial::get_receita_bruta() * 0.3) - 720000; //calcula o valor a ser pago
        // aliquota 30%
        // desconto = 720000
    }
}

double JuridicaIndustrial::get_result_simples_nacional(){ //retorna o valor a ser pago ou restituído
    if(_result_simples_nacional < 0){ //verifica se o valor é menor que 0
        std::cout << "A sua empresa não obteve faturamento." << std::endl;
        return _result_simples_nacional = 0;
    }
    else if(_result_simples_nacional > 0){ //verifica se o valor é maior que 0
        std::cout << "Valor a restituir: " << std::endl;
        return _result_simples_nacional;
    }
    return 0;
}

void JuridicaIndustrial::set_estoque(){ // ADICIONA PRODUTOS E VALORES AO ESTOQUE
    std::string fonte;
    int valor;
    bool opcao = false;
    int valida;
    while(!opcao){  // LOOP PARA ADICIONAR PRODUTOS E VALORES AO ESTOQUE
        std::cout << std::endl;
        std::cout << "Você deseja adicionar informação ao estoque? " << std::endl;
        std::cout << "(1) - Sim" << std::endl;
        std::cout << "(2) - Não" << std::endl;
        while (true){
            try{ // TRATAMENTO DE ERRO PARA ENTRADA DE DADOS
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
        if(valida == 1){ // VERIFICA SE O USUÁRIO DESEJA ADICIONAR PRODUTOS E VALORES AO ESTOQUE
            std::cin.ignore();
            std::cout << "Digite o nome do produto: ";  
            getline(std::cin, fonte);
            std::cout << "Digite o valor do produto: ";
            std::cin >> valor;
            _estoque.push_back({fonte, valor});
        }
        else if(valida == 2){ // CASO O USUÁRIO NÃO QUEIRA ADICIONAR PRODUTOS E VALORES AO ESTOQUE E ENCERRE A LISTA
            opcao = true;
        }
        else{ // CASO O USUÁRIO DIGITE UMA OPÇÃO INVÁLIDA
            std::cout<<std::endl;
            std::cout << "Opção inválida!" << std::endl;
        }
    }
}

void JuridicaIndustrial::get_estoque(){ //valor do estoque
    for (int i = 0; i < _estoque.size(); i++){
        std::cout <<"Fonte: " <<  _estoque[i].first << std::endl << " Valor: " << _estoque[i].second << std::endl; // lista os produtos e valores do estoque
        _valor_estoque += _estoque[i].second;
    }
    std::cout << "Valor total do estoque: " << _valor_estoque << std::endl; // valor total do estoque
}