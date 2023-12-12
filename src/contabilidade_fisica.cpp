#include <iostream>
#include <bits/stdc++.h>
#include "pessoa.h"
#include "contabilidade_fisica.h"
// declaração de imposto de renda
// inss e imposto de renda
// tetos de alíquotas
// buscar informações no site da receita federal
// caluculo de alíquotas de imposto de renda mensal e anual
// deduação por dependente
// desconto simplificado
// cálculos básicos por porcentagem das tabelas

// METODOS

// INSS

void ContabilFisica::_calcula_inss(Pessoa &fisico) // cálculo do inss do cliente pessoa física
{   
    long double salario;
    std::cout<<std::endl;
    std::cout << "Digite o seu salário: " << std::endl;
    while(true){
     try{ //tratamento de exceção para entradas inválidas
      std::cin >> salario;
      if(std::cin.fail()){
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        throw std::invalid_argument ("Devem ser digitados apenas números! Digite um salário válido: ");
      }
      else if(salario<0){
        throw std::invalid_argument ("O salário digitado deve ser um número positivo! Digite novamente: ");
      }
      break;

     }catch(std::invalid_argument &e){
        std::cerr<<e.what ()<<std::endl;
     }
    }

    _salario_bruto = salario;

    // Para Empregado, Empregado Doméstico e Trabalhador Avulso:

    if (fisico.get_tipo_pessoa()=="Empregado"){ // Separação de tipos de pessoa física, caso seja empregado

        if (_salario_bruto <= 1320){ // cálculo do inss para empregado com salário bruto menor que salário mínimo
            _inss = _salario_bruto*0.075;
        }
        else if (_salario_bruto >= 1320.01 && _salario_bruto <= 2571.29){ // cálculo do inss para empregado com salário bruto entre salário mínimo e 2571.29
            _inss = ((_salario_bruto-1320)*0.09)+99;
        }
        else if (_salario_bruto >= 2571.30 && salario <= 3856.94){ // cálculo do inss para empregado com salário bruto entre 2571.30 e 3856.94
            _inss = ((_salario_bruto-2571.29)*0.12)+(99+112.61);
        }
        else if (_salario_bruto >= 3856.95 && salario <= 7507.49){ // cálculo do inss para empregado com salário bruto entre 3856.95 e o teto máximo
            _inss = ((_salario_bruto-3856.29)*0.14)+(99+112.61+154.28);
        }
        else{
            _inss = (_salario_bruto*0.14)+713.10; // cálculo do inss para empregado com salário bruto acima do teto máximo
        }
    }

    // Para Contribuinte Individual, Facultativo e MEI
    else{


        // individual
        if (_salario_bruto >= 1320  &&  fisico.get_tipo_pessoa()=="Contribuinte Individual"){ // individual
            _inss = _salario_bruto*0.05;
            if(_inss > 66){
                _inss = 66;
            }
            // valor = 65.10
        }
        else if(_salario_bruto < 1320  &&  fisico.get_tipo_pessoa()=="Contribuinte Individual"){ // individual
            _inss = _salario_bruto*0.05;
            if(_inss > 66){
                _inss = 66;
            }
            // valor = 65.10
        }
        if (_salario_bruto >= 1320  &&  fisico.get_tipo_pessoa()=="Contribuinte Facultativo"){ // facultativo
            _inss = _salario_bruto*0.11;
            if(_inss > 145.20){
                _inss = 145.20;
            }
            // valor = 143.22
        }
        else if(_salario_bruto < 1320  &&  fisico.get_tipo_pessoa()=="Contribuinte Facultativo"){ // facultativo
            _inss = _salario_bruto*0.11;
            if(_inss > 145.20){
                _inss = 145.20;
            }
            // valor = 143.22
        }
        if (_salario_bruto >= 1320  &&  _salario_bruto <= 7507.49  &&  fisico.get_tipo_pessoa()=="Microempreendedor"){ // MEI
            _inss = _salario_bruto*0.20;
            if(_inss > 1501.49){
                _inss = 1501.49;
            }
            // valor = entre 260.40 e 1501.49(teto)
        }
        else if(_salario_bruto < 1320  &&  _salario_bruto <= 7507.49  &&  fisico.get_tipo_pessoa()=="Microempreendedor"){ // MEI
            _inss = _salario_bruto*0.20;
            if(_inss > 1501.49){
                _inss = 1501.49;
            }
            // valor = entre 260.40 e 1501.49(teto)
        }
    }
}

//DEDUÇÃO POR DEPENDENTE

void ContabilFisica::_calcula_deducao_dependente() // cálculo da dedução por dependente do cliente pessoa física
{
    int dependentes;
    std::cout<<std::endl;
    std::cout << "Digite o número de dependentes: " << std::endl;
    while(true){
     try{ //tratamento de exceção para entradas inválidas
      std::cin >> dependentes;
      if(std::cin.fail()){
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        throw std::invalid_argument ("Devem ser digitados apenas números! Digite um número válido: ");
      }
      else if(dependentes<0){
        throw std::invalid_argument ("O número digitado deve ser positivo! Digite novamente: ");
      }
      break;

     }catch(std::invalid_argument &e){
        std::cerr<<e.what ()<<std::endl;
     }
    }
    _deducao_dependente = dependentes * 189.59; // valor da dedução por dependente
}


