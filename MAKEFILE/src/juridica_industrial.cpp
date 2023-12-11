#include <iostream>
#include <bits/stdc++.h>
#include "pessoajuridica.h"
#include "contabilidade_juridica.h"
#include "juridica_industrial.h" 
#include "recebe_arquivo.h"

void JuridicaIndustrial::_calculo_aliquotas_anexos(std::string cpf){
    // INDUSTRIA*
    RecebeArquivo receita;
    std::cout << "Valor Total da Receita Bruta: " << receita.retorna_receita_bruta(cpf) << std::endl;

    // Metalurgia**

    // Todo tipo de Metal = Simples Nacional ANEXO II
    if ((receita.retorna_receita_bruta(cpf)/1000) <= 180){ //verifica se a receita bruta é menor que 180 mil
        _result_simples_nacional = (receita.retorna_receita_bruta(cpf)) * 0.045; //calcula o valor a ser pago
        // aliquota 4,5%
        // desconto = 0
    }
    else if (180 < (receita.retorna_receita_bruta(cpf)/1000) <= 360){ //verifica se a receita bruta é menor que 360 mil
        _result_simples_nacional = (receita.retorna_receita_bruta(cpf) * 0.078) - 5940; //calcula o valor a ser pago
        // aliquota 7,8%
        // desconto = 5940
    }
    else if (360 < (receita.retorna_receita_bruta(cpf)/1000) <= 720){ //verifica se a receita bruta é menor que 720 mil
        _result_simples_nacional = (receita.retorna_receita_bruta(cpf) * 0.1) - 13860; //calcula o valor a ser pago
        // aliquota 10%
        // desconto = 13860
    }
    else if (720 < (receita.retorna_receita_bruta(cpf)/1000) <= 1800){ //verifica se a receita bruta é menor que 1.8 milhões
        _result_simples_nacional = (receita.retorna_receita_bruta(cpf) * 0.112) - 22500; //calcula o valor a ser pago
        // aliquota 11,2%
        // desconto = 22500
    }   
    else if (1800 < (receita.retorna_receita_bruta(cpf)/1000) <= 3600){ //verifica se a receita bruta é menor que 3.6 milhões
        _result_simples_nacional = (receita.retorna_receita_bruta(cpf) * 0.147) - 85500; //calcula o valor a ser pago
        // aliquota 14,7%
        // desconto = 85500
    }
    else if (3600 < (receita.retorna_receita_bruta(cpf)/1000) <= 4800){ //verifica se a receita bruta é menor que 4.8 milhões
        _result_simples_nacional = (receita.retorna_receita_bruta(cpf) * 0.3) - 720000; //calcula o valor a ser pago
        // aliquota 30%
        // desconto = 720000
    }
    else 
        _result_simples_nacional = (receita.retorna_receita_bruta(cpf) * 0.3) - 720000; //calcula o valor a ser pago
        // aliquota 30%
        // desconto = 720000
}

double JuridicaIndustrial::get_result_simples_nacional(){ //retorna o valor a ser pago ou restituído
    if(_result_simples_nacional < 0){ //verifica se o valor é menor que 0
        std::cout << "A sua empresa não obteve faturamento." << std::endl;
        return _result_simples_nacional = 0;
    }
    else if(_result_simples_nacional >= 0){ //verifica se o valor é maior que 0
        std::cout << "Valor a restituir: ";
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
            while (true)
            {
                std::cout << "Digite o valor do produto: ";
                try
                { // TRATAMENTO DE ERRO PARA ENTRADA DE DADOS
                    std::cin >> valor;
                    if (std::cin.fail())
                    {
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        throw std::invalid_argument("Devem ser digitados apenas números!");
                    }
                    if (valor < 0)
                    {
                        std::cout << "O valor não pode ser negativo!" << std::endl;
                    }
                    else
                        break;
                }
                catch (std::invalid_argument &e)
                {
                    std::cerr << e.what() << std::endl;
                }
            }
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

double JuridicaIndustrial::get_estoque(){ //valor do estoque
    for (int i = 0; i < _estoque.size(); i++){
        std::cout <<"Fonte: " <<  _estoque[i].first << std::endl << "Valor: " << _estoque[i].second << std::endl; // lista os produtos e valores do estoque
        _valor_estoque += _estoque[i].second;
    }
    std::cout << "Valor total do estoque: ";
    return  _valor_estoque; // valor total do estoque
}

std::vector<std::pair<std::string, double>> JuridicaIndustrial::get_estoque_dados()
{
    return std::vector<std::pair<std::string, double>>(_estoque);
}
