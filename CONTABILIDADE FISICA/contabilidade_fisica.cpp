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

void ContabilFisica::_calcula_imposto_renda()
{
    double salario;
    std::cout << "Digite o seu salário: " << std::endl;
    std::cin >> salario;
    _salario = salario;
    // utilizar salario para calcular o imposto de renda na base de calculo
    if (_salario < 2112)
    {
        _imposto_renda.push_back(0);
    }
    else if (_salario >= 2112.01 && salario < 2826.65)
    {
        _imposto_renda.push_back(158.40);
    }
    else if (_salario >= 2826.66 && salario < 3751.05)
    {
        _imposto_renda.push_back(370.40);
    }
    else if (_salario >= 3751.06 && salario < 4664.68)
    {
        _imposto_renda.push_back(651.73);
    }
    else
    {
        _imposto_renda.push_back(884.96);
    }
}

void ContabilFisica::_calcula_aliquota(){
    if (_salario < 2112)
    {
        _imposto_renda.push_back(0);
    }
    else if (_salario >= 2112.01 && _salario < 2826.65)
    {
        _imposto_renda.push_back(0.075);
    }
    else if (_salario >= 2826.66 && _salario < 3751.05)
    {
        _imposto_renda.push_back(0.15);
    }
    else if (_salario >= 3751.06 && _salario < 4664.68)
    {
        _imposto_renda.push_back(0.225);
    }
    else
    {
        _imposto_renda.push_back(0.275);
    }
}

void ContabilFisica::_calcula_inss()
{
    double salario;
    std::cout << "Digite o seu salário de contribuição: " << std::endl;
    std::cin >> salario;
    _salario = salario;

    // Para Empregado, Empregado Doméstico e Trabalhador Avulso:

    if (_salario <= 1302)
    {
        _inss.push_back(0.075);
    }
    else if (_salario >= 1302.01 && salario <= 2571.29)
    {
        _inss.push_back(0.09);
    }
    else if (_salario >= 2571.30 && salario <= 3856.94)
    {
        _inss.push_back(0.12);
    }
    else if (_salario >= 3856.95 && salario <= 7507.49)
    {
        _inss.push_back(0.14);
    }

    // Para Contribuinte Individual, Facultativo e MEI

    // individual
    if (_salario == 1302)
    {
        _inss.push_back(0.05);
        // valor = 65.10
    }
    else if (_salario == 1302)
    { // facultativo
        _inss.push_back(0.11);
        // valor = 143.22
    }
    else if (_salario >= 1302 && salario <= 7507.49)
    {
        _inss.push_back(0.20);
        // valor = entre 260.40 e 1501.49(teto)
    }
}