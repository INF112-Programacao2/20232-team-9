#include <iostream>
#include <bits/stdc++.h>
#include "pessoajuridica.h"
#include "contabilidade_juridica.h"
#include "juridica_comercial.h"


void JuridicaComercial::_calculo_aliquotas_anexos(){ // cálcula as alíquotas de acordo com o anexo

    if ((JuridicaComercial::get_receita_bruta()/1000) < 180){ //verifica se a receita bruta é menor que 180 mil
        _result_simples_nacional = JuridicaComercial::get_receita_bruta() * 0.04; //calcula o valor a ser pago
        // aliquota 4%
        // desconto = 0
    }
    if (180 < (JuridicaComercial::get_receita_bruta()/1000) < 360){ //verifica se a receita bruta é menor que 360 mil
        _result_simples_nacional = (JuridicaComercial::get_receita_bruta() * 0.073) - 5940; //calcula o valor a ser pago
        // aliquota 7,3%
        // desconto = 5940
    }
    if (360 < (JuridicaComercial::get_receita_bruta()/1000) < 720){ //verifica se a receita bruta é menor que 720 mil
        _result_simples_nacional = (JuridicaComercial::get_receita_bruta() * 0.095) - 13860; //calcula o valor a ser pago
        // aliquota 9,5%
        // desconto = 13860
    }
    if (720 < (JuridicaComercial::get_receita_bruta()/1000) < 1800){ //verifica se a receita bruta é menor que 1.8 milhões
        _result_simples_nacional = (JuridicaComercial::get_receita_bruta() * 0.107) - 22500; //calcula o valor a ser pago
        // aliquota 10,7%
        // desconto = 22500
    }
    if (1800 < (JuridicaComercial::get_receita_bruta()/1000) < 3600){ //verifica se a receita bruta é menor que 3.6 milhões
        _result_simples_nacional = (JuridicaComercial::get_receita_bruta() * 0.143) - 87300; //calcula o valor a ser pago
        // aliquota 14,3%
        // desconto = 87300
    }
    if (3600 < (JuridicaComercial::get_receita_bruta()/1000) < 4800){ //verifica se a receita bruta é menor que 4.8 milhões
        _result_simples_nacional = (JuridicaComercial::get_receita_bruta() * 0.19) - 378000; //calcula o valor a ser pago
        // aliquota 19%
        // desconto = 378000
    }
}

double JuridicaComercial::get_result_simples_nacional(){ // retorna o valor a ser pago ou restituído
    if(_result_simples_nacional < 0){ //verifica se o valor é menor que 0
       std::cout << "A sua empresa não obteve faturamento." << std::endl;
        return _result_simples_nacional = 0;
    }
    else if(_result_simples_nacional > 0){ //verifica se o valor é maior que 0
        std::cout << "Valor a restituir: " << std::endl;
        return _result_simples_nacional;
    }
    return 0;
}