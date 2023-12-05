#include <iostream>
#include <bits/stdc++.h>
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

void ContabilFisica::_calcula_inss(Pessoa &fisico)
{
    double salario;
    std::cout<<std::endl;
    std::cout << "Digite o seu salário: " << std::endl;
    while(true){
     try{
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

    if (fisico.get_tipo_pessoa()=="Empregado"){

        if (_salario_bruto <= 1320){
            _inss = _salario_bruto*0.075;
        }
        else if (_salario_bruto >= 1320.01 && _salario_bruto <= 2571.29){
            _inss = ((_salario_bruto-1320)*0.09)+99;
        }
        else if (_salario_bruto >= 2571.30 && salario <= 3856.94){
            _inss = ((_salario_bruto-2571.29)*0.12)+(99+112.61);
        }
        else if (_salario_bruto >= 3856.95 && salario <= 7507.49){
            _inss = ((_salario_bruto-3856.29)*0.14)+(99+112.61+154.28);
        }
    }

    // Para Contribuinte Individual, Facultativo e MEI
    else{

        // individual
        if (_salario_bruto >= 1320  &&  fisico.get_tipo_pessoa()=="Contribuinte Individual"){
            _inss = _salario_bruto*0.05;
            if(_inss > 66){
                _inss = 66;
            }
            // valor = 65.10
        }
        else if (_salario_bruto >= 1320  &&  fisico.get_tipo_pessoa()=="Contribuinte Facultativo"){ // facultativo
            _inss = _salario_bruto*0.11;
            if(_inss > 145.20){
                _inss = 145.20;
            }
            // valor = 143.22
        }
        else if (_salario_bruto >= 1320  &&  _salario_bruto <= 7507.49  &&  fisico.get_tipo_pessoa()=="Microempreendedor"){ // MEI
            _inss = _salario_bruto*0.20;
            if(_inss > 1501.49){
                _inss = 1501.49;
            }
            // valor = entre 260.40 e 1501.49(teto)
        }
    }
}

//DEDUÇÃO POR DEPENDENTE

void ContabilFisica::_calcula_deducao_dependente()
{
    int dependentes;
    std::cout<<std::endl;
    std::cout << "Digite o número de dependentes: " << std::endl;
    while(true){
     try{
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
    _deducao_dependente = dependentes * 189.59;
}


// BASE DE CALCULO

void ContabilFisica::_base_calculos()
{
    _base_calculo = _salario_bruto - _inss - _deducao_dependente;
}



// IMPOSTO DE RENDA

void ContabilFisica::_calcula_imposto_renda(){
    // utilizar salario para calcular o imposto de renda na base de calculo
    double valor_aliquota;
    if (_base_calculo < 2112){
        _imposto_renda_final = ContabilFisica::_calcula_aliquota(_base_calculo);
    }
    else if (_base_calculo >= 2112.01 && _base_calculo < 2826.65){
        valor_aliquota = ContabilFisica::_calcula_aliquota(_base_calculo);
        _imposto_renda_final = valor_aliquota - 158.40; 
    }
    else if (_base_calculo >= 2826.66 && _base_calculo < 3751.05){
        valor_aliquota = ContabilFisica::_calcula_aliquota(_base_calculo);
        _imposto_renda_final = valor_aliquota - 370.40;
    }
    else if (_base_calculo >= 3751.06 && _base_calculo < 4664.68){
        valor_aliquota = ContabilFisica::_calcula_aliquota(_base_calculo);
        _imposto_renda_final = valor_aliquota - 651.53;
    }
    else{
        valor_aliquota = ContabilFisica::_calcula_aliquota(_base_calculo);
        _imposto_renda_final = valor_aliquota - 884.96;
    }
}


// ALIQUOTA


double ContabilFisica::_calcula_aliquota(double base_calculo){
    if (_base_calculo < 2112){
        return 0;
    }
    else if (_base_calculo >= 2112.01 && _base_calculo < 2826.65)
    {
        return base_calculo*0.075;
    }
    else if (_base_calculo >= 2826.66 && _base_calculo < 3751.05)
    {
        return base_calculo*0.15;
    }
    else if (_base_calculo >= 3751.06 && _base_calculo < 4664.68)
    {
        return base_calculo*0.225;
    }
    else{
        return base_calculo*0.275;
    }
}


double ContabilFisica::get_Imposto_Renda_Final(){
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
