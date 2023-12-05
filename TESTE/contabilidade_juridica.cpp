#include <iostream>
#include <bits/stdc++.h>
#include "pessoajuridica.h"
#include "contabilidade_juridica.h"


//SET

void ContabilJuridica::set_caixa(){
    double valor;
    bool opcao = false;
    int valida;
    while(!opcao){
        std::cout<<std::endl;
        std::cout << "Você deseja adicionar um valor ao caixa? " << std::endl;
        std::cout << "(1) - Sim" << std::endl;
        std::cout << "(2) - Não" << std::endl;
        std::cin >> valida;
        if(valida == 1){
            std::cout << "Digite o valor: ";
            std::cin >> valor;
            _caixa.push_back(valor);
        }
        else if(valida == 2){
            opcao = true;
        }
        else{
            std::cout << "Opção inválida" << std::endl;
        }
    }
    
}

void ContabilJuridica::set_contasPagar(){
    std::string fonte;
    double valor;
    bool opcao = false;
    int valida;
    while (!opcao){
        std::cout<<std::endl;
        std::cout << "Você deseja adicionar informação à contas a pagar? " << std::endl;
        std::cout << "(1) - Sim" << std::endl;
        std::cout << "(2) - Não" << std::endl;
        std::cin >> valida;
        if(valida == 1){
            std::cin.ignore ();
            std::cout << "Digite a fonte: ";
            getline (std::cin,fonte);
            std::cout << "Digite o valor: ";
            std::cin >> valor;
            _contasPagar.push_back({fonte,valor});
        }
        else if(valida == 2){
            opcao = true;
        }
        else{
            std::cout << "Opção inválida" << std::endl;
        }
    }
}

void ContabilJuridica::set_contasReceber(){
    std::string fonte;
    double valor;
    bool opcao = false;
    int valida;
    while (!opcao)
    {
        std::cout<<std::endl;
        std::cout << "Você deseja adicionar informação à contas a receber? " << std::endl;
        std::cout << "(1) - Sim" << std::endl;
        std::cout << "(2) - Não" << std::endl;
        std::cin >> valida;
        if(valida == 1){
            std::cin.ignore ();
            std::cout << "Digite a fonte: ";
            getline (std::cin,fonte);
            std::cout << "Digite o valor: ";
            std::cin >> valor;
            _contasReceber.push_back({fonte,valor});
        }
        else if(valida == 2){
            opcao = true;
        }
        else{
            std::cout << "Opção inválida" << std::endl;
        }
    }
}

void ContabilJuridica::set_realizavelCurtoPrazo(){
    std::string fonte;
    int valor;
    bool opcao = false;
    int valida;
    while (!opcao)
    {
        std::cout<<std::endl;
        std::cout << "Você deseja adicionar informação à realizável curto prazo? " << std::endl;
        std::cout << "(1) - Sim" << std::endl;
        std::cout << "(2) - Não" << std::endl;
        std::cin >> valida;
        if(valida == 1){
            std::cin.ignore ();
            std::cout << "Digite a fonte: ";
            getline (std::cin,fonte);
            std::cout << "Digite o valor: ";
            std::cin >> valor;
            _realizavelCurtoPrazo.push_back({fonte,valor});
        }
        else if(valida == 2){
            opcao = true;
        }
        else{
            std::cout << "Opção inválida" << std::endl;
        }
    }
}

void ContabilJuridica::set_realizavelLongoPrazo(){
    std::string fonte;
    int valor;
    bool opcao = false;
    int valida;
    while (!opcao)
    {
        std::cout<<std::endl;
        std::cout << "Você deseja adicionar informação à realizável longo prazo?" << std::endl;
        std::cout << "(1) - Sim" << std::endl;
        std::cout << "(2) - Não" << std::endl;
        std::cin >> valida;
        if(valida == 1){
            std::cin.ignore ();
            std::cout << "Digite a fonte: ";
            getline (std::cin,fonte);
            std::cout << "Digite o valor: ";
            std::cin >> valor;
            _realizavelLongoPrazo.push_back({fonte,valor});
        }
        else if(valida == 2){
            opcao = true;
        }
        else{
            std::cout << "Opção inválida" << std::endl;
        }
    }
}

