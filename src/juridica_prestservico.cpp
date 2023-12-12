#include <iostream>
#include <bits/stdc++.h>    
#include "pessoajuridica.h"
#include "contabilidade_juridica.h"
#include "juridica_prestservico.h"
#include "recebe_arquivo.h"

void JuridicaPrestServi::_calculo_aliquotas_anexos(std::string cpf){
    // SERVIÇO
    RecebeArquivo receita;
    std::cout << "Valor Total da Receita Bruta: " << receita.retorna_receita_bruta(cpf) << std::endl;

    // Serviços de limpeza, vigigilância, obras, contrução de imóveis, etc**.

    // ANEXO VI
    if ((receita.retorna_receita_bruta(cpf)/1000) <= 180){ //verifica se a receita bruta é menor que 180 mil
        _result_simples_nacional = (receita.retorna_receita_bruta(cpf)) * 0.045; //calcula o valor a ser pago
        // aliquota 4,5%    
        // desconto = 0
    }
    else if (180 < (receita.retorna_receita_bruta(cpf)/1000) <= 360){ //verifica se a receita bruta é menor que 360 mil
        _result_simples_nacional = (receita.retorna_receita_bruta(cpf) * 0.09) - 8100; //calcula o valor a ser pago
        // aliquota 9%
        // desconto = 8100
    }
    else if (360 < (receita.retorna_receita_bruta(cpf)/1000) <= 720){ //verifica se a receita bruta é menor que 720 mil
        _result_simples_nacional = (receita.retorna_receita_bruta(cpf) * 0.102) - 12420; //calcula o valor a ser pago
        // aliquota 10,2%
        // desconto = 12420
    }
    else if (720 < (receita.retorna_receita_bruta(cpf)/1000) <= 1800){ //verifica se a receita bruta é menor que 1.8 milhões
        _result_simples_nacional = (receita.retorna_receita_bruta(cpf) * 0.14) - 39780; //calcula o valor a ser pago
        // aliquota 14%
        // desconto = 39780
    }
    else if (1800 < (receita.retorna_receita_bruta(cpf)/1000) <= 3600){ //verifica se a receita bruta é menor que 3.6 milhões
        _result_simples_nacional = (receita.retorna_receita_bruta(cpf) * 0.22) - 183780; //calcula o valor a ser pago
        // aliquota 22%
        // desconto = 183780
    }
    else if (3600 < (receita.retorna_receita_bruta(cpf)/1000) <= 4800){ //verifica se a receita bruta é menor que 4.8 milhões
        _result_simples_nacional = (receita.retorna_receita_bruta(cpf) * 0.33) - 828000; //calcula o valor a ser pago 
        // aliquota 33%
        // desconto = 828000
    }
    else 
        _result_simples_nacional = (receita.retorna_receita_bruta(cpf) * 0.33) - 828000; //calcula o valor a ser pago
        // aliquota 33%
        // desconto = 828000
}

double JuridicaPrestServi::get_result_simples_nacional(){ //retorna o valor a ser pago ou restituído
    if(_result_simples_nacional < 0){ //verifica se o valor é menor que 0
        std::cout << "A sua empresa não obteve faturamento." << std::endl;
        return _result_simples_nacional = 0;
    }
    else if(_result_simples_nacional >= 0){ //verifica se o valor é maior que 0
        std::cout << "Valor a restituir: ";
        return _result_simples_nacional;
    }
    return 0;
}