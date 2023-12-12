#ifndef JURIDICAINDUSTRIAL_H_
#define JURIDICAINDUSTRIAL_H_
#include "pessoajuridica.h"
#include "contabilidade_juridica.h"
#include <bits/stdc++.h>

class JuridicaIndustrial: public ContabilJuridica{
private:
    std::vector<std::pair<std::string, double>> _estoque; // LISTA DE ESTOQUE
    double _result_simples_nacional; // RESULTADO DO SIMPLES NACIONAL
    double _valor_estoque; // VALOR DO ESTOQUE

public:
    //SET   
    void set_estoque();  // seta a lista e o valor do estoque
    //GET
    double get_estoque(); // retorna o valor total do estoque
    std::vector<std::pair<std::string, double>> get_estoque_dados(); // retorna a lista de estoque
    //METODOS
    virtual void _calculo_aliquotas_anexos(std::string cpf); // cálcula as alíquotas de acordo com o anexo
    virtual double get_result_simples_nacional(); // retorna o valor a ser pago ou restituído

};
#endif
/*
//INDUSTRIA*

    //Metalurgia**

    //Todo tipo de Metal = Simples Nacional ANEXO II
    if(valor1 < 180 )
{
    // aliquota 4,5%
    // desconto = 0
}
if (180 < valor 1 < 360)
{
    // aliquota 7,8%
    // desconto = 5940
}
if (360 < valor 1 < 720)
{
    // aliquota 10%
    // desconto = 13860
}
if (720 < valor 1 < 1800)
{
    // aliquota 11,2%
    // desconto = 22500
}
if (1800 < valor 1 < 3600)
{
    // aliquota 14,7%
    // desconto = 85500
}
if (3600 < valor 1 < 4800)
{
    // aliquota 30%
    // desconto = 720000
}
*/
