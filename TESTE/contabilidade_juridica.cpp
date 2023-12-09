#include <iostream>
#include <bits/stdc++.h>
#include "pessoajuridica.h"
#include "contabilidade_juridica.h"


//SET

void ContabilJuridica::set_caixa(){ //ADICIONA VALORES AO CAIXA
    double valor;
    bool opcao = false;
    int valida;
    while(!opcao){ //LOOP PARA ADICIONAR VÁRIOS VALORES AO CAIXA    
        std::cout<<std::endl;
        std::cout << "Você deseja adicionar um valor ao caixa? " << std::endl;
        std::cout << "(1) - Sim" << std::endl;
        std::cout << "(2) - Não" << std::endl;
        while(true){
          try { // tratamento de exceções para entrada de dados
            std::cin >> valida;
            if (std::cin.fail()){
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                throw std::invalid_argument("Devem ser digitados apenas números!");
            }
            break;
           }
           catch (std::invalid_argument &e){
                std::cerr << e.what() << std::endl;
           }
        }
        if(valida == 1){ //CASO O USUÁRIO DESEJE ADICIONAR UM VALOR AO CAIXA
            std::cout << "Digite o valor: ";
            std::cin >> valor;
            _caixa.push_back(valor);
        }
        else if(valida == 2){ // CASO O USUÁRIO NÃO DESEJE ADICIONAR MAIS VALORES AO CAIXA E ENCERRE A LISTA
            opcao = true;
        }
        else{ //CASO O USUÁRIO DIGITE UMA OPÇÃO INVÁLIDA
            std::cout<<std::endl;
            std::cout << "Opção inválida!" << std::endl;
        }
    }
    
}

void ContabilJuridica::set_contasPagar(){ //ADICIONA VALORES ÀS CONTAS A PAGAR
    std::string fonte; 
    double valor;
    bool opcao = false;
    int valida;
    while (!opcao){ //LOOP PARA ADICIONAR VÁRIOS VALORES ÀS CONTAS A PAGAR
        std::cout<<std::endl;
        std::cout << "Você deseja adicionar informação à contas a pagar? " << std::endl;
        std::cout << "(1) - Sim" << std::endl;
        std::cout << "(2) - Não" << std::endl;
        while (true){
            try{ //tratamento de exceções para entrada de dados
                std::cin >> valida;
                if (std::cin.fail()){
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    throw std::invalid_argument("Devem ser digitados apenas números!");
                }
                break;
            }
            catch (std::invalid_argument &e){
                std::cerr << e.what() << std::endl;
            }
        }
        if(valida == 1){ //CASO O USUÁRIO DESEJE ADICIONAR UM VALOR ÀS CONTAS A PAGAR
            std::cin.ignore (); 
            std::cout << "Digite a fonte: ";
            getline (std::cin,fonte);
            std::cout << "Digite o valor: ";
            std::cin >> valor;
            _contasPagar.push_back({fonte,valor});
        }
        else if(valida == 2){ //CASO O USUÁRIO NÃO DESEJE ADICIONAR MAIS VALORES ÀS CONTAS A PAGAR E ENCERRE A LISTA
            opcao = true;
        }
        else{ //CASO O USUÁRIO DIGITE UMA OPÇÃO INVÁLIDA
            std::cout<<std::endl;
            std::cout << "Opção inválida!" << std::endl;
        }
    }
}

void ContabilJuridica::set_contasReceber(){ //ADICIONA VALORES ÀS CONTAS A RECEBER
    std::string fonte;
    double valor;
    bool opcao = false;
    int valida;
    while (!opcao) //LOOP PARA ADICIONAR VÁRIOS VALORES ÀS CONTAS A RECEBER
    {
        std::cout<<std::endl;
        std::cout << "Você deseja adicionar informação à contas a receber? " << std::endl;
        std::cout << "(1) - Sim" << std::endl;
        std::cout << "(2) - Não" << std::endl;
        while (true){
            try{ //tratamento de exceções para entrada de dados
                std::cin >> valida;
                if (std::cin.fail()){
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    throw std::invalid_argument("Devem ser digitados apenas números!");
                }
                break;
            }
            catch (std::invalid_argument &e){
                std::cerr << e.what() << std::endl;
            }
        }
        if(valida == 1){ //CASO O USUÁRIO DESEJE ADICIONAR UM VALOR ÀS CONTAS A RECEBER
            std::cin.ignore ();
            std::cout << "Digite a fonte: ";
            getline (std::cin,fonte);
            std::cout << "Digite o valor: ";
            std::cin >> valor;
            _contasReceber.push_back({fonte,valor});
        }
        else if(valida == 2){ //CASO O USUÁRIO NÃO DESEJE ADICIONAR MAIS VALORES ÀS CONTAS A RECEBER E ENCERRE A LISTA
            opcao = true;
        }
        else{ //CASO O USUÁRIO DIGITE UMA OPÇÃO INVÁLIDA
            std::cout<<std::endl;
            std::cout << "Opção inválida!" << std::endl;
        }
    }
}

