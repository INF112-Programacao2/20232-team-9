#ifndef ESTATISTICOSFISICO_H
#define ESTATISTICOSFISICO_H

#include "pessoa.h"
#include "contabilidade_fisica.h"

class EstatisticosFisico{
private:
    std::vector<ContabilFisica> _contabil_fisica;
public:
    void imposto_renda_mensal();
    void imposto_renda_trimestral();
    void imposto_renda_semestral();
    void imposto_renda_anual();

};

#endif