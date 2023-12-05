#include <iostream>
#include <bits/stdc++.h>    
#include "pessoajuridica.h"
#include "contabilidade_juridica.h"
#include "juridica_prestservico.h"

void JuridicaPrestServi::_calculo_aliquotas_anexos(){
    // SERVIÇO

    // Serviços de limpeza, vigigilância, obras, contrução de imóveis, etc**.

    // ANEXO VI
    if ((JuridicaPrestServi::get_receita_bruta()/1000) < 180){
        _result_simples_nacional = JuridicaPrestServi::get_receita_bruta() * 0.045;
        // aliquota 4,5%
        // desconto = 0
    }
    if (180 < (JuridicaPrestServi::get_receita_bruta()/1000) < 360){
        _result_simples_nacional = (JuridicaPrestServi::get_receita_bruta() * 0.09) - 8100;
        // aliquota 9%
        // desconto = 8100
    }
    if (360 < (JuridicaPrestServi::get_receita_bruta()/1000) < 720){
        _result_simples_nacional = (JuridicaPrestServi::get_receita_bruta() * 0.102) - 12420;
        // aliquota 10,2%
        // desconto = 12420
    }
    if (720 < (JuridicaPrestServi::get_receita_bruta()/1000) < 1800){
        _result_simples_nacional = (JuridicaPrestServi::get_receita_bruta() * 0.14) - 39780;
        // aliquota 14%
        // desconto = 39780
    }
    if (1800 < (JuridicaPrestServi::get_receita_bruta()/1000) < 3600){
        _result_simples_nacional = (JuridicaPrestServi::get_receita_bruta() * 0.22) - 183780;
        // aliquota 22%
        // desconto = 183780
    }
    if (3600 < (JuridicaPrestServi::get_receita_bruta()/1000) < 4800){
        _result_simples_nacional = (JuridicaPrestServi::get_receita_bruta() * 0.33) - 828000;
        // aliquota 33%
        // desconto = 828000
    }
}

double JuridicaPrestServi::get_result_simples_nacional(){
    if(_result_simples_nacional < 0){
        std::cout << "A sua empresa não obteve faturamento." << std::endl;
        return _result_simples_nacional = 0;
    }
    else if(_result_simples_nacional > 0){
        std::cout << "Valor a restituir: " << std::endl;
        return _result_simples_nacional;
    }
    return 0;
}