#ifndef CONTABILIDADE_FISICA_H
#define CONTABILIDADE_FISICA_H

#include "pessoa.h"
#include <bits/stdc++.h>

class ContabilFisica
{
private:
    long double _salario_bruto;
    long double _base_calculo;
    long double _inss;
    long double _deducao_dependente;
    long double _aliquota;
    bool _empregado, _individual, _facultativo, _mei, _contribuinte;
    long double _imposto_renda_final;
    int _ano_contabil;


public:
    //SET
    void set_ano_contabil();

    //GETS
    long double get_inss();
    long double get_deducao_dependente();
    long double get_base_calculo();
    long double get_aliquota();
    long double get_imposto_dados();
    long double get_Imposto_Renda_Final();
    long double get_salario_bruto();
    int get_ano_contabil();

    void _calcula_imposto_renda();
    void _calcula_inss(Pessoa &fisico);
    long double _calcula_aliquota(double base_calculo);
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