// BASE DE CALCULO

void ContabilFisica::_base_calculos() // cálculo da base de cálculo do cliente pessoa física
{
    _base_calculo = _salario_bruto - _inss - _deducao_dependente; // cálculo da base de cálculo
}



// IMPOSTO DE RENDA

void ContabilFisica::_calcula_imposto_renda() // cálculo do imposto de renda do cliente pessoa física
{
    double valor_aliquota;
    if (_base_calculo < 2112){ // cálculo do imposto de renda para base de cálculo menor que 2112
        _imposto_renda_final = ContabilFisica::_calcula_aliquota(_base_calculo);
    }
    else if (_base_calculo >= 2112.01 && _base_calculo < 2826.65){ // cálculo do imposto de renda para base de cálculo entre 2112.01 e 2826.65
        valor_aliquota = ContabilFisica::_calcula_aliquota(_base_calculo); // cálculo da alíquota com chamada da função _calcula_aliquota
        _imposto_renda_final = valor_aliquota - 158.40; 
    }
    else if (_base_calculo >= 2826.66 && _base_calculo < 3751.05){ // cálculo do imposto de renda para base de cálculo entre 2826.66 e 3751.05
        valor_aliquota = ContabilFisica::_calcula_aliquota(_base_calculo); // cálculo da alíquota com chamada da função _calcula_aliquota
        _imposto_renda_final = valor_aliquota - 370.40;
    }
    else if (_base_calculo >= 3751.06 && _base_calculo < 4664.68){ // cálculo do imposto de renda para base de cálculo entre 3751.06 e 4664.68
        valor_aliquota = ContabilFisica::_calcula_aliquota(_base_calculo); // cálculo da alíquota com chamada da função _calcula_aliquota
        _imposto_renda_final = valor_aliquota - 651.53;
    }
    else{
        valor_aliquota = ContabilFisica::_calcula_aliquota(_base_calculo); // cálculo do imposto de renda para base de cálculo acima de 4664.68
        _imposto_renda_final = valor_aliquota - 884.96;
    }
}

// ALIQUOTA


long double ContabilFisica::_calcula_aliquota(double base_calculo){ // cálculo da alíquota com base de cálculo
    if (_base_calculo < 2112){ // cálculo da alíquota para base de cálculo menor que 2112
        return _aliquota = 0;
    }
    else if (_base_calculo >= 2112.01 && _base_calculo < 2826.65) // cálculo da alíquota para base de cálculo entre 2112.01 e 2826.65
    {
        return _aliquota = (base_calculo*0.075);
    }
    else if (_base_calculo >= 2826.66 && _base_calculo < 3751.05) // cálculo da alíquota para base de cálculo entre 2826.66 e 3751.05
    {
        return _aliquota = (base_calculo*0.15);
    }
    else if (_base_calculo >= 3751.06 && _base_calculo < 4664.68) // cálculo da alíquota para base de cálculo entre 3751.06 e 4664.68
    {
        return _aliquota = (base_calculo*0.225);
    }
    else{ // cálculo da alíquota para base de cálculo acima de 4664.68
        return _aliquota = (base_calculo*0.275); 
    }
}


long double ContabilFisica::get_Imposto_Renda_Final(){ // retorna o valor do imposto de renda a ser pago ou restituído
  std::cout<<std::endl;
    if(_imposto_renda_final < 0){
        std::cout << "Imposto de renda a restituir: ";
        return _imposto_renda_final*(-1);
    }
    else if(_imposto_renda_final >= 0){
        std::cout << "Imposto de renda a pagar: ";
        return _imposto_renda_final;
    }
    return 0;
}

long double ContabilFisica::get_inss(){ // retorna o valor do inss
    if(_inss < 0){
        return 0;
    }
    else{
        return _inss;
    }
}

long double ContabilFisica::get_deducao_dependente(){ // retorna o valor da dedução por dependente
    if(_deducao_dependente < 0){
        return 0;
    }
    else{
        return _deducao_dependente;
    }
}

long double ContabilFisica::get_base_calculo(){ // retorna o valor da base de cálculo
    if(_base_calculo < 0){
        return 0;
    }
    else{
        return _base_calculo;
    }
}

long double ContabilFisica::get_aliquota(){ // retorna o valor da alíquota
    if(_aliquota < 0){
        return 0;
    }
    else{
        return _aliquota;
    }
}

long double ContabilFisica::get_imposto_dados(){ // retorna o valor do imposto de renda a ser pago ou restituído
    if (_imposto_renda_final < 0)
    {
        return _imposto_renda_final * (-1);
    }
    else if (_imposto_renda_final >= 0)
    {
        return _imposto_renda_final;
    }
    return 0;
}

long double ContabilFisica::get_salario_bruto(){ // retorna o valor do salário bruto
    if(_salario_bruto < 0){
        return 0;
    }
    else{
        return _salario_bruto;
    }
}
void ContabilFisica::set_ano_contabil(){
    std::cout << "Qual o ano da aplicação do imposto de renda?" << std::endl;
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

int ContabilFisica::get_ano_contabil(){
    return _ano_contabil;
}