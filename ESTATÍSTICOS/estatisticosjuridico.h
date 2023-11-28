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
    void calcula_media_mensal();
    void calcula_media_trimestral();
    void calcula_media_semestral();
    void calcula_media_anual();



};

//Porcentagem de crescimento
//Media de crescimento
//Regressão Linear
//Desvio Padrão


#endif