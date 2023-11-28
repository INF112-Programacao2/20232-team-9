#ifndef CONTABILIDADE_FISICA_H
#define CONTABILIDADE_FISICA_H

#include "pessoa.h"
#include <bits/stdc++.h>

class ContabilFisica : public Pessoa
{
private:
    std::vector<double> _aliquotas;
    std::vector<double> _deducao_dependente_mensal;
    std::vector<double> _desconto_simplificado;
    std::vector<double> _porcentagem_tabelas;
    double _salario_bruto;
    double _base_calculo;
    double _inss;
    double _deducao_dependente;
    bool _empregado, _individual, _facultativo, _mei, _contribuinte;
    double _imposto_renda_final;


public:
    ContabilFisica ();
    void _calcula_imposto_renda();
    void _calcula_inss();
    double _calcula_aliquota(double base_calculo);
    void _calcula_deducao_dependente();
    void _base_calculos();
    double get_Imposto_Renda_Final();
};

#endif // CONTABILIDADE_FISICA_H

/*ORDEM DE CALCULOS
- CALCULAR INSS
- CALCULAR DEPENDENTES
- CALCULAR BASE DE CALCULO
- CALCULAR ALIQUOTA
- CALCULAR IMPOSTO DE RENDA

*/