void ContabilJuridica::set_realizavelCurtoPrazo(){ //ADICIONA VALORES AO REALIZÁVEL A CURTO PRAZO
    std::string fonte;
    int valor;
    bool opcao = false;
    int valida;
    while (!opcao){ //LOOP PARA ADICIONAR VÁRIOS VALORES AO REALIZÁVEL A CURTO PRAZO
        std::cout<<std::endl;
        std::cout << "Você deseja adicionar informação à realizável curto prazo? " << std::endl;
        std::cout << "(1) - Sim" << std::endl;
        std::cout << "(2) - Não" << std::endl;
        while (true){
            try{ //tratamento de exceções para entrada de dados
                std::cin >> valida;
                if (std::cin.fail()){
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    throw std::invalid_argument("Devem ser digitados apenas números!");
                }
                break;
            }
            catch (std::invalid_argument &e){
                std::cerr << e.what() << std::endl;
            }
        }
        if(valida == 1){ //CASO O USUÁRIO DESEJE ADICIONAR UM VALOR AO REALIZÁVEL A CURTO PRAZO
            std::cin.ignore ();
            std::cout << "Digite a fonte: ";
            getline (std::cin,fonte);
            std::cout << "Digite o valor: ";
            std::cin >> valor;
            _realizavelCurtoPrazo.push_back({fonte,valor});
        }
        else if(valida == 2){ //CASO O USUÁRIO NÃO DESEJE ADICIONAR MAIS VALORES AO REALIZÁVEL A CURTO PRAZO E ENCERRE A LISTA
            opcao = true;
        }
        else{ //CASO O USUÁRIO DIGITE UMA OPÇÃO INVÁLIDA
            std::cout<<std::endl;
            std::cout << "Opção inválida!" << std::endl;
        }
    }
}

void ContabilJuridica::set_realizavelLongoPrazo(){ //ADICIONA VALORES AO REALIZÁVEL A LONGO PRAZO
    std::string fonte;
    int valor;
    bool opcao = false;
    int valida;
    while (!opcao) //LOOP PARA ADICIONAR VÁRIOS VALORES AO REALIZÁVEL A LONGO PRAZO
    {
        std::cout<<std::endl;
        std::cout << "Você deseja adicionar informação à realizável longo prazo?" << std::endl;
        std::cout << "(1) - Sim" << std::endl;
        std::cout << "(2) - Não" << std::endl;
        while (true){
            try{ //tratamento de exceções para entrada de dados
                std::cin >> valida;
                if (std::cin.fail())
                {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    throw std::invalid_argument("Devem ser digitados apenas números!");
                }
                break;
            }
            catch (std::invalid_argument &e){
                std::cerr << e.what() << std::endl;
            }
        }
        if(valida == 1){ //CASO O USUÁRIO DESEJE ADICIONAR UM VALOR AO REALIZÁVEL A LONGO PRAZO
            std::cin.ignore ();
            std::cout << "Digite a fonte: ";
            getline (std::cin,fonte);
            std::cout << "Digite o valor: ";
            std::cin >> valor;
            _realizavelLongoPrazo.push_back({fonte,valor});
        }
        else if(valida == 2){ //CASO O USUÁRIO NÃO DESEJE ADICIONAR MAIS VALORES AO REALIZÁVEL A LONGO PRAZO E ENCERRE A LISTA
            opcao = true;
        }
        else{ //CASO O USUÁRIO DIGITE UMA OPÇÃO INVÁLIDA
            std::cout<<std::endl;
            std::cout << "Opção inválida!" << std::endl;
        }
    }
}