void ContabilJuridica::set_emprestimos(){
    std::string fonte;
    double valor;
    bool opcao = false;
    int valida;
    while (!opcao)
    {
        std::cout<<std::endl;
        std::cout << "Você deseja adicionar informação à emprestimos? " << std::endl;
        std::cout << "(1) - Sim" << std::endl;
        std::cout << "(2) - Não" << std::endl;
        std::cin >> valida;
        if(valida == 1){
            std::cin.ignore ();
            std::cout << "Digite a fonte: ";
            getline (std::cin,fonte);
            std::cout << "Digite o valor: ";
            std::cin >> valor;
            _emprestimos.push_back({fonte,valor});
        }
        else if(valida == 2){
            opcao = true;
        }
        else{
            std::cout << "Opção inválida" << std::endl;
        }
    }
}


//GET

double ContabilJuridica::get_caixa(){
    double total = 0;
    for(int i = 0; i < _caixa.size(); i++){
        total += _caixa[i];
    }
    return total;
}

double ContabilJuridica::get_contasPagar(){
    double total = 0;
    for(int i = 0; i < _contasPagar.size(); i++){
        std::cout << _contasPagar[i].first << " : " << _contasPagar[i].second << std::endl;
        total += _contasPagar[i].second;
    }
    std::cout << "Valor total de Contas a Pagar: ";
    return total;
}

double ContabilJuridica::get_contasReceber(){
    double total = 0;
    for(int i = 0; i < _contasReceber.size(); i++){
        std::cout << _contasReceber[i].first << " : " << _contasReceber[i].second << std::endl;
        total += _contasReceber[i].second;
    }
    std::cout << "Valor total de Contas a Receber: ";
    return total;
}

int ContabilJuridica::get_realizavelCurtoPrazo(){
    int total = 0;
    for(int i = 0; i < _realizavelCurtoPrazo.size(); i++){
        std::cout << _realizavelCurtoPrazo[i].first << " : " << _realizavelCurtoPrazo[i].second << std::endl;
        total += _realizavelCurtoPrazo[i].second;
    }
    std::cout << "Valor total de Realizável a Curto Prazo: ";
    return total;
}

int ContabilJuridica::get_realizavelLongoPrazo(){
    int total = 0;
    for(int i = 0; i < _realizavelLongoPrazo.size(); i++){
        std::cout << _realizavelLongoPrazo[i].first << " : " << _realizavelLongoPrazo[i].second << std::endl;
        total += _realizavelLongoPrazo[i].second;
    }
    std::cout << "Valor total de Realizável a Longo Prazo: ";
    return total;
}

double ContabilJuridica::get_emprestimos(){
    double total = 0;
    for(int i = 0; i < _emprestimos.size(); i++){
        std::cout << _emprestimos[i].first << " : " << _emprestimos[i].second << std::endl;
        total += _emprestimos[i].second;
    }
    std::cout << "Valor total de Empréstimos: ";
    return total;
}

//METODOS

void ContabilJuridica::_calculo_DRE(){
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

void ContabilJuridica::_calculo_fluxo_caixa(){
    double caixa = 0;
    for(int i=0; i<_caixa.size(); i++){
        caixa+=_caixa[i];
    }
    for(int i = 0; i < _result_dre.size(); i++){
        caixa += _result_dre[i];
    }
    std::cout << "Resultado do fluxo de caixa: " << caixa << std::endl;
}

void ContabilJuridica::_resultado_balancete(){
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

double ContabilJuridica::get_receita_bruta(){
    for(int i = 0; i < _receitas.size(); i++){
        _receita_bruta += _receitas[i];
    }
    return _receita_bruta;
}
