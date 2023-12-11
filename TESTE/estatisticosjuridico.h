#ifndef ESTATISTICOSJURIDICO_H
#define ESTATISTICOSJURIDICO_H

#include "pessoajuridica.h"
#include "contabilidade_juridica.h"
#include "juridica_comercial.h"
#include "juridica_industrial.h"
#include "juridica_prestservico.h"

class EstatisticosJuridico{
private:
    std::vector<JuridicaComercial> _juridica_comercial;
    std::vector<JuridicaIndustrial> _juridica_industrial;
    std::vector<JuridicaPrestServi> _juridica_prestservico;
public:



    //METODOS
    void dados_mensal(); //INFORMA OS DADOS DO BALANCETE DE DETERMINADO MÊS
    void calcula_media_trimestral(); //INFORMA OS DADOS E COMPARA RECEITAS E LUCRO DO BALANCETE DE DETERMINADO TRIMESTRE
    void calcula_media_semestral(); // INFORMA OS DADOS E COMPARA RECEITAS E LUCRO DO BALANCETE DE DETERMINADO SEMESTRE
    void calcula_media_anual();     // INFORMA OS DADOS, COMPARA RECEITAS E LUCRO DO BALANCETE DE DETERMINADO ANO, E INFORMA O VALOR A RESTITUIR DO SIMPLES NACIONAL
};

//Porcentagem de crescimento
//Media de crescimento
//Regressão Linear
//Desvio Padrão


#endif