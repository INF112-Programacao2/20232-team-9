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
            while (true)
            {
                std::cout << "Digite o valor: ";
                try
                { // tratamento de exceções para entrada de dados
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
            while (true)
            {
                std::cout << "Digite o valor: ";
                try
                { // tratamento de exceções para entrada de dados
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
                if (valor < 0)
                {
                    std::cout << "O valor não pode ser negativo!" << std::endl;
                }
                else
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
            while (true)
            {
                std::cout << "Digite o valor: ";
                try
                { // tratamento de exceções para entrada de dados
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
                if (valida < 0)
                {
                    std::cout << "O valor não pode ser negativo!" << std::endl;
                }
                else
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
            while (true)
            {
                std::cout << "Digite o valor: ";
                try
                { // tratamento de exceções para entrada de dados
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
            while (true)
            {
                std::cout << "Digite o valor: ";
                try
                { // tratamento de exceções para entrada de dados
                    std::cin >> valor;
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
            while (true)
            {
                std::cout << "Digite o valor: ";
                try
                { // tratamento de exceções para entrada de dados
                    std::cin >> valor;
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

long double ContabilJuridica::get_caixa(){ //RETORNA O VALOR TOTAL DO CAIXA
    double total = 0;
    for(int i = 0; i < _caixa.size(); i++){
        total += _caixa[i];
    }
    //std::cout << "Valor total de Caixa: ";
    return total;
}

long double ContabilJuridica::get_contasPagar(){ //RETORNA O VALOR TOTAL DAS CONTAS A PAGAR
    double total = 0;
    for(int i = 0; i < _contasPagar.size(); i++){
        std::cout << _contasPagar[i].first << " : " << _contasPagar[i].second << std::endl; //IMPRIME A LISTA DE CONTAS A PAGAR
        total += _contasPagar[i].second;
    }
    std::cout << "Valor total de Contas a Pagar: ";
    return total; // RETORNA O VALOR TOTAL DAS CONTAS A PAGAR
}

long double ContabilJuridica::get_contasReceber(){ //RETORNA O VALOR TOTAL DAS CONTAS A RECEBER
    double total = 0;
    for(int i = 0; i < _contasReceber.size(); i++){
        std::cout << _contasReceber[i].first << " : " << _contasReceber[i].second << std::endl; //IMPRIME A LISTA DE CONTAS A RECEBER
        total += _contasReceber[i].second;
    }
    std::cout << "Valor total de Contas a Receber: ";
    return total; // RETORNA O VALOR TOTAL DAS CONTAS A RECEBER
}

long double ContabilJuridica::get_realizavelCurtoPrazo(){ //RETORNA O VALOR TOTAL DO REALIZÁVEL A CURTO PRAZO
    int total = 0;
    for(int i = 0; i < _realizavelCurtoPrazo.size(); i++){
        std::cout << _realizavelCurtoPrazo[i].first << " : " << _realizavelCurtoPrazo[i].second << std::endl; //IMPRIME A LISTA DE REALIZÁVEL A CURTO PRAZO
        total += _realizavelCurtoPrazo[i].second;
    }
    std::cout << "Valor total de Realizável a Curto Prazo: ";
    return total; // RETORNA O VALOR TOTAL DO REALIZÁVEL A CURTO PRAZO
}

long double ContabilJuridica::get_realizavelLongoPrazo(){ //RETORNA O VALOR TOTAL DO REALIZÁVEL A LONGO PRAZO
    int total = 0;
    for(int i = 0; i < _realizavelLongoPrazo.size(); i++){
        std::cout << _realizavelLongoPrazo[i].first << " : " << _realizavelLongoPrazo[i].second << std::endl; //IMPRIME A LISTA DE REALIZÁVEL A LONGO PRAZO
        total += _realizavelLongoPrazo[i].second;
    }
    std::cout << "Valor total de Realizável a Longo Prazo: ";
    return total; // RETORNA O VALOR TOTAL DO REALIZÁVEL A LONGO PRAZO
}

long double ContabilJuridica::get_emprestimos(){ //RETORNA O VALOR TOTAL DE EMPRÉSTIMOS
    double total = 0;
    for(int i = 0; i < _emprestimos.size(); i++){
        std::cout << _emprestimos[i].first << " : " << _emprestimos[i].second << std::endl; //IMPRIME A LISTA DE EMPRÉSTIMOS
        total += _emprestimos[i].second;
    }
    std::cout << "Valor total de Empréstimos: ";
    return total; // RETORNA O VALOR TOTAL DE EMPRÉSTIMOS
}

//METODOS

void ContabilJuridica::_calculo_DRE(){ //CÁLCULO DA DEMONSTRAÇÃO DO RESULTADO DO EXERCÍCIO
    double receita = 0;
    double despesa = 0;
    for(int i = 0; i < _contasReceber.size(); i++){ 
        receita += _contasReceber[i].second; //CÁLCULO DAS RECEITAS
    }
    for(int i = 0; i < _contasPagar.size(); i++){
        despesa += _contasPagar[i].second; //CÁLCULO DAS DESPESAS
    }
    _receita_bruta = receita;
    _despesa = despesa;
    _lucro = receita - despesa; //CÁCULO DO LUCRO OU PREJUÍZO
    _result_dre = _lucro;
    std::cout << "Receita: " << receita << std::endl;
    std::cout << "Despesa: " << despesa << std::endl;
    if(_lucro>=0){
        std::cout << "Lucro: " << _lucro << std::endl;
    }
    else{
        std::cout << "Prejuizo: " << _lucro << std::endl;
    }
}

void ContabilJuridica::_calculo_fluxo_caixa(){ //CÁLCULO DO FLUXO DE CAIXA
    double caixa = 0;
    for(int i=0; i<_caixa.size(); i++){ //CÁLCULO DO CAIXA
        caixa+=_caixa[i];
    }
    caixa += _result_dre;
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


long double ContabilJuridica::get_receita_bruta(){ //RETORNA O VALOR DA RECEITA BRUTA
    return _receita_bruta; //RETORNA O VALOR DA RECEITA BRUTA
}

void ContabilJuridica::set_mes_contabil(){
    std::string mes;
    std::cout << "Digite o mês contábil: ";
    while (true){
     try
     {
      std::cin>>mes;
      if(mes != "1" && mes != "2" && mes != "3" && mes != "4" && mes != "5" && mes != "6" && mes != "7" && mes != "8" && mes != "9" && mes != "10" && mes != "11" && mes != "11"){
        throw std::invalid_argument ("O mês digitado não existe! Digite um mês válido (1 à 12): ");
      }
      _mes_contabil = mes;
      break;
     }
     catch(const std::invalid_argument& e)
     {
        std::cerr << e.what() << '\n';
     }
    }
    
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

long double ContabilJuridica::get_despesa(){
    return _despesa;
}

long double ContabilJuridica::get_lucro(){
    return _lucro;
}

void ContabilJuridica::set_ano_contabil(){
    std::cout << "Qual o ano da aplicação da Contabilidade?" << std::endl;
    while (true)
    {
        try
        { // tratamento de exceção para entradas inválidas
            std::cin >> _ano_contabil;
            if (std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                throw std::invalid_argument("Devem ser digitados apenas números! Digite um ano válido(entre 2010 e 2150): ");
            }
            else if (_ano_contabil < 2010 || _ano_contabil > 2150)
            {
                   throw std::invalid_argument("O ano contábil deve ser um ano válido(entre 2010 e 2150)! Digite novamente: ");
            }
            break;
        }
        catch (std::invalid_argument &e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
}

int ContabilJuridica::get_ano_contabil(){
    return _ano_contabil;
}

void ContabilJuridica::_limpa_vectors(){
    _caixa.clear();
    _contasPagar.clear();
    _contasReceber.clear();
    _realizavelCurtoPrazo.clear();
    _realizavelLongoPrazo.clear();
    _emprestimos.clear();
}
