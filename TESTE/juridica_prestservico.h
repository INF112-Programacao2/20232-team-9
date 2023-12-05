#include "pessoajuridica.h"
#include "contabilidade_juridica.h"


class JuridicaPrestServi: public ContabilJuridica{
private:
    double _result_simples_nacional;

public:
    void _calculo_aliquotas_anexos();
    double get_result_simples_nacional();
};
/*
// SERVIÇO

// Serviços de limpeza, vigigilância, obras, contrução de imóveis, etc**.

// ANEXO VI
if (valor 1 < 180)
{
    // aliquota 4,5%
    // desconto = 0
}
if (180 < valor 1 < 360)
{
    // aliquota 9%
    // desconto = 8100
}
if (360 < valor 1 < 720)
{
    // aliquota 10,2%
    // desconto = 12420
}
if (720 < valor 1 < 1800)
{
    // aliquota 14%
    // desconto = 39780
}
if (1800 < valor 1 < 3600)
{
    // aliquota 22%
    // desconto = 183780
}
if (3600 < valor 1 < 4800)
{
    // aliquota 33%
    // desconto = 828000
}
*/
