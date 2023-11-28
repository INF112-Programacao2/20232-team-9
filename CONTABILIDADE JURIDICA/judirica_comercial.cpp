#include <iostream>
#include <bits/stdc++.h>
#include "pessoajuridica.h"
#include "contabilidade_juridica.h"
#include "juridica_comercial.h"


void JuridicaComercial::_calculo_aliquotas_anexos(){

    if (JuridicaComercial::get_receita_bruta() < 180){
        _result_simples_nacional = JuridicaComercial::get_receita_bruta() * 0.04;
        // aliquota 4%
        // desconto = 0
    }
    if (180 < JuridicaComercial::get_receita_bruta() < 360){
        _result_simples_nacional = (JuridicaComercial::get_receita_bruta() * 0.073) - 5940;
        // aliquota 7,3%
        // desconto = 5940
    }
    if (360 < JuridicaComercial::get_receita_bruta() < 720){
        _result_simples_nacional = (JuridicaComercial::get_receita_bruta() * 0.095) - 13860;
        // aliquota 9,5%
        // desconto = 13860
    }
    if (720 < JuridicaComercial::get_receita_bruta() < 1800){
        _result_simples_nacional = (JuridicaComercial::get_receita_bruta() * 0.107) - 22500;
        // aliquota 10,7%
        // desconto = 22500
    }
    if (1800 < JuridicaComercial::get_receita_bruta() < 3600){
        _result_simples_nacional = (JuridicaComercial::get_receita_bruta() * 0.143) - 87300;
        // aliquota 14,3%
        // desconto = 87300
    }
    if (3600 < JuridicaComercial::get_receita_bruta() < 4800){
        _result_simples_nacional = (JuridicaComercial::get_receita_bruta() * 0.19) - 378000;
        // aliquota 19%
        // desconto = 378000
    }
}

double JuridicaComercial::get_result_simples_nacional(){
    if(_result_simples_nacional < 0){
       std::cout << "Valor a recolher: " << std::endl;
        return _result_simples_nacional*-1;
    }
    else if(_result_simples_nacional > 0){
        std::cout << "Valor a restituir: " << std::endl;
        return _result_simples_nacional;
    }
    return;
}