#ifndef ESTATISTICOSFISICO_H
#define ESTATISTICOSFISICO_H
#include <bits/stdc++.h>
#include "pessoa.h"
#include "contabilidade_fisica.h"
#include "recebe_arquivo.h"

class EstatisticosFisico{
private:
    std::vector<ContabilFisica> _contabil_fisica;
public:
    void imposto_renda_anual_fisico(); //INFORMA OS DADOS DA APLICAÇÃO DE DETERMINADO ANO
    void imposto_renda_trianual();// INFORMA OS DADOS DA APLICAÇÃO DE DETERMINADO TRIENIO, COMPARANDO OS RESULTADOS
    //void imposto_renda_semestral();
    //void imposto_renda_anual();

};

#endif