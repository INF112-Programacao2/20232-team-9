#ifndef CONTABILIDADE_FISICA_H
#define CONTABILIDADE_FISICA_H

#include "cadastro.h"
#include <bits/stdc++.h>

class ContabilFisica: public Cadastro{
private:
    std::vector<double> _imposto_renda;
    std::vector<double> _inss;
    std::vector<double> _tetos_aliquotas;
    std::vector<double> _aliquotas;
    std::vector<double> _deducao_dependente;
    std::vector<double> _desconto_simplificado;
    std::vector<double> _porcentagem_tabelas;
    std::vector<double> _porcentagem_tabelas_anual;
    std::vector<double> _porcentagem_tabelas_mensal;
    


public:



};


#endif // CONTABILIDADE_FISICA_H