void ContabilJuridica::set_emprestimos(){ //ADICIONA VALORES AOS EMPRÉSTIMOS
    std::string fonte;
    double valor;
    bool opcao = false;
    int valida;
    while (!opcao) //LOOP PARA ADICIONAR VÁRIOS VALORES AOS EMPRÉSTIMOS
    {
        std::cout<<std::endl;
        std::cout << "Você deseja adicionar informação à emprestimos? " << std::endl;
        std::cout << "(1) - Sim" << std::endl;
        std::cout << "(2) - Não" << std::endl;
        while (true){
            try{ //tratamento de exceções para entrada de dados
                std::cin >> valida;
                if (std::cin.fail()){
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
        if(valida == 1){ //CASO O USUÁRIO DESEJE ADICIONAR UM VALOR AOS EMPRÉSTIMOS
            std::cin.ignore ();
            std::cout << "Digite a fonte: ";
            getline (std::cin,fonte); 
            std::cout << "Digite o valor: ";
            std::cin >> valor;
            _emprestimos.push_back({fonte,valor});
        }
        else if(valida == 2){ //CASO O USUÁRIO NÃO DESEJE ADICIONAR MAIS VALORES AOS EMPRÉSTIMOS E ENCERRE A LISTA
            opcao = true;
        }
        else{ //CASO O USUÁRIO DIGITE UMA OPÇÃO INVÁLIDA
            std::cout<<std::endl;
            std::cout << "Opção inválida!" << std::endl;
        }
    }
}


//GETS

double ContabilJuridica::get_caixa(){ //RETORNA O VALOR TOTAL DO CAIXA
    double total = 0;
    for(int i = 0; i < _caixa.size(); i++){
        total += _caixa[i];
    }
    //std::cout << "Valor total de Caixa: ";
    return total;
}

double ContabilJuridica::get_contasPagar(){ //RETORNA O VALOR TOTAL DAS CONTAS A PAGAR
    double total = 0;
    for(int i = 0; i < _contasPagar.size(); i++){
        //std::cout << _contasPagar[i].first << " : " << _contasPagar[i].second << std::endl; //IMPRIME A LISTA DE CONTAS A PAGAR
        total += _contasPagar[i].second;
    }
    //std::cout << "Valor total de Contas a Pagar: ";
    return total; // RETORNA O VALOR TOTAL DAS CONTAS A PAGAR
}

double ContabilJuridica::get_contasReceber(){ //RETORNA O VALOR TOTAL DAS CONTAS A RECEBER
    double total = 0;
    for(int i = 0; i < _contasReceber.size(); i++){
        //std::cout << _contasReceber[i].first << " : " << _contasReceber[i].second << std::endl; //IMPRIME A LISTA DE CONTAS A RECEBER
        total += _contasReceber[i].second;
    }
    //std::cout << "Valor total de Contas a Receber: ";
    return total; // RETORNA O VALOR TOTAL DAS CONTAS A RECEBER
}

int ContabilJuridica::get_realizavelCurtoPrazo(){ //RETORNA O VALOR TOTAL DO REALIZÁVEL A CURTO PRAZO
    int total = 0;
    for(int i = 0; i < _realizavelCurtoPrazo.size(); i++){
        //std::cout << _realizavelCurtoPrazo[i].first << " : " << _realizavelCurtoPrazo[i].second << std::endl; //IMPRIME A LISTA DE REALIZÁVEL A CURTO PRAZO
        total += _realizavelCurtoPrazo[i].second;
    }
    //std::cout << "Valor total de Realizável a Curto Prazo: ";
    return total; // RETORNA O VALOR TOTAL DO REALIZÁVEL A CURTO PRAZO
}

int ContabilJuridica::get_realizavelLongoPrazo(){ //RETORNA O VALOR TOTAL DO REALIZÁVEL A LONGO PRAZO
    int total = 0;
    for(int i = 0; i < _realizavelLongoPrazo.size(); i++){
        //std::cout << _realizavelLongoPrazo[i].first << " : " << _realizavelLongoPrazo[i].second << std::endl; //IMPRIME A LISTA DE REALIZÁVEL A LONGO PRAZO
        total += _realizavelLongoPrazo[i].second;
    }
    //std::cout << "Valor total de Realizável a Longo Prazo: ";
    return total; // RETORNA O VALOR TOTAL DO REALIZÁVEL A LONGO PRAZO
}

double ContabilJuridica::get_emprestimos(){ //RETORNA O VALOR TOTAL DE EMPRÉSTIMOS
    double total = 0;
    for(int i = 0; i < _emprestimos.size(); i++){
        //std::cout << _emprestimos[i].first << " : " << _emprestimos[i].second << std::endl; //IMPRIME A LISTA DE EMPRÉSTIMOS
        total += _emprestimos[i].second;
    }
    //std::cout << "Valor total de Empréstimos: ";
    return total; // RETORNA O VALOR TOTAL DE EMPRÉSTIMOS
}

//METODOS

void ContabilJuridica::_calculo_DRE(){ //CÁLCULO DA DEMONSTRAÇÃO DO RESULTADO DO EXERCÍCIO
    double receita = 0;
    double despesa = 0;
    double lucro = 0;
    for(int i = 0; i < _contasReceber.size(); i++){ 
        receita += _contasReceber[i].second; //CÁLCULO DAS RECEITAS
    }
    for(int i = 0; i < _contasPagar.size(); i++){
        despesa += _contasPagar[i].second; //CÁLCULO DAS DESPESAS
    }
    _receitas.push_back(receita);
    _despesas.push_back(despesa);
    lucro = receita - despesa; //CÁCULO DO LUCRO OU PREJUÍZO
    _result_dre.push_back(lucro);
    std::cout << "Receita: " << receita << std::endl;
    std::cout << "Despesa: " << despesa << std::endl;
    if(lucro>=0){
        std::cout << "Lucro: " << lucro << std::endl;
    }
    else{
        std::cout << "Despesa: " << lucro << std::endl;
    }
}

void ContabilJuridica::_calculo_fluxo_caixa(){ //CÁLCULO DO FLUXO DE CAIXA
    double caixa = 0;
    for(int i=0; i<_caixa.size(); i++){ //CÁLCULO DO CAIXA
        caixa+=_caixa[i];
    }
    for(int i = 0; i < _result_dre.size(); i++){ //CÁLCULO DO FLUXO DE CAIXA
        caixa += _result_dre[i];
    }
    _resultado_fluxo_caixa = caixa;
    std::cout << "Resultado do fluxo de caixa: " << _resultado_fluxo_caixa << std::endl; //IMPRIME O RESULTADO DO FLUXO DE CAIXA
}

void ContabilJuridica::_resultado_balancete(){ //CÁLCULO DO BALANCETE
    double ativo = 0; 
    double passivo = 0;
    ativo = get_caixa() + get_contasReceber() + get_realizavelLongoPrazo(); //CÁLCULO DO ATIVO
    passivo = get_contasPagar() + get_emprestimos() + get_realizavelCurtoPrazo(); // CÁLCULO DO PASSIVO
    std::cout << "Ativo: " << ativo << std::endl;
    std::cout << "Passivo: " << passivo << std::endl;
    if(ativo > passivo){
        std::cout << "Ativo maior que passivo" << std::endl; //CASO A EMPRESA ESTEJA COM MAIS FATURAMENTO QUE DÍVIDAS
    }else if(ativo < passivo){
        std::cout << "Passivo maior que ativo" << std::endl; //CASO A EMPRESA ESTEJA COM MAIS DÍVIDAS QUE FATURAMENTO
    }else{
        std::cout << "Ativo igual ao passivo" << std::endl; //CASO DESEJADO CASO A CONTABILIDADE ESTEJA CORRETA
    }
}

/*void ContabilJuridica::_calculo_aliquotas_localidade(PessoaJuridica &juridico){
    //depende da localização da empresa (cadastro)
    if(juridico.get_local () == "MG"){ //MG
        
        //aliquota = 12% se vier de outro estado
        //aliquota = 18% se vier de outro pais
        //aliquota = 18% se for de MG
    }
    else if (juridico.get_local () == "SP"){ //SP
        //alquita = 12% se vier de outro estado
        //aliquota = 18% se vier de outro pais
        //aliquota = 18% se for de SP
    }
    else if (juridico.get_local () == "RJ"){ //RJ
        //aliquota = 12% se vier de outro estado
        //aliquota = 20% se vier de outro pais
        //aliquota = 20% se for de RJ
    }
}*/

double ContabilJuridica::get_receita_bruta(){ //RETORNA O VALOR DA RECEITA BRUTA
    for(int i = 0; i < _receitas.size(); i++){
        _receita_bruta += _receitas[i]; //CÁLCULO DA RECEITA BRUTA
    }
    return _receita_bruta; //RETORNA O VALOR DA RECEITA BRUTA
}

void ContabilJuridica::set_mes_contabil(){
    std::string mes;
    std::cout << "Digite o mês contábil: ";
    std::cin.ignore ();
    getline (std::cin,mes);
    _mes_contabil = mes;
}

std::string ContabilJuridica::get_mes_contabil(){
    return _mes_contabil;
}

//GETS PARA O ARMAZENAMENTO DE DADOS

std::vector<std::pair<std::string,double>> ContabilJuridica::get_contasReceber_dados(){
    return std::vector<std::pair<std::string,double>>(_contasReceber);
}

std::vector<std::pair<std::string,double>> ContabilJuridica::get_contasPagar_dados(){
    return std::vector<std::pair<std::string,double>>(_contasPagar);
}

std::vector<std::pair<std::string,double>> ContabilJuridica::get_realizavelCurtoPrazo_dados(){
    return std::vector<std::pair<std::string,double>>(_realizavelCurtoPrazo);
}

std::vector<std::pair<std::string,double>> ContabilJuridica::get_realizavelLongoPrazo_dados(){
    return std::vector<std::pair<std::string,double>>(_realizavelLongoPrazo);
}

std::vector<std::pair<std::string,double>> ContabilJuridica::get_emprestimos_dados(){
    return std::vector<std::pair<std::string,double>>(_emprestimos);
}

