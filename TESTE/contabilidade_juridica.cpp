#include <iostream>
#include <bits/stdc++.h>
#include "pessoajuridica.h"
#include "contabilidade_juridica.h"


//SET

void ContabilJuridica::set_caixa(int quant_elementos){
    double valor;
    for(int i = 0; i < quant_elementos; i++){
        std::cout << "Digite o valor: ";
        std::cin >> valor;
        _caixa.push_back(valor);
    }
    
}

void ContabilJuridica::set_contasPagar(int quant_elementos){
    std::string fonte;
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
    std::string fonte;
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
    std::string fonte;
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
    std::string fonte;
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
    std::string fonte;
    double valor;
    for(int i = 0; i < quant_elementos; i++){
        std::cout << "Digite a fonte: ";
        std::cin >> fonte;
        std::cout << "Digite o valor: ";
        std::cin >> valor;
        _emprestimos.push_back({fonte,valor});
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
        total += _contasPagar[i].second;
    }
    return total;
}

double ContabilJuridica::get_contasReceber(){
    double total = 0;
    for(int i = 0; i < _contasReceber.size(); i++){
        total += _contasReceber[i].second;
    }
    return total;
}

int ContabilJuridica::get_realizavelCurtoPrazo(){
    int total = 0;
    for(int i = 0; i < _realizavelCurtoPrazo.size(); i++){
        total += _realizavelCurtoPrazo[i].second;
    }
    return total;
}

int ContabilJuridica::get_realizavelLongoPrazo(){
    int total = 0;
    for(int i = 0; i < _realizavelLongoPrazo.size(); i++){
        total += _realizavelLongoPrazo[i].second;
    }
    return total;
}

double ContabilJuridica::get_emprestimos(){
    double total = 0;
    for(int i = 0; i < _emprestimos.size(); i++){
        total += _emprestimos[i].second;
    }
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
    std::cout << "Lucro: " << lucro << std::endl;
}

void ContabilJuridica::_calculo_fluxo_caixa(){
    double caixa = 0;
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

void ContabilJuridica::_calculo_aliquotas_localidade(PessoaJuridica &juridico){
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
}

double ContabilJuridica::get_receita_bruta(){
    for(int i = 0; i < _receitas.size(); i++){
        _receita_bruta += _receitas[i];
    }
    return _receita_bruta;
}
