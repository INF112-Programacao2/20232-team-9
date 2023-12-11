#ifndef CONTABILIDADE_FISICA_H
#define CONTABILIDADE_FISICA_H

#include "pessoa.h"
#include <bits/stdc++.h>

class ContabilFisica
{
private:
    //std::vector<double> _aliquotas;
    //std::vector<double> _deducao_dependente_mensal;
    //std::vector<double> _desconto_simplificado;
    //std::vector<double> _porcentagem_tabelas;
    double _salario_bruto;
    double _base_calculo;
    double _inss;
    double _deducao_dependente;
    double _aliquota;
    bool _empregado, _individual, _facultativo, _mei, _contribuinte;
    double _imposto_renda_final;
    int _ano_contabil;


public:
    //SET
    void set_ano_contabil();

    //GETS
    double get_inss();
    double get_deducao_dependente();
    double get_base_calculo();
    double get_aliquota();
    double get_imposto_dados();
    double get_Imposto_Renda_Final();
    double get_salario_bruto();
    int get_ano_contabil();

    void _calcula_imposto_renda();
    void _calcula_inss(Pessoa &fisico);
    double _calcula_aliquota(double base_calculo);
    void _calcula_deducao_dependente();
    void _base_calculos();
};

#endif // CONTABILIDADE_FISICA_H

/*ORDEM DE CALCULOS
- CALCULAR INSS
- CALCULAR DEPENDENTES
- CALCULAR BASE DE CALCULO
- CALCULAR ALIQUOTA
- CALCULAR IMPOSTO DE RENDA

*/